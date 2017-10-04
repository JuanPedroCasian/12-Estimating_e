/*
Estimating_e.cpp
Oct 3, 2017
Juan Casian
*/

#include <iostream>

using namespace std;

void AskUserForPrecision (float& Precision){
  cout << "Please Insert the number of digits you want to get from e: ";
  cin >> Precision;

  if (Precision <= 0) {
    cout << "The value you entered is lower than 0, try again." << endl;
    AskUserForPrecision(Precision);
  }
}

float Factorial (float FactorialNumber) {
  float Result = 1;                         //float is a type of variable that lets you print more digits than double

  if (FactorialNumber == 0){
    Result = 1;
  } else {

    Result = FactorialNumber;
    FactorialNumber -= 1;

    for (;FactorialNumber > 0; -- FactorialNumber){
      Result = Result * FactorialNumber;
     }
  }
  return Result;
}

float FindEWithPrecision (float Precision){
  float NumberOfLoops = Precision + 4, Result = 0, Fraction = 0; // I used precision + 4 because if I used just the precision I had the numbers were incorrect

  for (;NumberOfLoops >= 0; -- NumberOfLoops){

    Fraction = 1/Factorial (NumberOfLoops);
    Result = Result + Fraction;
  }

  return Result;
}

int main () {
  float Precision = 0, Result = 0;
  AskUserForPrecision(Precision);

  Result = FindEWithPrecision (Precision);

  cout.precision(Precision);

  cout << " e with the number of digits tu entered is: " << Result << endl;

return 0;
}
