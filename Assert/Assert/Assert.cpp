#include "pch.h"
#include <iostream>
#include <string>
#include <cassert>
#define ASSERT_EQUALL(a,b) if(abs(a-b)>0.000000001){ std::cout << a << " != "<< b<< std::endl; assert(abs(a-b)<0.000000001);}
#define ASSERT_NOTEQUALL(a,b)  if(abs(a-b)<0.000000001){ std::cout << a << " == "<< b<< std::endl; assert(abs(a-b)>0.000000001);}
#define ASSERT_TRUE(a) if(abs(a) < 0.000000001) {std::cout << a << " == 0" << std::endl; assert(abs(a) > 0.000000001);}
#define ASSERT_FALSE(a) if (abs(a) > 0.000000001) {std::cout << a << " =! 0" << std::endl; assert(abs(a) < 0.000000001);}
void assertNotEqual(float a, float b) {
	if (abs(a - b) < 0.000000001) {
		std::cout << a << " == " << b << std::endl;
		assert(abs(a - b) > 0.000000001);
	}
}
void assertEqual(float a, float b) {
	if (abs(a - b) > 0.000000001) {
		std::cout << a << " != " << b << std::endl;
		assert(abs(a - b) < 0.000000001);
	}
}
void assertFalse(float a) {
	if (abs(a) < 0.000000001) {
		std::cout << a << " == 0" << std::endl;
		assert(abs(a) > 0.000000001);
	}
}
void assertTrue(float a){
	if (abs(a) > 0.000000001) {
		std::cout << a << " != 0" << std::endl;
		assert(abs(a) < 0.000000001);
	}
}

	int main()
	{
		float a, b;
		std::cin >> a;
		std::cin >> b;
		ASSERT_EQUALL(a, b);
		ASSERT_NOTEQUALL(a, b);
		return 0;
	}