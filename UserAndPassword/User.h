#pragma once
#include <string>
#include "User.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
#define INTSIZE 23

using namespace std;

class User
{
public:
	User();

	User(string userid, string pwd);

	User(istream& in);


	void savepwd(ostream& out); // saves the passowrd

	friend ostream& operator << (ostream& os, const User& user) // helps output
	{
		os << setw(10) << left << user.userid << setw(20) << left << user.direct;
		if (user.userid != "")
		{
			os << setw(10) << right << "*";
		}

		return os;
	}
	string getid(); // gets the id

	void changehome(string homedir); // changes home dir

	void changepwd(string pwd);// changes password

	string getpwd(); // gets the password

	bool ismodified(); // tells if the user has been modifiy

private:
	string userid;
	string pwd;
	string direct;
	bool modify;
};