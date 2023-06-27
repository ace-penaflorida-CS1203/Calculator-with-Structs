# include <iostream>
# include <cstdlib>
# include <string>
# include <limits>
using namespace std;

// Globals
const int MAX_VAL_HISTORY = 100;
char backChar;
int arrayNum1[MAX_VAL_HISTORY]; // inittializing the arrays in the global scope so that their values persist throughout the lifetime of the program
int arrayNum2[MAX_VAL_HISTORY];
char arrayOperator1[MAX_VAL_HISTORY];
double arrayResult[MAX_VAL_HISTORY];
string outputArray[MAX_VAL_HISTORY];

string newOutputArray[MAX_VAL_HISTORY];
double prevArrayValue[MAX_VAL_HISTORY];
char newOperator[MAX_VAL_HISTORY];
double arrayNewValue[MAX_VAL_HISTORY];
double arrayNewResult[MAX_VAL_HISTORY];

int sizeVal = 0;

class Values{
public:
  float num1, num2;
  double sum, difference, product, quotient;
  char operator1; 

  double add(){
    return num1 + num2;}

  double subtract() {
    return num1 - num2;}

  double multiply() {
    return num1 * num2;}

  double divide() {
    return num1 / num2;}

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

// 2.) resuable code for each operation: the sizeVal is passed as a reference so that the value will update for each iteration
  void array_solutions(double result){ 
    if(sizeVal < MAX_VAL_HISTORY){
      arrayNum1[sizeVal] = num1;
      arrayNum2[sizeVal] = num2;
      arrayOperator1[sizeVal] = operator1;
      arrayResult[sizeVal] = result; 
      sizeVal++;
    }
  }

  void secondaryArray_solutions(double num1, char newOperation, double num2, double newResult){
    if(sizeVal < MAX_VAL_HISTORY){
      prevArrayValue[sizeVal] = num1;
      arrayNewValue[sizeVal] = num2;
      newOperator[sizeVal] = newOperation;
      arrayNewResult[sizeVal] = newResult; 
      sizeVal++;
    }
  }
  



//                  TO FIX:  HISTORY
  void secondary_history(){ // const keyword indicates that the valueInfo object cannot be modified within the function.
    system("cls");
    
    cout << "\n|                  HISTORY               |   \n\n"; 
    for (int i = 0; i < sizeVal; i++){ 
      // concatenating the converted values into 1 variable
      string concatValues = to_string(i + 1) + ".) " + to_string(prevArrayValue[i]) + " " + newOperator[i] + " " + to_string(arrayNewValue[i]) + " = " + to_string(arrayNewResult[i]);

      newOutputArray[i] = concatValues; // storing concatValues to outputArray
      cout << newOutputArray[i] <<  " | Address: " << &newOutputArray[i] << endl;
      //       dereferenncing                             address
    }
  }

//  3.) outputting the history
  /*void history_main(){ // const keyword indicates that the valueInfo object cannot be modified within the function.
    system("cls");
    //string outputArray[100]; // with index 100
    cout << "\n|                  HISTORY               |   \n\n"; 
    for (int i = 0; i < sizeVal; i++){ 
      // concatenating the converted values into 1 variable
      string concatValues = to_string(i + 1) + ".) " + to_string(arrayNum1[i]) + " " + arrayOperator1[i] + " " + to_string(arrayNum2[i]) + " = " + to_string(arrayResult[i]);

      outputArray[i] = concatValues; // storing concatValues to outputArray
      cout << outputArray[i] <<  " | Address: " << &outputArray[i] << endl;
      //       dereferenncing                             address

      string newConcatValues = to_string(i + 1) + ".) " + to_string(prevArrayValue[i]) + " " + newOperator[i] + " " + to_string(arrayNewValue[i]) + " = " + to_string(arrayNewResult[i]);

      newOutputArray[i] = newConcatValues; // storing newConcatValues to outputArray
      cout << newOutputArray[i] <<  " | Address: " << &newOutputArray[i] << endl;
      //       dereferenncing                             address
    }

  }*/




/*
  void history_main(){ // const keyword indicates that the valueInfo object cannot be modified within the function.
    system("cls");
    cout << "\n|                  HISTORY               |   \n\n";
    int i = 0, j = 0;
      while (i < sizeVal && j < sizeVal) {
      string concatValues;
      if (arrayResult[i] != 0) {
        concatValues = to_string(i + 1) + ".) " + to_string(arrayNum1[i]) + " " + arrayOperator1[i] + " " + to_string(arrayNum2[i]) + " = " + to_string(arrayResult[i]);
        i++;
      } else {
        concatValues = to_string(j + 1) + ".) " + to_string(prevArrayValue[j]) + " " + newOperator[j] + " " + to_string(arrayNewValue[j]) + " = " + to_string(arrayNewResult[j]);
        j++;
      }*
      cout << concatValues <<  " | Address: " << &concatValues << endl;
      }
}*/

// 4.) function if the user wants to perform another operation to the previous result
  void continueOperation (double prevResult){
    double newValue;
    double localResult = prevResult;
    char newOperation;
    bool isValid = false;

    do {
      cout << "\n   CONTINUE OPERATION: |Y/N|";
      cin >> backChar;
      if (backChar == 'y' || backChar == 'Y') {
        double loopValues = localResult;
        cout << "\n   New Operation: " << loopValues; 
        cin >> newOperation >> newValue;

        switch(newOperation){
          case '+':
            localResult = loopValues + newValue;
            cout << "   New Result: " << loopValues << " + " << newValue << " = " << localResult << endl;
            break;

          case '-':
            localResult = loopValues - newValue;
            cout << "   New Result: " << loopValues << " - " << newValue << " = " << localResult << endl;
            break;

          case '*':
            localResult = loopValues * newValue;
            cout << "   New Result: " << loopValues << " * " << newValue << " = " << localResult << endl;
            break;

          case '/':
            localResult = loopValues / newValue;
            cout << "   New Result: " << loopValues << " / " << newValue << " = " << localResult << endl;
            break;
        }
        secondaryArray_solutions(loopValues, newOperation, newValue, localResult);
      }
    } while (backChar == 'y' || backChar == 'Y');
  }

// 5.) resuable function for continuing the operation
  void userContinueChoice(double result) {
      char userInput;
      bool shouldContinue = true;
      while (shouldContinue) {
          cout << "\n   CONTINUE OPERATION: |Y/N|";
          cin >> userInput;
          if (userInput == 'y' || userInput == 'Y') {
              continueOperation(result);
          } else if (userInput == 'n' || userInput == 'N') {
              shouldContinue = false;
          }
      }
  }

