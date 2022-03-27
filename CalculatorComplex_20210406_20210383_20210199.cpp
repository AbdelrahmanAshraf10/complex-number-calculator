// FCAI – Programming 1 – 2022 - Assignment 2 
// Program Name: CalculatorComplex_20210406_20210383_20210199.cpp
// Program Description: calculator for complex numbers 
// Last Modification Date: 27/3/2022
// Author1 and ID and Group: 20210406 , A
// Author2 and ID and Group: 20210383 , A
// Author3 and ID and Group: 20210199 , A
// Teaching Assistant: 

#include <iostream>;
#include <string>;
#include <regex>;
#include <math.h>;
using namespace std;


bool complex_format(string user_text);
float extract_num(string user_text, float* real, float* imag);
double multiplication(float real1, float imag1, float real2, float imag2);
double addition(float real1,float real2,float imag1,float imag2);
double division(float real1, float real2,float imag1,float imag2);



int main()
{
	string user_text1, user_text2;
	float real1 = 0, imag1 = 0, real2 = 0, imag2 = 0;
	int mode;

	cout << " please enter your first complex number \n in this format (Num1+Num2i): ";
	cin >> user_text1;

	//checking the entered format for the first complex number
	while (complex_format(user_text1) == false)
	{
		cout << " invalid inputs or missing brackets!\n please try again: ";
		cin >> user_text1;
		continue;
	}
	cout << endl;
	extract_num(user_text1, &real1, &imag1);


	cout << " please enter your second complex number \n in this format (Num1+Num2i): ";
	cin >> user_text2;

	//checking the entered format for the second complex number
	while (complex_format(user_text2) == false)
	{
		cout << " invalid inputs or missing brackets!\n please try again: ";
		cin >> user_text2;
		continue;
	}
	extract_num(user_text2, &real2, &imag2);
	cout << endl;


	//determining the required operation for the complex numbers 
	cout << " please enter the number for the required mode:\n 1-addition\n 2-multiplication\n 3-division\n : ";
	cin >> mode;
	if (mode == 1)
	{
		addition(real1, real2, imag1, imag2);
	}
	if (mode == 2)
	{
		multiplication(real1, imag1, real2, imag2);
	}
	if (mode == 3)
	{
		division(real1, real2, imag1, imag2);
	}
}



//function for checking the complex format
bool complex_format(string user_text)
{
	regex valid_complex("[(]([+-])*[0-9]+(\\.[0-9]*)?[+-][0-9]+(\\.[0-9]*)?[i][)]");
	return regex_match(user_text, valid_complex);
}



//function to extract the real and imagenary parts in the complex number
float extract_num(string user_text, float* real, float* imag)
{
	int pos_plus = user_text.find('+');
	int pos_minus = user_text.find('-');
	int pos_i = user_text.find('i');
	int pos_sign = max(pos_minus, pos_plus);
	*real = stof(user_text.substr(1, pos_sign));
	*imag = stof(user_text.substr(pos_sign, pos_i));
	return 0;
}



//multyplying two complex numbers
double multiplication(float real1, float imag1, float real2, float imag2)
{
	float part1 = (real1 * real2) - (imag1 * imag2);
	float part2 = (real1 * imag2) + (real2 * imag1);
	cout << " the multiplication result is: ";
	cout << part1 << '+' << part2 << 'i' << "\n Thanks for using FCAI Complex Number Calculator!";
	return 0;
}



//dividing two complex numbers
double division(float real1, float real2, float imag1, float imag2)
{
	float denom;
	denom = (pow(real2, 2) + pow(imag2, 2));
	float nom1 = ((real1 * real2) + (imag1 * imag2));
	float nom2 = ((imag1 * real2) - (real1 * imag2));
	float part1 = (nom1 / denom);
	float part2 = (nom2 / denom);
	cout << " the division result is: ";
	cout << part1 << '+' << part2 << 'i' << "\n Thanks for using FCAI Complex Number Calculator! ";
	return 0;
}



//adding two complex numbers
double addition(float real1, float real2, float imag1, float imag2)
{
	float part1 = (real1 + real2);
	float part2 = (imag1 + imag2);
	cout << " the addition result is: ";
	cout << part1 << '+' << part2 << 'i' << "\n Thanks for using FCAI Complex Number Calculator!";
	return 0;
}
