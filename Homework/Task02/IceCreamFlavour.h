#ifndef ICE_CREAM_FLAVOUR_H_INCLUDED
#define ICE_CREAM_FLAVOUR_H_INCLUDED

#include <cstring>
#include <iostream>

struct IceCreamFlavour
{

	IceCreamFlavour(const char* flavourName = "Default name", double pricePerBall = 0.0)
	{
		strcpy_s(this->flavourName, strlen(flavourName) + 1, flavourName);
		this->pricePerBall = pricePerBall;
	}

	char flavourName[32];
	double pricePerBall;
};

#endif
