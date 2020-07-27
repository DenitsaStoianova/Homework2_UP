#include "pch.h"
#include<iostream>
#include<cstring>
#include "BookShop.h"
using namespace std;

BookShop::BookShop() : BookShop("Default", "Default", 4)
{
}

BookShop::BookShop(const char* name, const char* location, int capacity) : name(nullptr), location(nullptr)
{
	this->setName(name);
	this->setLocation(location);
	this->size = 0;
	this->capacity = (capacity >= 4) ? capacity : 4;
	this->printEditions = new PrintEdition*[this->capacity];
}

BookShop::BookShop(const BookShop& other) : name(nullptr), location(nullptr)
{
	this->setName(other.name);
	this->setLocation(other.location);
	this->copy(other);
}

BookShop& BookShop::operator=(const BookShop& other)
{
	if (this != &other)
	{
		this->setName(other.name);
		this->setLocation(other.location);
		this->del();
		this->copy(other);
	}
	return *this;
}

BookShop::~BookShop()
{
	delete[] this->name;
	delete[] this->location;
	this->del();
}

void BookShop::copy(const BookShop& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->printEditions = new PrintEdition*[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->printEditions[i] = other.printEditions[i]->clone();
	}
}

void BookShop::del()
{
	for (int i = 0; i < this->size; i++)
	{
		delete this->printEditions[i];
	}
	delete[] this->printEditions;
}

void BookShop::resizeUp()
{
	this->capacity *= 2;
	PrintEdition** temp = new PrintEdition*[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->printEditions[i];
	}
	delete[] this->printEditions;
	this->printEditions = temp;
}


void BookShop::resizeDown()
{
	this->capacity /= 2;
	PrintEdition** temp = new PrintEdition*[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->printEditions[i];
	}
	delete[] this->printEditions;
	this->printEditions = temp;
}

void BookShop::setName(const char* name)
{
	if (name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}

void BookShop::setLocation(const char* location)
{
	if (location != nullptr)
	{
		delete[] this->location;
		this->location = new char[strlen(location) + 1];
		strcpy_s(this->location, strlen(location) + 1, location);
	}
}

const char* BookShop::getName() const
{
	return this->name;
}

const char* BookShop::getLocation() const
{
	return this->location;
}

int BookShop::getCapacity() const
{
	return this->capacity;
}

int BookShop::getSize() const
{
	return this->size;
}

bool BookShop::hasEdition(const char* name) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (strcmp(this->printEditions[i]->getName(), name) == 0)
		{
			return true;
		}
	}
	return false;
}

void BookShop::addPrintEdition(const PrintEdition& printEdition)
{
	if (this->hasEdition(printEdition.getName()))
	{
		return;
	}

	if (this->isFull())
	{
		this->resizeUp();
	}

	this->printEditions[this->size++] = printEdition.clone();
}

void BookShop::removePrintEdition(const PrintEdition& printEdition)
{
	for (int i = 0; i < this->size; i++)
	{
		if (*(this->printEditions[i]) == printEdition)
		{
			delete this->printEditions[i];

			this->printEditions[i] = this->printEditions[this->size - 1];
			this->size--;

			if (this->size < this->capacity / 2)
			{
				this->resizeDown();
			}

			break;
		}
	}
}

void BookShop::sort(bool(*comparator)(PrintEdition* printEdition1, PrintEdition* printEdition2))
{
	for (int i = 0; i < this->size - 1; i++)
	{
		for (int j = i + 1; j < this->size; j++)
		{
			if (comparator(this->printEditions[i], this->printEditions[j]))
			{
				swap(this->printEditions[i], this->printEditions[j]);
			}
		}
	}
}

PrintEdition& BookShop::getExtreme(bool(*comparator)(PrintEdition* printEdition1, PrintEdition* printEdition2)) const
{
	PrintEdition* best = this->printEditions[0];
	for (int i = 0; i < this->size - 1; i++)
	{
		for (int j = i + 1; j < this->size; j++)
		{
			if (comparator(this->printEditions[i], best))
			{
				best = this->printEditions[i];
			}
		}
	}
	return *best;
}

void BookShop::showEditions() const
{
	cout << "~~~~~~~~~~~~~~BookShop~~~~~~~~~~~~~~" << endl;
	cout << "                Size: " << this->size << endl;
	cout << "             Capacity: " << this->capacity << endl;
	cout << "          Name: " << this->name << endl;
	cout << "             Location: " << this->location << endl;
	cout << endl;

	for (int i = 0; i < this->size; i++)
	{
		this->printEditions[i]->showInfo();
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
}


double BookShop::getTotalPrice() const
{
	double totalPrice = 0;

	for (int i = 0; i < this->size; i++)
	{
		totalPrice += this->printEditions[i]->getPrintPrice();
	}
	return totalPrice;
}

bool BookShop::isFull() const
{
	return this->size == this->capacity;
}

