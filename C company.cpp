#include"iostream"
#include "fstream"
using namespace std;
struct Employee
{
	char Name[100];
	float salary;

};
struct Branch
{
	char Name[100];
	int NEmployees; //this variable contains the number of employees in a branch
	Employee* E; //this will be used to create an array of Employees
};
struct Company
{
	char Name[100];
	int NBranches; //this variable contains the number of branches
	Branch** B; //this will be used to create an array of pointers to branches
};
void above2k(Company company, ofstream& fp2) {
	for (int i = 0; i < company.NBranches; i++) {
		for (int j = 0; j < company.B[i]->NEmployees; j++) {
			if (company.B[i]->E[j].salary > 2000) {
				fp2 << company.B[i]->E[j].Name;
				if (!(i == company.NBranches - 1 && j == company.B[i]->NEmployees - 1)) {
					fp2 << ", ";
				}
			}
		}

	}


}
void AVGs(Company company, ofstream& fp2) {
	float avg = 0;
	int flag = 1;
	string maxN;
	float temp;
	for (int i = 0; i < company.NBranches; i++) {

		for (int j = 0; j < company.B[i]->NEmployees; j++) {
			avg += company.B[i]->E[j].salary;
		}
		avg /= company.B[i]->NEmployees;
		if (flag) {
			maxN = company.B[i]->Name;
			flag = 0;
			temp = avg;
		}
		if (avg > temp) {
			maxN = company.B[i]->Name;

			temp = avg;
		}
		fp2 << company.B[i]->Name << " " << avg << " ";
		avg = 0;
	}





}
string AVGs(ofstream& fp2, Company company) {
	float avg = 0;
	int flag = 1;
	string maxN;
	float temp;
	for (int i = 0; i < company.NBranches; i++) {

		for (int j = 0; j < company.B[i]->NEmployees; j++) {
			avg += company.B[i]->E[j].salary;
		}
		avg /= company.B[i]->NEmployees;
		if (flag) {
			maxN = company.B[i]->Name;
			flag = 0;
			temp = avg;
		}
		if (avg > temp) {
			maxN = company.B[i]->Name;

			temp = avg;
		}

		avg = 0;
	}




	return maxN;
}// i make this to do overload
void maxS(Company company, ofstream& fp2) {
	int salary = company.B[0]->E[0].salary;

	for (int i = 0; i < company.NBranches; i++) {
		for (int j = 0; j < company.B[i]->NEmployees; j++) {
			if (company.B[i]->E[j].salary > salary) {
				salary = company.B[i]->E[j].salary;

			}
		}

	}

	for (int i = 0; i < company.NBranches; i++) {
		for (int j = 0; j < company.B[i]->NEmployees; j++) {
			if (company.B[i]->E[j].salary == salary) {

				fp2 << company.B[i]->E[j].Name << " " << salary << " ";
			}
		}

	}

}
void minS(Company company, ofstream& fp2) {
	int salary = company.B[0]->E[0].salary;
	string name = company.B[0]->E[0].Name;
	for (int i = 0; i < company.NBranches; i++) {
		for (int j = 0; j < company.B[i]->NEmployees; j++) {
			if (company.B[i]->E[j].salary < salary) {
				salary = company.B[i]->E[j].salary;
				name = company.B[i]->E[j].Name;
			}
		}

	}
	for (int i = 0; i < company.NBranches; i++) {
		for (int j = 0; j < company.B[i]->NEmployees; j++) {
			if (company.B[i]->E[j].salary == salary) {

				fp2 << company.B[i]->E[j].Name << " " << salary << " ";
			}
		}

	}

}
void Sort(Employee* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (_stricmp(arr[i].Name, arr[j].Name) > 0)
			{
				// swap the employees
				Employee temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void print_employees(Company& company, ofstream& fp2)//sorted by name in aced
{
	for (int i = 0; i < company.NBranches; i++)
	{
		fp2 << company.B[i]->Name << " ";


		Sort(company.B[i]->E, company.B[i]->NEmployees);


		for (int j = 0; j < company.B[i]->NEmployees; j++)
		{
			fp2 << company.B[i]->E[j].Name << " " << company.B[i]->E[j].salary << " ";
		}
		fp2 << endl;
	}
}
void Delete(Company& company) {

	for (int i = 0; i < company.NBranches; i++) {
		delete[] company.B[i]->E;
	}


	for (int i = 0; i < company.NBranches; i++) {
		delete company.B[i];
	}


	delete[] company.B;
}
int main() {
	ifstream fp1;
	ofstream fp2;
	Company company;

	int totalNEinC = 0;
	fp1.open("file1.txt");
	fp2.open("file2.txt");
	if (!fp1 || !fp2) {
		cout << "file not open";
		return 0;
	}
	fp1 >> company.Name >> company.NBranches;
	company.B = new Branch * [company.NBranches];
	for (int i = 0; i < company.NBranches; i++) {
		company.B[i] = new Branch;
	}
	for (int i = 0; i < company.NBranches; i++) {
		fp1 >> company.B[i]->Name;
		fp1 >> company.B[i]->NEmployees;
		totalNEinC += company.B[i]->NEmployees;
		company.B[i]->E = new Employee[company.B[i]->NEmployees];

		for (int j = 0; j < company.B[i]->NEmployees; j++) {
			fp1 >> company.B[i]->E[j].Name;
			fp1 >> company.B[i]->E[j].salary;

		}
	}

	//////////////////////////////////////// for read data up/////////////////////////////////////////////////

	fp2 << "company name : " << company.Name << endl << "total number of employess is : " << totalNEinC << endl;
	fp2 << "employess whose salaries are above 2000 : ";
	above2k(company, fp2);
	fp2 << endl;
	fp2 << "the average salary : ";
	AVGs(company, fp2);
	fp2 << endl;
	fp2 << "the branch with maximum  average salary is : " << AVGs(fp2, company);
	fp2 << endl;
	fp2 << "the employees(s) with maximum salary followed by their salary : ";
	maxS(company, fp2);
	fp2 << endl;
	fp2 << "the employees(s) with minimum salary followed by their salary : ";
	minS(company, fp2);
	fp2 << endl;
	fp2 << "the employees info. in each brach sorted in ascending order of thier names :" << endl;
	print_employees(company, fp2);

	fp1.close();
	fp2.close();
	Delete(company);
}