  Values(float value1, char operation1, float value2){
    num1 = value1;
    operator1 = operation1;
    num2 = value2;
  }
};


int main(){
  float num1, num2;
  double sum, difference, product, quotient;
  char operator1;
  //int sizeVal = 0;
  bool isValid = false;

  Values values(0.0f,'+',0.0f);

  do{
    system("cls");
    //sizeVal = 0; // reset sizeVal at the beginning of the loop
    
    while(!isValid)                                          {
      cout << "_____Mini Calculator_____\n\n";
      cout << "   Enter Equation: ";
      cin >> num1 >> operator1 >> num2;
      values = Values(num1, operator1, num2);
      isValid = values.isValidInput(num1, operator1, num2);   }

    switch(operator1){

      case '+':
        sum = values.add();
        cout << "\n   Sum: " << num1 << " + " << num2 << " = " << sum << endl;

        values.array_solutions(sum); // function for storing the values into the arrays
        values.userContinueChoice(sum); // function if the user wanted to perform new operation to the recent result
        values.history_main(); // function for  history
        //values.secondary_history();
        break;

      case '-':
        difference = values.subtract();
        cout << "\n   Difference: " << num1 << " - " << num2 << " = " << difference << endl;

        values.array_solutions(difference); 
        values.userContinueChoice(difference); 
        values.history_main(); 
        //values.secondary_history();
        break;

      case '*':
        product = values.multiply();
        cout << "\n   Product: " << num1 << " * " << num2 << " = " << product << endl;

        values.array_solutions(product); 
        values.userContinueChoice(product); 
        values.history_main(); 
        //values.secondary_history();
        break;

      case '/':
        quotient = values.divide();
        cout << "\n   Quotient: " << num1 << " / " << num2 << " = " << quotient << endl;

        values.array_solutions(quotient); 
        values.userContinueChoice(quotient); 
        values.history_main(); 
        //values.secondary_history();
        break;
  }

  
    cout << "\n   CONTINUE: |Y/N|";
    cin >> backChar;
    isValid = false; // resetting the variable 

  }while(backChar == 'y' || backChar == 'Y');

  
return 0;

}