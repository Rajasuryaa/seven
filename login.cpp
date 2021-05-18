#include<iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct login_details
{
	char username[15];
	char password[20];
}us;

char tmp_username[15];
char tmp_password[20];

void registration_form()
{
	cout<<"\tRegistration Form";
	cout<<"\nUSERNAME : "; cin>>us.username; 
	cout<<"PASSWORD : "; cin>>us.password;
	ofstream file ("user.bin", ios::app | ios::binary);
    file.write((char *)&us,sizeof(us));
    file.close();
}


void login_form()
{
	int success;
	success = 0;
  cout<<"\nUSERNAME : "; cin>>tmp_username; 
  cout<<"PASSWORD : "; cin>>tmp_password;
  ifstream f;
  f.open("user.bin",ios::in|ios::binary);
  f.seekg(0);
  while(f.read((char*)&us,sizeof(us)))
  {
  	if(strcmp(tmp_username,us.username)==0 && strcmp(tmp_password,us.password)==0)
  	{
  		cout<<"Succesfully Logged in"<<endl;
  		success++;
  		break;
    }
  }
  if(success < 1)
	   cout<<"Invalid User"<<endl;
  f.close();
}

int main()
{
//registration_form();
login_form();
}
