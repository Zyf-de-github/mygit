#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


//时间函数生成
//void ShowTime()
//{
//	auto now = time(nullptr);
//	struct tm* LocalTime = localtime(&now);
//	int year = LocalTime->tm_year + 1900;
//	int month = LocalTime->tm_mon + 1;
//	int day = LocalTime->tm_wday;
//	int hour = LocalTime->tm_hour;
//	int minute = LocalTime->tm_min;
//	int second = LocalTime->tm_sec;
//	cout << year << "-" << month << "-" << day << "-" << hour << "-" << minute << "-" << second << endl;
//}





//void printVector(vector<int>& v)
//{
//	//iterator 迭代器关键词
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < 10; i++)
//	{
//			cout << v[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << v.at(i) << " ";
//	}
//	cout << endl;
//}
//
//void test1()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	printVector(v1);

	////赋值
	//vector<int>v2;
	//v2 = v1;
	//printVector(v2 );

	////assign
	//vector<int>v3;
	//v3.assign(v1.begin(), v1.end());
	//printVector(v3);

//}
//
//class person
//{
//public:
//	person(string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//	bool operator==(const person& p)
//	{
//		if (this->name == p.name && this->age == p.age)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	string name;
//	int age;
//};
//
//void test2()
//{
//	vector<person>v;
//	person p1("aaa", 10);
//	person p2("bbb", 20);
//	person p3("ccc", 30);
//	person p4("ddd", 40);
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//
//
//	vector<person>::iterator it = find(v.begin(), v.end(), p2);
//	if (it == v.end())
//	{
//		cout << "找不到" << endl;
//	}
//	else
//	{
//		cout << "姓名：" << it->name << "  年龄：" << it->age;
//	}
//}
//
//
//int main()
//{
//	test2();
//	return 0;
//}
//







#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

int main() {
    ifstream file("time.txt"); // 打开文件
    if (!file.is_open()) {
        cerr << "Error opening file!" <<endl;
        return 1;
    }

    string timeStr;
    getline(file, timeStr); // 读取文件中的时间字符串
    file.close();

    tm tm = {};
    istringstream ss(timeStr);

    // 假设时间字符串格式为 "YYYY-MM-DD HH:MM:SS"
    ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");

    if (ss.fail()) {
        cerr << "Parse failed!" << endl;
        return 1;
    }

    // 输出解析后的时间
    cout << "Year: " << (tm.tm_year + 1900) << endl;
    cout << "Month: " << (tm.tm_mon + 1) << endl;
    cout << "Day: " << tm.tm_mday << endl;
    cout << "Hour: " << tm.tm_hour << endl;
    cout << "Minute: " << tm.tm_min << endl;
    cout << "Second: " << tm.tm_sec << endl;

    return 0;
}
