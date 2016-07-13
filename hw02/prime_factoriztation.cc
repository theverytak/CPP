// prime_factorization.cc
// 2017. 7. 13

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

string itoa(int number) {
  string result;
  char temp = number + '0';
  result += temp;
  return result;
}

bool IsPrime(int number) {
  for(int i = 2; i < sqrt(number); i++) {
    if(number / i == 0) {
      return false;
    }
  }
  return true;
}

string ArrayToString(int *array, int index) {
  string result;
  int prime_number = 1, num_of_each_prime = 0;
  for(int i = 0; i < index; i++) {
    // if new prime number detected and its the first one;
    if(array[i] != prime_number && result.length() == 0) {
      prime_number = array[i];
      result += itoa(prime_number);
      num_of_each_prime = 1;
    }
    // if new prime number detected and its not the first prime number of the array;
    else if(array[i] != prime_number && result.length() != 0) {
      prime_number = array[i];
      result += '^';
      result += itoa(num_of_each_prime);
      result += " X ";
      result += itoa(prime_number);
      num_of_each_prime = 1;
    }
    else if(array[i] == prime_number) {
      num_of_each_prime++;
    }
  }

  // complete the last words for result.
  // ex) in the case of number 6, "2^1X3" will be already added.
  // so add "^1" to the tail;
  result += '^';
  result += itoa(num_of_each_prime);

  return result;
}

// Implement this function
string PrimeFactorization(unsigned int number) {
  int root_number = sqrt(number) + 1;
  int prime_number = 2;
  int prime_array[100], index = 0;
  string result;

  while(prime_number <= root_number) {
    if(IsPrime(prime_number)) {
      if(number % prime_number == 0) {
        prime_array[index] = prime_number;
        index++;
        number /= prime_number;
      }
      else {
        prime_number++;
      }
    }
    else {
      prime_number++;
    }
  }

  // if number is a prime number itself;
  if(index == 0) {
    prime_array[index] = number;
    index++;
  }

  result = ArrayToString(prime_array, index);
  return result;
}

int main(int argc, char** argv)
{
    if(argc < 1) return -1;

    unsigned int number;
    sscanf(argv[1], "%u", &number);

    cout << PrimeFactorization(number) << endl;
    return 0;
}
