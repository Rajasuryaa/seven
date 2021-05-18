#include<iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "email.cpp"
using namespace std;

void thanknote(char[]);
void email(char[]);
void logform();
void tmp();
struct login_details
{
	char username[15];
	char password[20];
	char email[30];
	char mobile_no[11];
	char doorno[5];
	char street_name[30],dummy[2];
	char area[20];
	unsigned int pin_code;
}us;

char tmp_username[15];
string tmp_passwor = "";
char tmp_password[20];

void sleep(unsigned milliseconds)
{
	Sleep(milliseconds);
}
void registration_form()
{
	system("cls");
	cout<<"\tRegistration Form";
	cout<<"\nUSERNAME : "; cin>>us.username; 
	char user[100];
	strcpy(user,us.username);
	cout<<"PASSWORD : "; cin>>us.password;
	cout<<"EMAIL ID : ";cin>>us.email;
	cout<<"Mobile :";  cin>>us.mobile_no;
	cout<<"Door No :"; cin>>us.doorno;
	cin.getline(us.dummy,1,'\n');
	cout<<"Street :"; cin.getline(us.street_name,30,'\n');
	cout<<"Area :";  cin.getline(us.area,20,'\n');
	cout<<"Pincode :"; cin>>us.pin_code;
	
	
	ofstream file ("user.bin", ios::out | ios::app);
    file.write((char *)&us,sizeof(us));
    file.close();
    
    ofstream b ;
		b.open("LoggedTemp.txt",ios::out);
		b.write((char *)&us,sizeof(us));
    	b.close();
    


	thanknote(user);
//    eee(us.email);
    cout<<"Succesfully Registered"<<endl<<"Sending Email!"<<endl;
    eee(us.email);
    	sleep(7000);
    logform();
}


int login_form()
{
	int success;
	success = 0;
	system("cls");
  cout<<"\nUSERNAME : "; cin>>tmp_username; 
  
//   string pass ="";
   char ch;
   cout<<"PASSWORD : ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      tmp_passwor.push_back(ch);
      cout << '*';
      ch = _getch();
    strcpy(tmp_password, tmp_passwor.c_str()); 
   }
  
 // cout<<"PASSWORD : "; cin>>tmp_password;
    
//	ofstream file1 ("temp.txt", ios::out);
 //   file1.read((char*)&us,sizeof(us))
  //  file1.close();
  
  ifstream f;
  f.open("user.bin",ios::in);
  f.seekg(0);
  while(f.read((char*)&us,sizeof(us)))
  {
  //		if(strcmp(tmp_username,us.username)==0 && (tmp_password == us.password))
  	if(strcmp(tmp_username,us.username)==0 && strcmp(tmp_password,us.password)==0)
  	{
  		cout<<"\nLogging in.";
  		Sleep(500);
  		cout<<".";
  		Sleep(300);
  		cout<<".";
  		Sleep(200);
  		cout<<".";
  		Sleep(400);
  		cout<<"."<<endl;
  		success++;
  		Sleep(200);
  		ofstream f1;
		f1.open("history.dat",ios::out | ios::app);
		f1<<us.username<<endl;
				f1.close();
		
		ofstream a ;
		a.open("temp1.txt",ios::out);
		a<<us.email;
		a.close();
		tmp();
	/*	ofstream b ;
		b.open("LoggedTemp.txt",ios::out);
		b.write((char *)&us,sizeof(us));
    	b.close(); */
		
  		break;
    }
  }
  if(success < 1)
	{
	   cout<<"\nInvalid User"<<endl;
	   sleep(3000);
	   logform();
	}
  f.close();
}

void tmp()
{
	ofstream f7;
	f7.open("temp_bill.txt",ios::out);
	f7<<"Username	: "<<us.username<<endl;
	f7<<"Mobile		: "<<us.mobile_no<<endl; 
//	f7<<us.email<<endl;
	f7<<"Address	: "<<us.doorno<<","<<us.street_name<<","<<us.area<<endl;
	f7<<"Pin 		: "<<us.pin_code<<endl;
	f7.close();
}
void thanknote(char n[])
{
	char name[100];
	strcpy(name,n);
	
	ofstream f7;
	f7.open("ATTACHMENT.txt",ios::out);
	
	char t1[100] = "Thanks Mr.";
	strcat(t1,n);
//	cout<<t1;
	char t2[100] = " for registering to our Se7en - Food delivery app";
	strcat(t1,t2);
//	cout<<t1;
	f7<<t1;
	f7.close();
	
}
void logform()
{
	int ch,s;
	
	system("cls");	HANDLE  hConsole;
  			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout<<"\t\t\t\tSe7eN\n1.Login\n2.New Member? Register\nEnter Your Choice:";
	SetConsoleTextAttribute(hConsole, 14);
	cin>>ch;
	switch(ch)
	{
		case 1:
				login_form();
				break;
		case 2:
				registration_form();
				
				break;
		default:
				cout<<"Invalid Choice!";
				exit(-1);
			
	}
			
}
string emai()
{
	return us.email;
}
void email(char str2[100])
{
//	char str2[100];
//	cout<<"Enter : ";
 //   cin>>str2;
    char str1[] = "curl smtp://smtp.gmail.com:587 -v --mail-from \"ghirihari@gmail.com\" --mail-rcpt \"";
	strcat(str1,str2);

	char str3[] = "\" --ssl -u ghirihari@gmail.com:06071967 -T \"ATTACHMENT.txt\" -k --anyauth";
	strcat(str1,str3);
	//cout<<str1;
	
//	char* command = "curl smtp://smtp.gmail.com:587 -v --mail-from \"ghirihari@gmail.com\" --mail-rcpt \"ghirihari7@gmail.com\" --ssl -u ghirihari@gmail.com:06071967 -T \"ATTACHMENT.txt\" -k --anyauth";
 //   char* command = "curl smtp://smtp.gmail.com:587 -v --mail-from \"ghirihari@gmail.com\" --mail-rcpt \"aaa\" --ssl -u ghirihari@gmail.com:06071967 -T \"ATTACHMENT.txt\" -k --anyauth";
//	int i = strcmp(str1,command);
//	cout<<i;
	WinExec(str1, SW_SHOW);
   
}
/*
int main()
{
//registration_form();
login_form();
//char c[1000];
//cin>>c;
//eee(c);

}
*/
