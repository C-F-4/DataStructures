/**
 * Wrapper Functions allow more enhanced options to the algorithms (Functions Definitions)
 */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "wrapper.hpp"
#include "utils.hpp"

typedef unsigned int uint;

namespace wrapper {
/**
 * Local to Namespace
 */
enum OPERATINGSYSTEM {
    windows,
    mac,
    linux,
    unknown
    /*add more OS here*/
} operatingSystem;

int getOs() {
#ifdef _WIN32
    operatingSystem = windows;
#elif __APPLE__
    operatingSystem = mac;
#elif __linux__
    operatingSystem = linux;
#else
    operatingSystem = unknown;
#endif
    return wrapper::operatingSystem;
}

/**
 * Global/ available outside this namespace
 */
void clearScreen() {
    int id = getOs();
    if(id == operatingSystem) {
        system("CLS");
    }
    else if(id == operatingSystem) {
        system("CLEAR");
    }
    else if(id == operatingSystem) {
        system("clear");
    }
    else {
        std::clog << "Unknown OS found" << std::endl;
    }
}

// Update it to support constraints + Template + Template Specialization
template <typename T>
T inputOption(std::string msg = "") {
    T tmp;
    std::cout << msg << ">> ";
    std::cin >> tmp;
    return tmp;
}

std::pair<int, std::string> ioOption() {
    int op;
    std::string fileName;
    std::cout << "0 - for input/output from/to file" << std::endl
              << "1 - for input/output from/to console" << std::endl;
    op = wrapper::inputOption<int>();
    if(op == 0) {
        // Get the File Path - Absolute | Relative(to project directory)
        fileName = inputOption<std::string>();
    }
    else if(op == 1) {
        fileName = "";
    }
    return (std::pair<int, std::string>(op, fileName));
}

template <typename T>
std::vector<T> inputRawData(std::pair<int, std::string> option) {
    std::vector<T> input;
    if(option.first == 0) {
        // Read from file
        std::ifstream file;
        std::string fileName = option.second;
        file.open(fileName, std::ios::in);
        if(file.is_open()) {
            std::cout << "FILE_OPEN_SUCCESS" << std::endl;
            // Fill vector input
            int tmp;
            while(file >> tmp) {
                input.push_back(tmp);
            }
            file.close();
        }
        else {
            std::cout << "FILE_OPEN_ERROR: " << fileName << std::endl;
        }
    }
    else if(option.first == 1) {
        std::string msg = "Size ";
        size_t sizeV = inputOption<size_t>(msg);
        for(uint i = 0; i < sizeV; i++) {
            T tmp;
            std::cin >> tmp;
            input.push_back(tmp);
        }
    }
    return input;
}

template <typename T>
void printVector(std::vector<T> v) {
    for(uint i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void writeFile(std::string fileName, std::vector<T> v) {
    std::ofstream file;
    file.open(fileName, std::ios::out);
    if(file.is_open()) {
        for(uint i = 0; i < v.size(); i++) {
            file << v.at(i) << ' ';
        }
        std::cout << "Output has been saved at: " << fileName << std::endl;
        file.close();
    }
}

template <typename T>
void write(std::vector<T> v, std::pair<int, std::string> option) {
    if(option.first == 0) {
        std::string fileName = option.second;
        fileName += ".out";
        wrapper::writeFile(fileName, v);
    }
    else if(option.first == 1) {
        wrapper::printVector(v);
    }
}

int searchWrapper() {
    std::cout << "0 - Linear Search" << std::endl
              << "1 - Binary Search" << std::endl;
    int op;
    // What Algo user wants to use
    op = wrapper::inputOption<int>();
    // Get the user's preference of input
    std::pair<int, std::string> option = wrapper::ioOption();
    // Take the input here based on "option" and pass that to the utils algorithms
    std::vector<int> input;
    input = inputRawData<int>(option);
    int key = wrapper::inputOption<int>("Key ");
    if(op == 0) {
        // Do Linear SearchlinearSearch
        std::pair<bool, int> result = utils::linearSearch<int>(input, key);
        std::cout << result.first << ' ' << result.second << std::endl;
    }
    else if(op == 1) {
        // Do Binary Search
        std::pair<bool, int> result = utils::binarySearchWrap<int>(input, key);
        std::cout << result.first << ' ' << result.second << std::endl;
    }
    return 0;
}

int sortWrapper() {
    std::cout << "0 - Bubble Sort" << std::endl
              << "1 - Insertion Sort" << std::endl
              << "2 - Merge Sort" << std::endl
              << "3 - Quick Sort" << std::endl;
    int op;
    // What Algo user wants to use
    op = wrapper::inputOption<int>();
    // Get the user's preference of input
    std::pair<int, std::string> option = wrapper::ioOption();
    // Take the input here based on "option" and pass that to the utils algorithms
    std::vector<int> input;
    input = inputRawData<int>(option);
    if(op == 0) {
        // Do Bubble Sort
        std::vector<int> result = utils::bubbleSort(input);
        wrapper::write(result, option);
    }
    else if(op == 1) {
        // Do Insertion Sort
        std::vector<int> result = utils::insertionSort(input);
        wrapper::write(result, option);
    }
    else if(op == 2) {
        // Do Merge Sort
        std::vector<int> result = utils::mergeSort(input);
        wrapper::write(result, option);
    }
    else if(op == 3) {
        // Do Quick Sort
        std::vector<int> result = utils::quickSort(input);
        wrapper::write(result, option);
    }
    return 0;
}

struct Item {
    int value;
    int weight;
    int benefit;
    /*Item(int value, int weight):value(value), weight(weight) {
        benefit = value / weight;
    }*/
};

int greedyWrapper() {
    std::cout << "0 - Fractional Knapsack Problem" << std::endl
              << "1 - 0|1 Knapsack Problem" << std::endl
              << "2 - Machine Scheduling" << std::endl
              << "3 - Sum Of Subsets - DP" << std::endl
              << "4 - N Queens - DP" << std::endl
              << "5 - Maximum Contiguous Sum Subsequence" << std::endl
              << "6 - Fibonacci" << std::endl
              << "7 - Reduce N -> 1" << std::endl;
    int op;
    op = wrapper::inputOption<int>();
    if(op == 0) {
        // Do FKP
        size_t sackSize;
        std::cin >> sackSize;
        int noOfItems;
        std::cin >> noOfItems;
        std::vector<Item> items(noOfItems);
        for(int i = 0; i < noOfItems; i++) {
            int va, wb;
            std::cin >> va >> wb;
            items.at(i).value = va;
            items.at(i).weight = wb;
            items.at(i).benefit = va/wb;
        }
        utils::fracKnapsack(items, noOfItems, sackSize);
    }
    else if(op == 1) {
        // Do KP
        size_t sackSize;
        std::cin >> sackSize;
        int noOfItems;
        std::cin >> noOfItems;
        std::vector<Item> items(noOfItems);
        for(int i = 0; i < noOfItems; i++) {
            int va, wb;
            std::cin >> va >> wb;
            items.at(i).value = va;
            items.at(i).weight = wb;
            items.at(i).benefit = va/wb;
        }
        utils::zeroOneKnapsack(items, noOfItems, sackSize);
    }
    else if(op == 2) {
        // Do MS
        size_t sizeX;
        std::cin >> sizeX;
        struct job {
            char id;
            int deadline;
            int profit;
        };
        std::vector<job> v(sizeX);
        for(int i = 0; i < sizeX; i++) {
            std::cin >> v[i].id >> v[i].deadline >> v[i].profit;
        }
        utils::machineScheduling(v);
    }
    else if(op == 3) {
        // DP - Move to separate DP wrapper
        std::vector<int> v;
        for(int i = 0; i < 10; i++) {
            v.push_back(i);
        }
        v.at(0) = -1;
        //wrapper::printVector(utils::sumOfSubWrap(v, 5));
        utils::sumOfSubWrap(v, 7);
    }
    else if(op == 4) {
        // DP - - Move to DP wrapper
        size_t sizeBoard = 0;
        std::cin >> sizeBoard;
        utils::nQueens(sizeBoard);
    }
    else if(op == 5) {
        static const int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
        std::vector<int> num(arr, arr+sizeof(arr)/sizeof(arr[0]));
        /*for(int i = 0; i < 10; i++) {
            num.push_back(i);
        }*/
        std::pair<int, std::pair<int, int>> res = utils::maxContSumSub(num);
        std::cout << ">> " << res.first << std::endl;
        for(int i = res.second.first; i <= res.second.second; i++) {
            std::cout << num.at(i) << " ";
        }
        std::cout << std::endl;
    }
    else if(op == 6) {
        std::cout << utils::fibonacci(25) << std::endl;
        std::cout << utils::fibonacciMem(25) << std::endl;
    }
    else if(op == 7) {
        int num = 0;
        std::cin >> num;
        std::cout << utils::reduceN(num) << std::endl;
    }
    return 0;
}
}
