#include "Employee.h"
#include <vector>

using namespace std;


class Test 
{
public:
	vector<Employee> employees_to_test;

	vector<Employee> expectet_experience_search;
	vector<Employee> expectet_salary_search;
	vector<Employee> expectet_job_title_search;

	int experience_to_test;

	double salary_to_test;

	string job_title_to_test;

	Test(vector<Employee> employees_to_test,
		vector<Employee> expectet_experience_search,
		vector<Employee> expectet_salary_search,
		vector<Employee> expectet_job_title_search,

		int experience_to_test,
		double salary_to_test,
		string job_title_to_test):

		employees_to_test(employees_to_test),
		expectet_experience_search(expectet_experience_search),
		expectet_salary_search(expectet_salary_search),
		expectet_job_title_search(expectet_job_title_search),

		experience_to_test(experience_to_test),
		salary_to_test(salary_to_test),
		job_title_to_test(job_title_to_test)
	{}



};
