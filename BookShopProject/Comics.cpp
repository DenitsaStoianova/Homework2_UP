#include "pch.h"
#include <iostream>
#include<cstring>
#include "Comics.h"
using namespace std;

Comics::Comics() : Comics(0, 0, 0, "Default", "Default", "Default", 0)
{
}

Comics::Comics(double pricePerPage, int pages, int issue, const char* name, const char* publishers, const char* language, int yearOfIssue)
	: PrintEdition(pricePerPage, pages, issue, name), publishers(nullptr), language(nullptr)
{
	this->setPublishers(publishers);
	this->setLanguage(language);
	this->setYearOfIssue(yearOfIssue);
}

Comics::Comics(const Comics& other) 
	: Comics(other.pricePerPage, other.pages, other.issue, other.name, other.publishers, other.language, other.yearOfIssue)
{
}

Comics& Comics::operator=(const Comics& other)
{
	if (this != &other)
	{
		PrintEdition::operator=(other);
		this->setPublishers(other.publishers);
		this->setLanguage(other.language);
		this->setYearOfIssue(other.yearOfIssue);
	}
	return *this;
}

Comics::~Comics()
{
	delete[] this->publishers;
	delete[] this->language;
}

void Comics::setPublishers(const char* publishers)
{
	if (publishers != nullptr)
	{
		delete[] this->publishers;
		this->publishers = new char[strlen(publishers) + 1];
		strcpy_s(this->publishers, strlen(publishers) + 1, publishers);
	}
}

void Comics::setLanguage(const char* language)
{
	if (language != nullptr)
	{
		delete[] this->language;
		this->language = new char[strlen(language) + 1];
		strcpy_s(this->language, strlen(language) + 1, language);
	}
}

void Comics::setYearOfIssue(int yearOfIssue)
{
	this->yearOfIssue = yearOfIssue;
}

const char* Comics::getPublishers() const
{
	return this->publishers;
}

const char* Comics::getLanguage() const
{
	return this->language;
}

int Comics::getYearOfIssue() const
{
	return this->yearOfIssue;
}

double Comics::getSellPrice() const
{
	return ((this->yearOfIssue >= 2016) ? this->getPrintPrice() + 10 : this->getPrintPrice());
}

Comics* Comics::clone() const
{
	return new Comics(*this);
}

void Comics::showInfo() const
{
	cout << "----------Comics---------- " << endl;
	cout << "Price per page: " << this->pricePerPage << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Issue: " << this->issue << endl;
	cout << "Name: " << this->name << endl;
	cout << "Publishers: " << this->publishers << endl;
	cout << "Language: " << this->language << endl;
	cout << "Year of issue: " << this->yearOfIssue << endl;
	cout << "Sell price: " << this->getSellPrice() << endl;
	cout << "--------------------------" << endl;
	cout << endl;
}



