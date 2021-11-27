#pragma once
#include "User.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
#define INTSIZE 23

using namespace std;

class Hashtable
{
public:
	Hashtable(int size = INTSIZE);

	void create(int size); // create 

	bool add(string userid, string pwd); // adds information

	bool add(User* user); // also adds information

	int find(string userid);// finds the user

	void resize(size_t newsize);// resizes the hash


	void printheader(ostream& os) const;// prints the hash

	void readpwd(istream& in); // reads password


	void savepwd(ostream& out); // saves password


	friend ostream& operator << (ostream& os, const Hashtable& table) // output operator
	{
		table.printheader(os);
		for (size_t i = 0; i < table.size; i++)
		{
			os << setw(10) << left << i;

			if (table.table[i] != nullptr)
			{
				//os << setw(10);
				if (table.table[i]->ismodified())
				{
					os << setw(10) << left << "M";
				}
				else
				{
					os << setw(10) << left << " ";
				}
				os << *table.table[i];
			}
			os << endl;
		}
		return os;
	}

	bool changehome(string userid, string homedir); // changes home dir

	bool changepwd(string userid, string pwd); // changes password

	bool verify(string userid, string pwd); // verifies user and password

	bool remove(string userid); // removes user and password

	void clear();// clears the hash

	void printuser(string userid);// prinits the user

private:
	size_t size;
	size_t num;
	User** table;

	size_t hash(string key);

};