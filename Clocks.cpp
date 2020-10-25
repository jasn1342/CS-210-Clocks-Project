/*
 * Clocks.cpp

 *
 *  Created on: Sep 16, 2020
 *      Author: 1858940_snhu
 */
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <string>
using namespace std;

//Display Menu function
bool displayMenu(int &seconds, int &minutes, int &hours) {
	string button = "";
	int userInput = -1;
	//Prompt upon running program
	cout << "Button Pressed?";
	cout << endl;
	getline(std::cin, button);
	//Menu launches if user types "Yes" or "yes."
	if ((button == "Yes") || (button == "yes")) {
		//menu display header.
		for (int i = 0; i < 30; i++) {
			cout << "*";
		}
		cout << " " << endl;
		cout << "* 1 - Add One Hour          *" << endl;
		cout << "* 2 - Add One Minute        *" << endl;
		cout << "* 3 - Add One Second        *" << endl;
		cout << "* 4 - Exit Program          *" << endl;
		cout << " " << endl;
		//menu footer
		for (int i = 0; i < 30; i++) {
			cout << "*";
		}
		cout << endl;

		//User makes selection to add time to clocks based on numeric inputs.
		cout << "Make Selection: ";
		cin >> userInput;
		cout << userInput;
		if (userInput == 1) {
			hours = hours + 1;
		}
		if (userInput == 2) {
			minutes = minutes + 1;
		}
		if (userInput == 3) {
			seconds = seconds + 1;
		}
		if (userInput == 4) {
			cout << "End Program";
			usleep(1000);
			system("cls");
			return true;
		}
	}
	else {
		// any other input results in adding a second and waiting a second before screen clears.
		seconds = seconds + 1;
		usleep(1000);

	}

	system("cls");
	return false;
}

//24 hour clock layout function
void show24Hour(int seconds, int minutes, int hours) {
	//24 hour clock header
	for (int i = 0; i < 30; i++) {
		cout << "*";
	}
	cout << " " << endl;
	cout << "*        ";
	cout << "24-Hour Clock";
	cout << "       *" << endl;
	cout << "*" << setw(10) << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " ";
	cout << setw(10) << "*" << endl;
	//24 hour clock footer
	for (int i = 0; i < 30; i++) {
		cout << "*";
	}
	cout << endl;
}
//12 hour clock layout function
void show12Hour(int seconds, int minutes, int hours) {
	string str;

	//converting it into 12 hour format
	if (hours >= 12)
		str = "PM";
	else
		str = "AM";
	hours = hours > 12 ? hours - 12 : hours;
	//12 hour clock header
	for (int i = 0; i < 30; i++) {
		cout << "*";
	}
	cout << " " << endl;
	cout << "*        ";
	cout << "12-Hour Clock" << setw(8) << "*" << endl;
	cout << "*" << setw(9) << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << str;
	cout << setw(9) << "*" << endl;
	//12 hour clock footer
	for (int i = 0; i < 30; i++) {
		cout << "*";
	}
	cout << endl;
}

int main() {

	int seconds, minutes, hours;
		//storing total seconds
	time_t total_seconds = time(0);

		//getting values of seconds, minutes and hours
	struct tm* ct = localtime(&total_seconds);
	//getting real time from system
	seconds = ct->tm_sec;
	minutes = ct->tm_min;
	hours = ct->tm_hour;

	bool exit = false;

	while (!exit) {




		show12Hour(seconds, minutes, hours);
		show24Hour(seconds, minutes, hours);
		exit = displayMenu(seconds, minutes, hours);

	}


	system("cls");
	return 0;

}
