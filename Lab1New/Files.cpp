#include "Employee.h"

#include "Input.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
enum token { LAST_NAME, FIRST_NAME, MIDDLE_NAME, JOB_TITLE, ENER_YEAR, SALARY };
using namespace std;

bool file_exists(const string& filename) {
	ifstream file(filename);
	return file.is_open();
}

bool confirm_overwrite(const string& filename) {

	const int YES = 1;

	cout << "File '" << filename << "' already exists." << endl;
	cout << "Do you want to overwrite it?" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl;

	int user_choice = 0;

	user_choice = InputInt("Enter menu item:", 0, 3);

	if (user_choice == YES) { return true; }

	return false;

}

vector<Employee> get_employees_from_file(const string filename) {
	vector<Employee> files;

	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return files;
	}

	string line;
	while (getline(input_file, line)) {

		if (line.empty()) {
			cerr << "Warning: Skipped empty line." << endl;
			continue;
		}

		stringstream ss(line);

		string token{ "" };

		string last_name{ "" };
		string first_name{ "" };
		string middle_name{ "" };

		string job_title{ "" };

		int field_count = 0;

		int enter_year = 0;

		double salary = 0;

		while (getline(ss, token, ';')) {
			try {
				switch (field_count) {
				case LAST_NAME: last_name = token; break;
				case FIRST_NAME: first_name = token; break;
				case MIDDLE_NAME: middle_name = token; break;
				case JOB_TITLE: job_title = token; break;
				case ENER_YEAR: enter_year = stoi(token); break;
				case SALARY: salary = stod(token); break;
				default:
					cerr << "Warning: parsing " << field_count << " field: " << "wrong number of fields" << endl;
				}
			}
			catch (invalid_argument& e) {
				cerr << "Warning: converting field " << field_count << ": " << e.what() << endl;
			}

			field_count++;
		}

		Employee employee(last_name, first_name, middle_name, job_title, enter_year, salary);
		files.push_back(employee);
	}

	input_file.close();
	return files;
};

bool is_filepath_valid(const string& filepath) {

	regex file_path_regex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.csv$");

	if (!regex_match(filepath, file_path_regex)) {
		cerr << "Error: Invalid file path." << endl;
		return false;
	}

	return true;
}
bool is_filename_valid(string& filename) {
	regex filename_regex("^[^\\/:*?\"<>|]+\\.csv$");

	regex filename_reserved_names("^(?:CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9]|con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\\..*)?$");

	regex filename_reserved_chars("[\\/:*?\"<>|]");

	if (!regex_match(filename, filename_regex)) {
		cerr << "Error: Invalid file name." << endl;
		return false;
	}

	if (regex_match(filename, filename_reserved_names)) {
		cerr << "Error: Invalid file name. Using reserved filenames is prohibited!" << endl;
		return false;
	}

	if (regex_search(filename, filename_reserved_chars)) {
		cerr << "Error: Invalid file name. Using reserved characters is prohibited!" << endl;
		return false;
	}

	return true;
}

string get_valid_filepath() {
	bool is_path_valid = false;
	bool is_name_valid = false;

	string filename { "" };
	string filepath { "" };

	while (!is_path_valid && !is_name_valid) {
		filename = InputString("Enter filename (only csv acceptable): ");

		filepath = InputString("Enter full path to path: ");

		if (is_filepath_valid(filepath + filename) && is_filename_valid(filename)) {
			is_path_valid = true;
			is_name_valid = true;
		}
	}

	return filepath + filename;
}

string get_overwrite_confirmation(string& full_path) {
	while (file_exists(full_path)) {
		if (confirm_overwrite(full_path)) {
			return full_path;
		}
		else {
			cout << "Please choose another file." << endl;
			return get_valid_filepath();
		}
	}
	return full_path;
}
void export_to_file(vector<Employee> employees_to_export) {

	string full_path = get_valid_filepath();
	full_path = get_overwrite_confirmation(full_path);

	ofstream file(full_path);
	if (!file) {
		cerr << "Error: File is read-only or another error occurred." << endl;
		file.close();

		while (true) {
			cout << "Please enter a new path." << endl;
			full_path = get_valid_filepath();
			full_path = get_overwrite_confirmation(full_path);

			file.open(full_path);
			if (file) {
				break;
			}
			else {
				cerr << "Error: File is read-only or another error occurred." << endl;
				file.close();
			}
		}
	}

	for (Employee& export_employee : employees_to_export) {
		file << export_employee.get_last_name() << ";" << export_employee.get_first_name() << ";" << export_employee.get_middle_name() << ";"
			<< export_employee.get_job_title() << ";" << export_employee.get_enter_year() << ";" << export_employee.get_salary() << "\n";
	}

	file.close();
	cout << "Data successfully exported to file: " << full_path << endl;
}