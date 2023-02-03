#include "io_console.h"

void inputGeneralInfoShippingForm(ShippingForm*& Form) {
   	std::cin.ignore();
	std::cout << "Sender's name: ";
	getline(std::cin, Form->sender_name);
	std::cout << "From address: ";
	getline(std::cin, Form->from_address); //std::cin.ignore(MAX_STREAMSIZE, '\n');
	std::cout << "Sent date (yyyymmdd): ";
	std::cin >> Form->sent_date;

	std::cout << std::endl;

	std::cin.ignore();
	std::cout << "Receiver's name: ";
	getline(std::cin, Form->receiver_name);
	std::cout << "To address: ";
	getline(std::cin, Form->to_address);
	std::cout << "Received date (yyyymmdd): ";
	std::cin >> Form->received_date;
}

void inputDetailInfoShippingForm(ShippingForm*& Form) {
    if(Form->getType() == DOCUMENT) {
        std::cout << "Enter distance (km): ";
	    std::cin >> ((DocumentShippingForm*) Form)->distance;
    }
    else if(Form->getType() == PACKAGE) {
        std::cout << "Enter distance (km): ";
        std::cin >>  ((PackageShippingForm*) Form)->distance;
        std::cout << "Enter weight (kg): ";
        std::cin >>  ((PackageShippingForm*) Form)->weight;
    }
}

void inputForm(ShippingForm*& Form) {
	int type;
	std::cout << "Enter type of parcel: " << std::endl;
	std::cout << "1. Document\t2.Package\n";
	std::cout << "Type: ";
	std::cin >> type;
	if (type == DOCUMENT)
		Form = new DocumentShippingForm;
	else if (type == PACKAGE)
		Form = new PackageShippingForm;

	inputGeneralInfoShippingForm(Form);
	inputDetailInfoShippingForm(Form);
}

void printGeneralInfoToConsole(ShippingForm*& Form) {
	std::cout << "Sender's name: " << Form->sender_name;
	std::cout << "\nFrom address: " << Form->from_address;
	std::cout << "\nSent date: " << convertDate(Form->sent_date);

	std::cout << std::endl;

	std::cout << "Receiver's name: " << Form->receiver_name;
	std::cout << "\nTo address: " << Form->to_address;
	std::cout << "\nReceived date: " << convertDate(Form->received_date);
}

void printDetailInfoToConsole(ShippingForm*& Form) {
	if(Form->getType() == DOCUMENT) {
		std::cout << "Distance (km): " << ((DocumentShippingForm*) Form)->distance;
	}
	else if(Form->getType() == PACKAGE) {
		std::cout << "Distance (km): " << ((PackageShippingForm*) Form)->distance << std::endl;
		std::cout << "Weight (kg): " << ((PackageShippingForm*) Form)->weight;
	}
}

void printInfoToConsole(ShippingForm*& Form) {
	printGeneralInfoToConsole(Form);
	std::cout << std::endl;
	printDetailInfoToConsole(Form);

}



