#ifndef WRAPPER_HPP_INCLUDED
#define WRAPPER_HPP_INCLUDED

#include <vector>

/**
 * Wrapper Functions allow more enhanced options to the algorithms (Functions Headers)
 */
namespace wrapper{
    void clearScreen();

    template <typename T>
    T inputOption(std::string = "");

    std::pair<int, std::string> ioOption();

    template <typename T>
    void writeFile(std::string, std::vector<T>);

    template <typename T>
    void printVector(std::vector<T>);

    int searchWrapper();
    int sortWrapper();
    int greedyWrapper();
}

#endif // WRAPPER_HPP_INCLUDED
