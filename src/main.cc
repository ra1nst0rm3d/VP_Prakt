#include <iostream>

#include "config.hh"
#include "struct.hh"
#include "user_interact.hh"

#include "libDB.hh"


using namespace std;

int main() {
    libDB::Init();
    cout << "База данных" << endl;
    print_menu();
    user_handle();
    libDB::ShutDown();
    return 0;
}