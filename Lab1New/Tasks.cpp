#include "Employee.h"
#include "Employee_manager.h"



#include <iostream>

using namespace std;


void add_employee(Employee_manager &employees){
	
	Employee employee = Employee::get_input_employee();

	employees.add_employee(employee);
}