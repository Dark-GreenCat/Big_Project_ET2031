#include "data_structure.h"
Price default_money;

ShippingForm::ShippingForm() {
	this->ID = DEFAULT_ID;
	this->sender_name = BLANK_TEXT;
	this->receiver_name = BLANK_TEXT;
	this->from_address = BLANK_TEXT;
	this->to_address = BLANK_TEXT;
	this->sent_date = NULL_DATE;
	this->received_date = NULL_DATE;

	this->isSucceeded = false;
}

ShippingForm::~ShippingForm() {
	delete this;
}

void ShippingForm::inputGeneralInfo() {
	std::cin.ignore();
	std::cout << "Sender's name: ";
	getline(std::cin, sender_name);
	std::cout << "From address: ";
	getline(std::cin, from_address); //std::cin.ignore(MAX_STREAMSIZE, '\n');
	std::cout << "Sent date (yyyymmdd): ";
	std::cin >> sent_date;

	std::cout << std::endl;

	std::cin.ignore();
	std::cout << "Receiver's name: ";
	getline(std::cin, receiver_name);
	std::cout << "To address: ";
	getline(std::cin, to_address);
	std::cout << "Received date (yyyymmdd): ";
	std::cin >> received_date;
}

void ShippingForm::inputGeneralInfo(std::ifstream &filein)
{
	filein.ignore();
	getline(filein, sender_name);
	getline(filein, from_address); // std::cin.ignore(MAX_STREAMSIZE, '\n');
	filein >> sent_date;

	std::cout << std::endl;

	filein.ignore();
	getline(filein, receiver_name);
	getline(filein, to_address);
	filein >> received_date;
}

void ShippingForm::outputGeneralInfo() {
	std::cout << "Sender's name: " << sender_name;
	std::cout << "\nFrom address: " << from_address;
	std::cout << "\nSent date: " << convertDate(sent_date);

	std::cout << std::endl;

	std::cout << "Receiver's name: " << receiver_name;
	std::cout << "\nTo address: " << to_address;
	std::cout << "\nReceived date: " << convertDate(received_date);
}

/////////////////////////////////////
int DocumentShippingForm::getType(){
	return DOCUMENT;
}
double DocumentShippingForm::getShippingPrice(Price custom_price) {
	return (distance * custom_price.DOC_distance + custom_price.DOC_service);
}

void DocumentShippingForm::inputDetailInfo() {
	std::cout << "Enter distance (km): ";
	std::cin >> distance;
}

void DocumentShippingForm::inputDetailInfo(std::ifstream &filein)
{
	std::cout << "Enter distance (km): ";
	filein >> distance;
}

void DocumentShippingForm::outputDetailInfo() {
	std::cout << "Distance (km): " << distance;
}

/////////////////////////////////////
int PackageShippingForm::getType(){
	return PACKAGE;
}
double PackageShippingForm::getShippingPrice(Price custom_price){
	return (distance * custom_price.PAC_distance + weight * custom_price.PAC_weight);
}

void PackageShippingForm::inputDetailInfo() {
	std::cout << "Enter distance (km): ";
	std::cin >> distance;
	std::cout << "Enter weight (kg): ";
	std::cin >> weight;
}

void PackageShippingForm::inputDetailInfo(std::ifstream &filein)
{
	filein >> distance;
	filein >> weight;
}

void PackageShippingForm::outputDetailInfo() {
	std::cout << "Distance (km): " << distance << std::endl;
	std::cout << "Weight (kg): " << weight;
}

///////////////////////////////////
void ShippingFormList::addForm(ShippingForm* &Form) {
	this->FormList.push_back(Form);
}

void ShippingFormList::removeForm(int index) {
	this->FormList.erase(FormList.begin() + index);
}

void ShippingFormList::replaceForm(ShippingForm* &NewForm, int index) {
	this->FormList.insert(FormList.begin() + index, NewForm);
	this->removeForm(index + 1);
}

void ShippingFormList::inputList(std::ifstream &filein) {
	ShippingForm* Form;

	while(!filein.eof()) {
		inputForm(Form, filein);
		this->FormList.push_back(Form);
	}
}

