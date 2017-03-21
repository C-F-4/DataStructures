/**
 * Wrapper Functions allow more enhanced options to the algorithms (Functions Definitions)
 */
#include <iostream>
#include <cstdlib>
#include "wrapper.hpp"

namespace wrapper {
    OPERATINGSYSTEM operatingSystem;

    int getOs(){
        #ifdef _WIN32
            operatingSystem = windows;
        #elif __APPLE__
            operatingSystem = mac;
        #elif __linux__
            operatingSystem = linux;
        #endif
        return wrapper::operatingSystem;
    }

    void clearScreen(){
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
    }

    // Update it to support constraints + Template + Template Specialization
    int inputOption() {
        int tmp;
        std::cout << ">> ";
        std::cin >> tmp;
        return tmp;
    }

    int searchWrapper() {
        std::cout << "0 - Linear Search" << std::endl
            << "1 - Binary Search" << std::endl;
        int op;
        op = wrapper::inputOption();
        if(op == 0) {
            // Do Linear Search

        }
        else if(op == 1) {
            // Do Binary Search
        }
        return 0;
    }

    int sortWrapper() {
        std::cout << "0 - Bubble Sort" << std::endl
            << "1 - Insertion Sort" << std::endl
            << "2 - Merge Sort" << std::endl
            << "3 - Quick Sort" << std::endl;
        int op;
        op = wrapper::inputOption();
        if(op == 0) {
            // Do Bubble Sort
        }
        else if(op == 1) {
            // Do Insertion Sort
        }
        else if(op == 2) {
            // Do Merge Sort
        }
        else if(op == 3) {
            // Do Quick Sort
        }
        return 0;
    }

    int greedyWrapper() {
        std::cout << "0 - Knapsack Problem" << std::endl
             << "1 - Machine Scheduling" << std::endl;
        int op;
        op = wrapper::inputOption();
        if(op == 0) {
            // Do Knapsack Problem
        }
        else if(op == 1) {
            // Do Machine Scheduling
        }
        return 0;
    }
}
