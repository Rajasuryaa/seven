#include<iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct hotel_details
{
	char hotel[30];
	char item[10][30];
	char street_name[30],dummy[2];
	char area[20];

}hd;

void add_hotel()
{
	cout<<"\tAdd Restaurant"<<endl;
	cout<<"Restaurant Name :"; cin.getline(hd.name,20,'\n');
	cin.getline(hd.dummy,1,'\n');
	cout<<"Street :"; cin.getline(hd.street_name,30,'\n');
	cout<<"Area :";  cin.getline(hd.area,20,'\n');;
	ofstream file ("hotel.bin", ios::app | ios::binary);
    file.write((char *)&hd,sizeof(hd));
    file.close();
}

void add_food()
{
	while(f.read((char*)&hd,sizeof(hd)))
	{
		cout<<hd.hotel<<endl;
	}
	cout<<"\nAdd Food"<<endl;
	while(f.read((char*)&hd,sizeof(hd)))
	{
		
		
	}
}
