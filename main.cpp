#include "library.h"

using namespace std;

ShippingFormList List;

int main() { 
    FormManagementSystemInit Program(List);
    Program.init();

    int option;
    bool exitProgram = false;
    /* DELIVERY FORMS MANAGERMENT PROGRAM */
    while (!exitProgram) {
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
                printAllFormToFile(List);
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
                exitProgram = true;
                break;

            default:
                cout << "This feature is currently not available\n";   
                break;
        }
    }
    
}
