#include "data_structure.h"

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

void ShippingForm::inputInfo() {
	std::cout << "Enter sender's name: ";
	std::cin.ignore();
	std::cin >> this->sender_name;
}

void ShippingForm::outputInfo() {
	std::cout << "Sender's name: " << this->sender_name;
}

double DocumentShippingForm::getDocumentPrice(Price custom_price) {
	return (distance * custom_price.DOC_distance + custom_price.DOC_service);
}

double PackageShippingForm::getPackagePrice(Price custom_price){
	return (distance * custom_price.PAC_distance + weight * custom_price.PAC_weight);
}


