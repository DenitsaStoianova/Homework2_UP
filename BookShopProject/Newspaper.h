#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "PrintEdition.h"

class Newspaper : public PrintEdition
{
public:
	Newspaper();
	Newspaper(double, int, int, const char*, const char*, int);

	void setPrintDate(const char*);
	void setNumOfAdvertisements(int);

	const char* getPrintDate() const;
	int getNumOfAdvertisements() const;

	double getSellPrice() const;

	void showInfo() const;

	Newspaper* clone() const;

private:
	char printDate[11];
	int numOfAdvertisements;
};


#endif