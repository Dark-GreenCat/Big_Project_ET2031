#include "data_structure.h"

double DocumentShippingForm::getDocumentPrice(Price custom_price) {
	return (distance * custom_price.DOC_distance + custom_price.DOC_service);
};

double PackageShippingForm::getPackagePrice(Price custom_price){
	return (distance * custom_price.PAC_distance + weight * custom_price.PAC_weight);
};


