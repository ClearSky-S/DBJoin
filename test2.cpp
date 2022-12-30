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
	fstream block[12];
	ofstream output;

	output.open("./output2.csv");

	if (output.fail())
	{
		cout << "output file opening fail.\n";
	}

	/******************************************************************/

	// write codes here.

	cout <<"start making hash table\n";
	/* ------------ name_age의 해시테이블을 만듦------------------ */

	// 10개의 버킷을 만듦. 해시 테이블은 메모리가 아닌 디스크에 저장됨.
	// 버킷은 block[1]부터 block[10]까지 사용함.
	for (int i = 'a'; i <= 'j'; i++)
	{
		block[i - 'a' + 1].open("./name_age/temp_" + string(1, char(i)) + ".csv", ios::out);
		// cout << "./name_age/temp_" + string(1, char(i)) << "\n";
		if (block[i - 'a' + 1].fail())
		{
			cout << "output file opening fail.\n";
		}
	}

	for (int name_ageFileIndex = 0; name_ageFileIndex < 1000; name_ageFileIndex++)
	{
		block[0].open("./name_age/" + to_string(name_ageFileIndex) + ".csv");
		// cout << "./name_age/" + to_string(name_ageFileIndex) + ".csv\n";
		if (block[0].fail())
		{
			cout << "output file opening fail.\n";
		}

		// each block has 10 records. so, repeat 10 times
		for (int i = 0; i < 10; i++)
		{
			getline(block[0], buffer[0]);

			temp0.set_name_age(buffer[0]);

			// cout << buffer[0];

			int hashIndex = temp0.name.substr(0, 1).c_str()[0] - 'a' + 1;
			block[hashIndex] << buffer[0] << "\n";
		}
		block[0].close();
	}
	for (int i = 'a'; i <= 'j'; i++)
	{
		block[i - 'a' + 1].close();
	}
	/* ------------ name_age의 해시테이블 생성 완료------------------ */

	/* ------------ name_salary의 해시테이블을 만듦------------------ */

	// 10개의 버킷을 만듦. 해시 테이블은 메모리가 아닌 디스크에 저장됨.
	// 버킷은 block[1]부터 block[10]까지 사용함.
	for (int i = 'a'; i <= 'j'; i++)
	{
		block[i - 'a' + 1].open("./name_salary/temp_" + string(1, char(i)) + ".csv", ios::out);
		if (block[i - 'a' + 1].fail())
		{
			cout << "output file opening fail.\n";
		}
	}

	for (int name_salaryFileIndex = 0; name_salaryFileIndex < 1000; name_salaryFileIndex++)
	{
		block[0].open("./name_salary/" + to_string(name_salaryFileIndex) + ".csv");
		// cout << "./name_salary/" + to_string(name_salaryFileIndex) + ".csv\n";
		if (block[0].fail())
		{
			cout << "output file opening fail.\n";
		}

		// each block has 10 records. so, repeat 10 times
		for (int i = 0; i < 10; i++)
		{
			getline(block[0], buffer[0]);

			temp1.set_name_salary(buffer[0]);

			// cout << buffer[0];

			int hashIndex = temp1.name.substr(0, 1).c_str()[0] - 'a' + 1;
			block[hashIndex] << buffer[0] << "\n";
		}
		block[0].close();
	}
	for (int i = 'a'; i <= 'j'; i++)
	{
		block[i - 'a' + 1].close();
	}
	/* ------------ name_age의 해시테이블 생성 완료------------------ */
	cout <<"finished making hash table\n";

	cout <<"start join\n";

	for (int i = 'a'; i <= 'j'; i++)
	{
		block[0].open("./name_age/temp_"+ string(1, char(i))+ ".csv", ios::in);


		for(int j = 0;j<1000; j++){
			getline(block[0], buffer[0]);
			temp0.set_name_age(buffer[0]);

			block[1].open("./name_salary/temp_"+ string(1, char(i))+ ".csv", ios::in);
			for(int k = 0;k<1000; k++){
				getline(block[1], buffer[1]);
				temp1.set_name_salary(buffer[1]);
				if(temp0.name == temp1.name){
					// cout<< make_tuple(temp0.name, temp0.age, temp1.salary);
					output << make_tuple(temp0.name, temp0.age, temp1.salary);
					break;
				}
			}
			block[1].close();
		}
		block[0].close();
	}

	cout <<"finished join\n";
	/******************************************************************/

	output.close();
}
