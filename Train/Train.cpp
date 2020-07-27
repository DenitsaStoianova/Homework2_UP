#include "pch.h"
#include <iostream>
#include <cstring>
#include "Train.h"

Train::Train()
{
}

void Train::addTicket(Ticket* other)
{
	this->tickets.push_back(other);
}

void Train::removeTicket(Ticket* other)
{
	this->tickets.pop_back();
}

void Train::print() const
{
	for (int i = 0; i < this->tickets.size(); i++)
	{
		this->tickets[i]->print();
	}
}



