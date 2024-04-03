#include <iostream>
using namespace std;
void ShowGreeting() {
	cout << "Lab1.cpp" << endl;
	cout << "Quiz No. 1." << endl;
	cout << "Encapsulation. Classes in C++ and means of their construction" << endl;
	cout << "Employee: last name, first name, middle name, job title, enter year, salary." << endl;
	cout << "Create an array of objects. Implement the possibility of obtaining:" << endl;
	cout << "- a list of employees , whose work experience at a given enterprise exceeds a given number of years," << endl;
	cout << "- a list of employees whose salary is greater than a given one," << endl;
	cout << "- a list of employees occupying a given position." << endl;
	cout << "Student of group 4307, Gaponyako Fedor Dmitrievich. 2024\n\n\n" << endl;
}
//
//
//
//
//void ShowTasks_for_manual_input() {
//	cout << "1 - get a list of employees whose work experience at a given enterprise exceeds a specified number of years" << endl;
//	cout << "2 - get a list of employees whose salary is greater than a given one" << endl;
//	cout << "3 - get a list of employees holding this position" << endl;
//	cout << "4 - exit the program" << endl;
//	cout << "5 - save employees to file" << endl;
//	cout << "6 - add a new employee" << endl;
//	cout << "Select menu item:" << endl;
//}
//
//
//void ShowTasks_for_file_input() {
//	cout << "1 - get a list of employees whose work experience at a given enterprise exceeds a specified number of years" << endl;
//	cout << "2 - get a list of employees whose salary is greater than a given one" << endl;
//	cout << "3 - get a list of employees holding this position" << endl;
//	cout << "4 - exit the program" << endl;
//	cout << "Select menu item:" << endl;
//}
//
//void ShowInputChoice() {
//	cout << "1 - Use input from file" << endl;
//	cout << "2 - Use manual input" << endl;
//	cout << "Select input type:" << endl;
//
//}

void ShowMenu() {

	cout << "1 - Add a new employee;" << endl;
	cout << "2 - View a list of your employees;" << endl;
	cout << "3 - Save employees to file;" << endl;
	cout << "4 - Load employees from file;" << endl;
	cout << "5 - Get a list of employees whose work experience at a given enterprise exceeds a specified number of years;" << endl;
	cout << "6 - Get a list of employees whose salary is greater than a given one;" << endl;
	cout << "7 - Get a list of employees holding this position;" << endl;
	cout << "8 - Run unit tests;" << endl;
	cout << "9 - Exit the program;" << endl;

}