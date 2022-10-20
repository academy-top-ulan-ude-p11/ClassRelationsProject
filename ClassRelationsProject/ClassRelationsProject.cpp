#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point2D
{
	int x;
	int y;
public:
	Point2D(int x = 0, int y = 0) : x{ x }, y{ y } {}
	friend std::ostream& operator<<(std::ostream& out, Point2D p)
	{
		out << "x: " << p.x << ", y: " << p.y;
		return out;
	}
	void SetPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class Line
{
	Point2D pointBase;
	int dx;
	int dy;
public:
	Line(Point2D point, int dx, int dy) 
		: pointBase{ point }, dx{ dx }, dy{ dy } {}
	Line(int x = 0, int y = 0, int dx = 0, int dy = 0)
		: pointBase{ Point2D(x, y) }, dx{dx}, dy{dy} {}
	friend std::ostream& operator<<(std::ostream& out, Line l)
	{
		out << l.pointBase << ", dx: " << l.dx << ", dy: " << l.dy;
		return out;
	}
};

class Student
{
	char name[50];
public:
	Student(const char* name)
	{
		strcpy(this->name, name);
	}
	void PrintName()
	{
		std::cout << name;
	}
};

class Group
{
	Student** students;
	int sizeAll;
	int sizeCurr;
public:
	Group(int size) : sizeAll{ size }
	{
		students = new Student*[sizeAll];
		sizeCurr = 0;
	};
	~Group()
	{
		if (students)
		{
			delete[]students;
		}
			
	}

	void Add(Student* student)
	{
		if(sizeCurr < sizeAll)
			students[sizeCurr++] = student;
	}
	int GetSizeCurr()
	{
		return sizeCurr;
	}
};

class Boss;
class Employe;

class Company
{
	Boss* boss;
	Employe* employes[10];
	int emplCount = 0;
public:
	void AddBoss(Boss* boss)
	{
		this->boss = boss;
	}
	void AddEmployes(Employe* employe)
	{
		employes[emplCount++] = employe;
	}
};
class Boss
{
	Company* company;
public:
	void AddCompany(Company* acompany)
	{
		this->company = company;
	}
};



class Patient;
class Doctor
{
	Patient** patients;
	int patientsCount;
public:
	Doctor()
	{
		patients = nullptr;
		patientsCount = 0;
	}
	~Doctor()
	{
		if (patients)
			delete[]patients;
	}
	void AddPatient(Patient* patient)
	{
		Patient** patientsNew = new Patient*[patientsCount + 1];
		for (int i = 0; i < patientsCount; i++)
			patientsNew[i] = patients[i];
		patientsNew[patientsCount++] = patient;
		delete[]patients;
		patients = patientsNew;
	}
};

class Patient
{
	Doctor** doctors;
};

class Human
{
	char name[50];
	Human* parent;
};

int main()
{
	Line line;

	Student student("Billy");
	student.PrintName();
	
	{
		Group group(10);
		group.Add(&student);
	}
	
	student.PrintName();

}
