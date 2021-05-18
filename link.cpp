#include <iostream>
#include "customer.cpp"
#include "employee.cpp"
using namespace std;

int main()
{
	cout<<"User Details\n";
	struct user_details user;
	get_user_details(&user);
	display_user_details(&user);
	
	cout<<"Employee Details\n";
	struct emp_details emp;
	get_emp_details(&emp);
	display_emp_details(&emp);
}
