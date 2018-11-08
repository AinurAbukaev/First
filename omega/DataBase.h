#include <string>
#include "List.h"
#include "pch.h"
#include <iostream>
#include <fstream>


struct Patient
{
	std::string name;
	std::string surname;
	std::string age;
	std::string sex;
	std::string city;
	std::string VisitAmount;
};


struct DataBase
{
public:
	List<Patient> patients;
	void AddPatient_end();
	void GetInfo(int Id);
	void loadFile();
	void Add_First_Patient();
	void Add_Index_Patient();
	void Delete_Index_Patient();
	void Delete_First_Patient();
	void Delete_End_Patient();
	void Delete_All_Patient();
	void Get_Size_Patient();
};
void DataBase::AddPatient_end()
{
	Node<Patient> patient;
	std::cout << "Enter the name, surname, age, sex, city and visit amount  " << std::endl;
	std::cin >> patient.data.name >> patient.data.surname >> patient.data.age >> patient.data.sex >> patient.data.city >> patient.data.VisitAmount;
	patients.add_end(patient.data);
}
void DataBase::Add_First_Patient() 
{
	Node<Patient> patient;
	std::cout << "Enter the name, surname, age, sex, city and visit amount" << std::endl;
	std::cin >> patient.data.name >> patient.data.surname >> patient.data.age >> patient.data.sex >> patient.data.city >> patient.data.VisitAmount;
	patients.add_first(patient.data);
}


void DataBase::Delete_Index_Patient() {
	int Id = 0;
	std::cout << "Enter the Id" << std::endl;
	std::cin >> Id;
	patients.delete_index(Id);
}
void DataBase::Add_Index_Patient()
{
	int Id = 0;
	Node<Patient> patient;
	std::cout << "Enter the name, surname, age, sex, city, visit amount and Id" << std::endl;
	std::cin >> patient.data.name >> patient.data.surname >> patient.data.age >> patient.data.sex >> patient.data.city >> patient.data.VisitAmount >> Id;
	patients.add_index(patient.data, Id);
}

void DataBase::Delete_First_Patient() {
	patients.delete_first();
}
void DataBase::Delete_End_Patient() {
	patients.delete_end();
}
void DataBase::Delete_All_Patient() {
	patients.delete_all();
}
void DataBase::Get_Size_Patient() {
	patients.GetSize();
}
void DataBase::GetInfo(int Id)
{
	Patient& patient = patients.find(Id);
	std::cout << " " << patient.name << " " << patient.surname << " " << patient.age << " " << patient.sex << " " << patient.city << " " << patient.VisitAmount << " " << std::endl;

}
void DataBase::loadFile()
{
	std::string filename;
	std::cin >> filename;
	std::ifstream tmp(filename);

	while (tmp)
	{

		std::string mystring;
		Node<Patient> patient;
		for (int i = 0; i < 6; i++)
		{
			std::getline(tmp, mystring, ' ');
			if (i == 0) {
				patient.data.name = mystring;
			}
			if (i == 1) {
				patient.data.surname = mystring;
			}
			if (i == 2) {
				patient.data.age = mystring;
			}
			if (i == 3) {
				patient.data.sex = mystring;
			}
			if (i == 4) {
				patient.data.city = mystring;
			}
			if (i == 5) {
				patient.data.VisitAmount = mystring;
			}
			
			mystring = " ";
					   
		}
		patients.add_end(patient.data);


	}

}

