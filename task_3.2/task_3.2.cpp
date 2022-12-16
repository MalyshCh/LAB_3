#include <iostream>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;

int getSumElementsArray(int* linkBegin, int* linkEnd) { // 1.
    int sumElementsArray = 0;
    for (int* i = linkBegin; i <= linkEnd; i++) {
        sumElementsArray += *(i);
    }
    return sumElementsArray;
}

int sumParams(int param1, int param2) { // 3.
    return (param1 + param2);
}

int subParams(int param1, int param2) { // 3.
    return (param1 - param2);
}

typedef int (*newTypeFunction)(int, int); // 5.
newTypeFunction getCharToSelectFunction(char param) { // 4.
    if (param == '+') return &sumParams;
    else if (param == '-') return &subParams;
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "3 Лабораторная работа. Вопрос 2." << endl;

    // 1. Создайте функцию, которая принимает 2 указателя 
    // (на начало и конец массива) и которая возвращает сумму 
    // всех элементов массива.

    int myArray[5] = { 1, 6, 5, 4, 9 }; // массив
    int* myLinkmyArrayBegin = &myArray[0];
    int* myLinkmyArrayEnd = &myArray[4];

    // 2. Проверьте правильность работы функции, вызвав её и 
    // передав массив из нескольких чисел.

    cout << getSumElementsArray(myLinkmyArrayBegin, myLinkmyArrayEnd) << endl;

    // 3. Создайте 2 функции, принимающих 2 параметра и 
    // возвращающих их сумму и их разность соответственно.

    cout << "Функция 'Сумма' = " << sumParams(6, 4) << endl;
    cout << "Функция 'Разность' = " << subParams(9, 1) << endl;

    // 4. Создайте функцию, принимающую 1 параметр типа char.

    // 5. Созданная функция должна возвращать указатель на 
    // одну из двух функций (суммы или разности) в зависимости 
    // от значения переданного char. Если он равен '+', то 
    // возвращается указатель на функцию суммы, а если он 
    // равен '-', то возвращается указатель на функцию разности.

    // 6. Проверьте работу созданных функций, вызвав сначала 
    // ту, что возвращает указатель, а потом вызвав и эту 
    // функцию по указателю, получив правильное значение, 
    // которое затем выведите в консоль.

    cout << "Проверка работы созданных функций" << endl;
    cout << "(+) указатель на 'Сумма' - " << getCharToSelectFunction('+') << endl;
    cout << "(+) вызов 'Сумма' по указателю = " << getCharToSelectFunction('+')(6, 4) << endl;
    cout << "(-) указатель на 'Разность' - " << getCharToSelectFunction('-') << endl;
    cout << "(-) вызов 'Разность' по указателю = " << getCharToSelectFunction('-')(9, 1) << endl;

    // 7. Создайте динамический указатель типа float.

    float* dynamicPointer = new float(3.1415);

    // 8. Выведите его в консоль, а после удалите его из памяти 
    // с помощью delete.

    cout << "Вывод float по указателю - " << dynamicPointer << " = " << *dynamicPointer << endl;
    delete dynamicPointer;
}
