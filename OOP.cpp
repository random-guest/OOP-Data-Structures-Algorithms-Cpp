/*
	OBject Oriented Programming in C++
	Simple example that covers the main four OOP principles:
		1. Encapsulation
		2. Abstraction
		3. Inheritance
		4. Polymorphism
	Regerence: 
	https://www.youtube.com/watch?v=wN0x9eZLix4&ab_channel=freeCodeCamp.org
	
	Author : Abdulkarim Atrash
	E-mail : atrashabdulkarim@gmail.com
	*/

#include <iostream>
using namespace std;
/*
abstract class reflects abstraction principle of OOP
this is the contract, the class itself, that whichever class decides to sign, has to
provide an implementation for a method called AskForPromotion. (could be more)!
This obligatory task is achieved by the usage of abstract class
*/


class AbstractEmployee {
	virtual void AskForPromotion() = 0; 
	/*
	an example of a complicated task the need abstraction. 
	by virutal, we force the signing class to implement this method in. By this, 
	we have converted the class into abstrach class.
	*/
};


// here Employee class signed the contract and has to implement
// the method AskForPromotion.



class Employee:AbstractEmployee{ //Employee inherits from AbstractEmployee

private:
	
	string Company;
	int Age;
protected: // data here will be accessed from the derived classes !
	string Name;
public:
	// Encapsulation in Action: Setter & Getter for methods
	// that act on Data that we wish to prevent direct access to
	void setName(string name) {
		Name = name;
	}
	string getName() {
		return Name;
	}
	void setCompany(string company) {
		Name = company;
	}
	string getCompany() {
		return Company;
	}
	void setAge(int age) {
		if (age >= 18) {
			Age = age;
		}		
	}
	int getAge() {
		return Age;
	}
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
	void IntroduceYourself() {
		cout << "Name - " << Name << endl;
		cout << "Company - " << Company << endl;
		cout << "Age - " << Age << endl;
	}
	void AskForPromotion() {
		if (Age > 30) {
			cout << Name << " Got Promoted! " << endl;
		} 
		else {
			cout << Name << " Sorry, No Promotion for you!" << endl;
		}
	}

	// polymorphism in Action !
	virtual void Work() {

		cout << Name << " is checking email, task backlog, performing tasks..." << endl;

	}
	};



// interhitance in Action!
// adding public keyword will make Employee's method public to derived class
// otherwise, class methods are by default private


class Developer :public Employee { 

public:
	string FavProgrammingLanguage;
	Developer(string name, string company, int age, string FavProgLang) : Employee(name, company, age) 
	{
		FavProgrammingLanguage = FavProgLang;
	}
	void FixBug() {
		cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;

	}

	// polymorphism in Action !
	virtual void Work() {
		cout << Name << "  is writing " << FavProgrammingLanguage << " code" << endl;
	}
};




class Teacher :public Employee {
public:
	string Subject;
	Teacher(string name, string company, int age, string subject) :Employee(name, company, age)
	{
		Subject = subject;
	}
	void PrepareLesson() {
		cout << Name << " is preparing " << Subject << " lesson" << endl;
	}

	// polymorphism in Action !
	virtual void Work() {
		cout << Name << "  is teaching " << Subject <<  endl;
	}
};



int main() 
{
	//Employee employee1 = Employee("yo", "MK", 35);
	//Employee employee2 = Employee("Samer", "Google", 35);
	//employee1.AskForPromotion();
	//employee2.AskForPromotion();
	
	Developer dev = Developer("Kan", "YT", 34, "C++");
	//dev.FixBug();
	//dev.AskForPromotion();

	Teacher Tech = Teacher ("karim", "ISSD", 25,"Mathematics");
	//Tech.IntroduceYourself();
	//Tech.PrepareLesson();

	//employee1.Work();
	//me.Work();
	//karim.Work();

	/* The most common use of polymorphism is when a parent class
	* reference is used to refer to a child class object
	*/
	// create a pointer to a class Employee

	Employee* e1 = &dev; // a pointer to a bass class e, can hold reference to a derived class dev
	// the above statement is correct because Developer class inherits from Employee


	Employee* e2 = &Tech;
	
	// The next two lines worked because of the virtual word!
	// note: when a virtual function is invoked, it first checks if
	// there is an implementation in the derived class, if it does exist
	// then use it!
	
	e1->Work();
	e2->Work();
}