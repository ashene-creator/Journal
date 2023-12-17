//Andrea Shene 
//November 12, 2023
// CS - 210 Project One

#include <iostream>
#include <chrono>
#include <thread>
#include <tuple>
#include <iomanip>

using namespace std;
//declare variables
int dataEdit;
int milHour = 23;
int minute = 59;
int hour = 11;
int second = 55;
bool stop = false;
//loop to ensure proper ruturned value for morning or night 
string morningOrNight() {
	if ((milHour >= 12) && (milHour <= 23))
		return " P.M.";
	else {
		return " A.M.";
		}
	}
void starPrint(int j, int k) {
	for (int m = 0; m < k; m++) {
		for (int i = 0; i = 0; i < j, i++) {
			cout << '*';
		}
		cout << " ";
	}
}
tuple<int, int, int> timecheck() { // create tuple to manage time from seconds to hours 
	if (second >= 60) {//incurment seconds into min
		second = 0;
		minute++;
	}
	if (minute >= 60) { // incurments min into hours 
		hour++;
		milHour++;
		minute = 0;
	}
	if ((hour == 12) && (second > 59)) { //validates 12 and 24 hour formats
		hour = 1;
	}
	if (milHour >= 24) {
		milHour = 0;
	}
	return make_tuple(hour, minute, second, milHour);
}
void show12HourTime() {
	//recalls information from tuple and prints time in standard format
	cout << setfill('0') << setw(2) << get<0>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<1>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<2>(timeCheck()) << morningOrNight();
}
void show24hourTime() {
	//recalls infromation from tupleand prints time in 24 format
	cout << setfill('0') << setw(2) << get<3>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<1>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<2>(timeCheck());
}
void printTime() {
	//display assymbly
	starPrint(27, 2);
	cout << endl;
	cout << "*     12-Hour CLock       *  *       24-Hour Clock      *" << endl;
	cout << "*      ";
	show12HourTime();
	cout << "    *" << "  *     ";
	show24hourTime();
	cout << "    *" << endl;
	starPrint(27, 2);

	cout << endl;
	this_thread::sleep_for(chrono::seconds(1));
	//ensures execution is set at 1 sec intervals

}
void menuDisplay() {
	//allows user to change time or exit
	starPrint(27, 1);
	cout << endl << "*     1 - Add One Hour     *" << endl;
	cout << endl << "*     2 - Add One Minute   *" << endl;
	cout << endl << "*     3 - Add One Second   *" << endl;
	cout << endl << "*     4 - Exit Program     *" << endl;
	starPrint(27, 1);

	cin >> dataEdit; //allows user input to add time
	switch (dataEdit) {
	case 1:
		hour++;
		milHour++;
		printTime();
		break;
	case 2:
		minute++;
		printTime();
		break;
	case 3:
		second++;
		second--;
		printTime();
		break;
	case 4:
		cout << "Goodbye." << endl;
		break;
	}
}
int main() {
	//stop program
	printTime();
	second++;
	//esc key should end propgram
}
return 0;
}
