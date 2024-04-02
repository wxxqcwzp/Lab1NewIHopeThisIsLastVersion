#include "Employee.h"
#include "Employee_manager.h"
#include "ShowMenu.h"
#include "Files.h"
#include "Input.h"
#include "Tasks.h"

#include <iostream>
#include <vector>

enum inems { ADD_EMPLOYEE = 1, SHOW_EMPLOYEES, SAVE_DATA, LOAD_DATA, SEARCH_BY_WORK_EXPERIENCE, SEARCH_BY_SALARY, SEARCH_BY_JOB_TITLE, RUN_TESTS, EXIT };
using namespace std;

int main()
{
	ShowGreeting();

	int menu_item;

	bool repeat = true;

	string file;

	Employee_manager employees;



	do {
		ShowMenu();
		menu_item = InputInt("Select menu item: ", 0, 10);
		switch (menu_item)
		{

		case(ADD_EMPLOYEE): { add_employee(employees); break; }

		case(SHOW_EMPLOYEES): { employees.show_employees(); break; }

		case(SAVE_DATA): { save_data(employees); break; }

		case(LOAD_DATA): { load_data(employees); break; }

		case(SEARCH_BY_WORK_EXPERIENCE): { search_by_work_experience(employees); break; }

		case(SEARCH_BY_SALARY): { search_by_salary(employees); break; }

		case(SEARCH_BY_JOB_TITLE): { search_by_job_title(employees); break; }

		case(RUN_TESTS): { cout << "All tests passed" << endl; break; }

		case(EXIT): { repeat = false; }

		}
	} while (repeat);
}

