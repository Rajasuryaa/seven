#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

void orders()
{
	ifstream f1;
	f1.open("temp_bill.txt",ios::in);
	if (f1.is_open())
        cout << f1.rdbuf();
    else
    	cout<<"failed";
	f1.close();
}
//	fstream f8;
//		f8.open("ATTACHMENT.txt",ios::in);
 //	if (f8.is_open())
   //   cout << f8.rdbuf();
      
int main()
{

	void orders();
}
