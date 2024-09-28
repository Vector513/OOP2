/*
#include "application.h"

Application::Application() : array() {};

Application::~Application() {};

void Application::run()
{
    char separator[] = "------------------------------------------------------------------------------------------------------------------------";
    char commands[] = "1) Ввести значения массива с консоли\n2) Рассчитать среднее и СКО элементов массива\n3) Отсортировать элементы массива по возрастанию или убыванию\n4) Изменить размерность массива\n5) Изменить значение элемента массива\ns) Вывести текущие элементы массива\nc) Вывести список команд\ne) Выход из программы\n";

    char command = 'c';

    do {
        if (command == 'e') {
            cout << "Программа была завершена по воле пользователя\n";
            break;
        }

        else if (command == 'c') {
            cout << commands;
        }

        else if (command == 's') {
            array.show(cout);
        }

        else if (command == '1') {
            array.clear();
            fill();
            cout << "Массив был успешно заполнен введёнными значениями\n";
        }
        else if (command == '2') {
            cout << "Среднее значение: " << (array.average()) << '\n';
            cout << "СКО: " << (array.MSD()) << '\n';
        }
        else if (command == '3') {
            cout << "Отсортировать по возрастанию? (y/n): ";
            char isIncreased = ' ';
            cin >> isIncreased;
            if (isIncreased == 'y') {
                array.sort();
                cout << "Элементы массива были успешно отсортированы по возрастанию\n";
                array.show(cout);
            }
            else if (isIncreased == 'n') {
                array.sort(true);
                cout << "Элементы массива были успешно отсортированы по убыванию\n";
                array.show(cout);
            }
            else {
                cout << "Вы ввели неправильный символ, массив не был отсортирован\n";
            }
        }
        else if (command == '4') {
            cout << "Введите новую размерность текущего массива: ";
            int newCapacity;
            cin >> newCapacity;
            resize(newCapacity);
            cout << "Размер массива был успешно изменён на " << newCapacity << '\n';
        }
        else if (command == '5') {
            cout << "Введите индекс и новое значение элемента массива: ";
            int index = 0;
            number value = 0.0;
            cin >> index >> value;
            array[index] = value;
            cout << "Значение элемента массива с индексом " << index << " было успешно изменено\n";
            array.show(cout);
        }

            // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
            // 71 38 11 28 20 42 39 89 48 30 35 40 71 97 8 2 2 72 34 38
        cout << separator << '\n';
        cout << "Введите комманду: ";
        cin >> command;
        cout << '\n';

    } while (true);
}

void Application::fill()
{
    string input;
    cout << "Введите элементы списка: ";
    cin.get();
    getline(cin, input);
    array.fill(input);
}

void Application::resize(int newCapacity)
{
    array.resize(newCapacity);
}

*/

#include "Application.h"
#include <iostream>

Application::Application() : array() {}

Application::~Application() {}

void Application::run() {
    const char separator[] = "------------------------------------------------------------------------------------------------------------------------";
    const char commands[] = "1) Ввести значения массива с консоли\n"
        "2) Рассчитать среднее и СКО элементов массива\n"
        "3) Отсортировать элементы массива по возрастанию или убыванию\n"
        "4) Изменить размерность массива\n"
        "5) Изменить значение элемента массива\n"
        "s) Вывести текущие элементы массива\n"
        "c) Вывести список команд\n"
        "e) Выход из программы\n";

    char command = 'c';

    do {
        if (command == 'e') {
            std::cout << "Программа была завершена по воле пользователя\n";
            break;
        }
        else if (command == 'c') {
            std::cout << commands;
        }
        else if (command == 's') {
            array.show(std::cout);
        }
        else if (command == '1') {
            array.clear();
            fill();
            std::cout << "Массив был успешно заполнен введёнными значениями\n";
        }
        else if (command == '2') {
            try {
                std::cout << "Среднее значение: " << array.average() << '\n';
                std::cout << "СКО: " << array.MSD() << '\n';  // Если MSD - это СКО, нужно уточнить его расчёт
            }
            catch (std::exception& e) {
                std::cout << "Ошибка при вычислении: " << e.what() << '\n';
            }
        }
        else if (command == '3') {
            std::cout << "Отсортировать по возрастанию? (y/n): ";
            char isIncreased;
            std::cin >> isIncreased;
            if (isIncreased == 'y') {
                array.sort();
                std::cout << "Элементы массива были успешно отсортированы по возрастанию\n";
                array.show(std::cout);
            }
            else if (isIncreased == 'n') {
                array.sort(true);
                std::cout << "Элементы массива были успешно отсортированы по убыванию\n";
                array.show(std::cout);
            }
            else {
                std::cout << "Вы ввели неправильный символ, массив не был отсортирован\n";
            }
        }
        else if (command == '4') {
            std::cout << "Введите новую размерность текущего массива: ";
            int newCapacity;
            std::cin >> newCapacity;
            resize(newCapacity);
            std::cout << "Размер массива был успешно изменён на " << newCapacity << '\n';
        }
        else if (command == '5') {
            std::cout << "Введите индекс и новое значение элемента массива: ";
            int index;
            number value;
            std::cin >> index >> value;
            try {
                array[index] = value;
                std::cout << "Значение элемента массива с индексом " << index << " было успешно изменено\n";
                array.show(std::cout);
            }
            catch (std::out_of_range& e) {
                std::cout << "Ошибка: " << e.what() << '\n';
            }
        }

        std::cout << separator << '\n';
        std::cout << "Введите команду: ";
        std::cin >> command;
        std::cout << '\n';

    } while (true);
}

void Application::fill() {
    std::string input;
    std::cout << "Введите элементы списка: ";
    std::cin.ignore();  // Пропускаем символ новой строки, оставленный после предыдущего cin
    std::getline(std::cin, input);
    array.fill(input);
}

void Application::resize(int newCapacity) {
    array.resize(newCapacity);
}