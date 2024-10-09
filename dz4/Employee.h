#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee 
{
    char lastName[50];
    char firstName[50];
    char phoneNumber[15];
    double salary;
};

bool isValidPhoneNumber(const char* phone);

void addEmployee(Employee employees[], int& count);
void displayEmployees(const Employee employees[], int count);
void sortByLastName(Employee employees[], int count);
void searchByLastName(const Employee employees[], int count, const char* lastName);
void searchBySalaryRange(const Employee employees[], int count, double minSalary, double maxSalary);
void removeEmployee(Employee employees[], int& count, int index);

#endif
