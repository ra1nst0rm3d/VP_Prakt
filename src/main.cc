#include <iostream>
#include <cstring>

#include "../include/structs.hh"
#include "../include/user_interact.hh"
using namespace std;


int main() {
    cout << "База данных\n";
    BasePtr = (RowData_s*)malloc(sizeof(RowData_s));
    memset(BasePtr, 0, sizeof(RowData_s));
    print_menu();
    user_handle();
    return 0;
}