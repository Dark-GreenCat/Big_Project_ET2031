#include "ui_console.h"
#include "io_console.h"
#include "file.h"

void printMenu() {
	std::cout << "\t\tDELIVERY FORM MANAGEMENT SYSTEM\n";
	std::cout << "\tPlease choose an option below:\n";
	std::cout << "\t1. Add a form\n";
	std::cout << "\t2. Edit a form\n";
	std::cout << "\t3. Remove a form\n";
	std::cout << "\t4. Search forms via address\n";
	std::cout << "\t5. List completed delivery by time\n";
	std::cout << "\t6. Update price\n";
	std::cout << "\t7. Revenue\n";
	std::cout << "\t8. Print specific form\n";
	std::cout << "\t9. Print all forms\n";
	std::cout << "\t10. Exit program\n";
	std::cout << "\n\t-> Your option: ";
}

void inputFormList(ShippingFormList& List) {
	char choice = 'N';
	std::cout << "The current database has " << List.FormList.size() << " forms\n";
	std::cout << "Do you want to add more forms? (Y/N) :";
	std::cin >> choice;

	if (choice == 'Y' || choice == 'y')
		do {
			ShippingForm* Form;
			if (List.FormList.size() > 0) {
				std::ofstream fileout;
				fileout.open(INFOR_FILE, std::ios::app);
				fileout << "\n";
				fileout.close();
			}
			inputForm(Form);

			std::ofstream fileout;
			fileout.open(INFOR_FILE, std::ios::app);
			saveInputInfor(Form, fileout);
			fileout.close();

			List.FormList.push_back(Form);

			std::cout << "\nThe current database has " << List.FormList.size() << " forms\n";
			std::cout << "Do you want to add more forms? (Y/N) :";
			std::cin >> choice;
		} while (choice == 'Y' || choice == 'y');
}

void printFormList(ShippingFormList& List) {
	std::cout << "\nNumber of form: " << List.FormList.size() << std::endl;
	for (int i = 0; i < List.FormList.size(); i++) {
		std::cout << "\nForm #" << (i + 1) << std::endl;
		printInfoToConsole(List.FormList[i]);
		std::cout << std::endl;
	}
}

void printSpecificForm(ShippingFormList& List) {
	int index = 0;
	std::cout << "\nThe current database has " << List.FormList.size() << " forms\n";
	std::cout << "Choose a form to view its info [1 - " << List.FormList.size() << "]: ";
	std::cin >> index;

	std::cout << "\nForm #" << index << std::endl;
	printInfoToConsole(List.FormList[index - 1]);
	std::cout << std::endl;
}


void removeFormList(ShippingFormList& List) {
	char choice = 'N';
	std::cout << "\nThe current database has " << List.FormList.size() << " forms\n";
	std::cout << "Do you want to remove a form? (Y/N) :";
	std::cin >> choice;

	if (choice == 'Y' || choice == 'y')
		do {
			int number_of_forms = List.FormList.size();
			if (number_of_forms <= 0) {
				std::cout << "No forms available to remove\n";
				printAllFormToFile(List);
				return;
			}
			else {
				int form_index = 0;
				do {
					std::cout << "Choose a form index to remove [0 - " << number_of_forms - 1 << "]: ";
					std::cin >> form_index;
				} while (form_index < 0 || form_index >= number_of_forms);

				List.removeForm(form_index);
				std::cout << "Form number [" << form_index << "] has been successfully removed\n";

				std::cout << "\nThe current database has " << number_of_forms - 1 << " forms\n";
				std::cout << "Do you want to remove more forms? (Y/N) :";
				std::cin >> choice;
			}
		} while (choice == 'Y' || choice == 'y');
		printAllFormToFile(List);
}

