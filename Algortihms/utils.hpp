#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>

typedef unsigned int uint;

/**
 * Utils Functions features various Algorithm Approaches (Function Headers)
 */

namespace utils {
/**
 * Linear Search
 */
template <typename T>
std::pair<bool, int> linearSearch(std::vector<T> input, T key) {
    for(uint i = 0; i < input.size(); i++) {
        if(input.at(i) == key) {
            return std::pair<bool, int>(true, i);
        }
    }
    return std::pair<bool, int>(false, INT_MIN);
}

/**
 * Binary Search
 */
template <typename T>
std::pair<bool, int> binarySearch(std::vector<T> input, T key, int left, int right) {
    int mid = (left + right) / 2;
    if(input.at(mid) == key) {
        return std::pair<bool, int>(true, mid);
    }
    else if(left > right) {
        return std::pair<bool, int>(false, INT_MIN);
    }
    else if(input.at(mid) < key) {
        return binarySearch(input, key, mid+1, right);
    }
    else {
        return binarySearch(input, key, left, mid-1);
    }
}

template <typename T>
std::pair<bool, int> binarySearchWrap(std::vector<T> input, T key) {
    return binarySearch(input, key, 0, input.size()-1);
}

/**
 * Bubble Sort
 */
template <typename T>
std::vector<T> bubbleSort(std::vector<T> v) {
    for(uint i = 0; i < v.size()-1; i++) {
        for(uint j = 0; j < v.size()-i-1; j++) {
            if(v.at(j) > v.at(j+1)) {
                // swap
                int tmp = v.at(j);
                v.at(j) = v.at(j+1);
                v.at(j+1) = tmp;
            }
        }
    }
    return v;
}

/**
 * Insertion Sort
 */
template <typename T>
std::vector<T> insertionSort(std::vector<T> v) {
    return v;
}

/**
 * Merge Sort
 * Method Type: Divide and Conquer
 * Requires to be updated
 */
template <typename T>
void mergeX(std::vector<T>* v, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    std::vector<T> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = (*v).at(l + i);
    for (j = 0; j < n2; j++)
        R[j] = (*v).at(m + 1+ j);

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            (*v).at(k) = L[i];
            i++;
        }
        else {
            (*v).at(k) = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        (*v).at(k) = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        (*v).at(k) = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(std::vector<T>* v, int l, int r) {
    if(l < r) {
        int m = l+(r-l)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        mergeX(v, l, m, r);
    }
}

template <typename T>
std::vector<T> mergeSort(std::vector<T> v) {
    mergeSort(&v, 0, v.size()-1);
    return v;
}

/**
 * Quick Sort
 * Method Type: Divide and Conquer
 * Requires to be Updated
 */
template <typename T>
int quickPartition(std::vector<T>* v, int low, int high) {
    T pivot = (*v).at(high);
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if((*v).at(j) <= pivot) {
            i++;
            // swap
            int tmp = (*v).at(i);
            (*v).at(i) = (*v).at(j);
            (*v).at(j) = tmp;
        }
    }
    int tmp = (*v).at(i+1);
    (*v).at(i+1) = (*v).at(high);
    (*v).at(high) = tmp;
    return i+1;
}

template <typename T>
void quickSort(std::vector<T>* v, int low, int high) {
    if(low < high) {
        int pi = quickPartition(v, low, high);
        quickSort(v, low, pi-1);
        quickSort(v, pi+1, high);
    }
}

template <typename T>
std::vector<T> quickSort(std::vector<T> v) {
    quickSort(&v, 0, v.size()-1);
    return v;
}

/**
 * Fractional Knapsack Problem
 * Method Type: Greedy Approach
 */
template <typename T>
void fracKnapsack(std::vector<T> items, int itemSize, int sackSize) {
    sort(items.begin(), items.end(), [](T const& a, T const& b) {
             return a.benefit > b.benefit;
         });
    int resVal = 0;
    int resWt = 0;
    for(int i = 0; i < items.size(); i++) {
        if (resWt + items[i].weight <= sackSize)
        {
            resWt += items[i].weight;
            resVal += items[i].value;
        }
        // If we can't add (1) current Item add fractional part of it
        else
        {
            int remain = sackSize - resWt;
            resVal += items[i].value * ((double) remain / items[i].weight);
            break;
        }
    }
    std::cout << resVal << std::endl;
}

/**
 * 0-1 Knapsack Problem
 * Method Type: Dynamic Programming
 */
template <typename T>
void zeroOneKnapsack(std::vector<T> items, int itemSize, int sackSize) {
    sort(items.begin(), items.end(), [](T const& a, T const& b) {
             return a.benefit > b.benefit;
         });
    int resVal = 0;
    int resWt = 0;
    for(int i = 0; i < items.size(); i++) {
        if (resWt + items[i].weight <= sackSize)
        {
            resWt += items[i].weight;
            resVal += items[i].value;
        }
    }
    std::cout << resVal << std::endl;
}

/**
 * Machine Scheduling
 * Needs to be updated
 */
template <typename T>
void machineScheduling(std::vector<T> v) {
    std::sort(v.begin(), v.end(), [] (T const& a, T const& b){return (a.profit > b.profit);});
    int n = v.size();
    std::vector<int> result(n);
    std::vector<bool> slot(n);

    for (int i=0; i<n; i++)
        slot[i] = false;

    for (int i=0; i<n; i++) {
       for (int j=std::min(n, v[i].deadline)-1; j>=0; j--) {
          if (slot[j]==false) {
             result[j] = i;
             slot[j] = true;
             break;
          }
       }
    }

    for (int i=0; i<n; i++)
       if (slot[i])
         std::cout << v[result[i]].id << " ";
}

/**
 * Sum Of Subsets
 * Method Type: BackTracking
 */
void sumOfSubsets(std::vector<int> v, std::vector<bool> m, int curSum, int cur, int sum) {
    curSum += v.at(cur);
    m.at(cur) = true;
    if(curSum == sum) {
        m.at(cur) == true;
        for(uint i = 0; i < v.size(); i++) {
            if(m.at(i)) {
                std::cout << v.at(i) << ' ';
            }
        }
        std::cout << std::endl;
        return;
    }
    else if(curSum > sum) {
        return;
    }
    else {
        for(uint i = cur+1; i < v.size(); i++) {
            m.at(i) = true;
            sumOfSubsets(v, m, curSum, i, sum);
            m.at(i) = false;
        }
    }
}

void sumOfSubWrap(std::vector<int> v, int sum) {
    uint i = 0;
    for(i = 0; i < v.size(); i++) {
        if(v.at(i) > sum) {
            break;
        }
    }
    v.resize(i);

    std::vector<bool> marked(v.size(), false);
    sumOfSubsets(v, marked, 0, 0, sum);
}

/**
 * N-Queens
 * Method Type: BackTracking
 */

/**
* markUnmarkable() takes the newly occupied position co-ordinates as arguments - coordX and coordY
*   and marks unoccupiable positions into the canPlace vector and return the modified Vector/ the
*   chess board
* canPlace is a 2D vector represents the chess board, indicating the currently occupied positions
*   by the Queens and the positions, where new queens can or can't be placed
* sizeB is an argument telling you the size of the 2D Square vector or the chess board
*/
std::vector<std::vector<bool>> markUnmarkable(std::vector<std::vector<bool>> canPlace, size_t sizeB, int coordX, int coordY) {
    // Move in 8 Dimensions
    // Move top
    //canPlace[coordX][coordY] = false;
    for(int i = 0; i < coordX; i++) {
        canPlace[i][coordY] = false;
    }
    // Move right
    for(int j = coordY; j < sizeB; j++) {
        canPlace[coordX][j] = false;
    }
    // Move bottom
    for(int i = coordX; i < sizeB; i++) {
        canPlace[i][coordY] = false;
    }
    // Move left
    for(int j = 0; j < coordY; j++) {
        canPlace[coordX][j] = false;
    }
    // Move diag-top-left
    for(int i = coordX, j = coordY; i >= 0 && j >= 0; i--, j--) {
        canPlace[i][j] = false;
    }
    // Move diag-top-right
    for(int i = coordX, j = coordY; i >= 0 && j < sizeB; i--, j++) {
        canPlace[i][j] = false;
    }
    // Move diag-bottom-right
    for(int i = coordX, j = coordY; i < sizeB && j < sizeB; i++, j++) {
        canPlace[i][j] = false;
    }
    // Move diag-bottom-left
    for(int i = coordX, j = coordY; i < sizeB && j >= 0; i++, j--) {
        canPlace[i][j] = false;
    }
    return canPlace;
}

bool nQueens(std::vector<std::vector<bool>> queens, std::vector<std::vector<bool>> canPlace,
             int queensLeft, size_t sizeB) {
    if(queensLeft == 0) {
        // Print the output
        for(uint i = 0; i < sizeB; i++) {
            for(uint j = 0; j < sizeB; j++) {
                std::cout << queens[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return true;
    }
    else {
        for(int i = 0; i < sizeB; i++) {
            for(int j = 0; j < sizeB; j++) {
                // Mark cur as queen
                if(canPlace[i][j]) {
                    queens[i][j] = true;
                    //canPlace[i][j] = false;
                    bool foundFlag = nQueens(queens, markUnmarkable(canPlace, sizeB, i, j), queensLeft - 1, sizeB);
                    if(foundFlag) {
                        return true;
                    }
                    queens[i][j] = false;
                    //canPlace[i][j] = true;
                }
            }
        }
    }
}

void nQueens(size_t sizeB) {
    std::vector<std::vector<bool>> queens(sizeB, std::vector<bool>(sizeB, false));
    std::vector<std::vector<bool>> canPlace(sizeB, std::vector<bool>(sizeB, true));
    // Total Number of Queens to place
    int total = sizeB;
    nQueens(queens, canPlace, total, sizeB);
}

/**
 * Fibonacci
 * Method Type: Recursion
 */
int fibonacci(int cur) {
    if(cur <= 1) {
        return cur;
    }
    return fibonacci(cur-1) + fibonacci(cur-2);
}

/**
 * Fibonacci
 * Method Type: Dynamic Programming
 */
std::map<int, int> calcFib;
int fibonacciMem(int cur) {
    if(cur <= 1) {
        return cur;
    }
    else if(calcFib.find(cur) != calcFib.end()) {
        return calcFib[cur];
    }
    int val = fibonacciMem(cur-1) + fibonacciMem(cur-2);
    calcFib.insert(std::make_pair(cur, val));
    return val;
}

/**
 * Maximum Continuous Sub Sequence
 * Method Type: Iteration
 */
std::pair<int, std::pair<int, int>> maxContSumSub(std::vector<int> v) {
    int maxSum = 0;
    int start = 0;
    int finish = 0;
    int tmpSum = 0;
    for(int i = 0; i < v.size(); i++) {
        tmpSum += v.at(i);
        if(tmpSum < 0) {
            start = i;
            finish = i;
            tmpSum = 0;
        }
        else if(tmpSum > maxSum) {
            finish = i;
            maxSum = tmpSum;
        }
    }
    // Returns the max-sum, and start, finish values for that range
    std::pair<int, int> tmp(start, finish);
    std::pair<int, std::pair<int, int>> res(maxSum, tmp);
    return res;
}

/**
 * Reduce N to 1 in minimum steps
 * Method Used: Recursion
 */
int reduceN(int n, int steps) {
    if(n == 1) {
        return steps;
    }
    else if(n == 2 || n == 3) {
        return ++steps;
    }
    else if(n % 3 == 0) {
        n /= 3;
        steps ++;
    }
    else if((n-1) % 3 == 0 || (n-2) % 3 == 0 || ((n-1) % 2 == 0 && n % 2 != 0)) {
        n -= 1;
        steps ++;
    }
    else if(n % 2 == 0) {
        n /= 2;
        steps ++;
    }
    return reduceN(n, steps);
}

/**
 * ReduceN() is a wrapper function which takes in a number argument and returns the minimum number of steps to reduce that number
 * to 1 by either perfect dividing by 2 or 3 or subtracting by one
 */
int reduceN(int n) {
    if(n < 1) {
        return -1;
    }
    else {
        return reduceN(n, 0);
    }
}
}

#endif // UTILS_HPP_INCLUDED
