//#include "function.h"
#include "data_structure.h"
#include<cstring>
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
//find position with address
void Free(int *p){
	delete p;
}
void Copy(int *p, int *q, int oldSize){
	for(int i = 0; i < oldSize-1; i++){
		q[i] = p[i];
	}
}
int* Realloc(int *p, int newSize){
	int *q = new int[newSize];
	Copy (p, q, oldSize);
	Free(p);
	return q;
}
int* findPositionOfForm_fromAdress_findAdress(PackageShippingForm List[], std:: string look_for_string){
	int i;
	int *p = new int [i];
	int sizeOfP = 0;

	for(i=0; i<sizeof(List)/4; i++){
		if(strstr(List[i].from_address,look_for_string)){
			p = Realloc(*p, sizeOfP + 1);
			p[sizeOfP]=i;
			sizeOfP++;
		}else cout<<"Khong tim thay";
	}
	return p;
};