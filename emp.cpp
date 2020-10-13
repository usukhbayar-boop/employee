#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;

class Employee {
private:
    int id;
    char name[20];                      // <-----------      class array or object array?
    char position[10];
    float hours;
    float calcSalaryDir();
public:
    void startValue();
    void getData();
    void showData();
    float calcSalary();
    bool addHours(float);
};

void Employee::startValue() {
    id = 0;
    strcpy(name, "");
    strcpy(position, "employee");
    hours = 0;
}

void Employee::getData() {
     cout << "Id: ";
    cin >> id;

    cout << "Ner: ";
    cin >> name;

    cout << "Mergejil: ";
    cin >> position;

    cout << "Ajillasan tsag: ";
    cin >> hours;

}

void Employee::showData() {
     cout << "\n" << setw(20) << id;
    cout << setw(8) << name;
    cout << setw(12) << position;
    cout.width(20);
    cout << hours;
}

float Employee::calcSalary() {
     if(!strcmp(position, "zahiral")) {
        calcSalaryDir();
    } else {
    int pay = 12000;
    float total = pay * hours;
    return total;
    }

}

bool Employee::addHours(float add) {
     if(add > 24) {
        return 0;
    } else {
        if(add > 0) {
        hours += add;
        return 1;
        } else {
            return 0;
        }
    }
}

float Employee::calcSalaryDir() {
     if(!strcmp(position, "zahiral")) {
     int pay = 20000;
    float total = pay * hours;
    return total;
    } else {
        return 0;
    }
    }

void heading() {
    cout << endl;
    cout << setw(20) << "ID";
    cout << setw(8) << "Ner";
    cout << setw(12) << "Mergejil";
    cout << setw(20) << "Ajillasan tsag";
}



int main()
{
    Employee emp[10];
    int n;
    cout << "Ajilchdiin too: ";
    cin >> n;
    for(int i=0; i<n; i++) {
        emp[i].startValue();
        emp[i].getData();
        cout << "\nTsalin: " << emp[i].calcSalary();
        cout << "\n" << emp[i].addHours(20) << endl;
    }
    heading();
    for(int i = 0; i < n-1; i++) {
        int max = i;
        for(int j = i+1; j < n; j++) {
            if(emp[max].calcSalary() < emp[j].calcSalary()) {
                max = j;
            }
        }
        Employee temp;
        temp = emp[i];
        emp[i] = emp[max];
        emp[max] = temp;

    }
    for(int i=0; i<n; i++) {
        emp[i].showData();
    }
    getch();

    return 0;
}
