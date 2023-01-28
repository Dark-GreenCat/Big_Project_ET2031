#include "data_structure.h"
Price default_money;

ShippingForm::ShippingForm()
{
	this->ID = DEFAULT_ID;
	this->sender_name = BLANK_TEXT;
	this->receiver_name = BLANK_TEXT;
	this->from_address = BLANK_TEXT;
	this->to_address = BLANK_TEXT;
	this->sent_date = NULL_DATE;
	this->received_date = NULL_DATE;

	this->isSucceeded = false;
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

void ShippingForm::outputGeneralInfo()
{
	std::cout << "Sender's name: " << sender_name;
	std::cout << "\nFrom address: " << from_address;
	std::cout << "\nSent date: " << convertDate(sent_date);

	std::cout << std::endl;

	std::cout << "Receiver's name: " << receiver_name;
	std::cout << "\nTo address: " << to_address;
	std::cout << "\nReceived date: " << convertDate(received_date);
}

/////////////////////////////////////
double DocumentShippingForm::getShippingPrice(Price custom_price)
{
	return (distance * custom_price.DOC_distance + custom_price.DOC_service);
}

void DocumentShippingForm::inputInfo(std::ifstream &filein)
{
	std::cout << "Enter distance (km): ";
	filein >> distance;
}

void DocumentShippingForm::outputInfo()
{
	std::cout << "Distance (km): " << distance;
}

/////////////////////////////////////
double PackageShippingForm::getShippingPrice(Price custom_price)
{
	return (distance * custom_price.PAC_distance + weight * custom_price.PAC_weight);
}

void PackageShippingForm::inputInfo(std::ifstream &filein)
{
	std::cout << "Enter distance (km): ";
	filein >> distance;

	std::cout << "Enter weight (kg): ";
	filein >> weight;
}

void PackageShippingForm::outputInfo()
{
	std::cout << "Distance (km): " << distance << std::endl;
	std::cout << "Weight (kg): " << weight;
}

///////////////////////////////////
void ShippingFormList::addForm(ShippingForm* &Form)
{
	this->FormList.push_back(Form);
}

void ShippingFormList::inputList(std::ifstream &filein)
{
	char choice = 'N';
	std::cout << "The current database has " << FormList.size() << " forms\n";
	std::cout << "Do you want to add more forms? (Y/N) :";
	filein >> choice;

	if (choice == 'Y' || choice == 'y')
		do
		{
			ShippingForm* Form;
			inputForm(Form, filein);

			this->FormList.push_back(Form);

			std::cout << "\nThe current database has " << FormList.size() << " forms\n";
			std::cout << "Do you want to add more forms? (Y/N) :";
			filein >> choice;
		} while (choice == 'Y' || choice == 'y');
}
void ShippingFormList::outputList()
{
	std::cout << "\nNumber of form: " << FormList.size() << std::endl;
	for (int i = 0; i < FormList.size(); i++)
	{
		std::cout << "\nForm #" << (i + 1) << std::endl;
		outputAllFormInfo(*FormList.at(i));
		std::cout << std::endl;
	}
}
////////////////////////////
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
	Form->inputInfo(filein);
}

void outputAllFormInfo(ShippingForm &Form)
{
	Form.outputGeneralInfo();
	std::cout << std::endl;
	Form.outputInfo();
}

/*void doc_thong_tin_don_hang(ifstream &filein, PackageShippingForm s1){

};*/