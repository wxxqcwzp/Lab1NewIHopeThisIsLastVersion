#pragma once

#include "Employee.h"

#include <iostream>
#include <vector>

using namespace std;

bool file_exists(const string& filename);

bool confirm_overwrite(const string& filename);

vector<Employee> get_employees_from_file(const string fileName);

void export_to_file(vector<Employee> employees_to_export);

bool is_filepath_valid(const string& filepath);

bool is_filename_valid(const string& filename);

string get_valid_filepath();
