#include "function.h"

std::string convertDate(int date)
{
	std::ostringstream str;
	str.fill('0');
	str.width(2);
	str << date % 100 << '/';

	str.width(2);
	str << (date / 100) % 100 << '/';

	str << date / 10000;

	return str.str();
}

void printMenu() {
	std::cout << "\t\tDELIVERY FORM MANAGEMENT SYSTEM\n";
	std::cout << "\tPlease choose an option below:\n";
	std::cout << "\t1. Add a form\n";
	std::cout << "\t2. Edit a form\n";
	std::cout << "\t3. Remove a form\n";
	std::cout << "\t4. Search forms via address\n";
	std::cout << "\t5. List completed delivery by time\n";
	std::cout << "\t6. Updata price\n";
	std::cout << "\t7. Revenue\n";
	std::cout << "\t8. Print all forms\n";
	std::cout << "\t9. Exit program\n";
	std::cout << "\n\t-> Your option: "; 
}

void printEditorMenu() {
	std::cout << "\t\tFORM EDITOR\n";
	std::cout << "\t1. Add a form\n";
	std::cout << "\t2. Edit a form\n";
	std::cout << "\t3. Remove a form\n";	
}
