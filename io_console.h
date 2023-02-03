#ifndef IO_CONSOLE_H
#define IO_CONSOLE_H

#include "data_structure.h"
#include <iostream>

void inputGeneralInfoShippingForm(ShippingForm*& Form);
void inputDetailInfoShippingForm(ShippingForm*& Form);
void inputForm(ShippingForm*& Form);

void printGeneralInfoToConsole(ShippingForm*& Form);
void printDetailInfoToConsole(ShippingForm*& Form);
void printInfoToConsole(ShippingForm*& Form);

#endif