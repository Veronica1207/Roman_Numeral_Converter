//Assignment1: RomanNumeralConversion.cpp
//Driver class for the program. Converts Roman numeral values into their
//equivalent Hindu-Arabic numeric values.
//
//Veronica Logvinenko, A01208105
//Jan. 25th, 2021

#include <iostream>
#include <cctype>

using namespace std;
static const double NUMBER_OF_ITERATIONS = 10;

//function main begins program execution
int main(){
	
	bool exit;			//true, if \n is reached or a bad value is entered; otherwise false
	bool badValue;		//true, if bad value is entered; otherwise false

	cout << "10 Roman numeral values will be input and converted into" << endl;
	cout << "their equivalent Hindu-Arabic numeric values." << endl;

	//loop until NUMBER_OF_ITERATIONS is reached
	for (unsigned int i = 1; i <= NUMBER_OF_ITERATIONS; ++i)
	{		
		exit = false;	
		badValue = false;
		int value = 0;	//Hindu-Arabic equivalent for a single Roman numeral value
		int sum = 0;	//sum of all values entered
		int temp = 0;	//a previous value

		cout << "\nInput Roman numeral # " << i << ": ";
		char romanNumber = 0;

		//loop until exit is true
		while(exit == false) 
		{			
			romanNumber = cin.get();
			romanNumber = toupper(romanNumber);			
					
			//determine what char was entered
			switch (romanNumber)
			{
				case 'I':
					value = 1;		//assign 1 to value
					sum += value;	//add to the sum
					temp = 1;		//assign 1 to temp
					break;

				case 'V':
					value = 5;		//assign 5 to value
					if (temp == 1)	//check if a smaller number was entered before
					{
						value = value - temp;    //if yes, calculate a new value						
						sum += (value - temp);	 //add new value to and subtract the previously added value from the sum					
					}
					else						 
					{							 //if no,
						sum += value;			 //add new value to the sum
					}
					temp = 5;					 //assign 5 to temp
					break;

				case 'X':
					value = 10;
					if (temp == 1 || temp == 5) 
					{
						value = value - temp;
						sum += (value - temp);
					}
					else 
					{
						sum += value;
					}
					temp = 10;
					break;

				case 'L':
					value = 50;
					if (temp == 1 || temp == 5 || temp == 10)
					{
						value = value - temp;
						sum += (value - temp);
					}
					else 
					{
						sum += value;
					}
					temp = 50;
					break;

				case 'C':
					value = 100;
					if (temp == 1 || temp == 5 || temp == 10 || temp == 50)
					{
						value = value - temp;
						sum += (value - temp);
					}
					else 
					{
						sum += value;
					}
					temp = 100;
					break;

				case 'D':
					value = 500;
					if (temp == 1 || temp == 5 || temp == 10 || temp == 50 || temp == 100)
					{
						value = value - temp;
						sum += (value - temp);
					}
					else 
					{
						sum += value;
					}
					temp = 500;
					break;

				case 'M':
					value = 1000;
					if (temp == 1 || temp == 5 || temp == 10 || temp == 50 || temp == 100 || temp == 500)
					{
						value = value - temp;
						sum += (value - temp);
					}
					else 
					{
						sum += value;
					}
					temp = 0;
					break;
				
				case '\n':
					exit = true; //exit the loop if \n is reached
					break;
				default: 
					cin.clear();				//clear the error
					cin.ignore(INT_MAX, '\n');  //flush the input buffer
					sum = 0;								
					cerr << romanNumber << " Error - last character was not valid!!!" << '\n';
					badValue = true;
					exit = true;
			}
			
			//print all valid chars
			if (romanNumber != '\n' && badValue == false) 
			{
				cout << romanNumber;
			} 

		} //end while loop
		
		//print the sum
		if (sum != 0) {
			cout << " = " << sum << endl;
		}

	} //end for loop

	cout << "\nTHAT'S ALL FOLKS :)\n" << endl;

	system("pause");
} //end main