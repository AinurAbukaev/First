#include "pch.h"
#include <iostream>
#include <math.h>
#include <cmath>

bool equal(double a, double b) {
	double tmp = a - b;
	if (abs(tmp)<0.00000001) {
		return true;
	}
	else {
		return false;
	

	}
	
};
double det_square(int a,int b,int c) {
	double D_2 = b * b - 4 * a*c;
	return D_2;	   
}

bool square(int a, int b, int c) {
	
	if (equal(a, 0)) {
		std::cout << -b / c;
		return true;
	} 
	else {
		return false;

	}
	
	
}
bool norm(int a, int b, int c){
	if (equal(a, 0) && equal(c, 0) && equal(b, 0)) {
		return true;
	}
	else {
		return false;
	}
}
bool nenorm(int a, int b, int c) {
	if (equal(a, 0) && (!equal(c, 0)) && equal(b, 0)) {
		return true;
	}
	else {
		return false;
	}
}
double x1(int a, int b, int c){
	int x1 =( -b - sqrt(det_square(a, b, c)) )/ 2 * a;
		return x1;
}
double x2(int a, int b, int c) {
	int x2 =( -b + sqrt(det_square(a, b, c))) / 2 * a;
		return x2;
}



int main()
{
	std::cout << "Enter a,b,c"<< std::endl;
	double a, b, c;
	std::cin >> a >> b >> c;
	if (norm(a, b, c)) {
			std::cout << "All real numbers";
			return 0;
		}
	if (nenorm(a, b, c) || det_square(a, b, c) < 0) {

			std::cout << "No real decision";
			return 0;
		}
	if (square(a, b, c)) {
		return 0;
	};
	if (equal(x1(a, b, c), x2(a, b, c))) {
		std::cout << x1(a, b, c);
	}
	else {
		std::cout << x1(a, b, c) << "  " << x2(a, b, c);
	}
	return 0;
	
}
