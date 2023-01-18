#include "data_structure.h"

#include<iostream>
#include<string>
using namespace std;
#define MAX_NUMBER_OF_FORM 100
string convertDate(int date){//20220412
    std::string save="";
	save+=to_string(date%100)+"/"+to_string((date/100)%100) +"/"+to_string((date/10000));
	
    return save;
}
int main() {
	//ShippingForm List[MAX_NUMBER_OF_FORM];
	cout<<convertDate(20220412);
	
	return 0;
}
