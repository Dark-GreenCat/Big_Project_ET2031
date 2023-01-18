#include<iostream>
#include<string>
#include "getDocumentPrice.cpp"
using namespace std;
enum ShippingType 
{
	DOCUMENT = 1, 
	PACKAGE = 2
};
struct Price 
{
	double DOC_service = 12000;
	double DOC_distance = 2000;
	double PAC_weight = 10000;
	double PAC_distance = 2000;
};
class ShippingForm {
	private:
		int ID;
		
		double distance;
		double weight;
		ShippingType shipping_type;

		int sent_date;
		int received_date;

		bool isSucceeded;

	public:
		ShippingForm() {
			ID = 0;
		}	
		ShippingForm(std::string receiver_name, std::string to_address, double distance, double weight); //weight = 0 => DOC

		double getDocumentPrice(double distance,double DOC_distance, double DOC_service, Price money)
		{
			double price=0;
			this->distance=distance;
			money.DOC_distance=DOC_distance;
			money.DOC_service=DOC_service;
			price=distance*DOC_distance+DOC_service;
			return price;	
		}; 
		double getPackagePrice(double distance, double PAC_distance, double weight, double PAC_weight, Price money)
		{
			double price=0;
			this->distance=distance;
			money.PAC_distance=PAC_distance;
			money.PAC_weight=PAC_weight;
			price=distance*PAC_distance+weight*PAC_weight;
			return price;
		};
		Price updatePrice(double DOC_service, double DOC_distance, double PAC_weight, double PAC_distance, Price money)
		{
			money.DOC_service=DOC_service;
			money.PAC_distance=DOC_distance;
			money.PAC_weight=PAC_weight;
			money.PAC_distance=PAC_distance;
		};
		int convertDate(int newDate, ShippingForm oldDate)
		{
			oldDate.sent_date=newDate;
		};
};
int main()
{
	
	return 0;
}