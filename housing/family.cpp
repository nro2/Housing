//Housing
//Nick Robinson

#include <iostream>
#include <cstring>
#include "family.h"
#include <iomanip>
#pragma warning(disable:4996)

using namespace std;

family::family()
{
	familyID = new char[20];
	setFamilyID("NONE");

	familyName = new char[20];
	setFamilyName("NONE");

	members = 0;
	numOfFriends = 0;
}


family::family(const char famID[], const char famName[], int mem)
{
	familyID = nullptr;
	familyName = nullptr;
	friends = nullptr;
	members = mem;
	numOfFriends = 0;
	setFamilyID(famID);
	setFamilyName(famName);
	setMembers(mem);
	arr = new char*[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr[i] = nullptr;
	}
}

family::family(const family& aFamily) : familyID(nullptr), familyName(nullptr), friends(nullptr), members(0)
{
	setFamilyID(aFamily.familyID);
	setFamilyName(aFamily.familyName);
	setMembers(aFamily.members);
	numOfFriends = aFamily.numOfFriends;
	arr = new char*[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (aFamily.arr[i] != nullptr)
		{
			int len = strlen(aFamily.arr[i]) + 1;
			arr[i] = new char[len];
			strcpy(arr[i], aFamily.arr[i]);
		}
		else
		{
			arr[i] = nullptr;
		}
	}
}

const family& family::operator=(const family& aFamily)
{
	if (this != &aFamily)
	{
		setFamilyID(aFamily.familyID);
		setFamilyName(aFamily.familyName);
		setMembers(aFamily.members);
		numOfFriends = aFamily.numOfFriends;
		arr = new char*[MAX_SIZE];
		for (int i = 0; i < MAX_SIZE; i++)
		{
			if (aFamily.arr[i] != nullptr)
			{
				int len = strlen(aFamily.arr[i]) + 1;
				arr[i] = new char[len];
				strcpy(arr[i], aFamily.arr[i]);
			}
			else
			{
				arr[i] = nullptr;
			}
		}

	}
	return *this;
}

bool operator==(const family& d1, const family& d2)
{
	char * id1;
	char * id2;
	bool ret = false;

	id1 = d1.getId();
	id2 = d2.getId();

	if (strcmp(id1, id2) == 0)
	{
		ret = true;
	}
	return ret;
}

family::~family()
{
	if (familyName)
	{
		delete[] familyName;
	}
	if (familyID)
	{
		delete[] familyID;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (arr[i])
		{
			delete[] arr[i];
		}
	}
	if (arr)
	{
		delete[] arr;
	}
}

void family::setFamilyID(const char famID[])
{
	if (familyID)
	{
		delete[] familyID;
	}

	familyID = new char[strlen(famID) + 1];
	strcpy(familyID, famID);
}

void family::setFamilyName(const char famName[])
{
	if (familyName)
	{
		delete[] familyName;
	}

	familyName = new char[strlen(famName) + 1];
	strcpy(familyName, famName);
}

void family::setMembers(int mem)
{
	members = mem;
}

bool family::addFriend(const char * frnd)
{
	bool check = false;

	if (numOfFriends != MAX_SIZE)
	{
		arr[numOfFriends] = new char[strlen(frnd) + 1];
		strcpy(arr[numOfFriends], frnd);
		numOfFriends++;
		check = true;
	}
	return check;
}

char* family::getId() const
{
	return familyID;
}

char* family::getFamilyName() const
{
	return familyName;
}

int family::getMembers() const
{
	return members;
}

char * family::getFriend(int index) const
{
	return arr[index];
}

void family::getFriends(ostream & out)
{
	for (int i = 0; i < 3; i++)
	{
		if (arr[i])
		{
			out << arr[i] << " ";
		}
	}
}


ostream& operator<<(ostream& out, const family &fam)
{
	out << "Family ID: " << fam.getId() << endl;
	out << "  Name: " << fam.getFamilyName() << endl;
	out << "  Members: " << fam.getMembers() << endl;
	out << "  Friends: ";

	for (int i = 0; i < 3; i++)
	{
		if (fam.arr[i])
		{
			out << fam.arr[i] << " ";
		}
	}
	/*	for(int i = 0; i < MAX_SIZE; i++)
	{
	if(fam.arr[i] != nullptr)
	{
	out << fam.getFriend) << " ";
	}
	}
	*/
	out << endl;
	return out;
}
