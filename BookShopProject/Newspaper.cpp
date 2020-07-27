#include "pch.h"
#include <iostream>
#include<cstring>
#include "Newspaper.h"
using namespace std;

Newspaper::Newspaper() : Newspaper(0, 0, 0, "Default", "Default", 0)
{
}

Newspaper::Newspaper(double pricePerPage, int pages, int issue, const char* name, const char* printDate, int numOfAdvertisements)
	: PrintEdition(pricePerPage, pages, issue, name)
{
	this->setPrintDate(printDate);
	this->setNumOfAdvertisements(numOfAdvertisements);
}

void Newspaper::setPrintDate(const char* printDate)
{
	strcpy_s(this->printDate, strlen(printDate) + 1, printDate);
}

void Newspaper::setNumOfAdvertisements(int numOfAds)
{
	this->numOfAdvertisements = numOfAds;
}

const char* Newspaper::getPrintDate() const
{
	return this->printDate;
}

int Newspaper::getNumOfAdvertisements() const
{
	return this->numOfAdvertisements;
}

double Newspaper::getSellPrice() const
{
	return this->getPrintPrice() + this->numOfAdvertisements * (-0.05);
}

Newspaper* Newspaper::clone() const
{
	return new Newspaper(*this);
}

void Newspaper::showInfo() const
{
	cout << "----------Newspaper----------" << endl;
	cout << "Price per page: " << this->pricePerPage << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Issue: " << this->issue << endl;
	cout << "Name: " << this->name << endl;
	cout << "Print date: " << this->printDate << endl;
	cout << "Number of advertisements: " << this->numOfAdvertisements << endl;
	cout << "Sell price: " << this->getSellPrice() << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
}

