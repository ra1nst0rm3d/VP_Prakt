#include <ios>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "config.hh"
#include "libDB.hh"
#include "struct.hh"
#include "db_manip.hh"

using namespace std;

void Input() {
    ROW_STRUCT Data{};
    cout << "---- Создание записи " << libDB::GetSize()+1 << " ----" << endl;
    cout << "Введите фамилию: ";
    cin >> Data.Surname;
    cout << "Введите день рождения: ";
    cin >> Data.Day;
    cout << "Введите месяц рождения: ";
    cin >> Data.Month;
    cout << "Введите год рождения: ";
    cin >> Data.Year;
    cout << "Введите курс: ";
    cin >> Data.Course;
    cout << "Введите группу: ";
    cin >> Data.Group;
    libDB::Add(Data);
}

void Output() {
    char Date[11];
    ROW_STRUCT* Data;
    cout.setf(std::ios::left);
    cout << setw(30) << "Фамилия" << setw(19) << "Дата" << setw(14) << "Курс" << "Группа" << endl;
    for(unsigned i = 0; i < libDB::GetSize(); i++) {
        Data = libDB::Get(i);
        sprintf(Date, "%d.%d.%d", Data->Day, Data->Month, Data->Year);
        cout << setw(30) << Data->Surname << setw(15) << Date << setw(10) << Data->Course << Data->Group << endl;
    }
}

void InputFile(enum IO io, const char* filename) {
    libDB::Reset();
    unsigned LocalSize;
    ifstream in;
    ROW_STRUCT Data;
    if(io == BINARY) {
        in.open(filename, ios_base::binary);
        if(!in.is_open()) {
            cout << "InputFile: File not found!" << endl;
            return;
        }
        in >> LocalSize;
        for(unsigned i = 0; i < LocalSize; i++)
        {
            in.read((char*)&Data, sizeof(ROW_STRUCT));
            libDB::Add(Data);
        }
    }
    in.close();
}

void OutputFile(enum IO io, const char* filename) {
    ofstream out;
    ROW_STRUCT* Data;
    if(io == BINARY) {
        out.open(filename, ios_base::binary);
        out << libDB::GetSize();
        for(unsigned i = 0; i < libDB::GetSize(); i++) {
            Data = libDB::Get(i);
            out.write((char*)Data, sizeof(ROW_STRUCT));
        }
    }
    out.close();
}
