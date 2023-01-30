#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "function.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>

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
		~ShippingForm();
		void inputGeneralInfo();
		void inputGeneralInfo(std::ifstream &filein);
		void outputGeneralInfo();
		virtual void inputDetailInfo() = 0;
		virtual void inputDetailInfo(std::ifstream &filein) = 0;
		virtual void outputDetailInfo() = 0;

		virtual double getShippingPrice(Price money = default_money) = 0;
};

class DocumentShippingForm : public ShippingForm {
	private:
		double distance;

	public:
		virtual double getShippingPrice(Price money = default_money);
		virtual void inputDetailInfo();
		virtual void inputDetailInfo(std::ifstream &filein);
		virtual void outputDetailInfo();
};

class PackageShippingForm : public ShippingForm {
	private:
		double distance;
		double weight;

	public:
		virtual double getShippingPrice(Price money = default_money); 
		virtual void inputDetailInfo();
		virtual void inputDetailInfo(std::ifstream &filein);
		virtual void outputDetailInfo();
};



class ShippingFormList {
	public:
		std::vector<ShippingForm *> FormList;

		void addForm(ShippingForm* &Form);
		void removeForm(int index);
		void replaceForm(ShippingForm* &NewForm, int index);
		void inputList(std::ifstream &filein);
};


void inputForm(ShippingForm* &Form);
void inputForm(ShippingForm* &Form, std::ifstream &filein);
void outputAllFormInfo(ShippingForm &Form);

void inputFormList(ShippingFormList &List);
void printFormList(ShippingFormList &List);

void removeFormList(ShippingFormList &List);
void editFormList(ShippingFormList &List);
#endif