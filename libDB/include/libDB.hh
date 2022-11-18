#pragma once
#include <iostream>

#include "../include/config.hh"

using std::size_t;

namespace libDB {
    static ROW_STRUCT* BasePtr;
    static size_t Size;

    // Манипуляции с БД в памяти
    void Add(ROW_STRUCT Data);
    void Delete(unsigned pos);
    ROW_STRUCT* Get(unsigned pos);
    inline int Set(ROW_STRUCT Data, unsigned pos);
    void Swap(int prev, int  next);
    size_t GetSize();
    size_t* GetPtrToSize();
    void SetSize(int Size);
    int Init();
    void ShutDown();
    void Reset();

}