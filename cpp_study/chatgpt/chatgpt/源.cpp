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

// ��ȡ��ǰʱ��ĺ���
string getCurrentDateTime() {
    auto now = time(nullptr);
    auto localTime = *localtime(&now);

    stringstream ss;
    ss << put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// ��¼����
void recordAttendance(const string& employeeID, const string& status) {
    ofstream file("attendance_records.txt", ios::app);
    if (!file.is_open()) {
        cerr << "�޷��򿪿��ڼ�¼�ļ�!" << endl;
        return;
    }

    file << employeeID << "," << status << "," << getCurrentDateTime() << endl;
    file.close();

    cout << "���ڼ�¼�ѱ��档" << endl;
}

// ��ʾ���п��ڼ�¼
void displayRecords() {
    ifstream file("attendance_records.txt");
    if (!file.is_open()) {
        cerr << "�޷��򿪿��ڼ�¼�ļ�!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

// ����ĳ��Ա���Ŀ��ڼ�¼
void searchEmployeeRecords(const string& employeeID) {
    ifstream file("attendance_records.txt");
    if (!file.is_open()) {
        cerr << "�޷��򿪿��ڼ�¼�ļ�!" << endl;
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
        cout << "û���ҵ���Ա���Ŀ��ڼ�¼��" << endl;
    }

    file.close();
}

// ����Ա��������ʱ��
void calculateTotalWorkTime(const string& employeeID) {
    ifstream file("attendance_records.txt");
    if (!file.is_open()) {
        cerr << "�޷��򿪿��ڼ�¼�ļ�!" << endl;
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

            if (status == "�ϰ�") {
                workStartTimes[employeeID] = recordTime;
            }
            else if (status == "�°�" && workStartTimes.find(employeeID) != workStartTimes.end()) {
                totalWorkTime += difftime(recordTime, workStartTimes[employeeID]);
                workStartTimes.erase(employeeID);
            }
        }
    }

    // ����δ�°�ļ�¼
    for (const auto& pair : workStartTimes) {
        cout << "����: Ա�� " << employeeID << " ��δ�������ϰ��¼��" << endl;
    }

    file.close();

    cout << "Ա�� " << employeeID << " ���ܹ���ʱ��Ϊ " << totalWorkTime / 3600 << " Сʱ "
        << (totalWorkTime % 3600) / 60 << " ���� " << totalWorkTime % 60 << " �롣" << endl;
}

// ������
int main() {
    while (true) {
        cout << "1. ��¼����" << endl;
        cout << "2. ��ʾ���ڼ�¼" << endl;
        cout << "3. ����Ա�����ڼ�¼" << endl;
        cout << "4. ����Ա��������ʱ��" << endl;
        cout << "5. �˳�" << endl;
        cout << "��ѡ�����: ";

        int choice;
        cin >> choice;
        cin.ignore(); // ������뻺����

        if (choice == 1) {
            cout << "������Ա��ID: ";
            string employeeID;
            getline(cin, employeeID);

            cout << "�����뿼��״̬ (�� '�ϰ�' �� '�°�'): ";
            string status;
            getline(cin, status);

            recordAttendance(employeeID, status);
        }
        else if (choice == 2) {
            displayRecords();
        }
        else if (choice == 3) {
            cout << "������Ա��ID: ";
            string employeeID;
            getline(cin, employeeID);

            searchEmployeeRecords(employeeID);
        }
        else if (choice == 4) {
            cout << "������Ա��ID: ";
            string employeeID;
            getline(cin, employeeID);

            calculateTotalWorkTime(employeeID);
        }
        else if (choice == 5) {
            cout << "�˳�ϵͳ��" << endl;
            break;
        }
        else {
            cout << "��Ч��ѡ�����������롣" << endl;
        }
    }

    return 0;
}
