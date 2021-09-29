#ifndef CLEARSCREEN_H
#define CLEARSCREEN_H
#include <cstdlib>

void ClearScreen()
{

#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}
#endif