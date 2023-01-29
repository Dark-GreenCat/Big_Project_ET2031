#include "data_structure.h"
Price default_money;

ShippingForm::ShippingForm() {
	this->ID = DEFAULT_ID;
	this->sender_name = BLANK_TEXT;
	this->receiver_name = BLANK_TEXT;
	this->from_address = BLANK_TEXT;
	this->to_address = BLANK_TEXT;
	this->sent_date = NULL_DATE;
	this->received_date = NULL_DATE;

	this->isSucceeded = false;
}

ShippingForm::~ShippingForm() {
	delete this;
}

void ShippingForm::inputGeneralInfo() {
	std::cin.ignore();
	std::cout << "Sender's name: ";
	getline(std::cin, sender_name); 
	std::cout << "From address: ";
	getline(std::cin, from_address); //std::cin.ignore(MAX_STREAMSIZE, '\n');
	std::cout << "Sent date (yyyymmdd): ";
	std::cin >> sent_date;

	std::cout << std::endl;

	std::cin.ignore();
	std::cout << "Receiver's name: ";
	getline(std::cin, receiver_name);
	std::cout << "To address: ";
	getline(std::cin, to_address);
	std::cout << "Received date (yyyymmdd): ";
	std::cin >> received_date;
}

void ShippingForm::inputGeneralInfo(std::ifstream &filein)
{
	filein.ignore();
	std::cout << "Sender's name: ";
	getline(filein, sender_name, '-');
	std::cout << "From address: ";
	getline(filein, from_address); // std::cin.ignore(MAX_STREAMSIZE, '\n');
	std::cout << "Sent date (yyyymmdd): ";
	filein >> sent_date;

	std::cout << std::endl;

	filein.ignore();
	std::cout << "Receiver's name: ";
	getline(filein, receiver_name);
	std::cout << "To address: ";
	getline(filein, to_address);
	std::cout << "Received date (yyyymmdd): ";
	filein >> received_date;
}

void ShippingForm::outputGeneralInfo() {
	std::cout << "Sender's name: " << sender_name;
	std::cout << "\nFrom address: " << from_address;
	std::cout << "\nSent date: " << convertDate(sent_date);

	std::cout << std::endl;

	std::cout << "Receiver's name: " << receiver_name;
	std::cout << "\nTo address: " << to_address;
	std::cout << "\nReceived date: " << convertDate(received_date);
}

/////////////////////////////////////
double DocumentShippingForm::getShippingPrice(Price custom_price) {
	return (distance * custom_price.DOC_distance + custom_price.DOC_service);
}

void DocumentShippingForm::inputDetailInfo() {
	std::cout << "Enter distance (km): ";
	std::cin >> distance;
}

void DocumentShippingForm::inputDetailInfo(std::ifstream &filein)
{
	std::cout << "Enter distance (km): ";
	filein >> distance;
}

void DocumentShippingForm::outputDetailInfo() {
	std::cout << "Distance (km): " << distance;
}

/////////////////////////////////////
double PackageShippingForm::getShippingPrice(Price custom_price){
	return (distance * custom_price.PAC_distance + weight * custom_price.PAC_weight);
}

void PackageShippingForm::inputDetailInfo() {
	std::cout << "Enter distance (km): ";
	std::cin >> distance;

	std::cout << "Enter weight (kg): ";
	std::cin >> weight;
}

void PackageShippingForm::inputDetailInfo(std::ifstream &filein)
{
	std::cout << "Enter distance (km): ";
	filein >> distance;

	std::cout << "Enter weight (kg): ";
	filein >> weight;
}

void PackageShippingForm::outputDetailInfo() {
	std::cout << "Distance (km): " << distance << std::endl;
	std::cout << "Weight (kg): " << weight;
}

///////////////////////////////////
void ShippingFormList::addForm(ShippingForm* &Form) {
	this->FormList.push_back(Form);
}

void ShippingFormList::removeForm(int index) {
	this->FormList.erase(FormList.begin() + index);
}

void ShippingFormList::replaceForm(ShippingForm* &NewForm, int index) {
	this->FormList.insert(FormList.begin() + index, NewForm);
	this->removeForm(index + 1);
}

void ShippingFormList::inputList(std::ifstream &filein) {
	char choice = 'N';
	std::cout << "The current database has " << FormList.size() << " forms\n";
	std::cout << "Do you want to add more forms? (Y/N) :";
	filein >> choice;

	if (choice == 'Y' || choice == 'y')
		do {
			ShippingForm* Form;
			inputForm(Form, filein);

			this->FormList.push_back(Form);

			std::cout << "\nThe current database has " << FormList.size() << " forms\n";
			std::cout << "Do you want to add more forms? (Y/N) :";
			filein >> choice;
		} while (choice == 'Y' || choice == 'y');
}

////////////////////////////
void inputForm(ShippingForm* &Form) {
	int type;
	std::cout << "Enter type of parcel: " << std::endl;
	std::cout << "1. Document\t2.Package\n";
	std::cout << "Type: ";
	std::cin >> type;
	if (type == DOCUMENT)
		Form = new DocumentShippingForm;
	else if (type == PACKAGE)
		Form = new PackageShippingForm;

	Form->inputGeneralInfo();
	Form->inputDetailInfo();
}

void inputForm(ShippingForm* &Form, std::ifstream &filein)
{
	int type;
	std::cout << "Enter type of parcel: " << std::endl;
	std::cout << "1. Document\t2.Package\n";
	std::cout << "Type: ";
	filein >> type;
	if (type == DOCUMENT)
		Form = new DocumentShippingForm;
	else if (type == PACKAGE)
		Form = new PackageShippingForm;

	Form->inputGeneralInfo(filein);
	Form->inputDetailInfo(filein);
}

void outputAllFormInfo(ShippingForm &Form) {
	Form.outputGeneralInfo();
	std::cout << std::endl;
	Form.outputDetailInfo();
}

void inputFormList(ShippingFormList& List) {
	char choice = 'N';
	std::cout << "The current database has " << List.FormList.size() << " forms\n";
	std::cout << "Do you want to add more forms? (Y/N) :";
	std::cin >> choice;

	if (choice == 'Y' || choice == 'y')
		do {
			ShippingForm *Form;
			inputForm(Form);

			List.FormList.push_back(Form);

			std::cout << "\nThe current database has " << List.FormList.size() << " forms\n";
			std::cout << "Do you want to add more forms? (Y/N) :";
			std::cin >> choice;
		} while (choice == 'Y' || choice == 'y');
}

void printFormList(ShippingFormList &List) {
	std::cout << "\nNumber of form: " << List.FormList.size() << std::endl;
	for(int i = 0; i < List.FormList.size(); i++) {
		std::cout << "\nForm #" << (i + 1) << std::endl;
		outputAllFormInfo(*List.FormList.at(i));
		std::cout << std::endl;
	}
}

void removeFormList(ShippingFormList &List) {
	char choice = 'N';
	std::cout << "\nThe current database has " << List.FormList.size() << " forms\n";
	std::cout << "Do you want to remove a form? (Y/N) :";
	std::cin >> choice;

	if (choice == 'Y' || choice == 'y')
		do {
			int number_of_forms = List.FormList.size();
			if (number_of_forms <= 0) {
				std::cout << "No forms available to remove\n";
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
}

void editFormList(ShippingFormList &List) {
	char choice = 'N';
	std::cout << "The current database has " << List.FormList.size() << " forms\n";
	std::cout << "Do you want to edit more forms? (Y/N) :";
	std::cin >> choice;

	if (choice == 'Y' || choice == 'y')
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