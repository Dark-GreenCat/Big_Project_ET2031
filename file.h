#ifndef FILE_H
#define FILE_H 

#include "data_structure.h"

#define INFOR_FILE "infor.txt"
#define MONEY_FILE "money.txt"

void loadForm(ShippingForm*& Form, std::ifstream& filein);

void saveInputInfor(ShippingForm* &Form);

void creatNewFile(std::string file_name);
bool ifFileExist(std::string file_name);
void renameFile(const char* old_name, const char* new_name);
void removeFile(const char* file_name);
void printAllFormToFile(ShippingFormList &List);

void printMoneyToFile(Price money);
void loadInputMoney(Price &money);

#endif