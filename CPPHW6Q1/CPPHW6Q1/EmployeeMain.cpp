/*
EmployeeMain.cpp
Calculates bonus and pay for employees
CPP Workshop
Homework 6 Qestion 1
Avraham Meyers
Created on 5.4.21 and Modified on 5.5.21
*/

#include "FullTime.h"
#include "PartTime.h"
#include <iostream>
using namespace std;
int main()
{
	FullTime arrF[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrF[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	PartTime arrP[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	for (int i = 0; i < 3; i++)
	{
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].SalaryAfterBonus() << endl;
	}


	for (int i = 0; i < 3; i++)
	{
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].SalaryAfterBonus() << endl;
	}
	return 0;
}
/*
Enter employee details :
aba
1
0
0
4
Enter employee details :
bbb
1
0
0
3
Enter employee details :
ccc
333
0
0
2
Enter employee details :
ddd
444
0
0
1
1
Enter employee details :
eee
555
4
3
2
2
Enter employee details :
fff
666
1
2
3
4
Employee:       aba
Employee ID : 1
Years seniority : 0
Salary per Month : 4
After Bonus : 500.333
Employee : bbb
Employee ID : 1
Years seniority : 0
Salary per Month : 3
After Bonus : 500.25
Employee : ccc
Employee ID : 333
Years seniority : 0
Salary per Month : 2
After Bonus : 500.167
Employee : ddd
Employee ID : 444
Years seniority : 0
Hours : 1
Salary Per Month : 1
After Bonus : 501
Employee : eee
Employee ID : 555
Years seniority : 4
Hours : 2
Salary Per Month : 4
After Bonus : 504
Employee : fff
Employee ID : 666
Years seniority : 1
Hours : 3
Salary Per Month : 12
After Bonus : 512
*/