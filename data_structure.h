#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <iostream>
#include <string>

#define DEFAULT_ID 0
#define BLANK_TEXT ""
#define NULL_DATE 0

enum ShippingType {
	DOCUMENT = 1, 
	PACKAGE = 2
};

struct Price {
	double DOC_service = 12000;
	double DOC_distance = 2000;
	double PAC_weight = 10000;
	double PAC_distance = 2000;
} default_price;


class ShippingForm {
	public:
		int ID;

		std::string sender_name;
		std::string receiver_name;

		std::string from_address;
		std::string to_address;

		int sent_date;
		int received_date;

		bool isSucceeded;

		ShippingForm();
		void inputInfo();
		void outputInfo();
};

class DocumentShippingForm : public ShippingForm {
	private:
		double distance;

	public:
		double getDocumentPrice(Price money = default_price); //Kien
};

class PackageShippingForm : public ShippingForm {
	private:
		double distance;
		double weight;

	public:
		double getPackagePrice(Price money = default_price); //Kien
};

#endif