////////////////////////////
void inputForm(ShippingForm* &Form) {
	int type;
	std::cout << "Enter type of parcel: " << std::endl;
	std::cout << "1. Document\t2.Package\n";
	std::cout << "Type: ";
	std::cin >> type;
	if (type == DOCUMENT)
		Form = new DocumentShippingForm;
	else if (type == PACKAGE)
		Form = new PackageShippingForm;

	Form->inputGeneralInfo();
	Form->inputDetailInfo();
}

void inputForm(ShippingForm* &Form, std::ifstream &filein)
{
	int type;
	filein >> type;
	if (type == DOCUMENT)
		Form = new DocumentShippingForm;
	else if (type == PACKAGE)
		Form = new PackageShippingForm;

	Form->inputGeneralInfo(filein);
	Form->inputDetailInfo(filein);
}

void outputAllFormInfo(ShippingForm &Form) {
	Form.outputGeneralInfo();
	std::cout << std::endl;
	Form.outputDetailInfo();
}

void saveInputInfor(ShippingForm* &Form){
	std::ofstream fileout;
    fileout.open("infor.text", std::ios::app);
	fileout<<Form->getType()<<"\n";
    fileout<<Form->sender_name<<"\n";
	fileout<<Form->from_address<<"\n";
	fileout<<Form->sent_date<<"\n";
	fileout<<Form->receiver_name<<"\n";
	fileout<<Form->to_address<<"\n";
	fileout<<Form->received_date<<"\n";
	
	if(Form->getType() == DOCUMENT) {
		fileout << ((DocumentShippingForm*) Form)->distance;
	}
	else if(Form->getType() ==PACKAGE){
		fileout<<((PackageShippingForm*)Form)->distance<<"\n";
		fileout<<((PackageShippingForm*)Form)->weight;
	}
    fileout.close();
}

void creatNewFile(std::string file_name) {
    std::ofstream file(file_name);
    file.close();
}
bool ifFileExist(std::string file_name) {
    std::ifstream file;
    file.open(file_name);

    if(file) return true;
    else return false;
}
void renameFile(const char* old_name, const char* new_name) {
    rename(old_name, new_name);
}
void removeFile(const char* file_name) {
    remove(file_name);
}
void printAllFormToFile(ShippingFormList &List){
    creatNewFile("infor.text");
	std::ofstream fileout;
	fileout.open("infor.text", std::ios::app);
	if(List.FormList.size() > 0)
		saveInputInfor(List.FormList.at(0));
	for(int i=1;i<List.FormList.size();i++){
		fileout<<"\n"<<List.FormList.at(i)->getType()<<"\n";
		fileout<<List.FormList.at(i)->sender_name<<"\n";
		fileout<<List.FormList.at(i)->from_address<<"\n";
		fileout<<List.FormList.at(i)->sent_date<<"\n";
		fileout<<List.FormList.at(i)->receiver_name<<"\n";
		fileout<<List.FormList.at(i)->to_address<<"\n";
		fileout<<List.FormList.at(i)->received_date<<"\n";
		if(List.FormList.at(i)->getType() == DOCUMENT) {
			fileout << ((DocumentShippingForm*) List.FormList.at(i))->distance;
		}
		else if(List.FormList.at(i)->getType() ==PACKAGE){
			fileout<<((PackageShippingForm*)List.FormList.at(i))->distance<<"\n";
			fileout<<((PackageShippingForm*)List.FormList.at(i))->weight;
		}
		fileout.close();
	}
}
void printMoneyToFile(Price money){
	creatNewFile("money.txt");
	std::ofstream fileout;
	fileout.open("money.txt", std::ios::app);
	fileout<<money.DOC_service<<"\n";
	fileout<<money.DOC_distance<<"\n";
	fileout<<money.PAC_weight<<"\n";
	fileout<<money.PAC_distance;
	fileout.close();
}
void loadInputMoney(Price &money){
	std::ifstream filein;
    filein.open("money.txt", std::ios_base::in);
	filein>>money.DOC_service;
	filein>>money.DOC_distance;
	filein>>money.PAC_weight;
	filein>>money.PAC_distance;
	filein.close();
}
