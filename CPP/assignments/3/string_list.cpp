#include "string_list.h"

StringList::StringList() : max_capacity_(25), curr_size_(0) {
    string_array_ = new string*[max_capacity_];
    for (unsigned int i = 0; i < max_capacity_; i++) {
      string_array_[i] = NULL;
    }
  }

StringList::~StringList() {
    for (unsigned int i = 0; i < curr_size_; i++) {
      delete string_array_[i];
    }
    delete[] string_array_;
    string_array_ = NULL;
  }

void StringList::AddItem(string* the_string) {
    if (curr_size_ == max_capacity_)
      IncreaseCapacity();
    string_array_[curr_size_] = the_string;
    curr_size_++;
  }

void StringList::DeleteItem(unsigned int index) {
    if (index >= curr_size_)
      return;
    delete string_array_[index];
    CompactArray(index);
    curr_size_--;
  }

string* StringList::GetItem(unsigned int index) {
    if (index >= curr_size_)
      return NULL;
    return string_array_[index];
  }

int StringList::GetSize() {
    return curr_size_;
  }

int StringList::GetCapacity() {
    return max_capacity_;
  }

void StringList::Sort() {
    for (unsigned int i = 0; i <= (curr_size_ - 1); i++) {
      unsigned int j = i;
      while ((j > 0) && (ToUpper(*string_array_[j]) <
                         ToUpper(*string_array_[j - 1]))) {
        string* temp_ptr = string_array_[j];
        string_array_[j] = string_array_[j - 1];
        string_array_[j - 1] = temp_ptr;
        j = j - 1;
      }
    }
  }

string StringList::ToFile() {
    stringstream all_strings;
    unsigned int i;
    if (curr_size_ == 0)
      return "";
    for (i = 0; i < (curr_size_ - 1); i++) {
      all_strings << (*string_array_[i]) << '`';
    }
    all_strings << (*string_array_[i]);
    return all_strings.str();
  }

ostream& operator <<(ostream &out, const StringList &string_list) {
    for (unsigned int i = 0; i < string_list.curr_size_; i++) {
      out << (i + 1) << ") " << (*string_list.string_array_[i])  << '\n';
    }
    return out;
  }

void StringList::IncreaseCapacity() {
    max_capacity_ += 10;
    string** temp = new string*[max_capacity_];
    unsigned int i;
    for (i = 0; i < curr_size_; i++) {
      temp[i] = string_array_[i];
    }
    while (i < max_capacity_) {
      temp[i] = NULL;
      i++;
    }
    delete[] string_array_;
    string_array_ = temp;
    temp = NULL;
  }

void StringList::CompactArray(unsigned int index) {
    while (index < curr_size_ - 1) {
      string_array_[index] = string_array_[index + 1];
      index++;
    }
    string_array_[index] = NULL;
  }

string StringList::ToUpper(string the_string) {
    for (unsigned int i = 0; i < the_string.length(); i++) {
      the_string[i] = toupper(the_string[i]);
    }
    return the_string;
  }
