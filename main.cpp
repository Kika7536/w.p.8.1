#include<iostream>
using namespace std;

bool check(string arg) {

	int hours, minutes;

	
	if (arg.length() != 5) { cout << "Mistake.The time should be in the format HH:MM" << endl; return false; }

	
	
	for (int i = 0; i < arg.length(); i++) {
		

		if (!(arg[i] - '0' >= 0 && arg[1] - '0' <= 9)) {
			cout << "Mistake.The time should be in the format HH:MM" << endl;
			return false;
		}

		if (i == 2 && arg[i] != ':') {
			cout << "Mistake.The time should be in the format HH:MM" << endl;
			return false;
		}

		
	}
	
	hours = (arg[0] - '0') * 10 + (arg[1] - '0');
	minutes = (arg[3] - '0') * 10 + (arg[4] - '0');

	if (hours > 23 || minutes > 59) { cout << "Max time is 23:59" << endl; return false; }

	
	return true;
}

void res(string start, string end) {
	int st_h, st_m, end_h, end_m, res_h, res_m;
	string res = "";

	st_h = ((start[0] - '0') * 10) + (start[1] - '0');
	st_m = ((start[3] - '0') * 10) + (start[4] - '0');
	
	end_h = ((end[0] - '0') * 10) + (end[1] - '0');
	end_m = ((end[3] - '0') * 10) + (end[4] - '0');

	if (st_m > end_m) {
		end_m += 60;
		end_h--;
		res_m = end_m - st_m;
	}
	else {
		res_m = end_m - st_m;
	}

	if (st_h > end_h) end_h += 24;

	res_h = end_h - st_h;
	
	
	cout << "The trip was " << res_h << " hours " << res_m << " minutes" << endl << endl;
	
	
}


void main() {
	setlocale(LC_ALL, "rus");

	cout << "Задание 1. Время в пути." << endl;
	cout << "---------------------------------------" << endl << endl;

	string start_time, end_time, res_time;
	bool time = false;

	while (!time) {
		cout << "Enter the departure time: ";
		cin >> start_time;
		time = check(start_time);
	}

	
	time = false;
	while (!time) {
		cout << "Enter the arrival time: ";
		cin >> end_time;
		time = check(end_time);
	}

	res(start_time, end_time);
	
	main();

}
//Возможно тут много сложностей, но вроде все работает как надо