#include "Employee.h"
#include "Employee_manager.h"
#include "TestsClass.h"


bool is_vectors_equal(vector<Employee> &employees_to_tests,vector<Employee> &expected_employees){

	for (int i = 0; i < employees_to_tests.size(); i++) {

		if (employees_to_tests[i].get_last_name() != expected_employees[i].get_last_name()) {return false;}
	}

	return true;
}


bool run_search_by_experience_test(vector<Employee>& employee_to_tests, vector<Employee>& expected_employees, int experience) {

	Employee_manager employees;

	employees.set_employees(employee_to_tests);

	vector<Employee> tested_employees = employees.search_by_work_experience(experience);

	bool test_passed = false;

	test_passed = is_vectors_equal(tested_employees,expected_employees);

	return test_passed;

}


bool run_search_by_salary_test(vector<Employee>& employee_to_tests, vector<Employee>& expected_employees, double salary) {

	Employee_manager employees;

	employees.set_employees(employee_to_tests);

	vector<Employee> tested_employees = employees.search_by_salary(salary);

	bool test_passed = false;

	test_passed = is_vectors_equal(tested_employees, expected_employees);

	return test_passed;

}


bool run_search_by_job_title_test(vector<Employee>& employee_to_tests, vector<Employee>& expected_employees, string job_title) {

	Employee_manager employees;

	employees.set_employees(employee_to_tests);

	vector<Employee> tested_employees = employees.search_by_job_title(job_title);

	bool test_passed = false;

	test_passed = is_vectors_equal(tested_employees, expected_employees);


	return test_passed;

}




void run_tests() {

	vector<Test> search_tests{

		Test(


			vector<Employee>{

				{"a","a","a","a",2000,50000.25},
				{"b","b","b","b",2001,49000.25},
				{"c","c","c","c",2002,48000.25}

			},
			vector<Employee>{

				{"a","a","a","a",2000,50000.25},
				{"b","b","b","b",2001,49000.25}

			},
			vector<Employee>{

				{"a","a","a","a",2000,50000.25}

			},

			vector<Employee>{

				{"c","c","c","c",2002,48000.25}

			},22,490000,"c"

		),


		Test(

			vector<Employee>{

				{"d","d","d","d",2020,50},
				{"e","e","e","e",2021,49},
				{"f","f","f","f",2022,48}

			},
			vector<Employee>{

			},
			vector<Employee>{

			},

			vector<Employee>{

			},5,50,"a"

		),
		Test(

			vector<Employee>{

				{"Ivanov","Ivan","Ivanovich","Programmer",1990,100000},
				{"Petrov","Peter","Petrovich","Programmer",1995,123456},
				{"Antonov","Anton","Antonovich","Programmer",2000,654321}

			},
			vector<Employee>{

				{"Ivanov","Ivan","Ivanovich","Programmer",1990,100000},
				{"Petrov","Peter","Petrovich","Programmer",1995,123456},
				{"Antonov","Anton","Antonovich","Programmer",2000,654321}

			},
			vector<Employee>{

				{"Ivanov","Ivan","Ivanovich","Programmer",1990,100000},
				{"Petrov","Peter","Petrovich","Programmer",1995,123456},
				{"Antonov","Anton","Antonovich","Programmer",2000,654321}

			},

			vector<Employee>{

				{"Ivanov","Ivan","Ivanovich","Programmer",1990,100000},
				{"Petrov","Peter","Petrovich","Programmer",1995,123456},
				{"Antonov","Anton","Antonovich","Programmer",2000,654321}

			},1,10,"Programmer"

		),
		Test(

			vector<Employee>{

				{"Ivanov","Ivan","Ivanovich","",2010,100000},
				{"Petrov","Peter","Petrovich","",2015,123456},
				{"Antonov","Anton","Antonovich","Programmer",2023,654321}

			},
			vector<Employee>{

				{"Ivanov","Ivan","Ivanovich","",2010,100000},
				{"Petrov","Peter","Petrovich","",2015,123456}

			},
			vector<Employee>{

				{"Antonov","Anton","Antonovich","Programmer",2023,654321}

			},

			vector<Employee>{

				{"Ivanov", "Ivan", "Ivanovich", "", 2010, 100000},
				{ "Petrov","Peter","Petrovich","",2015,123456 }

			},7,500000,""

		),

		Test(

		vector<Employee>{

			{"a", "a", "a", "a", 2000, 50.100001},
			{ "b","b","b","b",2001,50.1 },
			{ "c","c","c","c",2002,50.999999 }

			},
			vector<Employee>{

				{"a", "a", "a", "a", 2000, 50.100001},
				{ "b","b","b","b b",2001,50.1 },
				{ "c","c","c","c",2002,50.099999 }

			},
			vector<Employee>{

				{"a", "a", "a", "a", 2000, 50.100001},
				{ "c","c","c","c",2002,50.099999 }


			},

			vector<Employee>{

				{ "b", "b", "b", "b b", 2001, 50.1 },

			}, 7, 500000, "b b"

		)

	};

	cout << endl;

	bool tests_passed = true;

	for (Test current_test : search_tests) {

		if (!run_search_by_experience_test(current_test.employees_to_test, current_test.expectet_experience_search, current_test.experience_to_test)) {
			tests_passed = false;
		}
		if (!run_search_by_salary_test(current_test.employees_to_test, current_test.expectet_salary_search, current_test.salary_to_test)) {
			tests_passed = false;
		}
		if (!run_search_by_job_title_test(current_test.employees_to_test, current_test.expectet_job_title_search, current_test.job_title_to_test)) {
			tests_passed = false;
		}

	}
	cout << endl;
	if (tests_passed) { cout << "All tests passed successfully" << endl; }
	else { cout << "Tests passed unsuccessfully" << endl; }
	cout << endl;






}









