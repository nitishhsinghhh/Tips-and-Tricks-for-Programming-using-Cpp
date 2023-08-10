// Program to convert into minutes

#include<iostream>
using namespace std;

class Solution {
public:
	double converting(double hours, double minutes, double seconds) {
		return (hours * 60) + (minutes) + (seconds / 60);
	}
};

void main() {
	double hours, minutes, seconds;
	cout << "Hours: ";
	cin >> hours;
	cout << "Minutes: "; 
	cin >> minutes;
	cout << "Seconds: ";
	cin >> seconds;

	Solution oSolution;
	if(hours>=0 && minutes>=0 && seconds>=0)
		cout << "The time in minutes is " << oSolution.converting(hours, minutes, seconds) << endl;
	else 
		cout << "Invalid inputs!" << endl;
	system("pause");
}

/*
Output:
Hours: 12
Minutes: 34
Seconds: 660
The time in minutes is 765
*/
