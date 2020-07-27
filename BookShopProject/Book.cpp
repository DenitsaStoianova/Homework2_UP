#include "pch.h"
#include <iostream>
#include<cstring>
#include "Book.h"
using namespace std;

Book::Book() : Book(0, 0, 0, "Default", "Default", true, 0)
{
}

Book::Book(double pricePerPage, int pages, int issue, const char* name, const char* authorName, bool hasHardcovers, int year)
	: PrintEdition(pricePerPage, pages, issue, name), authorName(nullptr)
{
	this->setAuthorName(name);
	this->setHasHardcovers(hasHardcovers);
	this->setYear(year);
}

Book::Book(const Book& other)
	: Book(other.pricePerPage, other.pages, other.issue, other.name, other.authorName, other.hasHardcovers, other.year)
{
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		PrintEdition::operator=(other);
		this->setAuthorName(other.authorName);
		this->setHasHardcovers(other.hasHardcovers);
		this->setYear(other.year);
	}
	return *this;
}

Book::~Book()
{
	delete[] this->authorName;
}

void Book::setAuthorName(const char* authorName)
{
	if (authorName != nullptr)
	{
		delete[] this->authorName;
		this->authorName = new char[strlen(authorName) + 1];
		strcpy_s(this->authorName, strlen(authorName) + 1, authorName);
	}
}

void Book::setHasHardcovers(bool hasHardcovers)
{
	this->hasHardcovers = hasHardcovers;
}

void Book::setYear(int year)
{
	this->year = year;
}

const char* Book::getAuthorName() const
{
	return this->authorName;
}

bool Book::getHasHardcovers() const
{
	return this->hasHardcovers;
}

int Book::getYear() const
{
	return this->year;
}

double Book::getSellPrice() const
{
	return ((this->hasHardcovers) ? 5 + this->getPrintPrice() : 2.50 + this->getPrintPrice());
}

Book* Book::clone() const
{
	return new Book(*this);
}

void Book::showInfo() const
{
	cout << "----------Book---------- " << endl;
	cout << "Price per page: " << this->pricePerPage << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Issue: " << this->issue << endl;
	cout << "Name: " << this->name << endl;
	cout << "Author name: " << this->authorName << endl;
	cout << "Has hardcovers: " << ((this->hasHardcovers) ? "Yes" : "No") << endl;
	cout << "Year: " << this->year << endl;
	cout << "Sell price: " << this->getSellPrice() << endl;
	cout << "-------------------------" << endl;
	cout << endl;
}
