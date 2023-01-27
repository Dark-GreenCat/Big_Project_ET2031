#include "data_structure.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include<fstream>
using namespace std;

#define MAX_NUMBER_OF_FORM 100


int main() { 
    ifstream filein;
    filein.open("infor.text", ios_base::in);
    ShippingFormList pLIST;
    pLIST.inputList(filein);
    pLIST.outputList();
    filein.close();
    
    return 0;
}
