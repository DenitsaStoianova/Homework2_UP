#include "pch.h"
#include <cstring>
#include <iostream>
#include "IceCream.h"
using namespace std;

char nameBuffer[200];

IceCream::IceCream(const IceCreamFlavour& flavour, const int& ballsCount, const char* name)
	: name(nullptr)
{
	setFlavour(flavour);
	setBallsCount(ballsCount);
	setName(name);
}

IceCream::IceCream(const IceCream& other) : IceCream(other.flavour, other.ballsCount, other.name)
{
}


IceCream& IceCream::operator=(const IceCream& other)
{
	if (this != &other)
	{
		setFlavour(other.flavour);
		setBallsCount(other.ballsCount);
		setName(other.name);
	}

	return *this;
}

IceCream::~IceCream()
{
	delete[] this->name;
}

void IceCream::setFlavour(const IceCreamFlavour& flavour)
{
	this->flavour = flavour;
}

void IceCream::setBallsCount(const int& ballsCount)
{
	this->ballsCount = ballsCount;
}

void IceCream::setName(const char* name)
{
	if (name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

}

IceCreamFlavour IceCream::getFlavour() const
{
	return this->flavour;
}

int IceCream::getBallsCount() const
{
	return this->ballsCount;
}

const char* IceCream::getName() const
{
	return this->name;
}

double IceCream::getPrice() const
{
	return this->ballsCount * this->flavour.pricePerBall;
}

void IceCream::read()
{
	cout << endl << "Enter ice cream flavour name: ";
	cin.ignore();
	cin.getline(nameBuffer, 200);
	setName(nameBuffer);

	cout << "Enter price per ball: ";
	cin >> flavour.pricePerBall;

	cout << "Enter balls count: ";
	cin >> ballsCount;

	cout << "Enter ice cream name: ";
	cin.ignore();
	cin.getline(name, strlen(name) + 1);
}

void IceCream::print() const
{
	cout << "Flavour name: " << flavour.flavourName << endl;
	cout << "Price per ball: " << flavour.pricePerBall << endl;
	cout << "Balls count: " << ballsCount << endl;
	cout << "Ice cream name: " << name << endl;
	cout << endl;
}

IceCream getIceCreamForChild(IceCream* iceCreams, int size, double pocketMoney)
{
	IceCream bestIceCream;
	int maxIceCreamBalls = iceCreams[0].getBallsCount();
	double maxIceCreamPrice = iceCreams[0].getPrice();

	for (int i = 0; i < size; i++)
	{
		if (iceCreams[i].getPrice() <= pocketMoney)
		{
			if (iceCreams[i].getBallsCount() > maxIceCreamBalls)
			{
				bestIceCream = iceCreams[i];
			}
			else if (iceCreams[i].getBallsCount() == maxIceCreamBalls)
			{
				if (iceCreams[i].getPrice() > bestIceCream.getPrice())
				{
					bestIceCream = iceCreams[i];
				}
			}
		}
	}

	return bestIceCream;
}

void findIceCreams(IceCream* iceCreams, int size, IceCreamFlavour flavour)
{
	cout << endl << "Ice creams with " << flavour.flavourName << " flavour: " << endl;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(iceCreams[i].getFlavour().flavourName, flavour.flavourName) == 0)
		{
			iceCreams[i].print();
		}
	}
}

bool IceCream::operator<(const IceCream& other) const
{
	if (strcmp(this->flavour.flavourName, other.flavour.flavourName) == 0)
	{
		if (this->flavour.pricePerBall == other.flavour.pricePerBall)
		{
			if (this->ballsCount == other.ballsCount)
			{
				return strcmp(this->name, other.name) < 0;
			}
			return this->ballsCount < other.ballsCount;
		}
		return this->flavour.pricePerBall < other.flavour.pricePerBall;
	}
	return strcmp(this->flavour.flavourName, other.flavour.flavourName) < 0;
}

bool IceCream::operator<=(const IceCream& other) const
{
	return !(*this > other);
}

bool IceCream::operator==(const IceCream& other) const
{	 
	if (strcmp(this->flavour.flavourName, other.flavour.flavourName) == 0)
	{
		if (this->flavour.pricePerBall == other.flavour.pricePerBall)
		{
			if (this->ballsCount == other.ballsCount)
			{
				return strcmp(this->name, other.name) == 0;
			}
			return this->ballsCount == other.ballsCount;
		}
		return this->flavour.pricePerBall == other.flavour.pricePerBall;
	}
	return strcmp(this->flavour.flavourName, other.flavour.flavourName) == 0;
}

bool IceCream::operator>=(const IceCream& other) const
{
	return !(*this < other);
}
bool IceCream::operator>(const IceCream& other) const
{
	if (strcmp(this->flavour.flavourName, other.flavour.flavourName) == 0)
	{
		if (this->flavour.pricePerBall == other.flavour.pricePerBall)
		{
			if (this->ballsCount == other.ballsCount)
			{
				return strcmp(this->name, other.name) > 0;
			}
			return this->ballsCount > other.ballsCount;
		}
		return this->flavour.pricePerBall > other.flavour.pricePerBall;
	}
	return strcmp(this->flavour.flavourName, other.flavour.flavourName) > 0;
}

bool IceCream::operator!=(const IceCream& other) const
{
	return !(*this == other);
}
