#pragma once

enum IO {
    BINARY = 0,
    TEXT = 1
};

void Input(); // ввод с клавиатуры
void InputFile(enum IO io, const char* filename); // из файла
void Output(); // вывод в консоль
void OutputFile(enum IO io, const char* filename); // в файл


