#pragma once

#include "Employee.h"


#include <vector>

using namespace std;


class Test 
{
private:

	vector<Employee> employees_to_test;

	vector<Employee> expectet_experience_search;
	vector<Employee> expectet_salary_search;
	vector<Employee> expectet_job_title_search;

	int experience_to_test;

	double salary_to_test;

	string expected_job_title;

public:

	Test(vector<Employee> employees_to_test,
		vector<Employee> expectet_experience_search,
		vector<Employee> expectet_salary_search,
		vector<Employee> expectet_job_title_search,

		int experience_to_test,
		double salary_to_test,
		string expected_job_title):

		employees_to_test(employees_to_test),
		expectet_experience_search(expectet_experience_search),
		expectet_salary_search(expectet_salary_search),
		expectet_job_title_search(expectet_job_title_search),

		experience_to_test(experience_to_test),
		salary_to_test(salary_to_test),
		expected_job_title(expected_job_title)
	{}



};
