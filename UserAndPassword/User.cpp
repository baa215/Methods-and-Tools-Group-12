#include "User.h"
using namespace std;



User::User() : userid(""), pwd("") // definition for User
{
	modify = false;
}
User::User(string userid, string pwd) : userid(userid), pwd(pwd) // definition for User
{
	direct = "/users/" + userid;
	modify = false;
}
User::User(istream& in) // definition for User
{
	string mod;
	in >> mod;
	modify = (mod == "M");
	in >> userid;
	in >> pwd;
	in >> direct;
}

void User::savepwd(ostream& out)// definition for savepwd
{
	if (modify)
	{
		out << "M" << "\t";
	}
	else
	{
		out << "N" << "\t";
	}
	out << userid << "\t" << pwd << "\t" << direct << "\t";
}

string User::getid()// definition for getid
{
	return userid;
}
void User::changehome(string homedir)// definition for changehome
{
	direct = homedir;
	modify = true;
}
void User::changepwd(string pwd)// definition for changepwd
{
	this->pwd = pwd;
	modify = true;
}
string User::getpwd()// definition for getpwd
{
	return pwd;
}
bool User::ismodified()// definition for ismodified
{
	return modify;
}

