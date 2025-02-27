#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <map>

using namespace std;

// 获取当前时间的函数
string getCurrentDateTime() {
    auto now = time(nullptr);
    auto localTime = *localtime(&now);

    stringstream ss;
    ss << put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// 记录考勤
void recordAttendance(const string& employeeID, const string& status) {
    ofstream file("attendance_records.txt", ios::app);
    if (!file.is_open()) {
        cerr << "无法打开考勤记录文件!" << endl;
        return;
    }

    file << employeeID << "," << status << "," << getCurrentDateTime() << endl;
    file.close();

    cout << "考勤记录已保存。" << endl;
}

// 显示所有考勤记录
void displayRecords() {
    ifstream file("attendance_records.txt");
    if (!file.is_open()) {
        cerr << "无法打开考勤记录文件!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

// 查找某个员工的考勤记录
void searchEmployeeRecords(const string& employeeID) {
    ifstream file("attendance_records.txt");
    if (!file.is_open()) {
        cerr << "无法打开考勤记录文件!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, status, datetime;
        getline(ss, id, ',');
        getline(ss, status, ',');
        getline(ss, datetime, ',');

        if (id == employeeID) {
            cout << line << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "没有找到该员工的考勤记录。" << endl;
    }

    file.close();
}

// 计算员工工作总时间
void calculateTotalWorkTime(const string& employeeID) {
    ifstream file("attendance_records.txt");
    if (!file.is_open()) {
        cerr << "无法打开考勤记录文件!" << endl;
        return;
    }

    string line;
    map<string, time_t> workStartTimes;
    long totalWorkTime = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, status, datetime;
        getline(ss, id, ',');
        getline(ss, status, ',');
        getline(ss, datetime, ',');

        if (id == employeeID) {
            tm tm = {};
            istringstream ss(datetime) >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
            time_t recordTime = mktime(&tm);

            if (status == "上班") {
                workStartTimes[employeeID] = recordTime;
            }
            else if (status == "下班" && workStartTimes.find(employeeID) != workStartTimes.end()) {
                totalWorkTime += difftime(recordTime, workStartTimes[employeeID]);
                workStartTimes.erase(employeeID);
            }
        }
    }

    // 处理未下班的记录
    for (const auto& pair : workStartTimes) {
        cout << "警告: 员工 " << employeeID << " 有未结束的上班记录。" << endl;
    }

    file.close();

    cout << "员工 " << employeeID << " 的总工作时间为 " << totalWorkTime / 3600 << " 小时 "
        << (totalWorkTime % 3600) / 60 << " 分钟 " << totalWorkTime % 60 << " 秒。" << endl;
}

// 主函数
int main() {
    while (true) {
        cout << "1. 记录考勤" << endl;
        cout << "2. 显示考勤记录" << endl;
        cout << "3. 查找员工考勤记录" << endl;
        cout << "4. 计算员工工作总时间" << endl;
        cout << "5. 退出" << endl;
        cout << "请选择操作: ";

        int choice;
        cin >> choice;
        cin.ignore(); // 清除输入缓冲区

        if (choice == 1) {
            cout << "请输入员工ID: ";
            string employeeID;
            getline(cin, employeeID);

            cout << "请输入考勤状态 (如 '上班' 或 '下班'): ";
            string status;
            getline(cin, status);

            recordAttendance(employeeID, status);
        }
        else if (choice == 2) {
            displayRecords();
        }
        else if (choice == 3) {
            cout << "请输入员工ID: ";
            string employeeID;
            getline(cin, employeeID);

            searchEmployeeRecords(employeeID);
        }
        else if (choice == 4) {
            cout << "请输入员工ID: ";
            string employeeID;
            getline(cin, employeeID);

            calculateTotalWorkTime(employeeID);
        }
        else if (choice == 5) {
            cout << "退出系统。" << endl;
            break;
        }
        else {
            cout << "无效的选择，请重新输入。" << endl;
        }
    }

    return 0;
}
