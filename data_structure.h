#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "function.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

#define DEFAULT_ID 0
#define BLANK_TEXT ""
#define NULL_DATE 0

const int MAX_STREAMSIZE = std::numeric_limits<std::streamsize>::max();

enum ParcelType {
	DOCUMENT = 1, 
	PACKAGE = 2
};

struct Price {
	double DOC_service = 12000;
	double DOC_distance = 2000;
	double PAC_weight = 10000;
	double PAC_distance = 2000;
};

extern Price default_money;

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
		void inputGeneralInfo();
		void outputGeneralInfo();
		virtual void inputInfo() = 0;
		virtual void outputInfo() = 0;

		virtual double getShippingPrice(Price money = default_money) = 0;
};

class DocumentShippingForm : public ShippingForm {
	private:
		double distance;

	public:
		virtual double getShippingPrice(Price money = default_money);
		virtual void inputInfo();
		virtual void outputInfo();
};

class PackageShippingForm : public ShippingForm {
	private:
		double distance;
		double weight;

	public:
		virtual double getShippingPrice(Price money = default_money); 
		virtual void inputInfo();
		virtual void outputInfo();
};



class ShippingFormList {
	public:
		std::vector<ShippingForm *> FormList;

		void inputList();
		void outputList();
};


void outputAllFormInfo(ShippingForm& Form);

#endif