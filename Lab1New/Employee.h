#pragma once

#include <iostream>
#include "Input.h"

using namespace std;

class Employee {
private:

	string last_name;
	string first_name;
	string middle_name;

	string job_title;

	int enter_year;

	double salary;

public:
	Employee(string last_name, string first_name, string middle_name, string job_title, int enter_year, double salary) :
		last_name(last_name), first_name(first_name), middle_name(middle_name),job_title(job_title), enter_year(enter_year), salary(salary) {}


	string get_last_name() { return last_name; }
	string get_first_name() { return first_name; }
	string get_middle_name() { return middle_name; }

	string get_job_title() { return job_title; }

	int get_work_experience() { return 2024 - enter_year; }
	int get_enter_year() { return enter_year; }

	double get_salary() { return salary; }


	void show_employee() { cout << last_name << ' ' << first_name << ' ' << middle_name << "; " << job_title << "; enter year:" << enter_year << "; salary:" << salary << endl; }

};
