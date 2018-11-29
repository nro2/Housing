//Housing
//Nick Robinson

#ifndef FAMILYMGR_H
#define FAMILYMGR_H

#include <iostream>
#include "hashtable.h"

using namespace std;


class familymgr{

	public:
		familymgr();
		~familymgr();

		void printAllFamilies();
		void printGroup(family *);
		void printSmallCircle(char*);
		void addFamily(family&);

	private:
		hashtable * families;
};

#endif
