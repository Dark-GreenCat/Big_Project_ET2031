#include "data_structure.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_NUMBER_OF_FORM 100

int main() { 
    // vector<ShippingForm *> pList; 
    // Price price;

    // DocumentShippingForm DocList;
    // DocList.inputInfo();

    // pList.push_back(&DocList);
    // cout << DocList.getShippingPrice(price);
    // cout << endl << default_money.DOC_distance << endl;

    // cout << pList.at(0)->getShippingPrice(price);
    // cout << endl << default_money.DOC_distance << endl;

    ShippingFormList pLIST;
    pLIST.inputList();
    pLIST.outputList();
}
