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

	Employee_manager employees;

	do {
		ShowMenu();
		menu_item = InputInt("Select menu item: ", 0, 10);
		switch (menu_item)
		{

		case(ADD_EMPLOYEE): { add_employee(employees); break; }
		case(SHOW_EMPLOYEES): { employees.show_employees(); break; }
		case(SAVE_DATA): {}
		case(LOAD_DATA): {}
		case(SEARCH_BY_WORK_EXPERIENCE): {}
		case(SEARCH_BY_SALARY): {}
		case(SEARCH_BY_JOB_TITLE): {}
		case(RUN_TESTS): { break; }
		case(EXIT): { repeat = false; }

		}
	} while (repeat);
}

