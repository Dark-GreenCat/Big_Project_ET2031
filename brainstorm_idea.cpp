#include <iostream>
#include <string>
// class Address {
// 	private:
		

// 	public:
// 		void enterAddress()
// };

enum ShippingType {
	DOCUMENT = 1, 
	PACKAGE = 2
};

struct Price {
	double DOC_service = 12000;
	double DOC_distance = 2000;
	double PAC_weight = 10000;
	double PAC_distance = 2000;
};

class ShippingForm {
	private:
		int ID;
	
	public:
		std::string sender_name;
		std::string receiver_name;

		std::string from_address;
		std::string to_address;
		
		int sent_date;
		int received_date;

		double distance;
		double weight;
		ShippingType shipping_type;

		bool isSucceeded;

		ShippingForm(std::string receiver_name, std::string to_address, double distance, double weight); //weight = 0 => DOC

		double getDocumentPrice();
		double getPackagePrice();
};
