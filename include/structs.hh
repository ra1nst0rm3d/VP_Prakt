#pragma once


typedef struct RowData_s {
    unsigned Day, Month, Year, Course;
    char Surname[20], Group[10];
} RowData_s;

typedef struct Menu_s {
    unsigned Pos;
    char* Str;
} Menu_s;

const Menu_s MenuTable[13] = {
    {1, "Ввод информации с клавиатуры"},
    {2, "Ввож информации из текстового файла"},
    {3, "Ввод информации из бинарного файла"},
    {4, "Вывод таблицы на экран"},
    {5, "Вывод данных в файл"},
    {6, "Вывод распечатки по запросу"},
    {7, "Перевод БД в текстовый файл"},
    {8, "Перевод текстового файла в бинарный"},
    {9, "Добавление записи"},
    {10, "Изменение записи"},
    {11, "Удаление записи"},
    {12, "Сортировка"},
    {13, "Выход"}
};

static RowData_s* BasePtr;
static unsigned Size = 1;