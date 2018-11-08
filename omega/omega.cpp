#include "pch.h"
#include <iostream>
#include <string>
#include "DataBase.h"

void choice() {
	DataBase db;
	for (;;)
	{

		std::cout << "1 - add a patient to the end;" << std::endl<<"2 - add a patient to the top;" << std::endl <<"3 - add a patient by index;" << std::endl <<"4 - add patients from file;" << std::endl <<"5 - delete the first patient;"  << std::endl<<"6 - delete the last patient;" << std::endl <<"7 - delete all patients;" << std::endl <<"8 - delete the patient by index; " << std::endl << "9 - find out info about a person;" << std::endl <<"10 - find out the size; " << std::endl;
		int choice = 0;
		std::cin >> choice;

		int tmp = 0;
		switch (choice)
		{
		case 1:
			db.AddPatient_end();
			break;
		case 2:
			db.Add_First_Patient();
		case 3:
			db.Add_Index_Patient();
		case 4:
			std::cout << "Enter the filename" << std::endl;
			db.loadFile();
			break;	
		case 5:
			db.Delete_First_Patient();
		case 6:
			db.Delete_End_Patient();
		case 7:
			db.Delete_All_Patient();
		case 8:
			db.Delete_Index_Patient();
		case 9:
			std::cout << "Enter the Id" << std::endl;
			std::cin >> tmp;
			db.GetInfo(tmp);
			break;
		case 10:
			db.Get_Size_Patient();	



		default:
			std::cout << "Sorry, it is impossible" << std::endl;
			break;


		}

	}
}
int main()
{
	choice();
	return 0;
}

