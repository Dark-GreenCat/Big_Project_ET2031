#include "init.h"

FormManagementSystemInit::FormManagementSystemInit() {
    this->form_info_file = INFOR_FILE;
    this->price_info_file = MONEY_FILE;
    this->cur_price = &current_price;
}

FormManagementSystemInit::FormManagementSystemInit(ShippingFormList& pList, std::string form_info_file, std::string price_info_file, Price* cur_price) {
    this->pList = &pList;
    this->form_info_file = form_info_file;
    this->price_info_file = price_info_file;
    this->cur_price = cur_price;
}

void FormManagementSystemInit::init() {
    if(!isFileExist(form_info_file))
        creatNewFile(form_info_file);
    if(!isFileExist(price_info_file));
        creatNewFile(price_info_file);

    std::ifstream filein;
    filein.open(form_info_file, std::ios_base::in);
    filein.peek();
    pList->inputList(filein);
    filein.close();

    loadInputMoney(*cur_price, price_info_file);
}