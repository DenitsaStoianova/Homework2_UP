#ifndef COMICS_H
#define COMICS_H

#include "PrintEdition.h"

class Comics : public PrintEdition
{
public:
	Comics();
	Comics(double, int, int, const char*, const char*, const char*, int);
	Comics(const Comics&);
	Comics& operator=(const Comics&);
	~Comics();

	void setPublishers(const char*);
	void setLanguage(const char*);
	void setYearOfIssue(int);

	const char* getPublishers() const;
	const char* getLanguage() const;
	int getYearOfIssue() const;

	double getSellPrice() const;

	void showInfo() const;

	Comics* clone() const;

private:
	char* publishers;
	char* language;
	int yearOfIssue;
};



#endif