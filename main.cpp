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
    
    ifstream filein;
    filein.open("infor.text", ios_base::in);
    filein.peek();
    List.inputList(filein);
    printFormList(List);
    filein.close();

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

            case 4: // Search forms via address
                searchFormList(List);
                break;
                
            case 5: // List completed delivery by time
                listCompletedFileByTime(List);
                break;
            
            case 6: // Update price
                updatePrice();
                break;

            case 7:
                printRevenue(List);
                break;

            case 8: // Print specific form
                printSpecificForm(List);
                break;

            case 9: // Print all forms
                printFormList(List);
                break;

            case 10: // Exit program
                List.FormList.clear();
                exit(1);
                break;

            default:
                cout << "This feature is currently not available\n";   
                break;
        }
    }
}
