//Housing
//Nick Robinson

#include "familymgr.h"

familymgr::familymgr()
{
	families = new hashtable();
}

familymgr::~familymgr()
{
	if (families)
		delete families;
}

void familymgr::printAllFamilies()
{
	cout << *families;
}

void familymgr::printGroup(family*)
{

}

void familymgr::printSmallCircle(char* item)
{
	family * fam = families->lookup(item);
	if (fam != nullptr)
	{
		cout << "Print family and immediate friends " << item << endl;
		cout << "== Family ==" << endl;
		cout << *fam << endl;
		cout << "== Friends (1 level) ==" << endl;

		for (int i = 0; i < 3; i++)
		{
			char* famFriend = fam->getFriend(i);
			if (famFriend != nullptr)
			{
				family* famFriendPtr = families->lookup(famFriend);
				if (famFriendPtr != nullptr)
					cout << *famFriendPtr;
			}
		}
	}
}

void familymgr::addFamily(family & fam)
{
	families->insert(fam.getId(), fam);
}

