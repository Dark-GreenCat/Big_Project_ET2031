#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#include "data_structure.h"

void inputFormList(ShippingFormList &List);
void printFormList(ShippingFormList &List);
void printSpecificForm(ShippingFormList &List);

void removeFormList(ShippingFormList &List);
void editFormList(ShippingFormList &List);
void searchFormList(ShippingFormList &List);

void listCompletedFileByTime(ShippingFormList &List);

void updatePrice();
void printRevenue(ShippingFormList &List);

#endif