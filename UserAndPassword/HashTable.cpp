#include "Hashtable.h"
#include "User.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
#define INTSIZE 23
using namespace std;


Hashtable::Hashtable(int size)// definition for Hashtable
{
	create(size);
}
void Hashtable::create(int size)// definition for create
{
	this->size = size;
	table = new User * [size];
	for (int i = 0; i < size; i++)
	{
		table[i] = nullptr;
	}
	num = 0;
}
bool Hashtable::add(string userid, string pwd)// definition for add
{
	int found = find(userid);
	if (found >= 0)
	{
		return false;
	}
	if (num == size)
	{
		resize(2 * size);
	}
	size_t index = hash(userid);
	while (table[index] != nullptr)
	{
		index = (index + 1) % size;
	}
	++num;
	table[index] = new User(userid, pwd);
	return true;
}
bool Hashtable::add(User* user)// definition for add
{
	int found = find(user->getid());
	if (found >= 0)
	{
		return false;
	}
	if (num == size)
	{
		resize(2 * size);
	}
	size_t index = hash(user->getid());
	while (table[index] != nullptr)
	{
		index = (index + 1) % size;
	}
	++num;
	table[index] = user;
	return true;
}
int Hashtable::find(string userid)// definition for find
{
	size_t index = hash(userid);
	int count = 0;

	while (table[index] != nullptr && table[index]->getid() != userid)
	{
		index = (index + 1) % size;
		count++;
		if (count == size)
		{
			return -1;
		}
	}
	if (table[index] == nullptr)
	{
		return -1;
	}
	return index;
}

void Hashtable::resize(size_t newsize)// definition for resize
{
	User** oldtable = table;
	int oldsize = size;
	int oldnum = num;
	create(newsize);

	for (int i = 0; i < oldsize; i++)
	{
		if (oldtable[i] != nullptr)
		{
			add(oldtable[i]);
		}
	}
	delete[] oldtable;
}

void Hashtable::printheader(ostream& os) const// definition for printheader
{
	os << setw(10) << " " << setw(10) << left << "mod" << setw(10) << left << "userid" << setw(20) << left << "home Dir"
		<< setw(10) << right << "Pwd" << endl;
}

void Hashtable::readpwd(istream& in)// definition for readpwd
{
	string tmp;
	while (in.good())
	{

		User* user = new User(in);
		getline(in, tmp);
		add(user);
	}
}

void Hashtable::savepwd(ostream& out)// definition for savepwd
{
	string tmp;
	for (size_t i = 0; i < size; i++)
	{
		if (table[i] != nullptr)
		{
			table[i]->savepwd(out);
			out << endl;
		}

	}
}


bool Hashtable::changehome(string userid, string homedir)// definition for changehome
{
	size_t index = find(userid);
	if (index < 0)
	{
		return false;
	}
	table[index]->changehome(homedir);
}
bool Hashtable::changepwd(string userid, string pwd)// definition for changepwd
{
	size_t index = find(userid);
	if (index < 0)
	{
		return false;
	}
	table[index]->changepwd(pwd);
}
bool Hashtable::verify(string userid, string pwd)// definition for verify
{
	size_t index = find(userid);
	if (index < 0)
	{
		return false;
	}
	return (table[index]->getpwd() == pwd);
}
bool Hashtable::remove(string userid)// definition for remove
{
	size_t index = find(userid);
	if (index < 0)
	{
		return false;
	}
	delete table[index];
	table[index] = nullptr;
}
void Hashtable::clear()// definition for clear
{
	for (size_t i = 0; i < size; i++)
	{
		if (table[i] != nullptr)
		{
			delete table[i];
		}

	}
	delete[] table;
	create(INTSIZE);
}
void Hashtable::printuser(string userid)// definition for printuser
{
	size_t index = find(userid);
	if (index < 0)
	{
		cout << userid << " not found." << endl;
	}
	else
	{
		cout << "That user was found." << endl;
		cout << endl;
		printheader(cout);
		cout << *table[index] << endl;
	}
}
size_t Hashtable::hash(string key)// definition for hash
{
	size_t sum = 0;
	for (size_t i = 0; i < key.size(); i++)
	{
		sum += (size_t)key[i];
	}
	return sum % size;
}
