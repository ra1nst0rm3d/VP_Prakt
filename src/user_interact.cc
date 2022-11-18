#include <iostream>
#include <cstring>

#include "struct.hh"
#include "libDB.hh"
#include "db_manip.hh"

using namespace std;


void print_menu() {
    for(auto a : MenuTable) {
        cout << a.Pos << ". " << a.Val << endl;
    }
}

void user_handle() {
    unsigned Answer;
    cout << "Выберите действие: ";
    cin >> Answer;
    switch(Answer) {
        case 1:
            Input();
            break;
        case 3:
            char name_in[40];
            memset(name_in, 0, sizeof(name_in));
            cin >> name_in;
            InputFile(BINARY, name_in);
            break;
        case 4:
            Output();
            break;
        case 5:
            char name[40];
            memset(name, 0, sizeof(name));
            cin >> name;
            OutputFile(BINARY, name);
            break;
        case 10:
            int row, num;
            Output();
            cout << "Какую бы запись вы хотели бы отредактировать: ";
            cin >> row;
            cout << "Что редактируем: 1 - фамилию, 2 - дату рождения, 3 - курс, 4 - группу: ";
            cin >> num;
            Edit(row-1, num-1);
            break;
        case 11:
            Output();
            cout << "Введите номер записи для удаления: ";
            cin >> row;
            libDB::Delete(row-1);
            break;
        case 12:
            cout << "Что сортируем: 1 - фамилии, 2 - даты, 3 - курсы, 4 - группу: ";
            cin >> num;
            cout << "По возрастанию или в обратном порядке: 0 - по возрастанию, 1 - в обратном порядке: ";
            cin >> row;
            Sort(num, row);
            break;
        case 13:
            return;
        default:
            cout << "Вы ввели номер нереализованной функции" << endl;
            user_handle();
    }
    print_menu();
    user_handle(); 
}