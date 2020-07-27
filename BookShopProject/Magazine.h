#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "PrintEdition.h"

class Magazine : public PrintEdition
{
public:
	Magazine();
	Magazine(double, int, int, const char*, bool, int);

	void setPosters(bool);
	void setNumOfInterviews(int);

	bool getPosters() const;
	int getNumOfInterviews() const;

	double getSellPrice() const;

	void showInfo() const;

	Magazine* clone() const;

private:
	bool hasPosters;
	int numberOfInterviews;
};

#endif