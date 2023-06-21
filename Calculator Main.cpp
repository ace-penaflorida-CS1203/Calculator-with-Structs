
#include <iostream>
# include <cstdlib>
# include <string>
# include <typeinfo>
# include <limits>

using namespace std

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
  return num1 + num2;
}

double subtract(float num1, float num2) {
  return num1 - num2;
}

double multiply(float num1, float num2) {
  return num1 * num2;
}

double divide(float num1, float num2) {
  return num1 / num2;
}


// 1.) Handling Errors
bool isValidOperation(char operation) {
    return operation == '+' || operation == '-' || operation == '*' || operation == '/';
}

bool isValidInput(int num1, char operation, int num2) {
    if (cin && isValidOperation(operation)) {
        return true;
    } else {
        system("cls");
        cout << "Error: Input valid values and operator. \n\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}


//  2.) resuable code for each operation: the sizeVal is passed as a reference so that the value will update for each iteration
void array_solutions(int &sizeVal, Values& value, double result){ 
  if(sizeVal < MAX_VAL_HISTORY){
          value.arrayNum1[sizeVal] = value.num1;
          value.arrayNum2[sizeVal] = value.num2;
          value.arrayOperator1[sizeVal] = value.operator1;
          value.arrayResult[sizeVal] = result; 
          sizeVal++;
        }
}

//  3.) outputting the history
void history_main(const Values valueInfo, int sizeVal){ // const keyword indicates that the valueInfo object cannot be modified within the function.
  system("cls");
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


// 4.) function if the user wants to perform another operation to the previous result
void continueOperation (double prevResult){
  double newValue;
  double localResult = prevResult;
  char newOperation;
  bool isValid = false;
  

  while (!isValid) {
        double loopValues = localResult;
        cout << "\n   New Operation: " << loopValues; 
        cin >> newOperation >> newValue;

        switch(newOperation){
          case '+':
            localResult = add(loopValues,newValue);
            cout << "   New Result: " << loopValues << " + " << newValue << " = " << localResult << endl;
            break;
          case '-':
            localResult = subtract(loopValues,newValue);
            cout << "   New Result: " << loopValues << " - " << newValue << " = " << localResult << endl;
            break;
          case '*':
            localResult = multiply(loopValues,newValue);
            cout << "   New Result: " << loopValues << " * " << newValue << " = " << localResult << endl;
            break;
          case '/':
            localResult = divide(loopValues,newValue);
            cout << "   New Result: " << loopValues << " / " << newValue << " = " << localResult << endl;
            break;
        }
        
        isValid = isValidInput(loopValues, newOperation, newValue); // for input validation: returns a bool 
        
        }
}

// 5.) resuable function for continuing the operation
void userContinueChoice(double result) {
    char userInput;
    bool shouldContinue = true;
    while (shouldContinue) {
        cout << "\nCONTINUE OPERATION: |Y/N|";
        cin >> userInput;
        if (userInput == 'y' || userInput == 'Y') {
            continueOperation(result);
        } else if (userInput == 'n' || userInput == 'N') {
            shouldContinue = false;
        }
    }
}


int main() {

    Values value;
    int sizeVal = 0;
    string input;
    bool isValid = false;

    do{
      system("cls");
      
      while (!isValid) {
        cout << "_____Mini Calculator_____\n\n";
        cout << "   Enter Equation: ";
        cin >> value.num1 >> value.operator1 >> value.num2;

        isValid = isValidInput(value.num1, value.operator1, value.num2); // returns a bool 
        }
      
      
      switch(value.operator1){

        case '+':
          value.sum = add(value.num1, value.num2);
          cout << "\n   Sum: " << value.num1 << " + " << value.num2 << " = " << value.sum << endl;

          array_solutions(sizeVal, value, value.sum); // function for storing the values into the arrays
          userContinueChoice(value.sum); // function if the user wanted to perform new operation to the recent result
          history_main(value, sizeVal); // function for  history
          break;


        case '-':
          value.difference = subtract(value.num1, value.num2);
          cout << "\n   Difference: " << value.num1 << " - " << value.num2 << " = " << value.difference << endl;

          array_solutions(sizeVal, value, value.difference);
          userContinueChoice(value.difference);
          history_main(value, sizeVal);
          break;


        case '*':
          value.product = multiply(value.num1, value.num2);
          cout << "\n   Product: " << value.num1 << " * " << value.num2 << " = " << value.product << endl;

          array_solutions(sizeVal, value, value.product);
          userContinueChoice(value.product);
          history_main(value, sizeVal);
          break;


        case '/':
          value.quotient = divide(value.num1, value.num2);
          cout << "\n   Quotient: " << value.num1 << " +/ " << value.num2 << " = " << value.quotient << endl;

          array_solutions(sizeVal, value, value.quotient);
          userContinueChoice(value.quotient);
          history_main(value, sizeVal);
          break;

        default:
          cout << "\n   Invalid Operation";
      }

      cout << "\n   CONTINUE: |Y/N|";
      cin >> backChar;
      isValid = false; // resetting the variable 

    }while(backChar == 'y' || backChar == 'Y');
   
   return 0;
   }