void editFormList(ShippingFormList& List) {
	char choice = 'N';
	std::cout << "The current database has " << List.FormList.size() << " forms\n";
	std::cout << "Do you want to edit more forms? (Y/N) :";
	std::cin >> choice;

	if (choice == 'Y' || choice == 'y') {
		do {
			int number_of_forms = List.FormList.size();
			if (number_of_forms <= 0) {
				std::cout << "No forms available to edit\n";
				return;
			}
			else {
				int form_index = 0;
				do {
					std::cout << "Choose a form index to edit [0 - " << number_of_forms - 1 << "]: ";
					std::cin >> form_index;
				} while (form_index < 0 || form_index >= number_of_forms);


				std::cout << "Editing form number [" << form_index << "]:\n\n";
				ShippingForm* NewForm;
				inputForm(NewForm);
				List.replaceForm(NewForm, form_index);

				std::cout << "\nThe current database has " << number_of_forms << " forms\n";
				std::cout << "Do you want to edit more forms? (Y/N) :";
				std::cin >> choice;
			}
		} while (choice == 'Y' || choice == 'y');
	}

	printAllFormToFile(List);
}

void searchFormList(ShippingFormList& List) {
	std::string search_str;
	std::cout << "\nEnter address to find forms [Redundant spaces can cause unexpected errors]: ";
	std::cin.ignore();
	getline(std::cin, search_str);

	std::vector<int> index;
	for (int i = 0; i < List.FormList.size(); i++) {
		if (List.FormList[i]->from_address.find(search_str) != STRING_NOT_FOUND || List.FormList[i]->to_address.find(search_str) != STRING_NOT_FOUND) {
			(index).push_back(i);
		}
	}

	std::cout << "\nThere are " << index.size() << " results matched\n";
	for (int i = 0; i < index.size(); i++) {
		std::cout << "Form index: " << index[i] << std::endl;
	}
}


void listCompletedFileByTime(ShippingFormList& List) {
	int from_date = NULL_DATE,
		to_date = NULL_DATE;

	std::cout << "\nEnter the start time [yyyymmdd]: ";
	std::cin >> from_date;
	std::cout << "Enter the end time [yyyymmdd]: ";
	std::cin >> to_date;

	std::cout << "\nCompleted delivery:\n";
	for (int i = 0; i < List.FormList.size(); i++) {
		if (from_date <= List.FormList[i]->received_date && List.FormList[i]->received_date <= to_date)
			std::cout << "Form #" << i + 1 << std::endl;
	}
}

void updatePrice() {
	std::cout << "Please choose an option below:\n";
	std::cout << "1. Update price\n";
	std::cout << "2. Return to default\n\n";

	int option = 0;
	do {
		std::cout << "->Your option [1-2]: ";
		std::cin >> option;
	} while (!(option == 1 || option == 2));

	if (option == 1) {
		Price custom_price;
		std::cout << "Enter new price:\n";

		std::cout << "1. Document\n";
		std::cout << "\tService's price: ";
		std::cin >> custom_price.DOC_service;
		std::cout << "\tDistance's price (per km): ";
		std::cin >> custom_price.DOC_distance;

		std::cout << "2. Package\n";
		std::cout << "\tWeight's price (per kg): ";
		std::cin >> custom_price.PAC_weight;
		std::cout << "\tDistance's price (per km): ";
		std::cin >> custom_price.PAC_distance;

		current_price = custom_price;
	}
	else if (option == 2) {
		current_price = default_price;
	}

	std::cout << "New price:\n";
	std::cout << "1. Document:\nService: " << current_price.DOC_service << "\nDistance: " << current_price.DOC_distance << std::endl;
	std::cout << "2. Package:\nWeight: " << current_price.PAC_weight << "\nDistance: " << current_price.PAC_distance << std::endl;
	printMoneyToFile(current_price);
}

void printRevenue(ShippingFormList& List) {
	int from_date = NULL_DATE,
		to_date = NULL_DATE;

	std::cout << "\nEnter the start time [yyyymmdd]: ";
	std::cin >> from_date;
	std::cout << "Enter the end time [yyyymmdd]: ";
	std::cin >> to_date;

	unsigned long long int revenue = 0;
	for (int i = 0; i < List.FormList.size(); i++) {
		if (from_date <= List.FormList[i]->received_date && List.FormList[i]->received_date <= to_date)
			revenue += List.FormList[i]->getShippingPrice();
	}

	std::cout << "\nRevenue from " << convertDate(from_date) << " to " << convertDate(to_date) << ": " << revenue << std::endl;
}