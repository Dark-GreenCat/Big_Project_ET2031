#include "gui_connect.h"

void inputSingleForm(ShippingFormList& List, int type, std::string sender_name, std::string from_address, int sent_date,
                                                        std::string receiver_name, std::string to_address, int received_date) {
    ShippingForm* Form;
    if (List.FormList.size() > 0) {
        std::ofstream fileout;
        fileout.open(INFOR_FILE, std::ios::app);
        fileout << "\n";
        fileout.close();
    }
    
	if (type == DOCUMENT)
		Form = new DocumentShippingForm;
	else if (type == PACKAGE)
		Form = new PackageShippingForm;

	Form->sender_name = sender_name;
	Form->from_address = from_address;
	Form->sent_date = sent_date;
	Form->receiver_name = receiver_name;
    Form->to_address = to_address;
	Form->received_date = received_date;

	if (Form->getType() == DOCUMENT) {
		std::cout << "Enter distance (km): ";
		std::cin >> ((DocumentShippingForm*)Form)->distance;
	}
	else if (Form->getType() == PACKAGE) {
		std::cout << "Enter distance (km): ";
		std::cin >> ((PackageShippingForm*)Form)->distance;
		std::cout << "Enter weight (kg): ";
		std::cin >> ((PackageShippingForm*)Form)->weight;
	}

    std::ofstream fileout;
    fileout.open(INFOR_FILE, std::ios::app);
    saveInputInfor(Form, fileout);
    fileout.close();

    List.FormList.push_back(Form);
}