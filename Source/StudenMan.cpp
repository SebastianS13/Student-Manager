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


	return 0;
}
