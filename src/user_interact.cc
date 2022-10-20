#include <iostream>

#include "../include/user_interact.hh"
#include "../include/structs.hh"
#include "../include/struct_methods.hh"
using namespace std;

void print_menu() {
    for(auto s: MenuTable) {
        cout << s.Pos << ". " << s.Str << endl;
    }
}

void user_handle() {
    unsigned Answer;
    cout << "Что вы хотите сделать: ";
    cin >> Answer;
    switch(Answer) {
        case 1:
            input_keyboard();
            break;
        case 4:
            output_table();
            break;
        case 13:
            free(BasePtr);
            exit(0);
        default:
            cout << "Вы ввели номер нереализованной функции, либо неправильное число\n";
            user_handle();
    }
    print_menu();
    user_handle();
}