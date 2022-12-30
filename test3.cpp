#include <bits/stdc++.h>
using namespace std;

class name_grade
{
public:
	string student_name;
	int korean;
	int math;
	int english;
	int science;
	int social;
	int history;

	void set_grade(string tuple)
	{
		stringstream tuplestr(tuple);
		string tempstr;

		getline(tuplestr, student_name, ',');

		getline(tuplestr, tempstr, ',');
		korean = stoi(tempstr);

		getline(tuplestr, tempstr, ',');
		math = stoi(tempstr);

		getline(tuplestr, tempstr, ',');
		english = stoi(tempstr);

		getline(tuplestr, tempstr, ',');
		science = stoi(tempstr);

		getline(tuplestr, tempstr, ',');
		social = stoi(tempstr);

		getline(tuplestr, tempstr);
		history = stoi(tempstr);
	}
};

class name_number
{
public:
	string student_name;
	string student_number;

	void set_number(string tuple)
	{
		stringstream tuplestr(tuple);
		string tempstr;

		getline(tuplestr, student_name, ',');
		getline(tuplestr, student_number, ',');
	}
};

string make_tuple(string name, string number)
{
	string ret = "";

	ret += name + "," + number + "\n";

	return ret;
}

int main()
{

	string buffer[2];
	name_grade temp0;
	name_grade temp1;
	name_number temp2;
	fstream block[12];
	ofstream output;

	output.open("./output3.csv");

	if (output.fail())
	{
		cout << "output file opening fail.\n";
	}

	/*********************************************************************/
	// write codes here.

	cout << "start making hash table\n";
	/* ------------ name_grade1 해시테이블을 만듦------------------ */

	// 10개의 버킷을 만듦. 해시 테이블은 메모리가 아닌 디스크에 저장됨.
	// 버킷은 block[1]부터 block[10]까지 사용함.
	// block[0]은 데이터를 읽어오는데 사용함.
	for (int i = 'a'; i <= 'j'; i++)
	{
		block[i - 'a' + 1].open("./name_grade1/temp_" + string(1, char(i)) + ".csv", ios::out);
		if (block[i - 'a' + 1].fail())
		{
			cout << "output file opening fail.\n";
		}
	}

	for (int t = 0; t < 1000; t++)
	{
		block[0].open("./name_grade1/" + to_string(t) + ".csv");

		if (block[0].fail())
		{
			cout << "output file opening fail.\n";
		}

		// each block has 10 records. so, repeat 10 times
		for (int i = 0; i < 10; i++)
		{
			getline(block[0], buffer[0]);

			temp0.set_grade(buffer[0]);

			// cout << buffer[0];

			int hashIndex = temp0.student_name.substr(0, 1).c_str()[0] - 'a' + 1;
			block[hashIndex] << buffer[0] << "\n";
		}
		block[0].close();
	}
	for (int i = 'a'; i <= 'j'; i++)
	{
		block[i - 'a' + 1].close();
	}
	/* ------------ name_grade1 해시테이블 생성 완료------------------ */

	/* ------------ name_grade2 해시테이블을 만듦------------------ */

	// 10개의 버킷을 만듦. 해시 테이블은 메모리가 아닌 디스크에 저장됨.
	// 버킷은 block[1]부터 block[10]까지 사용함.
	for (int i = 'a'; i <= 'j'; i++)
	{
		block[i - 'a' + 1].open("./name_grade2/temp_" + string(1, char(i)) + ".csv", ios::out);
		if (block[i - 'a' + 1].fail())
		{
			cout << "output file opening fail.\n";
		}
	}

	for (int t = 0; t < 1000; t++)
	{
		block[0].open("./name_grade2/" + to_string(t) + ".csv");

		if (block[0].fail())
		{
			cout << "output file opening fail.\n";
		}

		// each block has 10 records. so, repeat 10 times
		for (int i = 0; i < 10; i++)
		{
			getline(block[0], buffer[0]);

			temp1.set_grade(buffer[0]);

			// cout << buffer[0];

			int hashIndex = temp1.student_name.substr(0, 1).c_str()[0] - 'a' + 1;
			block[hashIndex] << buffer[0] << "\n";
		}
		block[0].close();
	}
	for (int i = 'a'; i <= 'j'; i++)
	{
		block[i - 'a' + 1].close();
	}
	/* ------------ name_grade2 해시테이블 생성 완료------------------ */

	/* ------------ name_number 해시테이블을 만듦------------------ */

	// 10개의 버킷을 만듦. 해시 테이블은 메모리가 아닌 디스크에 저장됨.
	// 버킷은 block[1]부터 block[10]까지 사용함.
	for (int i = 'a'; i <= 'j'; i++)
	{
		block[i - 'a' + 1].open("./name_number/temp_" + string(1, char(i)) + ".csv", ios::out);
		if (block[i - 'a' + 1].fail())
		{
			cout << "output file opening fail.\n";
		}
	}

	for (int t = 0; t < 1000; t++)
	{
		block[0].open("./name_number/" + to_string(t) + ".csv");

		if (block[0].fail())
		{
			cout << "output file opening fail.\n";
		}

		// each block has 10 records. so, repeat 10 times
		for (int i = 0; i < 10; i++)
		{
			getline(block[0], buffer[0]);

			temp2.set_number(buffer[0]);

			// cout << buffer[0];

			int hashIndex = temp2.student_name.substr(0, 1).c_str()[0] - 'a' + 1;
			block[hashIndex] << buffer[0] << "\n";
		}
		block[0].close();
	}
	for (int i = 'a'; i <= 'j'; i++)
	{
		block[i - 'a' + 1].close();
	}
	/* ------------ name_number 해시테이블 생성 완료------------------ */
	cout << "finished making hash table\n";

	cout << "start join\n";

	for (int i = 'a'; i <= 'j'; i++)
	{
		block[0].open("./name_grade1/temp_" + string(1, char(i)) + ".csv", ios::in);
		// cout<< "./name_grade1/temp_" + string(1, char(i)) + ".csv\n";
		if (block[0].fail())
		{
			cout << "output file opening fail.\n";
		}

		for (int j = 0; j < 1000; j++)
		{
			getline(block[0], buffer[0]);
			temp0.set_grade(buffer[0]);

			block[1].open("./name_grade2/temp_" + string(1, char(i)) + ".csv", ios::in);
			// cout<< "./name_grade2/temp_" + string(1, char(i)) + ".csv\n";
			if (block[1].fail())
			{
				cout << "output file opening fail.\n";
			}
			for (int k = 0; k < 1000; k++)
			{
				getline(block[1], buffer[1]);
				temp1.set_grade(buffer[1]);
				if (temp0.student_name == temp1.student_name)
				{
					int enhanced = 0;

					if (temp0.korean > temp1.korean) enhanced ++;
					if (temp0.math > temp1.math) enhanced ++;
					if (temp0.english > temp1.english) enhanced ++;
					if (temp0.science > temp1.science) enhanced ++;
					if (temp0.social > temp1.social) enhanced ++;
					if (temp0.history > temp1.history) enhanced ++;

					if(enhanced >=2){
						block[2].open("./name_number/temp_" + string(1, char(i)) + ".csv", ios::in);
						for(int j = 0; j <1000;j++){
							getline(block[2], buffer[0]);
							temp2.set_number(buffer[0]);
							if(temp0.student_name==temp2.student_name){
								cout << make_tuple(temp0.student_name, temp2.student_number);
								output << make_tuple(temp0.student_name, temp2.student_number);
								break;
							}
						}
						// cout << temp0.student_name + " " + temp1.student_name + " " + to_string(enhanced) +  "\n";
						block[2].close();
					}

					break;
				}
			}
			block[1].close();
		}
		block[0].close();
	}

	cout << "finished join\n";

	/*********************************************************************/

	output.close();
}
