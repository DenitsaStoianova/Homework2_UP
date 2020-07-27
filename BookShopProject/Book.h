#ifndef BOOK_H
#define BOOK_H

#include "PrintEdition.h"

class Book : public PrintEdition
{
public:
	Book();
	Book(double, int, int, const char*, const char*, bool, int);
	Book(const Book&);
	Book& operator=(const Book&);
	~Book();

	void setAuthorName(const char*);
	void setHasHardcovers(bool);
	void setYear(int);

	const char* getAuthorName() const;
	bool getHasHardcovers() const;
	int getYear() const;

	double getSellPrice() const;

	void showInfo() const;

	Book* clone() const;

private:
	char* authorName;
	bool hasHardcovers;
	int year;
};

#endif