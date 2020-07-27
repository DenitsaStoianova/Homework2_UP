#ifndef ICE_CREAM_H_INCLUDED
#define ICE_CREAM_H_INCLUDED

#include "IceCreamFlavour.h"

class IceCream
{
public:
	IceCream(const IceCreamFlavour& = IceCreamFlavour(), const int& = 0, const char* = "Default");
	IceCream(const IceCream& other);
	IceCream& operator=(const IceCream& other);
	~IceCream();

	void setFlavour(const IceCreamFlavour&);
	void setBallsCount(const int&);
	void setName(const char*);

	IceCreamFlavour getFlavour() const;
	int getBallsCount() const;
	const char* getName() const;

	double getPrice() const;

	void read();
	void print() const;

	bool operator<(const IceCream& other) const;
	bool operator<=(const IceCream& other) const;
	bool operator==(const IceCream& other) const;
	bool operator>=(const IceCream& other) const;
	bool operator>(const IceCream& other) const;
	bool operator!=(const IceCream& other) const;


private:
	IceCreamFlavour flavour;
	int ballsCount;
	char* name;
};








#endif