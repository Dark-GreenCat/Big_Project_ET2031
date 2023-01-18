#include "function.h"
#include "data_structure.h"

std::string convertDate(int date) {
	std::string save = "";
	save += std::to_string(date % 100) + "/" +
		std::to_string((date / 100) % 100) + "/" +
		std::to_string((date / 10000));

	return save;
};

Price updatePrice(double DOC_service, double DOC_distance, double PAC_weight, double PAC_distance) {
	Price new_price;
	new_price.DOC_service = DOC_service;
	new_price.PAC_distance = DOC_distance;
	new_price.PAC_weight = PAC_weight;
	new_price.PAC_distance = PAC_distance;

	return new_price;
};
