#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

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
    cout << "Введите дату рождения в формате dd.mm.yyyy: ";
    cin >> Data.Date;
    cout << "Введите курс: ";
    cin >> Data.Course;
    cout << "Введите группу: ";
    cin >> Data.Group;
    libDB::Add(Data);
}

void Output() {
    wcout << "------------" << endl;
    if(libDB::GetSize() == 0) {
        cout << "Тут ничего нет, БД пустая!" << endl;
        cout << "------------" << endl;
        return;
    }
    ROW_STRUCT* Data;
    wcout.setf(std::ios::left);
    wcout << "№  " << setw(30) << "Фамилия" << setw(19) << "Дата" << setw(14) << "Курс" << "Группа" << endl;
    for(unsigned i = 0; i < libDB::GetSize(); i++) {
        Data = libDB::Get(i);
        wcout << i+1 << "  " << setw(30) << Data->Surname << setw(15) << Data->Date << setw(10) << Data->Course << Data->Group << endl;
    }

    wcout << "------------" << endl;
}

void InputFile(enum IO io, const char* filename) {
    libDB::Reset();
    size_t LocalSize;
    ifstream in;
    ROW_STRUCT Data;
    if(io == BINARY) {
        in.open(filename, ios_base::binary);
        if(!in.is_open()) {
            cout << "InputFile: File not found!" << endl;
            return;
        }
        if(!in.eof())in.read((char*)libDB::GetPtrToSize(), sizeof(size_t));
        cout << "DEBUG: libDB::Size = " << libDB::GetSize() << endl;
        for(unsigned i = 0; i < libDB::GetSize(); i++)
        {
            if(!in.eof()) in.read((char*)&Data, sizeof(Data));
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
        if(!out.is_open()) {
            cout << "OutputFile: file not opened!" << endl;
            return;
        }
        out.write((char*)libDB::GetPtrToSize(), sizeof(size_t));
        
        for(unsigned i = 0; i < libDB::GetSize(); i++) {
            Data = libDB::Get(i);
            out.write((char*)Data, sizeof(*Data));
        }
    }
    out.close();
}

int Edit(int placement, int editable) {
    ROW_STRUCT *Ptr = libDB::Get(placement);
    if(Ptr == NULL) {
        cout << "Edit: позиция для изменения больше кол-ва записей в БД!" << endl;
        return 0;
    }
    cout << "Введите значение: ";
    switch(editable) {
        case 0:
            cin >> Ptr->Surname;
            break;
        case 1:
            cin >> Ptr->Date;
            break;
        case 2:
            cin >> Ptr->Course;
            break;
        case 3:
            cin >> Ptr->Group;
            break;
        default:
            cout << "Вы ввели неправильное число редактируемого значения" << endl;
            return 1;
    }
    return 0;
}

void SortBySurname(bool reverse = 0) {
    ROW_STRUCT *prev, *next;
    for(unsigned i = 0; i < libDB::GetSize(); i++)  {
        prev = libDB::Get(i);
        for(unsigned j  = i+1; j < libDB::GetSize(); j++) {
            next = libDB::Get(j);
            if(reverse) {
                if(strlen(prev->Surname) > strlen(next->Surname)) {
                    libDB::Swap(i, j);
                }
            } else {
                if(strlen(prev->Surname) < strlen(next->Surname)) {
                    libDB::Swap(i, j);
                }
            }
        }
    }
}

void SortByDate(bool reverse = 0) {
    ROW_STRUCT *prev, *next;
    unsigned DayPrev, MonthPrev, YearPrev, DayNext, MonthNext, YearNext;

    for(unsigned i = 0; i < libDB::GetSize(); i++)  {
        prev = libDB::Get(i);
        sscanf(prev->Date, "%d.%d.%d", &DayPrev, &MonthPrev, &YearPrev);
        for(unsigned j  = i+1; j < libDB::GetSize(); j++) {
            next = libDB::Get(j);
            sscanf(next->Date, "%d.%d.%d", &DayNext, &MonthNext, &YearNext);
            if(reverse) {
                if(YearPrev > YearNext) {
                    libDB::Swap(i, j);
                } else if(MonthPrev > MonthNext) {
                    libDB::Swap(i, j);
                } else if(DayPrev > DayNext) {
                    libDB::Swap(i, j);
                }
            } else {
                if(YearPrev < YearNext) {
                    libDB::Swap(i, j);
                } else if(MonthPrev < MonthNext) {
                    libDB::Swap(i, j);
                } else if(DayPrev < DayNext) {
                    libDB::Swap(i, j);
                }
            }
        }
    }
}

void SortByCourse(bool reverse = 0) {
    ROW_STRUCT *prev, *next;
    for(unsigned i = 0; i < libDB::GetSize(); i++)  {
        prev = libDB::Get(i);
        for(unsigned j  = i+1; j < libDB::GetSize(); j++) {
            next = libDB::Get(j);
            if(reverse) {
                if(prev->Course > next->Course) {
                    libDB::Swap(i, j);
                }
            } else {
                if(prev->Course < next->Course) {
                    libDB::Swap(i, j);
                }
            }
        }
    }
}

void SortByGroup(bool reverse = 0) {
    ROW_STRUCT *prev, *next;
    for(unsigned i = 0; i < libDB::GetSize(); i++)  {
        prev = libDB::Get(i);
        for(unsigned j  = i+1; j < libDB::GetSize(); j++) {
            next = libDB::Get(j);
            if(reverse) {
                if(strlen(prev->Group) > strlen(next->Group)) {
                    libDB::Swap(i, j);
                }
            } else {
                if(strlen(prev->Group) < strlen(next->Group)) {
                    libDB::Swap(i, j);
                }
            }
        }
    }
}

void Sort(int TypeOfSort, bool reverse) {
    switch(TypeOfSort) {
        case 1:
            SortBySurname(reverse);
            break;
        case 2:
            SortByDate(reverse);
            break;
        case 3:
            SortByCourse(reverse);
            break;
        case 4:
            SortByGroup(reverse);
            break;
    }
}