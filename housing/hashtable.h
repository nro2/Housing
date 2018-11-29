//Housing
//Nick Robinson

#include <iostream>
#include <cstring>
#include "family.h"
#include <iomanip>


#ifndef HASHTABLE_H
#define HASHTABLE_H


class hashtable{

	private:
		struct Node
		{
				
			Node(const family& aFamily)
			{
				item = aFamily;
				next = nullptr;
			}

			family item;
			Node * next;
		};

		Node ** table;
		int capacity;
		int size;
		const size_t DEFAULT_CAPACITY = 7877;
		void destroyTable();
		size_t hashstr(char const * const key) const;


	public:
		hashtable();
		hashtable(int);
		hashtable(const hashtable& otherTab);
		~hashtable();

		const hashtable& operator=(const hashtable& otherTab);

		void insert(char const * const key, const family& aFamily);
		family * lookup(char *)const;
		int getSize()const;
		void dumpTable();

		friend ostream& operator<<(ostream& out, hashtable& ht);
};

#endif
