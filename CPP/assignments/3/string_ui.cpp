#include "string_ui.h"

StringUI::StringUI() {
    string_list = new StringList;
  }

StringUI::~StringUI() {
    delete string_list;
  }

void StringUI::Menu() {
    Loading();
    int input;
    bool loop = true;
    while (loop) {
      ClearScreen();
      DrawMenu();
      cout << " $ ";
      input = reader.readInt(1, 9);
      switch (input) {
        case 1:
          CreateString();
          break;
        case 2:
          EditString();
          break;
        case 3:
          DeleteString();
          break;
        case 4:
          ViewStrings();
          break;
        case 5:
          ViewSpecificString();
          break;
        case 6:
          DeleteAllStrings();
          break;
        case 7:
          SaveList();
          break;
        case 8:
          RetreiveList();
          break;
        case 9:
          loop = false;
          break;
      }
    }
    return;
  }

void StringUI::CreateString() {
  string the_string;
  cout << string(26, '=') << endl;
  cout << "Enter a new string: ";
  the_string = reader.readString(false);
  string_list->AddItem(new string(the_string));
  cout << endl << "The string \"" << the_string;
  cout << "\" was created successfully." << endl;
  Sleeps(2000);
  ClearScreen();
  return;
}

void StringUI::EditString() {
  string the_string;
  string* string_ptr;
  int string_index;
  cout << string(26, '=') << endl;
  if (string_list->GetSize() == 0) {
    cout << "The list is empty." << endl;
    Sleeps(2000);
    return;
  }
  cout << "Enter an index of the string to edit: ";
  string_index = reader.readInt(0, (string_list->GetSize() - 1));
  cout << "The string at " << string_index << " is: |";
  string_ptr = string_list->GetItem(string_index);
  cout << *string_ptr << '|' << endl;
  Sleeps(500);
  cout << endl;
  cout << "Enter a new value for the string: ";
  the_string = reader.readString(false);
  *string_ptr = the_string;
  cout << endl;
  cout << "The string at " << string_index << " was successfully";
  cout << " changed to: |" << *string_ptr << '|' << endl;
  Sleeps(2000);
  return;
}

void StringUI::DeleteString() {
  int string_index;
  cout << string(26, '=') << endl;
  if (string_list->GetSize() == 0) {
    cout << "The list is empty." << endl;
    Sleeps(2000);
    return;
  }
  cout << "Enter an index of the string to delete: ";
  string_index = reader.readInt(0, (string_list->GetSize() - 1));
  string_list->DeleteItem(string_index);
  cout << endl << "The string at " << string_index;
  cout << " was successfully deleted." << endl;
  Sleeps(2000);
  return;
}

void StringUI::ViewStrings() {
  cout << string(26, '=') << endl;
  if (string_list->GetSize() == 0) {
    cout << "The list is empty." << endl;
    Sleeps(2000);
    return;
  }
  cout << *string_list;
  Sleeps(4000);
  return;
}

void StringUI::ViewSpecificString() {
  string* string_ptr;
  int string_index;
  cout << string(26, '=') << endl;
  if (string_list->GetSize() == 0) {
    cout << "The list is empty." << endl;
    Sleeps(2000);
    return;
  }
  cout << "Enter an index of the string to print: ";
  string_index = reader.readInt(0, (string_list->GetSize() - 1));
  cout << "The string at " << string_index << " is: |";
  string_ptr = string_list->GetItem(string_index);
  cout << *string_ptr << '|' << endl;
  Sleeps(2000);
  return;
}

void StringUI::DeleteAllStrings() {
  cout << string(26, '=') << endl;
  if (string_list->GetSize() == 0) {
    cout << "The list is empty." << endl;
    Sleeps(2000);
    return;
  }
  while (string_list->GetSize() != 0) {
    string_list->DeleteItem(0);
  }
  cout << "All strings were deleted successfully." << endl;
  Sleeps(2000);
  return;
}

