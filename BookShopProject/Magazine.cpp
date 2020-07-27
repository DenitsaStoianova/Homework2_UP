#include "pch.h"
#include <iostream>
#include<cstring>
#include "Magazine.h"
using namespace std;

Magazine::Magazine() : Magazine(0, 0, 0, "Default", true, 0)
{
}

Magazine::Magazine(double pricePerPage, int pages, int issue, const char* name, bool hasPosters, int numberOfInterviews)
	: PrintEdition(pricePerPage, pages, issue, name)
{
	this->setPosters(hasPosters);
	this->setNumOfInterviews(numberOfInterviews);
}

void Magazine::setPosters(bool posters)
{
	this->hasPosters = posters;
}

void Magazine::setNumOfInterviews(int num)
{
	this->numberOfInterviews = num;
}

bool Magazine::getPosters() const
{
	return this->hasPosters;
}

int Magazine::getNumOfInterviews() const
{
	return this->numberOfInterviews;
}

double Magazine::getSellPrice() const
{
	return ((this->hasPosters) ? this->getPrintPrice() + 1.50 : this->getPrintPrice()) + this->numberOfInterviews * 1;
}

Magazine* Magazine::clone() const
{
	return new Magazine(*this);
}

void Magazine::showInfo() const
{
	cout << "----------Magazine---------- " << endl;
	cout << "Price per page: " << this->pricePerPage << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Issue: " << this->issue << endl;
	cout << "Name: " << this->name << endl;
	cout << "Has posters: " << ((this->hasPosters) ? "Yes" : "No") << endl;
	cout << "Number of interviews: " << this->numberOfInterviews << endl;
	cout << "Sell price: " << this->getSellPrice() << endl;
	cout << "----------------------------" << endl;
	cout << endl;
}