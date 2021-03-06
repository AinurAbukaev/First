#include "pch.h"
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <fstream>



int Hash(std::string str) {
	int sum = 0;
	if (str.size() % 2 != 0) {
		str += 'w';
	}
	for (int i = 0; i < str.size(); i += 2) {
		int proizv = str[i] * str[i + 1];
		int delen = str[i] / str[i + 1];
		sum += proizv;
		sum += delen;
	}
	while (sum >= 60000) {
		sum = sqrt(sum);
	}
	return sum;
}


struct Book
{
	std::string title;
	std::string author;
};
struct element {
	
	std::list<Book> Element;
};

class Lib
{
public:
	element lib[60000];
	void AddBook(std::string title, std::string author)
	{
		
		Book new_book;
		new_book.title = title;
		new_book.author = author;
		lib[Hash(title)].Element.push_back(new_book);
		std::cout << "Well done" << std::endl;
		}	

	

	void AddFromFile() {


		

		setlocale(LC_ALL, "RUSSIAN");
		std::ifstream file("lib.txt");
		std::string tmp;
		std::string temp1;
		std::string temp2;
		while (getline(file, tmp))

		{

			std::istringstream iss(tmp);
			std::string mystring;
			

			int i = 0;
			while (getline(iss, mystring, '\t')) {
				if (i == 0) {
					temp1 = mystring;
					

				}
				if (i == 1) {
					temp2 = mystring;
					
				}
				
				i++;
			}
			AddBook(temp1, temp2);
			

		}
	}

	void GetInfo(std::string title){

		std::list <Book>::iterator  iter;
		std::string index;
		int tmp = 0;
		for (iter = lib[Hash(title)].Element.begin(); iter != lib[Hash(title)].Element.end(); iter++)
		{
			if ((*iter).title == title)
			{
				tmp++;
				std::cout << (*iter).title<< "  "<<(*iter).author << std::endl;
			}

		}
		if (tmp == 0) {
			std::cout << "There is not book in library";
		}

	}
};

void choice() {
	Lib MyLib;
	std::string title, author;
	for (;;)
	{

		std::cout << "1 - add a book;" << std::endl << "2 - add a patient in the file;" << std::endl << "3 - find book;" << std::endl;
		int choice = 0;
		std::cin >> choice;

		int tmp = 0;
		switch (choice)
		{
		case 1:
			std::cout << "Enter the title and author"<<std::endl;
			std::cin >> title >> author;
			MyLib.AddBook(title, author);
			system("pause");
			break;
		case 2:
			MyLib.AddFromFile();
			break;
			system("pause");
		case 3:
			std::cout << "Enter the title" << std::endl;
			std::cin >> title;
            MyLib.GetInfo(title);
			system("pause");
			break;


		default:
			std::cout << "Sorry, it is impossible" << std::endl;
			system("pause");
			break;


		}

	}
}

int main()
{
	choice();
	return 0;
}