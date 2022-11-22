#include <iostream>
#include <fstream>
#include <cstring>

#include "../include/libDB.hh"


using namespace std;

namespace libDB {

     void Add(ROW_STRUCT Data) {
        BasePtr = (ROW_STRUCT*)realloc(BasePtr, sizeof(ROW_STRUCT) * (Size+1));
        if(BasePtr) {
            *(BasePtr+Size) = Data;
            Size++;
        } else if (BasePtr == NULL) {
            cout << "Bad news: we lost DB :)\n";
            exit(-1);
        }
    }

    int Init() {
        BasePtr = (ROW_STRUCT*)malloc(sizeof(ROW_STRUCT));
        if (BasePtr) return 0;
        return 1;
    }

    void ShutDown() {
        free(BasePtr);
        BasePtr = NULL;
    }

    inline int Set(ROW_STRUCT Data, unsigned pos) {
        if(pos > Size) return -1;
        *(BasePtr+pos) = Data;
        return 0;
    }

    size_t GetSize() {
        return Size;
    }

    size_t* GetPtrToSize() {
        return &Size;
    }

    void SetSize(int Size) {
        libDB::Size = Size;
    }

    ROW_STRUCT* Get(unsigned pos) {
        if (pos > Size) return NULL;
        return (BasePtr+pos);
    }

    void Delete(unsigned pos) {
        if(pos > Size) {
            cout << "Delete: позиция для удаления больше кол-ва записей в БД!" << endl;
            return;
        }
        ROW_STRUCT* NewBase = (ROW_STRUCT*)malloc(sizeof(ROW_STRUCT) * (Size-1));
        int k = 0;
        for(unsigned i = 0; i < Size; i++) {
            if(i != pos) {
                *(NewBase+k) = *(BasePtr+i);
                k++;
            }
        }
        free(BasePtr);
        BasePtr = NewBase;
        Size--;
    }

    void Reset() {
        libDB::ShutDown();
        libDB::Init();
    }
    
    void Swap(int prev, int next) {
        ROW_STRUCT tmp1 = *(libDB::Get(prev));
        ROW_STRUCT tmp2 = *(libDB::Get(next));

        libDB::Set(tmp1, next);
        libDB::Set(tmp2, prev);
    }
}