#include "pch.h"
#include <iostream>
#include<cstring>
#include "PrintEdition.h"
using namespace std;

PrintEdition::PrintEdition() : PrintEdition(0, 0, 0, "Default")
{
}

PrintEdition::PrintEdition(double pricePerPage, int pages, int issue, const char* name) : name(nullptr)
{
	this->setPricePerPage(pricePerPage);
	this->setPages(pages);
	this->setIssue(issue);
	this->setName(name);
}

PrintEdition::PrintEdition(const PrintEdition& other) : PrintEdition(other.pricePerPage, other.pages, other.issue, other.name)
{
}

PrintEdition& PrintEdition::operator=(const PrintEdition& other)
{
	if (this != &other)
	{
		this->setPricePerPage(other.pricePerPage);
		this->setPages(other.pages);
		this->setIssue(other.issue);
		this->setName(other.name);
	}
	return *this;
}

PrintEdition::~PrintEdition()
{
	delete[] this->name;
}

void PrintEdition::setPricePerPage(double pricePerPage)
{
	this->pricePerPage = pricePerPage;
}

void PrintEdition::setPages(int pages)
{
	this->pages = pages;
}

void PrintEdition::setIssue(int issue)
{
	this->issue = issue;
}

void PrintEdition::setName(const char* name)
{
	if (name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}

double PrintEdition::getPricePerPage() const
{
	return this->pricePerPage;
}

int PrintEdition::getPages() const
{
	return this->pages;
}

int PrintEdition::getIssue() const
{
	return this->issue;
}

const char* PrintEdition::getName() const
{
	return this->name;
}

double PrintEdition::getPrintPrice() const
{
	return this->pricePerPage * this->pages;
}

bool PrintEdition::operator==(const PrintEdition& other) const
{
	return strcmp(this->name, other.name) == 0;
}
