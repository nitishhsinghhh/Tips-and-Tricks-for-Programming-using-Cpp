// Write a program that prints the prime factorization of a given number.
#include <iostream>
#include<cmath>
class PrimeFactors{
  private:
    int n;
  public:
    //Constructor
    PrimeFactors(int num): n(num){}
    
    void calculatePrimeFactors(){
        std::cout<<"The prime factors are: ";
        if(n==1){
            std::cout<<"none\n";
            return;
        }
        //for even prime number 2
        if(n%2 == 0){
            print(2);
        }
        //divide by 2 until the number is an odd number
        while(n%2 == 0){
            n /= 2;
        }
        // Iterate over odd numbers starting from 3
        for(int i=3;i<=sqrt(n);i+=2){
            if(n%i==0 && primeCheck(i)){
                print(i);
            }
            while(n%i==0){
                n /= i;
            }
        }
        // if number is not divided above and greater than 2
        if(n>1 && primeCheck(n)){
            print(n);
        }
    }
  private:
    bool primeCheck(int x){
        if(x<2) return false;
        bool flag = true;
        for(int i=2;i*i<=x;i++){
            if(x%i == 0){
                flag = false;
                break;
            }
        }
        return flag;
    }
    void print(int num){
        std::cout<<num<<" ";
    }
};
int main() {
    // Write C++ code here
    int n;
    do{
        std::cin>>n;
        if(n<1){
            std::cout<<"Please enter positive integer\n";
        }
    }while(n<1);
    PrimeFactors pf(n);
    pf.calculatePrimeFactors();
    return 0;
}
/*
  =====================OUTPUT==================
  Input: n = 6
  Output: The prime factors are: 2 3
  ---------------------
  Input: n = 1
  Output: The prime factors are: none
  ---------------------
  Input: n = 88
  Ouput: The prime factors are: 2 11
*/
