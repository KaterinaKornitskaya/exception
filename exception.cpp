// exception.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
/*
	Написать функцию, определяющую, является ли счастливым 6-значное 
	число.
	Функция должна выбрасывать два исключения.
	Первое исключение - если число содержит 5 или менее цифр.
	Второе исключение - если число содержит 7 или более цифр.
	Второе исключение выбросите с использованием класса exception.
	Исключения обрабатываем в main()
*/

void is_sixdigit(int number)  // ф-ия проверка: является ли число 6-значным
{
    if (number < 100000)  // если число < 100000 - исключительная ситуация
    {
        throw "This number has less than 6 digits!";  // возбуждение исключения
    }

    if (number > 999999)  // если число > 999999 - исключительная ситуация
    {
        throw std::exception("This number has more than 6 digits!");  // возбуждение исключения
    }
}

void is_lucky() {  // ф-ия: является ли число счастливым

    int number;  // переменная для ввода пользователем 6-значного числа
    std::cout << "Enter number: ";
    std::cin >> number;

    is_sixdigit(number);  // вызов ф-ии является ли число 6-значным

    short n1 = number / 100000;        // цифра 1
    short n2 = (number / 10000) % 10;  // цифра 2
    short n3 = (number / 1000) % 10;   // цифра 3
    short n4 = (number / 100) % 10;    // цифра 4
    short n5 = (number / 10) % 10;     // цифра 5
    short n6 = number % 10;            // цифра 6

    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << ' ' << n6;

    int sum1 = n1 + n2 + n3;  // сумма первых трех цифр
    int sum2 = n4 + n5 + n6;  // сумма вторых трех цифр
    if (sum1 == sum2)         // если суммы равны
    {
        std::cout << "\nYeah! This is a lucky number!\n";
    }
    else
    {
        std::cout << "\nOops, it is not a lucky number:(\n";
    }
}

int main()
{
    try
    {
        is_lucky();  // вызов основной ф-ии программы
    }
   catch (const char* x)  // обработка исключения
   {
       std::cout << "\n" << x << "\n";
   }
   catch (const std::exception& x)  // обработка исключения
   {
       std::cout << "\nWe catch:" << x.what() << "\n";
   }

    return 0;
}
