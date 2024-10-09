#include <iostream>
#include "Employee.h"

using namespace std;

int main() 
{
    Employee employees[100];
    int employeeCount = 0;

    int choice;
    do 
    {
        cout << "Menu:" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display Employees" << endl;
        cout << "3. Search by Last Name" << endl;
        cout << "4. Search by Salary Range" << endl;
        cout << "5. Sort by Last Name" << endl;
        cout << "6. Remove Employee" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            addEmployee(employees, employeeCount);
            break;
        case 2:
            displayEmployees(employees, employeeCount);
            break;
        case 3: 
        {
            char lastName[50];
            cout << "Enter last name to search: ";
            cin >> lastName;
            searchByLastName(employees, employeeCount, lastName);
            break;
        }
        case 4: 
        {
            double minSalary, maxSalary;
            cout << "Enter minimum salary: ";
            cin >> minSalary;
            cout << "Enter maximum salary: ";
            cin >> maxSalary;
            searchBySalaryRange(employees, employeeCount, minSalary, maxSalary);
            break;
        }
        case 5:
            sortByLastName(employees, employeeCount);
            break;
        case 6: 
        {
            int index;
            char confirmation;
            cout << "Enter index of employee to remove: ";
            cin >> index;
            cout << "Are you sure you want to remove this employee? (y/n): ";
            cin >> confirmation;
            if (confirmation == 'y' || confirmation == 'Y') {
                removeEmployee(employees, employeeCount, index - 1);
            }
            break;
        }
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }

    } 
    while (choice != 7);

    return 0;
}