void StringUI::SaveList() {
  string file_name;
  fstream file_reader;
  cout << string(26, '=') << endl;
  if (string_list->GetSize() == 0) {
    cout << "The list is empty." << endl;
    Sleeps(2000);
    return;
  }
  cout << "Enter the name of the file." << endl;
  cout << " $ ";
  file_name = reader.readString(false);
  file_reader.open(file_name.c_str(), std::ios::out);
  if (!file_reader) {
    cout << endl << "This file could not be written." << endl;
    Sleeps(2000);
    return;
  }
  file_reader << string_list->ToFile();
  file_reader.close();
  cout << endl << "The string list was successfully saved";
  cout << " to a file." << endl;
  Sleeps(2000);
  return;
}

void StringUI::RetreiveList() {
  string the_string;
  string file_name;
  fstream file_reader;
  cout << string(26, '=') << endl;
  if (string_list->GetSize() != 0) {
    cout << "The string list is not empty." << endl;
    cout << "Are you sure you want to overwrite it?" << endl;
    the_string = reader.readString(false, 3);
    if (toupper(the_string.at(0)) != 'Y') {
      return;
    } else {
      while (string_list->GetSize() != 0) {
        string_list->DeleteItem(0);
      }
    }
  }
  cout << "Enter the name of the file." << endl;
  cout << " $ ";
  file_name = reader.readString(false);
  file_reader.open(file_name.c_str(), std::ios::in);
  if (!file_reader) {
    cout << endl << "The file could not be read." << endl;
    Sleeps(2000);
    return;
  }
  while (!file_reader.eof()) {
    getline(file_reader, the_string, '`');
    string_list->AddItem(new string(the_string));
  }
  file_reader.close();
  cout << endl << "The string list was successfully read";
  cout << " from the file." << endl;
  Sleeps(2000);
  return;
}

void StringUI::ClearScreen() {
  #ifdef WIN_32
    system("cls");
  #else
    system("clear");
  #endif
  }

void StringUI::Sleeps(int miliseconds) {
  #ifdef WIN_32
    Sleep(miliseconds);
  #else
    usleep(miliseconds * 1000);  // takes microseconds
    // sleep(miliseconds / 1000); // takes seconds
  #endif
  }

void StringUI::Loading() {
    unsigned int counter = 0, full = 20;
    ClearScreen();
    srand(time(0));
    do {
      cout << endl;
      cout << setw(21) << setfill(' ') << "Loading ..." << "\n" << endl;
      cout << setw(6) << setfill(' ') << "|";
      cout << setw(counter) << setfill('#') << "";
      cout << setw(full - counter) << setfill('_') << "";
      cout << "|" << endl;
      Sleeps(rand() % 1500 + 1);  // sleeps for 1 – 1500 miliseconds
      ClearScreen();
      counter++;
    } while (counter <= full);
  }

void StringUI::DrawMenu() {
    cout << '+' << setw(25) << setfill('-') << "+" << endl;
    cout << '|' << setw(16) << setfill(' ') << "Main Menu";
    cout << setw(9) << setfill(' ') << "|" << endl;
    cout << '+' << setw(25) << setfill('-') << "+" << endl;
    cout << "|Please enter one of the |" << endl;
    cout << '|' << setw(21) << setfill(' ') << "following options:";
    cout << setw(4) << setfill(' ') << "|" << endl;
    cout << '+' << setw(25) << setfill('-') << "+" << endl;
    cout << "| 1) " << "Create New String";
    cout << setw(4) << setfill(' ') << "|" << endl;
    cout << "| 2) " << "Edit a String";
    cout << setw(8) << setfill(' ') << "|" << endl;
    cout << "| 3) " << "Delete a String";
    cout << setw(6) << setfill(' ') << "|" << endl;
    cout << "| 4) " << "View all Strings";
    cout << setw(5) << setfill(' ') << "|" << endl;
    cout << "| 5) View Specific String|" << endl;
    cout << "| 6) " << "Delete all Strings";
    cout << setw(3) << setfill(' ') << "|" << endl;
    cout << "| 7) " << "Save the list";
    cout << setw(8) << setfill(' ') << "|" << endl;
    cout << "|" << setw(13) << setfill(' ') << "to a file";
    cout << setw(12) << setfill(' ') << "|" << endl;
    cout << "| 8) " << "Retreive a previous |" << endl;
    cout << "|  saved list from a file|" << endl;
    cout << "| 9) " << "Quit Program";
    cout << setw(9) << setfill(' ') << "|" << endl;
    cout << '+' << string(24, '-') << '+' << endl;
  }
