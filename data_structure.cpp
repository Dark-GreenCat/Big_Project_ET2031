#include "data_structure.h"
Price default_money;

ShippingForm::ShippingForm() {
	this->ID = DEFAULT_ID;
	this->sender_name = BLANK_TEXT;
	this->receiver_name = BLANK_TEXT;
	this->from_address = BLANK_TEXT;
	this->to_address = BLANK_TEXT;
	this->sent_date = NULL_DATE;
	this-> received_date = NULL_DATE;

	this->isSucceeded = false;
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

void DocumentShippingForm::inputInfo() {
	std::cout << "Enter distance (km): ";
	std::cin >> distance;
}

void DocumentShippingForm::outputInfo() {
	std::cout << "Distance (km): " << distance;
}

/////////////////////////////////////
double PackageShippingForm::getShippingPrice(Price custom_price){
	return (distance * custom_price.PAC_distance + weight * custom_price.PAC_weight);
}

void PackageShippingForm::inputInfo() {
	std::cout << "Enter distance (km): ";
	std::cin >> distance;

	std::cout << "Enter weight (kg): ";
	std::cin >> weight;
}

void PackageShippingForm::outputInfo() {
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
	Form->inputInfo();
}

void outputAllFormInfo(ShippingForm& Form) {
	Form.outputGeneralInfo();
	std::cout << std::endl;
	Form.outputInfo();
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

void printFormList(ShippingFormList& List) {
	std::cout << "\nNumber of form: " << List.FormList.size() << std::endl;
	for(int i = 0; i < List.FormList.size(); i++) {
		std::cout << "\nForm #" << (i + 1) << std::endl;
		outputAllFormInfo(*List.FormList.at(i));
		std::cout << std::endl;
	}
}