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
	{std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
    fileout<<sender_name<<"\n";
    fileout.close();}  

	std::cout << "From address: ";
	getline(std::cin, from_address); //std::cin.ignore(MAX_STREAMSIZE, '\n');
	{std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
    fileout<<from_address<<"\n";
    fileout.close();}

	std::cout << "Sent date (yyyymmdd): ";
	std::cin >> sent_date;
	{std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
    fileout<<sent_date<<"\n";
    fileout.close();}

	std::cout << std::endl;

	std::cin.ignore();
	std::cout << "Receiver's name: ";
	getline(std::cin, receiver_name);
	{std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
    fileout<<receiver_name<<"\n";
    fileout.close();}

	std::cout << "To address: ";
	getline(std::cin, to_address);
	{std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
    fileout<<to_address<<"\n";
    fileout.close();}

	std::cout << "Received date (yyyymmdd): ";
	std::cin >> received_date;
	{std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
    fileout<<received_date<<"\n";
    fileout.close();}
}

void ShippingForm::inputGeneralInfo(std::ifstream &filein)
{
	filein.ignore();
	getline(filein, sender_name);
	getline(filein, from_address); // std::cin.ignore(MAX_STREAMSIZE, '\n');
	filein >> sent_date;

	std::cout << std::endl;

	filein.ignore();
	getline(filein, receiver_name);
	getline(filein, to_address);
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
	{std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
    fileout<<distance;
    fileout.close();}
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
	{std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
    fileout<<distance<<"\n";
    fileout.close();}

	std::cout << "Enter weight (kg): ";
	std::cin >> weight;
	{std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
    fileout<<weight;
    fileout.close();}
}

void PackageShippingForm::inputDetailInfo(std::ifstream &filein)
{
	filein >> distance;
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
	ShippingForm* Form;

	while(!filein.eof()) {
		inputForm(Form, filein);
		this->FormList.push_back(Form);
	}
}

////////////////////////////
void inputForm(ShippingForm* &Form) {
	int type;
	std::cout << "Enter type of parcel: " << std::endl;
	std::cout << "1. Document\t2.Package\n";
	std::cout << "Type: ";
	std::cin >> type;
	{std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
    fileout<<type<<"\n";
    fileout.close();}
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
			{std::ofstream fileout;
			fileout.open("infor.text", std::ios::app);
			fileout<<"\n";
			fileout.close();}
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

void printSpecificForm(ShippingFormList &List) {
	int index = 0;
	std::cout << "\nThe current database has " << List.FormList.size() << " forms\n";
	std::cout << "Choose a form to view its info [1 - " << List.FormList.size() << "]: ";
	std::cin >> index;

	std::cout << "\nForm #" << index << std::endl;
	outputAllFormInfo(*List.FormList.at(index - 1));
	std::cout << std::endl;
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

void searchFormList(ShippingFormList &List) {
	std::string search_str;
	std::cout << "\nEnter address to find forms [Redundant spaces can cause unexpected errors]: ";
	std::cin.ignore();
	getline(std::cin, search_str);

	std::vector<int> index;
	for(int i = 0; i < List.FormList.size(); i++) {
		if(List.FormList.at(i)->from_address.find(search_str) != STRING_NOT_FOUND || List.FormList.at(i)->to_address.find(search_str) != STRING_NOT_FOUND) {
			(index).push_back(i);
		}
	}

	std::cout << "\nThere are " << index.size() << " results matched\n";
	for(int i = 0; i < index.size(); i++) {
		std::cout << "Form index: " << index.at(i) << std::endl;
	}
}


void listCompletedFileByTime(ShippingFormList &List) {
	int from_date = NULL_DATE,
		to_date = NULL_DATE;

	std::cout << "\nEnter the start time [yyyymmdd]: ";
	std::cin >> from_date;
	std::cout << "Enter the end time [yyyymmdd]: ";
	std::cin >> to_date;

	std::cout << "\nCompleted delivery:\n";
	for(int i = 0; i < List.FormList.size(); i++) {
		if(from_date <= List.FormList.at(i)->received_date && List.FormList.at(i)->received_date <= to_date)
			std::cout << "Form #" << i + 1 << std::endl;
	}
}

void updatePrice() {
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

	default_money = custom_price;
	std::cout << "New price:\n";
	std::cout <<"1. Document:\nService: " << default_money.DOC_service << "\nDistance: " << default_money.DOC_distance << std::endl;
	std::cout <<"2. Package:\nWeight: " << default_money.PAC_weight << "\nDistance: " << default_money.PAC_distance << std::endl;
}

void printRevenue(ShippingFormList &List) {
	int from_date = NULL_DATE,
		to_date = NULL_DATE;

	std::cout << "\nEnter the start time [yyyymmdd]: ";
	std::cin >> from_date;
	std::cout << "Enter the end time [yyyymmdd]: ";
	std::cin >> to_date;

	unsigned long long int revenue = 0;
	for(int i = 0; i < List.FormList.size(); i++) {
		if(from_date <= List.FormList.at(i)->received_date && List.FormList.at(i)->received_date <= to_date)
			revenue += List.FormList.at(i)->getShippingPrice();
	}

	std::cout << "\nRevenue from " << convertDate(from_date) << " to " << convertDate(to_date) << ": " << revenue << std::endl;
}