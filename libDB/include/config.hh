// Define your row struct here
#pragma once

// Используем pragma pack для того, чтобы на всех системах структура была одного размера, и следовательно, мы могли прочитать её без ошибок из бинарного файла
#pragma pack(push)
#pragma pack(2)
typedef struct RowData_s {
    unsigned Day,Month,Year,Course;
    char Surname[36], Group[16];
} RowData_s;
#pragma pack(pop)

#define ROW_STRUCT RowData_s


#ifndef ROW_STRUCT
#define ROW_STRUCT void*
#endif