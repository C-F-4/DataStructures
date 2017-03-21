#include <iostream>
#include "wrapper.hpp"

/**
 * List of Various Available Algorithmic Approaches
 * Searching Algorithms
 *** Linear Search
 *** Binary Search

 * Sorting Algorithms
 *** Bubble Sort
 *** Insertion Sort
 *** Merge Sort
 *** Quick Sort

 * Greedy Approach
 *** Knapsack Problem
 *** Machine Scheduling
 */

int main(void)
{
    int op;
    // Create options here to use each algorithm
    std::cout << "Available Options:" << std::endl
         << "0 - Available Searching Algorithms" << std::endl
         << "1 - Sorting Algorithms" << std::endl
         << "2 - Greedy Approaches" << std::endl;
    op = wrapper::inputOption();
    int retVal;
    if(op == 0) {
        wrapper::clearScreen();
        retVal = wrapper::searchWrapper();
    }
    else if(op == 1) {
        wrapper::clearScreen();
        retVal = wrapper::sortWrapper();
    }
    else if(op == 2) {
        wrapper::clearScreen();
        retVal = wrapper::greedyWrapper();
    }
    return 0;
}
