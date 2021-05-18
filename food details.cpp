#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;

class food
{
	public:	
		char hotel[20];
		char food_name[20],dummy[2];
		int price;
		int time;
		food select(char[],int);
}fd;

void add_food()
{
//	cout<<"Hotel : "; cin.getline(fd.hotel,20,'\n');
	//fstream file ("food.dat", ios::out|ios::binary);
	//file.seekg(9*sizeof(fd));
	strcpy(fd.hotel,"Cockaraco");
	
	cout<<"Food Name :";  cin.getline(fd.food_name,20,'\n');
	cout<<"Price : "; cin>>fd.price;
	cin.getline(fd.dummy,3,'\n');
	cout<<"Time :"	; cin>>fd.time;
	fstream file ("food.dat", ios::app|ios::binary);
    file.write((char *)&fd,sizeof(fd));
    file.close();
}

void read_food()
{
  ifstream f;
  f.open("food.dat",ios::in|ios::binary);
  f.seekg(0);
  while(f.read((char*)&fd,sizeof(fd)))
  {
  	
  	cout<<"Food : "<<fd.food_name<<endl;
  	cout<<"Price : "<<fd.price<<endl;
  	cout<<"Hotel : "<<fd.hotel<<endl;
  	cout<<"Time : "<<fd.time<<endl;
  }
  f.close();
}

int hotel_food(char hotel[])
{
	system("cls");
  cout<<"Hotel "<<hotel<<"\nMenu";	
  ifstream f;
  f.open("food.dat",ios::in|ios::binary);
  f.seekg(0); 
  cout<<endl;
  cout<<"S.no\tFood\t\tPrice\tPrep Time"<<endl;
  int i=1,z=0,c=0;
  			HANDLE  hConsole;
  			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  			SetConsoleTextAttribute(hConsole, 11);
  while(f.read((char*)&fd,sizeof(fd)))
  {
  	if(strcmp(hotel,fd.hotel) == 0)
  	{
  	//	cout<<"Food : "<<fd.food_name;
  	//	cout<<"\t\tPrice : "<<fd.price<<"Rs";
  	//	cout<<"Hotel : "<<fd.hotel<<endl;
  	//	cout<<"\tTime : "<<fd.time<<"Minutes"<<endl;
			z++; c++;
			cout<<i++<<"\t"<<fd.food_name;
  			cout<<"\t"<<fd.price<<"Rs";
  			cout<<"\t"<<fd.time<<"Minutes"<<endl;
  			
    }
    else
    	//i=0;
    if(strcmp(hotel,fd.hotel) == 0)
    	++i;
    }
    if(c==0)
    {
    	cout<<"\nHotel not found !";
	}
  f.close();
  return(z);	
}

food select(char hotel[],char food[])
{
	ifstream f;
	int z=0,s;
	f.open("food.dat",ios::in|ios::binary);
	while(f.read((char*)&fd,sizeof(fd)))
	{
  		if(strcmp(hotel,fd.hotel) == 0 && strcmp(food,fd.food_name) == 0)
  		{
		cout<<"\t"<<fd.food_name;
  		cout<<"\t"<<fd.price<<"Rs";
  		cout<<"\t"<<fd.time<<"Minutes"<<endl;
  		z++;
   		}
   		if(z!=0)
   		{
   			cout<<"Place The Order? (0/1) :"; cin>>s;
  			if(s==1)
  				return fd;
  			else
  				hotel_food(hotel);
  		}
   	}
   		HANDLE  hConsole;
  			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  			SetConsoleTextAttribute(hConsole, 10);
   		
  		if(z==0)
  		{
  			fd.price = 0;
  			return fd;
		  }
 
}
void replace()
{
	FILE *g;
	g = fopen("foodre.dat", "r+b");

// While we can read one structure
while (fread(&fd, sizeof(fd), 1, g) == 1)
{
	cout<<"Food Name :";  cin.getline(fd.food_name,20,'\n');
	cout<<"Price : "; cin>>fd.price;
	cin.getline(fd.dummy,3,'\n');
	cout<<"Time :"	; cin>>fd.time;
    // Your code to update the structure...
    // Seek backwards in the file from the current position
    // So when we write we will overwrite the structure we just read
 //   fseek(g, -sizeof(fd), SEEK_END);
		
    // Write out the structure again, overwriting the previous data
    fwrite(&fd, sizeof(fd), 1, g);
}
}
/*
int main()
{

	int c;
	char dummy[3];
	for(int i=0;i<10;i++)
	{
		add_food();
		cin.getline(dummy,1,'\n');
	}
}
/*
//	read_food();
	char hot[30];
	cout<<"\nEnter Hotel Name :"; cin>>hot;
//	hotel_food(hot);
select(hot,"Butter Naan");
}
*/
