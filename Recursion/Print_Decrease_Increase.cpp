// The program prints a number first in decreasing order and then in increasing order using recursion.
#include <iostream>
class PrintDecreaseIncrease{
    private:
        int n;
        //function to print decrease increase using recursion
        void pdi(int &n){
            if(n==0) return;
            std::cout<<n<<std::endl;
            pdi(--n);
            std::cout<<++n<<std::endl;
        }
    public:
        // constructor 
        PrintDecreaseIncrease(int num): n(num) {}
        // function to call pdi() function
        void printPDI(){
            std::cout<<"Print Decrease & Increase:\n";
            // call the pdi() function 
            pdi(n);
        }
};
int main() {
    int inputNumber;
    // Handling non-positive input value
    do{
        std::cout << "Enter a number: ";
        std::cin >> inputNumber;
        if(inputNumber <= 0){
            std::cout<<"Please give positive number as input!\n";
        }
    }while(inputNumber <= 0);
    // creating object of PrintDecreaseIncrease class
    PrintDecreaseIncrease obj(inputNumber);
    // calling printPDI() method 
    obj.printPDI();
    return 0;
}
/*
====================OUTPUT SECTION========================
Input: n = 4
Output: 4
        3
        2
        1
        1
        2
        3
        4
-----------------
Input: 2
Output: 2
        1
        1
        2
-----------------
Input: 1
Output: 1
        1
==========================================================
*/
