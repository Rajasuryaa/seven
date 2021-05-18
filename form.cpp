#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<cstdio>
#include "avlhotel7G.cpp"
#include "food details.cpp"
#include "temp1.cpp"

#include <windows.h>
#include<queue>
int total=0,ch=0;
queue <food> bill,bile;


struct login
{
	char username[15];
	char password[20];
	char email[30];
}u;


void boot()
{
//	themeboot();
	system("cls");
   	cout<<"\n\n\n\n\t\t\t\t";
    Sleep(1000);
	cout<<"S";
	Sleep(1000);
	cout<<"e";
	Sleep(1000);
	cout<<"7";
	Sleep(1000);
	cout<<"e";	
	Sleep(1000);
	cout<<"N"<<endl;
	Sleep(1000);

	
}
void title()
{
	system("cls");
	HANDLE  hConsole;
  			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 	SetConsoleTextAttribute(hConsole, 14);
	cout<<"\t\t\tSe7eN\n";
//	HANDLE  hConsole;
  //			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  			SetConsoleTextAttribute(hConsole, 11);
	if(total>0)
		cout<<"Total:"<<total<<endl;
		SetConsoleTextAttribute(hConsole, 10);
 /*   cout<<"\t\t\t\t";
    Sleep(1000);
	cout<<"S";
	Sleep(1000);
	cout<<"e";
	Sleep(1000);
	cout<<"7";
	Sleep(1000);
	cout<<"e";	
	Sleep(1000);
	cout<<"N"<<endl;
	Sleep(1000);
	*/	
}

void bill_gen();
void bile_gen();
void form()
{	
//	theme();
	star:
do{	
	
	title();
	
	//system("COLOR 2");
	cout<<"Restaurants :"<<endl;
	node *root;
	root = readf();
	disp_hotels(root);
	char hotel[30],dummy[1];
//	cout<<"<Press Enter to continue>";
	cin.getline(dummy,1);
	cout<<"Where to order? (Restaurant Name) :";
	cin.getline(hotel,30,'\n');
	mid:
	title();
			HANDLE  hConsole;
  			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	  if(hotel_food(hotel)==0)
  		{
    	cout<<"\n***No Data Available***\n";
    	Sleep(3000);
    	goto star;
    	}

	 	SetConsoleTextAttribute(hConsole, 10);
	char order[20];
	cout<<"<Press Enter to continue>";
	cin.getline(dummy,1);
	cout<<"What Do you Need? (Name The Food) :";
	cin.getline(order,20,'\n');
	
	food fd;
	//bill
		SetConsoleTextAttribute(hConsole, 11);
	fd = select(hotel,order);
		SetConsoleTextAttribute(hConsole, 10);
		if(fd.price == 0)
			goto mid;
	int qty;
	cout<<"Quantity :";
	cin>>qty;
	
	
	
	for(int i=0;i<qty;i++)
	{
		bill.push(fd); bile.push(fd);
		total = total+fd.price;
	}
	SetConsoleTextAttribute(hConsole, 14);
	cout<<"\nTotal Amount :"<<total<<"Rs"<<endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout<<"Finalise? (0/1) :";
	cin>>ch;
}while(ch!=1);
	bill_gen();
	bile_gen();
	
	
}



void bill_gen()
{
	int i=1;

	ofstream f,f7;
	f.open("history.dat",ios::out | ios::app);
		f7.open("temp_bill.txt",ios::out| ios::app);
	system("cls");
	cout<<"\t\t\t\tSe7eN"<<endl;
		cout<<"\nBill Details\n"<<endl;
		food fd;
		cout<<"S.no\tFood\t\tPrice\tPrep Time\tHotel Name"<<endl;
		f7<<"\nS.no\tFood\t\tPrice\tPrep Time\tHotel Name"<<endl;
		HANDLE  hConsole;
  			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 11);
	while(!bill.empty())
	{
		fd = bill.front();
		cout<<i++<<"\t"<<fd.food_name;
			f7<<fd.hotel<<"\t";
		f<<fd.hotel<<endl;////////////////////
		
			f7<<fd.food_name<<"\t";
		f<<fd.food_name<<endl;//////////////////
		
			f7<<fd.price<<"Rs"<<endl;
  		cout<<"\t"<<fd.price<<"Rs";

  		f<<fd.price<<"Rs"<<endl;//////////////////
  		cout<<"\t"<<fd.time<<"Minutes";

	//	f<<fd.time<<"Minutes"<<endl;//////////////////
		//	f7<<total<<endl;
		cout<<"\t"<<fd.hotel<<endl;


  		bill.pop();
	}
	f<<"END"<<endl;
//	f7<<"END"<<endl;
		SetConsoleTextAttribute(hConsole, 10);
	cout<<"\nTotal Amount		"<<total<<"Rs";
	f<<total<<"Rs"<<endl;
	f7<<total<<"Rs"<<endl;

	char c[1];
	cout<<"\n<Press Any Key To Confirm>";
	cin.getline(c,10,'\n');
	cin.getline(c,10,'\n');
	
}

void bile_gen()
{
	ofstream f2;
	f2.open("ATTACHMENT.txt",ios::out);

	food fd;
	f2<<"Se7eN - Food Delivery App"<<endl<<"The Following order has been placed"<<endl;
	while(!bile.empty())
	{
		fd = bile.front();
		f2<<"Hotel : "<<fd.hotel<<endl;
		
	
		f2<<"Food : "<<fd.food_name<<endl;;
		
	
  		f2<<"Price : "<<fd.price<<"Rs"<<endl;
  		
  	
  		bile.pop();
	}
	f2<<"Total : "<<total<<"Rs"<<endl<<"Thanks For Ordering! See you Again";

	
	f2.close();
	ifstream f3;
	char email[100];
    f3.open("temp1.txt",ios::in);
	f3>>email;
	cout<<"Placing Order";
	for(int i=0 ; i<5; i++)
	{
		Sleep(1000);
		cout<<".";
	}
	bee(email);
	Sleep(7000);
	form();
}

void history()
{
	HANDLE  hConsole;
  			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char str[20];
	ifstream f2;
	f2.open("history.dat",ios::in);
  	f2.seekg(0);
 	while(f2>>str)
   {
   	
   		SetConsoleTextAttribute(hConsole, 169);
  	cout<<"\nUser : "<<str<<endl;
//	f2.getline(str,30,'\n');
			SetConsoleTextAttribute(hConsole, 14);
 	f2>>str;

  	while(strcmp(str,"END")!=0)
	{
	  cout<<"Hotel : "<<str<<endl;
 	//	f2>>str;
 		f2.getline(str,30,'\n');
 		f2.getline(str,30,'\n');
 		//f2>>str;
 	//	fgets (str , 100 , f2);
  //		f2.getline(str,20,',');
		cout<<"Food : "<<str<<endl;
		//f2.getline(str,30,'\n');
		f2>>str;
		cout<<"Price : "<<str<<endl;
	//	f2.getline(str,30,'\n');
		f2>>str;
    }
  	f2>>str;
	cout<<"Total : "<<str<<endl;
}
  f2.close();
  
}







