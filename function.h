#include <iostream>
#include "data_structure.h"
#include<string>
std::string convertDate(int date){//20220412
    std::string save="";
	save+=std::to_string(date%100)+"/"+std::to_string((date/100)%100) +"/"+std::to_string((date/10000));
	
    return save;
} 
Price updatePrice(double DOC_service, double DOC_distance, double PAC_weight, double PAC_distance, Price money)
{
    money.DOC_service = DOC_service;
    money.PAC_distance = DOC_distance;
    money.PAC_weight = PAC_weight;
    money.PAC_distance = PAC_distance;
};
