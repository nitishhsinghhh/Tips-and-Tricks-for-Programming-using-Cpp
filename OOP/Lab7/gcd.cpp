#include<iostream>
using namespace std;

int gcd(int x, int y) {
	if (x == 0 || y == 0)
		return y, x;
	if (x == y)
		return x;
	if (x > y)
		return gcd(x - y, y);
	if (y > x)
		return gcd(x, y - x);
}

int main() {
	cout << "\t\t\t***Program to calcualte the G.C.D for two integers using recursion.***" << endl;
	cout << "Please enteer two integers: " << endl;
	int x, y;
	cin >> x >> y;
	cout << "The G.C.D of " << x << "and " << y << " is " << gcd(x, y); 
	return 0;
}
