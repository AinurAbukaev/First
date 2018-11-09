#include <string>
#include "List.h"
#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>



struct Patient
{
	std::string name;
	std::string surname;
	int age;
	std::string sex;
	std::string city;
	int VisitAmount;
};


class DataBase
{
public:
	List<Patient> patients;
	void AddPatient_end();
	void GetInfo(int Id);
	
	void Add_First_Patient();
	void Add_Index_Patient();
	void Delete_Index_Patient();
	void Delete_First_Patient();
	void Delete_End_Patient();
	void Delete_All_Patient();
	int Get_Size_Patient();
	void loadFile1();
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
int DataBase::Get_Size_Patient() {
	return patients.GetSize();
}
void DataBase::GetInfo(int Id)
{
	Patient& patient = patients.find(Id);
	std::cout << " " << patient.name << " " << patient.surname << " " << patient.age << " " << patient.sex << " " << patient.city << " " << patient.VisitAmount << " " << std::endl;

}

void DataBase::loadFile1() {
	setlocale(LC_ALL, "RUSSIAN");
	std::ifstream file("patients.txt");
	std::string tmp;

	while (getline(file, tmp))

	{		
		Node<Patient> patient;
		std::istringstream iss(tmp);
		std::string mystring;
		int i = 0;
		while (getline(iss, mystring, '\t')) {
				if (i == 0) {
					patient.data.name = mystring;
				}
				if (i == 1) {
					patient.data.surname = mystring;
				}
				if (i == 2) {
					patient.data.age = atoi(mystring.c_str()) ;
				}
				if (i == 3) {
					patient.data.sex = mystring;
				}
				if (i == 4) {
					patient.data.city = mystring;
				}
				if (i == 5) {
					patient.data.VisitAmount = atoi(mystring.c_str());
				}
				patients.add_end(patient.data);
				i++;
			}
			
	}
}