/*
 * Name        : driver.cpp
 * Author      : Konstantin Rebrov
 * Language    : C++
 * Description : This file defines the main function for the program.
 *               It creates a new instance of the StringUI class and then calls
 *               the Menu() function (defined in string_ui.cpp) that does all
 *               the work.
 */

#include "string_ui.h"

int main() {
    StringUI display;
    display.Menu();
    
    return 0;
}