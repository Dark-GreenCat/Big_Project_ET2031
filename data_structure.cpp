#include "data_structure.h"

double ShippingForm::getDocumentPrice(double distance,double DOC_distance, double DOC_service, Price money) {
	double price=0;
			this->distance=distance;
			money.DOC_distance=DOC_distance;
			money.DOC_service=DOC_service;
			price=distance*DOC_distance+DOC_service;
			return price;
}
double ShippingForm::getPackagePrice(double distance, double PAC_distance, double weight, double PAC_weight, Price money){
	double price=0;
	this->distance=distance;
	money.PAC_distance=PAC_distance;
	money.PAC_weight=PAC_weight;
	price=distance*PAC_distance+weight*PAC_weight;
	return price;
};
