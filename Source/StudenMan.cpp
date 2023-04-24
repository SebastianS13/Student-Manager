#include <iostream>
#include <fstream>

std::string GetStudentGrade(std::string Name)
{
	std::ifstream Students;
	Students.open("Student.dat");

	if (Students.is_open())
	{
		std::string CurrentName;
		std::string CurrentSurname;
		std::string CurrentGrade;

		while (Students >> CurrentName >> CurrentSurname >> CurrentGrade)
		{
			if (CurrentName == Name)
			{
				return Name + "'s grade is: " + CurrentGrade;
			}
		}
	}
	else
	{
		std::cout << "UNABLE TO OPEN 'Students.dat'" << std::endl;
	}

	Students.close();

	return "";
}

void NewStudent()
{
	std::string Name;
	std::string Surname;
	std::string Grade;

	std::cout << "Enter Name, Surname, Grade" << std::endl;
	
	std::cout << "Name: ";
	std::cin >> Name;

	std::cout << "Surname: ";
	std::cin >> Surname;

	std::cout << "Grade: ";
	std::cin >> Grade;


	std::ofstream Students;
	Students.open("Student.dat");

	if (Students.is_open())
	{
		Students << Name << " " << Surname << " " << Grade << std::endl;
	}
	else
	{
		std::cout << "UNABLE TO OPEN 'Students.dat'" << std::endl;
	}

	Students.close();

}

int main()
{
	int choice = 1;

	while (true)
	{

		std::cout << "1. Add new student \n2. Get student grade \nAnything else: Quit" << std::endl;
		std::cin >> choice;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		if (choice == 1)
		{
			NewStudent();
		}
		else if (choice == 2)
		{
			std::string Name;
			std::cout << "Name: ";
			std::cin >> Name;
			std::cout << GetStudentGrade(Name) << std::endl;
		}
		else
		{
			break;
		}

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
