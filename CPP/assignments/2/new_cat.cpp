/*
 * Name        : new_cat.cpp
 * Author      : Konstantin Rebrov
 * Description : This program duplicates features of the UNIX cat utility.
 * Sources     : Luke Sathrum's code examples
 */

#include <iostream>
#include <fstream>
using std::ifstream;
using std::cout;
using std::cin;
using std::string;
using std::endl;

/*
 * This is the program's main function/entry point.
 * It takes command-line arguments for files
 * and prints their contents to stdout.
 * If no files are specified, it outputs
 * all subsequent user input.
 * @param int argc - the number of command-line arguments
 *                 - that are specified by the user including
 *                 - the compiled executable file.
 * @param char *argv[] - an array of C-strings containing
 *                     - filenames to be read and output.
 * @return int - the main function returns a value indicating
 *             - the program's exit status.
 *             - 0 means that the program finished successfully.
 *             - 1 means that a filename was not valid.
 */
int main(int argc, char *argv[]) {
  // If no other command-line arguments are specified
  if (argc == 1) {
    string line;
    // use cin to read in user input
    while (!cin.eof()) {
      getline(cin, line);
      // to prevent the EOF character from being output
      if (cin.good())
        cout << line << endl;
    }
  // If other command-line arguments are specified
  // they are the names of the files
  } else if (argc > 1) {
    ifstream reader;
    // loop through and read each command-line argument
    // to determine if it is valid
    for (int i = 1; i < argc; i++) {
      reader.open(argv[i]);
      // if opening filename was not successful
      if (!reader) {
        cout << "The filename " << argv[i] << " is not valid." << endl;
        // end the program and return an error status to the OS
        return 1;
      }
      reader.close();
    }
    // loop through and read each command-line argument
    // to output the file contents
    for (int i = 1; i < argc; i++) {
      reader.open(argv[i]);
      char letter;
      // loop through the file and output each character
      while (!reader.eof()) {
        letter = reader.get();
        // to prevent the EOF character from being output
        if (reader.good())
          cout << letter;
      }
      reader.close();
    }
  }

  // This ends our program
  return 0;
}
