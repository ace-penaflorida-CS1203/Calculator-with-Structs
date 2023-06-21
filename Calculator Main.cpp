
#include <iostream>
# include <cstdlib>
# include <string>
# include <typeinfo>

using namespace std;

const int MAX_VAL_HISTORY = 100;
char backChar; 

struct Values{
  float num1, num2;
  double sum, difference, product, quotient;
  char operator1; 
  int arrayNum1[MAX_VAL_HISTORY]; // inittializing the arrays
  int arrayNum2[MAX_VAL_HISTORY];
  char arrayOperator1[MAX_VAL_HISTORY];
  double arrayResult[MAX_VAL_HISTORY];
};


double add(float num1, float num2) {
  return num1 + num2;}

double subtract(float num1, float num2) {
  return num1 - num2;}

double multiply(float num1, float num2) {
  return num1 * num2;}

double divide(float num1, float num2) {
  return num1 / num2;}


// resuable code for each operation: the sizeVal is passed as a reference so that the value will update for each iteration
void array_solutions(int &sizeVal, Values& value, double result){ 
  if(sizeVal < MAX_VAL_HISTORY){
          value.arrayNum1[sizeVal] = value.num1;
          value.arrayNum2[sizeVal] = value.num2;
          value.arrayOperator1[sizeVal] = value.operator1;
          value.arrayResult[sizeVal] = result; 
          sizeVal++;
        }
}


void history_main(const Values valueInfo, int sizeVal){ // const keyword indicates that the valueInfo object cannot be modified within the function.
  string outputArray[MAX_VAL_HISTORY]; // with index 100
  cout << "\n|   HISTORY  |   \n"; 
  for (int i = 0; i < sizeVal; i++){ 
  
    // concatenating the converted values into 1 variable
    string concatValues = to_string(i + 1) + ".) " + to_string(valueInfo.arrayNum1[i]) + " " + valueInfo.arrayOperator1[i] + " " + to_string(valueInfo.arrayNum2[i]) + " = " + to_string(valueInfo.arrayResult[i]);

    outputArray[i] = concatValues; // storing concatValues to outputArray
    cout << *(outputArray + i) <<  " | Address: " << &outputArray[i] << endl;
    //       dereferenncing                             address
  }
}


int main() {

    Values value;
    int sizeVal = 0;

    do{

      cout << "\n\nNo Spaces\n";
      cout << "\n   Values: ";
      cin >> value.num1 >> value.operator1 >> value.num2;
      
      switch(value.operator1){

        case '+':
          value.sum = add(value.num1, value.num2);
          cout << "Sum: " << value.num1 << " + " << value.num2 << " = " << value.sum << endl;

          array_solutions(sizeVal, value, value.sum);
          history_main(value, sizeVal);
          break;


        case '-':
          value.difference = subtract(value.num1, value.num2);
          cout << "Difference: " << value.num1 << " - " << value.num2 << " = " << value.difference << endl;

          array_solutions(sizeVal, value, value.difference);
          history_main(value, sizeVal);
          break;


        case '*':
          value.product = multiply(value.num1, value.num2);
          cout << "Product: " << value.num1 << " * " << value.num2 << " = " << value.product << endl;

          array_solutions(sizeVal, value, value.product);
          history_main(value, sizeVal);
          break;


        case '/':
          value.quotient = divide(value.num1, value.num2);
          cout << "Quotient: " << value.num1 << " +/ " << value.num2 << " = " << value.quotient << endl;

          array_solutions(sizeVal, value, value.quotient);
          history_main(value, sizeVal);
          break;

        default:
          cout << "Invalid Operation";
      }

      cout << "\nCONTINUE: |Y/N|";
      cin >> backChar;

    }while(backChar == 'y' || backChar == 'Y');
   
   return 0;
   }