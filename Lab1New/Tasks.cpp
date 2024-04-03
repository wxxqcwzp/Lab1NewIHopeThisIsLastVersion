#include "Employee.h"
#include "Employee_manager.h"
#include "Files.h"
#include "Input.h"


#include <iostream>

using namespace std;

bool confirm_save_search_results() {

	cout << "Do you want to save your search results? " << endl << "1 - Yes;" << endl << "0 - No;" << endl;;
	int user_choice = InputInt("Enter menu item:", -1, 2);

	return user_choice;
}

void add_employee(Employee_manager& employees) {

	Employee employee(
		InputString("Enter employee's last name:"),
		InputString("Enter employee's first name:"),
		InputString("Enter employee's middle name:"),
		InputString("Enter employee's job title:"),
		InputInt("Enter employee's enter year:", 0, 2025),
		InputDouble("Enter employee's salary:", 0, DBL_MAX)
		);

	employees.add_employee(employee);
}

void load_data(Employee_manager& employees) {

	string filepath = get_valid_filepath();

	vector<Employee> employees_from_file = get_employees_from_file(filepath);

	if (employees_from_file.empty()) { cerr << "Error reading from file" << endl; }

	else { employees.set_employees(employees_from_file); }
}

void save_data(Employee_manager& employees) {

	string filepath = get_valid_filepath();

	vector<Employee> employees_to_export = employees.get_employees();

	if (employees_to_export.empty()) { cerr << "Error saving to file" << endl; return; }

	else { export_to_file(employees_to_export); }
}

void search_by_work_experience(Employee_manager& employees) {

	if (employees.get_employees().empty()) { cout << "There is no employees" << endl; return; }

	int work_experience = InputInt("Enter a experience threshold to search employees:", 0, 2025);

	vector<Employee> suitable_employees = employees.search_by_work_experience(work_experience);

	if (suitable_employees.empty()) { cout << "There is no suitable employees" << endl; return; }

	cout << "Suitable employees:" << endl;
	employees.show_suitable_employees(suitable_employees);

	if (confirm_save_search_results()) { export_to_file(suitable_employees); }
}

void search_by_salary(Employee_manager& employees) {

	if (employees.get_employees().empty()) { cout << "There is no employees" << endl; return; }

	double salary = InputDouble("Enter a salary treshold to search employees:", 0, DBL_MAX);

	vector<Employee> suitable_employees = employees.search_by_salary(salary);

	if (suitable_employees.empty()) { cout << "There is no suitable employees" << endl; return; }

	cout << "Suitable employees" << endl;
	employees.show_suitable_employees(suitable_employees);

	if (confirm_save_search_results()) { export_to_file(suitable_employees); }
}

void search_by_job_title(Employee_manager& employees) {

	if (employees.get_employees().empty()) { cout << "There is no employees" << endl; return; }

	string job_title = InputString("Enter a job title to search employees:");

	vector<Employee> suitable_employees = employees.search_by_job_title(job_title);

	if (suitable_employees.empty()) { cout << "There is no suitable employees" << endl; return; }

	cout << "Suitable employees:" << endl;
	employees.show_suitable_employees(suitable_employees);

	if (confirm_save_search_results()) { export_to_file(suitable_employees); }
}

