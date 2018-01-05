/*
 * Name        : Assignment 1 header file
 * Author      : Konstantin Rebrov
 * Description : Function prototypes for assignment_1.cpp
 * Sources     : Luke Sathrum's lecture slides and sample code.
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

#include <string>
#include <cctype>
#include <cstdlib>
using std::string;

/*
 * This function takes a string as input and
 * checks if all characters in the string are alphabetic
 * @param const string &input_string - the string that is input
 * @return bool - true if the string is alphabetic, else false
 */
bool CheckAlphabetic(const string &input_string);

/*
 * This function takes a string as input and
 * performs a Ceasar Cipher shift on it by the number of characters
 * that are specified by the user
 * @param string &input_string - the string that is to be encrypted
 * @param int shift_size - the number of characters to shift by
 * @return bool - true if the string was encrypted, else false
 */
bool EncryptString(string &input_string, int shift_size);

/*
 * This function takes a string as input and
 * decrypts a Ceasar Cipher shift on it by the number of characters
 * that the string was shifted by
 * @param string &input_string - the string that is to be decrypted
 * @param int shift_size - the number of chars that the string was shifted by
 * @return bool - true if the string was decrypted, else false
 */
bool DecryptString(string &input_string, int shift_size);

/*
 * This function computes the average value of an array of doubles.
 * @param double arr_values[] - the array of doubles that is passed in
 * @param unsigned int arr_size - the size of the array
 * @return double - the average (mean) value of the array
 */
double ComputeAverage(double arr_values[], unsigned int arr_size);

/*
 * This function finds the smallest value of an array of doubles.
 * @param double arr_values[] - the array of doubles that is passed in
 * @param unsigned int arr_size - the size of the array
 * @return double - the smallest value in the array
 */
double FindMinValue(double arr_values[], unsigned int arr_size);

/*
 * This function finds the largest value of an array of doubles.
 * @param double arr_values[] - the array of doubles that is passed in
 * @param unsigned int arr_size - the size of the array
 * @return double - the largest value in the array
 */
double FindMaxValue(double arr_values[], unsigned int arr_size);

#endif /* ASSIGNMENT_1_H */
