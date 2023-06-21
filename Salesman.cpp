#include<iostream>
#define size 20
using namespace std;
bool isFoundid(double salesman_id[], int& x) {
	//x is id
	int flag = 0;
	for (int i = 0; i < size; i++) {

		if (x == salesman_id[i])flag = 1;
	}
	return flag;
}
void inputvalidton(int& x) {
	while (x < 0) {
		cout << "you enter a minus intger plz enter postitve intger\n";
		cin >> x;
	}


}
void printOptions() {
	cout << "1 . Add a salesman" << endl;
	cout << "2 . Delete a salesman" << endl;
	cout << "3 . Search for a salesman by his ID " << endl;
	cout << "4 . Exit " << endl;
}
void add(double salesman_id[], double salesman_salary[], long salesman_phoneNumber[]) {
	int static id = 14;
	int sales;
	int phonenumber;
	if (salesman_id[size - 1] != 0) {
		cout << "Sorry, the company has enough salesmen at the current time\n,if you want to add a new salesman, you should delete one first.\n\n";
		return;
	}
	else {
		cout << "your id is : " << id << endl << endl;

		cout << "enter the sales\n";
		cin >> sales;
		inputvalidton(sales);
		cout << "enter the phone number\n";
		cin >> phonenumber;
		inputvalidton(phonenumber);

		for (int i = 0; i < size; i++) {
			if (salesman_id[i] == 0) {
				salesman_id[i] = id;
				salesman_salary[i] = sales;
				salesman_phoneNumber[i] = phonenumber;
				break;
			}
		}
	}//else braces 

	id++;
}// add braces
void Delete(double salesman_id[], double salesman_salary[], long salesman_phoneNumber[]) {
	int id;
	int free;

	cout << "enter the id to delete it\n";
	cin >> id;
	inputvalidton(id);
	if (isFoundid(salesman_id, id)) {}
	else {
		cout << "not Found\n\n\n";
		return;
	}
	for (int i = 0; i < size; i++) { if (salesman_id[i] == id) { free = i; break; } }
	for (int i = free; i < size; i++) {


		salesman_id[i] = salesman_id[i + 1];
		salesman_salary[i] = salesman_salary[i + 1];
		salesman_phoneNumber[i] = salesman_phoneNumber[i + 1];



	}
	salesman_id[size - 1] = 0;

	cout << "its deleted thx for using\n\n\n";

}
void search(double salesman_id[], double salesman_salary[], long salesman_phoneNumber[]) {
	int id;
	int flag = 0;
	cout << "enter the id" << endl;
	cin >> id;
	inputvalidton(id);
	if (isFoundid(salesman_id, id)) {}
	else {
		cout << "not Found\n\n\n";
		return;
	}
	for (int i = 0; i < size; i++) {

		if (salesman_id[i] == id) {
			cout << "ID :" << salesman_id[i] << endl;
			cout << "SALARY : " << salesman_salary[i] << " $ " << endl;
			cout << "PHONE NUMBER :" << salesman_phoneNumber[i] << endl << endl << endl;
			break;

		}
	}
}

int main() {
	double salesman_id[20] = { 11,12,13 };
	double salesman_salary[20] = { 100,150,250 };
	long salesman_phoneNumber[20] = { 2388888,2377777,2355555 };
	int task = 0;


	while (task != 4) {
		printOptions();
		cout << "Choose one of these tasks\n";
		cin >> task;
		while (task > 4 || task < 1) {
			cout << "wrong input enter again\n";
			cin >> task;
		}//nested while loop braces
		switch (task) {
		case 1:add(salesman_id, salesman_salary, salesman_phoneNumber); break;
		case 2:Delete(salesman_id, salesman_salary, salesman_phoneNumber); break;
		case 3:search(salesman_id, salesman_salary, salesman_phoneNumber); break;
		case 4:cout << "byeeee";

		}//switch braces
	}// main while loop braces

}// main func braces