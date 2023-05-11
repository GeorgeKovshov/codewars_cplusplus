#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void sayHi(string name, int age); // the declaration of function


void get_age() {
	int age;
	cout << "Enter your age: ";
	cin >> age;
	cout << "You are " << age << " years old" << endl;
}

void get_name() {
	string name;
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "You are " << name<< endl;

}

void calculator() {
	int num1, num2;
	cout << "Enter first number: ";
	cin >> num1;

	cout << "Enter second number: ";
	cin >> num2;

	cout << num1 + num2; 

}

void lucky_nums() {
	int luckyNums[] = { 4,8,14,53,23 };
	int luckyNums2[20] = { 4,8,14,53,23 }; //number inside brackets is the declaration of the array length

	cout << luckyNums[2] << endl;
	luckyNums[2] = 119;
	cout << luckyNums[2] << endl;
}



double cube(double num) {
	double result = num * num * num;
	return result;

}

void isTall_male(bool isMale, bool isTall) {
	if (isMale && isTall) {
		cout << "You are a tall male";
	}
	else if (isMale || !isTall) {
		cout << "You are either male or NOT tall";
	}
	else {
		cout << "You are neither male nor tall";
	}

}

int getMax(int num1, int num2) {
	int result;

	if (num1 > num2) {
		result = num1;
	}
	else {
		result = num2;
	}
	return result;
}

int getMax(int num1, int num2, int num3) {
	int result;

	if (num1 > num2 && num1 >= num3) {
		result = num1;
	}
	else if(num2 > num1 && num2 >= num3){
		result = num2;
	}
	else {
		result = num3;

	}
	return result;
}

double calculator1() {
	int num1, num2, result;
	char op;

	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter operator: ";
	cin >> op;
	cout << "Enter second number: ";
	cin >> num2;

	if (op == '+') {
		result = num1 + num2;
	}
	else if (op == '-') {
		result = num1 - num2;
	}
	else if (op == '/') {
		result = num1 / num2;
	}
	else if (op == '*') {
		result = num1 * num2;
	}
	else {
		cout << "invalid operator";
		result = 0;
	}
	return result;
}


string getDayOfWeek(int dayNum) {
	string dayName;
	switch (dayNum) {
	case 0:
		dayName = "Sunday";
		break;
	case 1:
		dayName = "Monday";
		break;
	case 2:
		dayName = "Tuesday";
		break;
	case 3:
		dayName = "Wednesday";
		break;
	case 4:
		dayName = "Thursday";
		break;
	case 5:
		dayName = "Friday";
		break;
	case 6:
		dayName = "Saturday";
		break;
	default:
		dayName = "Invalid Day Number";
	}

	return dayName;
}

void looptry() {
	int index = 1;
	while (index <= 5) {
		cout << index << endl;
		index++;
	}
	do {
		cout << index << endl;
		index--;
	} while (index > 0);
}

void loopfor() {

	int nums[] = { 2,4,3,41,5 };
	for (int i = 0; i < 5; i++) {
		cout << nums[i] << endl;
	}

}

int power(int baseNum, int powNum) {
	int result = 1;
	for (int i = 0; i < powNum; i++) {
		result = result * baseNum;

	}
	return result;
}

void twodArray() {
	int numberGrid[3][2] = {  //2d array needs specific lengths
		{1, 2},
		{1, 3},
		{5, 6}
	};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << numberGrid[i][j] << " ";
		}
		cout << endl;
	}
}

void pointers() {
	int age = 19;
	int* pAge = &age;
	double gpa = 2.7;
	double* pGpa = &gpa;
	cout << "adress: " << pAge << " value: " << *pAge << endl;
	cout << "adress: " << pGpa << " value: " << *pGpa << endl;;
}


class Book {
public:
	string title;
	string author;
	int pages;
	
	Book() {
		title = "no title";
		author = "no author";
		pages = 0;
		cout << "Passed no information" << endl;
	}
	// you can make multiple construsctors
	Book(string aTitle, string aAuthor, int aPages) {
		title = aTitle;
		author = aAuthor;
		pages = aPages;
		cout << "Creating a book" << endl;
	}
};

void books() {
	
	Book book1;
	book1.title = "Harry Potter";
	book1.author = "JK Rowling";
	book1.pages = 500;

	Book book2;
	book2.title = "Lord of the Rings";
	book2.author = "Tolkien";
	book2.pages = 700;

	cout << book1.title;
}

void books2() {
	Book book1("Harry Potter", "JK Rowling", 500);

	Book book2("Lord of the Rings", "Tolkien", 700);

	cout << book1.title;
}


class Student {
public:
	string name;
	string major;
	double gpa;
	Student(string aName, string aMajor, double aGpa) {
		name = aName;
		major = aMajor;
		gpa = aGpa;
	}

	bool hasHonors() {
		if (gpa >= 3.5) {
			return true;
		}
		return false;
	}
};

void students() {
	Student student1("Jim", "Business", 2.4);
	Student student2("Pam", "Art", 3.6);

	cout << student1.hasHonors();
}

class Movie {
private:
	string rating;

public:
	string title;
	string director;
	Movie(string aTitle, string aDirector, string aRating) {
		title = aTitle;
		director = aDirector;
		setRating(aRating);
	}

	void setRating(string aRating) {
		string possibilities[4] = { "PG","G", "R", "PG-13" };
		///bool is_possible = find(possibilities->begin(), possibilities->end(), aRating) != possibilities->end();
		bool is_possible = false;
		for (int i = 0; i < 4; i++) {
			if (strcmp(aRating.c_str(), possibilities[i].c_str()) == 0) {
				is_possible = true;
			}
		}
		if (is_possible) {
			rating = aRating;
		}
		else {
			rating = "NR";
		}
	}
	string getRating() {
		return rating;
	}

};

void movies() {
	Movie avengers("The Avengers", "Joss Whedon", "PG-13");
	cout << avengers.getRating() << endl;

}

void chars() {
	const char* testing = "test";
	char possibility[] = "sausage";
	string test[4] = { "sausage", "test", "radio", "button" };
	cout << possibility << " " << testing;

}


class Chef {
public:
	void makeChicken() {
		cout << "The chef makes chicken" << endl;
	}
	void makeSalad() {
		cout << "The chef makes salad" << endl;
	}
	void makeSpecialDish() {
		cout << "The chef makes bbq" << endl;
	}
};

class ItalianChef: public Chef {
public:
	void makePasta() {
		cout << "The chef makes pasta" << endl;
	}
	void makeSpecialDish() {
		cout << "The chef makes chicken parm" << endl;
	}
};


int main(void)
{	
	//lucky_nums();
	//sayHi("John", 32);

	//cout << cube(5.0) << endl;

	//bool isMale = true;
	//bool isTall = true;

	//cout << getMax(5, 32) << endl;
	//cout << getMax(5, 32, 64) << endl;

	//cout << calculator1();

	//cout << getDayOfWeek(1) << endl;
	
	//loopfor();
	//cout << power(2, 3);
	//twodArray();
	//books2();
	Chef chef;
	chef.makeChicken();
	chef.makeSpecialDish();
	ItalianChef chef2;
	chef2.makeSpecialDish();


	return 0;

}

void sayHi(string name, int age) {
	cout << "Hello " << name << endl << "You are " << age;

}