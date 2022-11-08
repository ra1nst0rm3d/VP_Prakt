// Define your row struct here
#pragma once

// Используем pragma pack для того, чтобы на всех системах структура была одного размера, и следовательно, мы могли прочитать её без ошибок из бинарного файла
#pragma pack(push)
#pragma pack(4)
typedef struct RowData_s {
    char Surname[36], Group[16], Date[12];
    unsigned Course;
} RowData_s;
#pragma pack(pop)

#define ROW_STRUCT RowData_s


#ifndef ROW_STRUCT
#define ROW_STRUCT void*
#endif