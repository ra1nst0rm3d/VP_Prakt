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
        case 13:
            return;
        default:
            cout << "Вы ввели номер нереализованной функции" << endl;
            user_handle();
    }
    print_menu();
    user_handle(); 
}