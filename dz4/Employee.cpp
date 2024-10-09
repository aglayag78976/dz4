#include <iostream>
#include "Employee.h"

using namespace std;

bool isValidPhoneNumber(const char* phone) 
{
    return (phone[0] == '(' && phone[4] == ')' && phone[5] == ' ' &&
        isdigit(phone[1]) && isdigit(phone[2]) && isdigit(phone[3]) && isdigit(phone[6]));
}

void addEmployee(Employee employees[], int& count) 
{
    if (count >= 100) 
    {
        cout << "Employee book is full." << endl;
        return;
    }
    Employee emp{};
    cout << "Enter first name: ";
    cin >> emp.firstName;
    cout << "Enter last name: ";
    cin >> emp.lastName;
    do 
    {
        cout << "Enter phone number ((XXX) XXXXXX): ";
        cin >> emp.phoneNumber;
    } 
    while (!isValidPhoneNumber(emp.phoneNumber));
    cout << "Enter salary: ";
    cin >> emp.salary;
    employees[count++] = emp;
}

void displayEmployees(const Employee employees[], int count) 
{
    for (int i = 0; i < count; ++i) 
    {
        cout << "Employee #" << (i + 1) << ":" << endl;
        cout << "Name: " << employees[i].firstName << " " << employees[i].lastName << endl;
        cout << "Phone: " << employees[i].phoneNumber << endl;
        cout << "Salary: " << employees[i].salary << endl;
    }
}

void sortByLastName(Employee employees[], int count) 
{
    for (int i = 0; i < count - 1; ++i) 
    {
        for (int j = 0; j < count - i - 1; ++j) 
        {
            if (strcmp(employees[j].lastName, employees[j + 1].lastName) > 0) 
            {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

void searchByLastName(const Employee employees[], int count, const char* lastName) 
{
    for (int i = 0; i < count; ++i) 
    {
        bool match = true;
        for (int j = 0; lastName[j] != '\0' && match; ++j) 
        {
            if (lastName[j] != employees[i].lastName[j]) 
            {
                match = false;
            }
        }

        if (match) 
        {
            cout << "Employee found:" << endl;
            cout << "Name: " << employees[i].firstName << " " << employees[i].lastName << endl;
            cout << "Phone: " << employees[i].phoneNumber << endl;
            cout << "Salary: " << employees[i].salary << endl;
        }
    }
}

void searchBySalaryRange(const Employee employees[], int count, double minSalary, double maxSalary) 
{
    for (int i = 0; i < count; ++i) 
    {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) 
        {
            cout << "Employee found:" << endl;
            cout << "Name: " << employees[i].firstName << " " << employees[i].lastName << endl;
            cout << "Phone: " << employees[i].phoneNumber << endl;
            cout << "Salary: " << employees[i].salary << endl;
        }
    }
}

void removeEmployee(Employee employees[], int& count, int index) 
{
    if (index < 0 || index >= count) 
    {
        cout << "Invalid index" << endl;
        return;
    }
    for (int i = index; i < count - 1; ++i) 
    {
        employees[i] = employees[i + 1];
    }
    count--;
}
