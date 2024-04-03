#pragma once
#include <vector>
#include "Employee.h"

class Employee_manager
{
private:

	vector<Employee> employees;

public:

	void set_employees(vector<Employee> new_employees) { 
		
		if(new_employees.empty()){ cout << "There is no employees" << endl; return; }
		
		employees = new_employees;
	
	}


	void show_employees() {
		cout << endl;
		if (employees.empty()) { cout << "You haven't added any employees yet" << endl; }
		for (Employee employee : employees) { employee.show_employee(); }
		cout << endl;
	}

	void show_suitable_employees(vector<Employee> suitable_employees) {

		for (Employee employee : suitable_employees) { employee.show_employee(); }
		cout << endl;

	}


	void add_employee(Employee employee) { employees.push_back(employee); }


	vector<Employee> search_by_work_experience(int work_experience) {

		vector<Employee> suitable_employees;

		for (Employee employee : employees) {

			if (employee.get_work_experience() > work_experience) { suitable_employees.push_back(employee); }
		}

		return suitable_employees;

	}

	vector<Employee> search_by_salary(double salary) {

		vector<Employee> suitable_employees;

		for (Employee employee : employees) {

			if (employee.get_salary() > salary) { suitable_employees.push_back(employee); }

		}

		return suitable_employees;
	}

	vector<Employee> search_by_job_title(string job_title) {

		vector<Employee> suitable_employees;

		for (Employee employee : employees) {

			if (employee.get_job_title() == job_title) { suitable_employees.push_back(employee); }

		}
		return suitable_employees;
	}

	vector<Employee>get_employees() {
		return employees;
	}

};
