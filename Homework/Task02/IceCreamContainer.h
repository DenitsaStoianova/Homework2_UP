#ifndef ICE_CREAM_CONTAINER_INCLUDED
#define ICE_CREAM_CONTAINER_INCLUDED

#include "IceCream.h"

class IceCreamContainer
{
public:
	IceCreamContainer();
	IceCreamContainer(const IceCream*, int size);
	IceCreamContainer(const IceCreamContainer& other);
	IceCreamContainer& operator=(const IceCreamContainer& other);
	~IceCreamContainer();

	void addIceCream(const IceCream& other);
	void removeIceCream(const IceCream& other);

	bool has(const IceCream& other) const;
	double getPriceOfAllIceCreams() const;

	int getCapacity() const;
	void print() const;

private:
	IceCream* iceCreams;
	int size;
	int capacity;

	void copy(const IceCreamContainer& other);
	void del();
	void resize();
	void contraction();
};


#endif