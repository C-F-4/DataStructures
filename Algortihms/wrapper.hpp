#ifndef WRAPPER_HPP_INCLUDED
#define WRAPPER_HPP_INCLUDED

/**
 * Wrapper Functions allow more enhanced options to the algorithms (Functions Headers)
 */
namespace wrapper{
    enum OPERATINGSYSTEM {
        windows,
        mac,
        linux
        /*add more OS here*/
    };

    void clearScreen();
    int inputOption();
    int searchWrapper();
    int sortWrapper();
    int greedyWrapper();
}

#endif // WRAPPER_HPP_INCLUDED
