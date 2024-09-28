/*
#include "application.h"

Application::Application() : array() {};

Application::~Application() {};

void Application::run()
{
    char separator[] = "------------------------------------------------------------------------------------------------------------------------";
    char commands[] = "1) ������ �������� ������� � �������\n2) ���������� ������� � ��� ��������� �������\n3) ������������� �������� ������� �� ����������� ��� ��������\n4) �������� ����������� �������\n5) �������� �������� �������� �������\ns) ������� ������� �������� �������\nc) ������� ������ ������\ne) ����� �� ���������\n";

    char command = 'c';

    do {
        if (command == 'e') {
            cout << "��������� ���� ��������� �� ���� ������������\n";
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
            cout << "������ ��� ������� �������� ��������� ����������\n";
        }
        else if (command == '2') {
            cout << "������� ��������: " << (array.average()) << '\n';
            cout << "���: " << (array.MSD()) << '\n';
        }
        else if (command == '3') {
            cout << "������������� �� �����������? (y/n): ";
            char isIncreased = ' ';
            cin >> isIncreased;
            if (isIncreased == 'y') {
                array.sort();
                cout << "�������� ������� ���� ������� ������������� �� �����������\n";
                array.show(cout);
            }
            else if (isIncreased == 'n') {
                array.sort(true);
                cout << "�������� ������� ���� ������� ������������� �� ��������\n";
                array.show(cout);
            }
            else {
                cout << "�� ����� ������������ ������, ������ �� ��� ������������\n";
            }
        }
        else if (command == '4') {
            cout << "������� ����� ����������� �������� �������: ";
            int newCapacity;
            cin >> newCapacity;
            resize(newCapacity);
            cout << "������ ������� ��� ������� ������ �� " << newCapacity << '\n';
        }
        else if (command == '5') {
            cout << "������� ������ � ����� �������� �������� �������: ";
            int index = 0;
            number value = 0.0;
            cin >> index >> value;
            array[index] = value;
            cout << "�������� �������� ������� � �������� " << index << " ���� ������� ��������\n";
            array.show(cout);
        }

            // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
            // 71 38 11 28 20 42 39 89 48 30 35 40 71 97 8 2 2 72 34 38
        cout << separator << '\n';
        cout << "������� ��������: ";
        cin >> command;
        cout << '\n';

    } while (true);
}

void Application::fill()
{
    string input;
    cout << "������� �������� ������: ";
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
    const char commands[] = "1) ������ �������� ������� � �������\n"
        "2) ���������� ������� � ��� ��������� �������\n"
        "3) ������������� �������� ������� �� ����������� ��� ��������\n"
        "4) �������� ����������� �������\n"
        "5) �������� �������� �������� �������\n"
        "s) ������� ������� �������� �������\n"
        "c) ������� ������ ������\n"
        "e) ����� �� ���������\n";

    char command = 'c';

    do {
        if (command == 'e') {
            std::cout << "��������� ���� ��������� �� ���� ������������\n";
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
            std::cout << "������ ��� ������� �������� ��������� ����������\n";
        }
        else if (command == '2') {
            try {
                std::cout << "������� ��������: " << array.average() << '\n';
                std::cout << "���: " << array.MSD() << '\n';  // ���� MSD - ��� ���, ����� �������� ��� ������
            }
            catch (std::exception& e) {
                std::cout << "������ ��� ����������: " << e.what() << '\n';
            }
        }
        else if (command == '3') {
            std::cout << "������������� �� �����������? (y/n): ";
            char isIncreased;
            std::cin >> isIncreased;
            if (isIncreased == 'y') {
                array.sort();
                std::cout << "�������� ������� ���� ������� ������������� �� �����������\n";
                array.show(std::cout);
            }
            else if (isIncreased == 'n') {
                array.sort(true);
                std::cout << "�������� ������� ���� ������� ������������� �� ��������\n";
                array.show(std::cout);
            }
            else {
                std::cout << "�� ����� ������������ ������, ������ �� ��� ������������\n";
            }
        }
        else if (command == '4') {
            std::cout << "������� ����� ����������� �������� �������: ";
            int newCapacity;
            std::cin >> newCapacity;
            resize(newCapacity);
            std::cout << "������ ������� ��� ������� ������ �� " << newCapacity << '\n';
        }
        else if (command == '5') {
            std::cout << "������� ������ � ����� �������� �������� �������: ";
            int index;
            number value;
            std::cin >> index >> value;
            try {
                array[index] = value;
                std::cout << "�������� �������� ������� � �������� " << index << " ���� ������� ��������\n";
                array.show(std::cout);
            }
            catch (std::out_of_range& e) {
                std::cout << "������: " << e.what() << '\n';
            }
        }

        std::cout << separator << '\n';
        std::cout << "������� �������: ";
        std::cin >> command;
        std::cout << '\n';

    } while (true);
}

void Application::fill() {
    std::string input;
    std::cout << "������� �������� ������: ";
    std::cin.ignore();  // ���������� ������ ����� ������, ����������� ����� ����������� cin
    std::getline(std::cin, input);
    array.fill(input);
}

void Application::resize(int newCapacity) {
    array.resize(newCapacity);
}