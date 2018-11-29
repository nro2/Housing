//Housing
//Nick Robinson

#include "hashtable.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include "family.h"

using namespace std;

hashtable::hashtable()
{
	size = 0;
	capacity = DEFAULT_CAPACITY;
	table = new  Node *[capacity];

	for (int i = 0; i < capacity; i++)
	{
		table[i] = nullptr;
	}
}

hashtable::hashtable(int tSize)
{
	size = 0;
	capacity = tSize;
	table = new Node *[capacity];

	for (int i = 0; i < capacity; i++)
	{
		table[i] = nullptr;
	}
}

hashtable::hashtable(const hashtable& otherTab) :capacity(otherTab.capacity), size(otherTab.size)
{
	table = new Node*[capacity];

	int i;
	for (i = 0; i < capacity; i++)
	{
		if (otherTab.table[i] == nullptr)
		{
			table[i] = nullptr;
		}
		else
		{
			table[i] = new Node(otherTab.table[i]->item);

			Node * source = otherTab.table[i]->next;
			Node * destination = table[i];
			while (source)
			{
				destination->next = new Node(source->item);
				destination = destination->next;
				source = source->next;
			}
			destination->next = nullptr;
		}
	}
}

const hashtable& hashtable::operator=(const hashtable&otherTab)
{
	if (this != &otherTab)
	{
		destroyTable();

		table = new Node*[capacity];
		capacity = otherTab.capacity;
		size = otherTab.size;

		int i;
		for (i = 0; i < capacity; i++)
		{
			if (otherTab.table[i] == nullptr)
			{
				table[i] = nullptr;
			}
			else
			{
				table[i] = new Node(otherTab.table[i]->item);

				Node * source = otherTab.table[i]->next;
				Node * destination = table[i];
				while (source)
				{
					destination->next = new Node(source->item);
					destination = destination->next;
					source = source->next;
				}
				destination->next = nullptr;
			}
		}
	}
	return *this;
}

void hashtable::destroyTable()
{
	for (int i = 0; i < capacity; i++)
	{
		Node * head = table[i];
		Node * curr;
		while (head)
		{
			curr = head->next;
			head->next = nullptr;
			delete head;
			head = curr;
		}
	}
	delete[] table;
}

hashtable::~hashtable()
{
	destroyTable();
}

void hashtable::insert(char const* const key, const family& aFamily)
{
	size_t index = hashstr(key);

	Node * newNode = new Node(aFamily);

	newNode->next = table[index];
	table[index] = newNode;
	size++;
}

family * hashtable::lookup(char * key)const
{
	size_t index = hashstr(key);

	Node * curr = table[index];
	family * ret = nullptr;

	while (curr)
	{
		if (curr->item.getId())
		{
			char * temp = new char[strlen(curr->item.getId()) + 1];
			strcpy(temp, curr->item.getId());

			if (strcmp(key, temp) == 0)
			{
				delete [] temp;
				ret = &curr->item;
				curr = nullptr;
			}
			else
			{
				delete [] temp;
				curr = curr->next;
			}
		}
	}
	return ret;
}

ostream & operator<<(ostream& out, hashtable& ht)
{
	hashtable::Node * curr;

	for (int i = 0; i < ht.capacity; i++)
	{
		out << "table[" << i << "]:" << endl;
		out << "List:" << endl;

		for (curr = ht.table[i]; curr; curr = curr->next)
		{
			out << curr->item;
		}

		out << setw(20) << right << setfill('-') << "" << endl;

	}
	return out;
}

size_t hashtable::hashstr(char const * key) const
{
	size_t index = key[0];
	size_t length = strlen(key);

	for (size_t i = 1; i < length; i++)
	{
		index = (index * 32) + (int)key[i];
	}

	return index % capacity;

}

int hashtable::getSize() const
{
	return size;
}

void hashtable::dumpTable()
{
	for (int i = 0; i < capacity; i++)
	{
		for (Node * curr = table[i]; curr; curr = curr->next)
		{
			cout << curr->item << endl;
		}
	}
}
