#include <iostream>

int fib(int n);
int fib_iter(int n);
int stepPerms(int n);

int main(){

  for (int i = 0; i < 10 ; i++) {
    std::cout << fib_iter(i) << ", ";
  }
  std::cout << "\n";

  //segmentation fault if all are run at the same time
  
  // std::cout << stepPerms(0) << std::endl;
  // std::cout << stepPerms(1) << std::endl;
  // std::cout << stepPerms(2) << std::endl;
  std::cout << stepPerms(3) << " == 4" << std::endl;
  // std::cout << stepPerms(4) << std::endl;
  std::cout << stepPerms(5) << " == 13" << std::endl;
  // std::cout << stepPerms(6) << std::endl;
  std::cout << stepPerms(7) << " == 44" << std::endl;
  // std::cout << stepPerms(8) << std::endl;


}


int fib(int n){
  if (n <2){
    return 1;
  } else {
    return fib(n-1) + fib(n-2);
  }
}

int fib_iter(int n) {
  int num1 = 0;
  int num2 = 1;
  int sum = 1;
  int temp;
  for (int i = 0; i < n; i++) {
    sum = num1 + num2;
    temp = num1;
    num1 = num2;
    num2 += temp;
  }
  return sum;
}

int stepPerms(int n) {
  /*
  Function recursively calculates and returns the integer number of ways 
  Davis can climb a staircase, modulo 10000000007.
  */
  if (n <= 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else if (n == 2) {
    return 2;
  } else if (n == 3) {
    return 4;
  } else {
    return (stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3)) % 10000000007;
  }
}

