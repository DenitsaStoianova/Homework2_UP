#include "pch.h"
#include <cstring>
#include <iostream>
#include "IceCreamContainer.h"
using namespace std;

int IceCreamContainer::getCapacity() const
{
	return this->capacity;
}

void IceCreamContainer::copy(const IceCreamContainer& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->iceCreams = new IceCream[other.capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->iceCreams[i] = other.iceCreams[i];
	}
}

void IceCreamContainer::del()
{
	delete[] this->iceCreams;
}

void IceCreamContainer::resize()
{
	this->capacity *= 2;
	IceCream* temp = new IceCream[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->iceCreams[i];
	}
	delete[] this->iceCreams;
	this->iceCreams = temp;
}

void IceCreamContainer::contraction()
{
	this->capacity = this->size;
	IceCream* temp = new IceCream[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->iceCreams[i];
	}
	delete[] this->iceCreams;
	this->iceCreams = temp;
}

IceCreamContainer::IceCreamContainer()
{
	this->size = 0;
	this->capacity = 8;
	this->iceCreams = new IceCream[this->capacity];
}

IceCreamContainer::IceCreamContainer(const IceCream* iceCreams, int size)
{
	this->size = size;
	if (size > 8)
	{
		this->capacity = size;
	}
	else
	{
		this->capacity = 8;
	}
	this->iceCreams = new IceCream[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->iceCreams[i].setFlavour(iceCreams[i].getFlavour());
		this->iceCreams[i].setName(iceCreams[i].getName());
		this->iceCreams[i].setBallsCount(iceCreams[i].getBallsCount());
	}

}

IceCreamContainer::IceCreamContainer(const IceCreamContainer& other)
{
	this->copy(other);
}

IceCreamContainer& IceCreamContainer::operator=(const IceCreamContainer& other)
{
	if (this != &other)
	{
		this->del();
		this->copy(other);
	}
	return *this;
}

IceCreamContainer::~IceCreamContainer()
{
	this->del();
}

void IceCreamContainer::addIceCream(const IceCream& other)
{
	if (this->size == this->capacity)
	{
		this->resize();
	}

	this->iceCreams[this->size++] = other;

	if (this->size * 4 == this->capacity)
	{
		this->contraction();
	}
}

void IceCreamContainer::removeIceCream(const IceCream& other)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->iceCreams[i] == other)
		{
			for (int j = i; j < this->size - 1; j++)
			{
				this->iceCreams[j] = this->iceCreams[j + 1];
			}
			this->size--;
		}
	}

	if (this->size * 4 == this->capacity)
	{
		this->contraction();
	}
}

bool IceCreamContainer::has(const IceCream& other) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->iceCreams[i] == other)
		{
			return true;
		}
	}
	return false;
}

double IceCreamContainer::getPriceOfAllIceCreams() const
{
	double result = 0;
	for (int i = 0; i < this->size; i++)
	{
		result += this->iceCreams[i].getPrice();
	}
	return result;
}

void IceCreamContainer::print() const
{
	cout << "Ice cream container: " << endl;
	for (int i = 0; i < this->size; i++)
	{
		iceCreams[i].print();
	}
}


