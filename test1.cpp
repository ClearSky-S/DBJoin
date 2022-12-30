#include <bits/stdc++.h>
using namespace std;

class name_age
{
public:
	string name;
	string age;

	void set_name_age(string tuple)
	{
		stringstream tuplestr(tuple);
		string agestr;

		getline(tuplestr, name, ',');
		getline(tuplestr, age);
	}
};

class name_salary
{
public:
	string name;
	string salary;

	void set_name_salary(string tuple)
	{
		stringstream tuplestr(tuple);
		string salarystr;

		getline(tuplestr, name, ',');
		getline(tuplestr, salary);
	}
};

string make_tuple(string name, string age, string salary)
{
	return name + ',' + age + ',' + salary + '\n';
}

int main()
{

	string buffer[2];
	name_age temp0;
	name_salary temp1;
	int current_block[2] = {};
	fstream block[12];
	ofstream output;

	output.open("./output1.csv");

	if (output.fail())
	{
		cout << "output file opening fail.\n";
	}
	/*********************************************************************************/
	// write codes here.
	// Merge Join
	// sorting is already done.

	for(int name_ageFileIndex=0, name_salaryFileIndex=0;name_ageFileIndex<1000,name_salaryFileIndex<1000; name_ageFileIndex++, name_salaryFileIndex++){
		block[0].open("./name_age/" + to_string(name_ageFileIndex) + ".csv");
		block[1].open("./name_salary/" + to_string(name_salaryFileIndex) + ".csv");

		// each block has 10 records. so, repeat 10 times
		for(int i=0;i<10;i++){
			getline(block[0], buffer[0]);
			temp0.set_name_age(buffer[0]);

			getline(block[1], buffer[0]);
			temp1.set_name_salary(buffer[0]);

			// 조건문을 사용하긴 했지만 현재 문제에서는 항상 참이므로 큰 의미는 없긴 함.
			if(temp0.name==temp1.name){
				buffer[0] = make_tuple(temp0.name, temp0.age, temp1.salary);
				// cout << buffer[0];
				output << buffer[0];
			}
		}

		block[0].close();
		block[1].close();
		
	}

	/*********************************************************************************/

	output.close();
}
