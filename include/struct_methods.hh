#pragma once
#include <cstdlib>
#include <iostream>
#include "structs.hh"

using namespace std;

void append(RowData_s Data) {
    Size++;
    BasePtr = (RowData_s*)realloc(BasePtr, sizeof(RowData_s) * Size);
    *(BasePtr+Size-1) = Data;
}

void input_keyboard() {
    cout << "------ Создание записи " << Size << " ------\n";
    RowData_s Data;
    cout << "Введите фамилию студента: ";
    cin >> Data.Surname;
    cout << Data.Surname;
    cout << "Введите день рождения студента: ";
    cin >> Data.Day;
    cout << "Введите месяц рождения студента: ";
    cin >> Data.Month;
    cout << "Введите год рождения студента: ";
    cin >> Data.Year;
    cout << "Введите курс студента: ";
    cin >> Data.Course;
    cout << "Введите группу студента: ";
    cin >> Data.Group;
    append(Data);
}

void output_table() {
    cout << "Фамилия\tДата рождения\tКурс\tГруппа\t\n";
    for(int i = 1; i < Size; i++) {
        cout << "\n" << (BasePtr+i)->Surname << "\t" << (BasePtr+i)->Day << "." << (BasePtr+i)->Month << "." << (BasePtr+i)->Year << "\t" << (BasePtr+i)->Course << "\t" << (BasePtr+i)->Group << "\n";
    }
}