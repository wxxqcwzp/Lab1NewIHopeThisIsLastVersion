#include "Employee.h"
#include "Employee_manager.h"
#include "TestsClass.h"


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

				{"Ivanov","Ivan","Ivanovich","",1990,100000},
				{"Petrov","Peter","Petrovich","",1995,123456},
				{"Antonov","Anton","Antonovich","Programmer",2000,654321}

			},
			vector<Employee>{

				{"Ivanov","Ivan","Ivanovich","",2010,100000},
				{"Petrov","Peter","Petrovich","",2015,123456}

			},
			vector<Employee>{

				{"Antonov","Anton","Antonovich","Programmer",2000,654321}

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



}