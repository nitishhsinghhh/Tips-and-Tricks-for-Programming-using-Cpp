#include <iostream>
#include <stdexcept>

using namespace std;

double divideNumbers(double dividend, double divisor) {
    if (divisor == 0)
        throw runtime_error("Division by zero error!");
    
    return dividend / divisor;
}

int main() {
    try {
        double result = divideNumbers(10.0, 0.0);
        cout << "Result: " << result << endl;
    } catch (const exception& ex) {
        cout << "Exception caught: " << ex.what() << endl;
    }
    
    return 0;
}
