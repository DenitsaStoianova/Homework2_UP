#ifndef TRAIN_H
#define TRAIN_H

#include <vector>
#include "Ticket.h"
using namespace std;

class Train
{
private:
	vector<Ticket* > tickets;
public:
	Train();
	
	void removeTicket(Ticket*);
	void addTicket(Ticket*);
	
	void print() const;
};


#endif