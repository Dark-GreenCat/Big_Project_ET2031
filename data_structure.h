#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "function.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <cstdio>

#define DEFAULT_ID 0
#define BLANK_TEXT ""
#define NULL_DATE 0

#define STRING_NOT_FOUND std::string::npos

const int MAX_STREAMSIZE = std::numeric_limits<std::streamsize>::max();

enum ParcelType {
	DOCUMENT = 1, 
	PACKAGE = 2
};

struct Price {
	unsigned int DOC_service = 12000;
	unsigned int DOC_distance = 2000;
	unsigned int PAC_weight = 10000;
	unsigned int PAC_distance = 2000;
};

extern Price default_price;
extern Price current_price;

class ShippingForm {
	public:
		int ID;

		std::string sender_name;
		std::string receiver_name;

		std::string from_address;
		std::string to_address;

		int sent_date;
		int received_date;

		int revenue;
		bool isSucceeded;

		ShippingForm();
		~ShippingForm();
		virtual int getType() = 0;
		void inputGeneralInfo(std::ifstream& filein);
		virtual void inputDetailInfo(std::ifstream& filein) = 0;

		virtual double getShippingPrice(Price money = current_price) = 0;
};

class DocumentShippingForm : public ShippingForm {
	public:
		double distance;

		~DocumentShippingForm();
		virtual int getType();
		virtual double getShippingPrice(Price money = current_price);
		virtual void inputDetailInfo(std::ifstream& filein);
};

class PackageShippingForm : public ShippingForm {
	public:
		double distance;
		double weight;

		~PackageShippingForm();
		virtual int getType();
		virtual double getShippingPrice(Price money = current_price); 
		virtual void inputDetailInfo(std::ifstream &filein);
};



class ShippingFormList {
	public:
		std::vector<ShippingForm*> FormList;

		void addForm(ShippingForm*& Form);
		void removeForm(int index);
		void replaceForm(ShippingForm*& NewForm, int index);
		void inputList(std::ifstream& filein);
};

#endif