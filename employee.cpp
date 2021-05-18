#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

struct emp_details
{
	char name[30];
//	char father_name[30];
	char email_id[30];
	char dob[10];
	char doj[10];
	char designation[20];
	char mobile_no[11];
	char doorno[5];
	char street_name[30],dummy[2];
	char area[20];
	unsigned int pin_code,salary;
	char vehicle_no[11];
};

void get_emp_details(struct emp_details *emp)
{
	cin.getline(emp->dummy,1,'\n');
	cout<<"Name :"; cin.getline(emp->name,20,'\n');
	cout<<"Date of birth :"; cin>>emp->dob;
	cin.getline(emp->dummy,3,'\n');
	_strdate(emp->doj);
	cout<<"Mobile :"; cin>>emp->mobile_no;
	cout<<"Email id :"; cin>>emp->email_id;
	cout<<"Vehicle No :"; cin>>emp->vehicle_no;
	cout<<"Permanent/Contact Address\n";
	cout<<"Door No :"; cin>>emp->doorno;
	cin.getline(emp->dummy,1,'\n');
	cout<<"Street :"; cin.getline(emp->street_name,30,'\n');
	cout<<"Area :"; cin.getline(emp->area,20,'\n');
	cout<<"Pincode :"; cin>>emp->pin_code;
}

void display_emp_details(struct emp_details *emp)
{
	cout<<"\nName	:"<<emp->name<<endl;
	cout<<"Date of birth	:"<<emp->dob<<endl;
	cout<<"Date of Joining	:"<<emp->doj<<endl;
	cout<<"Mobile	:"<<emp->mobile_no<<endl;
	cout<<"Email 	:"<<emp->email_id<<endl;
	cout<<"Vehicle No	:"<<emp->vehicle_no<<endl;
	cout<<"Permanent/Contact Address"<<endl;
	cout<<"Door No	:"<<emp->doorno<<endl;
	cout<<"Street	:"<<emp->street_name<<endl;
	cout<<"Area	:"<<emp->area<<endl;
	cout<<"Pincode	:"<<emp->pin_code<<endl;
}
/*
int main()
{
	struct emp_details emp;
	get_emp_details(&emp);
	display_emp_details(&emp);

}

*/
