#include "function.h"

std::string convertDate(int date){
	std::string save = "";
	save += std::to_string(date % 100) + "/" +
			std::to_string((date / 100) % 100) + "/" +
			std::to_string((date / 10000));

	return save;
}

// Price updatePrice(double DOC_service, double DOC_distance, double PAC_weight, double PAC_distance){
// 	Price new_price;
// 	new_price.DOC_service = DOC_service;
// 	new_price.PAC_distance = DOC_distance;
// 	new_price.PAC_weight = PAC_weight;
// 	new_price.PAC_distance = PAC_distance;

// 	return new_price;
// };
// // find position with address
// void Free(int *p){
// 	delete[] p;
// }
// void Copy(int *p, int *q){
// 	for (int i = 0; i < sizeof(p)/4; i++)
// 	{
// 		q[i] = p[i];
// 	}
// }

// int *Realloc(int *p, int newSize){
// 	int *q = new int[newSize];
// 	Copy(p, q); 
// 	Free(p);
// 	return q;
// }
// char *string_to_char(std::string str){ // ham chuyen string sang char*
// 	char *ch = (char *)str.c_str();
// 	return ch;
// }

// int *findPositionOfForm_fromAdress_findAdress(PackageShippingForm List[], std::string look_for_string){
// 	int i = 0;
// 	int *p = new int[i];
// 	int sizeOfP = 0;

// 	for (i = 0; i < sizeof(List) / (sizeof(List) / sizeof(List[0])); i++)
// 	{
// 		if (strstr(string_to_char(List[i].from_address), string_to_char(look_for_string)))
// 		{
// 			p = Realloc(p, sizeOfP + 1);
// 			p[sizeOfP] = i;
// 			sizeOfP++;
// 		}
// 		else
// 			std::cout << "Khong tim thay";
// 	}
// 	return p;
// };