#ifndef RELIEF_HPP
#define RELIEF_HPP

//Header Files
#include <iostream> 
#include <limits>
#include <iomanip>
using namespace std;

//Function Declaration
void Marital_Status(double& TotalTaxRelief1);
void Children(double& TotalTaxRelief2);
void Contribution(double& TotalTaxRelief3);
void Lifestyle(double& TotalTaxRelief4);
double Total_Tax_Relief(double TotalTaxRelief1, double TotalTaxRelief2, double TotalTaxRelief3, double TotalTaxRelief4);

#endif