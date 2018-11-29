//Housing
//Nick Robinson

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

#ifndef FAMILY_H
#define FAMILY_H



const int MAX_SIZE = 3;

class family{

	private:
	char* familyID;
	char* familyName;
	int members;
	char* friends;
	int numOfFriends;
	char ** arr;
	

	public:

	family(const char[], const char[], int);
	family(const family& aFamily);
	family();
	~family();
	
	const family& operator=(const family& aFamily);
	friend ostream& operator<<(ostream& out, const family &fam);

	void setFamilyID(const char[]);
	void setFamilyName(const char[]);
	void setMembers(int);
	bool addFriend(const char *);

	char* getId() const;
	char* getFamilyName() const;
	int getMembers() const;
	char* getFriend(int) const;
	void getFriends(ostream & out);
	
};

bool operator== (const family& d1, const family& d2);

#endif

	
