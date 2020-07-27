#ifndef BOOHSHOP_H
#define BOOKSHOP_H

#include "PrintEdition.h"

class BookShop
{
public:
	BookShop();
	BookShop(const char*, const char*, int capacity);
	BookShop(const BookShop&);
	BookShop& operator=(const BookShop&);
	~BookShop();

	void setName(const char*);
	void setLocation(const char*);

	const char* getName() const;
	const char* getLocation() const;
	int getCapacity() const;
	int getSize() const;

	void addPrintEdition(const PrintEdition&);
	void removePrintEdition(const PrintEdition&);
	
	void showEditions() const;
	void sort(bool(*comparator)(PrintEdition* printEdition1, PrintEdition* printEdition2));

	double getTotalPrice() const;
	PrintEdition& getExtreme(bool(*comparator)(PrintEdition* printEdition1, PrintEdition* printEdition2)) const;

	bool isFull() const;
	bool hasEdition(const char*) const;

private:
	char* name;
	char* location;
	PrintEdition** printEditions;
	int size;
	int capacity;

	void copy(const BookShop&);
	void del();
	void resizeUp();
	void resizeDown();

};




#endif