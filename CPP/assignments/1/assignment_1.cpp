/*
 * Name        : Assignment #1
 * Author      : Konstantin Rebrov
 * Description : The purpose of this assignment is to 
                 practice basic programming techniques using the C++ 
                 programming language.
 * Sources     : Luke Sathrum's lecture slides and sample code.
 */

#include "assignment_1.h"

bool CheckAlphabetic(const string &input_string) {
  if (input_string.empty()) {
    return false;
  } else {
    for (unsigned int i = 0; i < input_string.length(); i++)
      if (!isalpha(input_string.at(i))) {
        return false;
      }
  }
  return true;
}

bool EncryptString(string &input_string, int shift_size) {
  if (!CheckAlphabetic(input_string))
    return false;
  // determines what one shift is
  int shift_one = (shift_size > 0) ? 1 : -1;
  // converts shift_size to positive so that it could be used in a loop
  shift_size = abs(shift_size);
  for (unsigned int i = 0; i < input_string.length(); i++) {
    for (int j = 0; j < shift_size; j++) {
      if (input_string.at(i) == 'A' && shift_one == -1) {
        input_string.at(i) = 'Z';
      } else if (input_string.at(i) == 'a' && shift_one == -1) {
        input_string.at(i) = 'z';
      } else if (input_string.at(i) == 'Z' && shift_one == 1) {
        input_string.at(i) = 'A';
      } else if (input_string.at(i) == 'z' && shift_one == 1) {
        input_string.at(i) = 'a';
      } else {
        input_string.at(i) = input_string.at(i) + shift_one;
      }
    }
  }
  return true;
}

bool DecryptString(string &input_string, int shift_size) {
  return EncryptString(input_string, -shift_size);
}

double ComputeAverage(double arr_values[], unsigned int arr_size) {
  double total = 0.0;
  for (unsigned int i = 0; i < arr_size; i++) {
    total += arr_values[i];
  }
  total /= arr_size;
  return total;
}

double FindMinValue(double arr_values[], unsigned int arr_size) {
  double min_value = arr_values[0];
  for (unsigned int i = 1; i < arr_size; i++) {
    min_value = (arr_values[i] < min_value) ? arr_values[i] : min_value;
  }
  return min_value;
}

double FindMaxValue(double arr_values[], unsigned int arr_size) {
  double max_value = arr_values[0];
  for (unsigned int i = 1; i < arr_size; i++) {
    max_value = (arr_values[i] > max_value) ? arr_values[i] : max_value;
  }
  return max_value;
}
