#include "data_structure.h"
#include "function.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_NUMBER_OF_FORM 100

int main() { 
    ShippingFormList List;
    
    int option;
    /* DELIVERY FORMS MANAGERMENT PROGRAM */
    while (true) {
        cout << endl;
        printMenu();
        cin >> option;

        // User input wrong data
        if (!cin) {
            // user didn't input a number
            cin.clear();                      // reset failbit
            cin.ignore(MAX_STREAMSIZE, '\n'); // skip bad input
        }

        switch (option) {
            case 1: // Add a form
                inputFormList(List);
                break;

            case 2: // Edit a form
                editFormList(List);
                break;

            case 3: // Remove a form
                removeFormList(List);
                break;

            case 8: // Print all forms
                printFormList(List);
                break;

            case 9:
                List.FormList.clear();
                exit(1);
                break;

            default:
                cout << "This feature is currently not available\n";   
                break;
        }
    }
/*
    int option;
    printMenu();
    cout << "\n\t-> Your option: "; cin >> option;
    
    switch (option) {
    case 1:
        int editor_option;
        cout << "\n\n\t---------------------------------\n";
        printEditorMenu();
        cout << "\n\t-> Your option: ";
        cin >> editor_option;
        cout << endl;

        switch (editor_option) {
            case 1:
                inputFormList(List);
                break;
            case 3:
                int position;
                cout << "The current database has " << List.FormList.size() << " form(s)\n";
                cout << "Remove form in position [0 - " << List.FormList.size() - 1 <<"]: ";
                cin >> position;
                List.removeForm(position);
                break;
        }

        break;
    
    default:
        break;
    }
*/
    printFormList(List);
}
