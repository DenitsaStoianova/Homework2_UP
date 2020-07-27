#ifndef PRINTEDITION_H
#define PRINTEDITION_H

class PrintEdition
{
public:
	PrintEdition();
	PrintEdition(double, int, int, const char*);
	PrintEdition(const PrintEdition&);
	PrintEdition& operator=(const PrintEdition&);
	virtual ~PrintEdition();

	void setPricePerPage(double);
	void setPages(int);
	void setIssue(int);
	void setName(const char*);

	double getPricePerPage() const;
	int getPages() const;
	int getIssue() const;
	const char* getName() const;

	virtual double getSellPrice() const = 0;
	double getPrintPrice() const;

	virtual void showInfo() const = 0;

	virtual PrintEdition* clone() const = 0;

	bool operator==(const PrintEdition&) const;

protected:
	double pricePerPage;
	int pages;
	int issue;
	char* name;
};


#endif