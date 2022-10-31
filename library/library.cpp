#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <io.h>
#include <vector>
#include <regex> 

using namespace std;

class book {
public:
    string name;
    string author;
    void see() {

    }
    void set_name() {
        cout << "Введите название книги: ";
        cin >> name;
    }
    void set_author() {
        cout << "Введите автора: ";
        cin >> author;
    }
    string get_name() {
        return name;
    }
    string get_author() {
        return author;
    }
};

class otdel :public book {
public:
    book arr_of_books[10];
    string nameOfOtdel;
    int number_of_book = 0;
    void add() {
        if (number_of_book + 1 <= 10) {
            number_of_book++;
            cout << "Введите данные новой книги\n\n";
            cout << "Название: ";
            cin >> arr_of_books[number_of_book - 1].name;
            cout << "Автор: ";
            cin >> arr_of_books[number_of_book - 1].author;
            cout << endl;
            cout << "Новая книга успешно добавлена!" << endl;
        }
        else cout << "Недостаточно памяти для добавления нового объекта!" << endl << endl;
    }
    void del() {
        int number_of_deleted_item;
        cout << "Введите название удаляемой книги: ";
        cin >> number_of_deleted_item;
        number_of_deleted_item--;
        for (int i = number_of_deleted_item; i < number_of_book - 1; i++)
            arr_of_books[i] = arr_of_books[i + 1];
        number_of_book--;
        cout << "Книга удалена!" << endl << endl;
    }
    void see() {
        for (int i = 0; i < number_of_book; i++) {
            cout << arr_of_books[i].name << " " << arr_of_books[i].author << endl;
        }
        cout << endl;
    }
    string get_nameOfOtdel() {
        return nameOfOtdel;
    }
};


class library :public otdel {
    otdel arr_of_otdel[10];
    string nameOfLibrary;
    int numberOfOtdel = 0;
public:
    void set_nameOfLibrary() {
        cout << "Название библиотеки: ";
        cin >> nameOfLibrary;
    }

    string get_nameOfLibrary() {
        return nameOfLibrary;
    }
    void addOtdel() {
        if (numberOfOtdel + 1 <= 10) {
            numberOfOtdel++;
            cout << "Название отделa: ";
            cin >> arr_of_otdel[numberOfOtdel - 1].nameOfOtdel;
            cout << "Новый отдел успешно добавлен!" << endl;
        }
        else cout << "Недостаточно памяти для добавления нового объекта!" << endl << endl;
    }
    void delOtdel() {
        int number_of_deleted_otdel;
        cout << "Введите название удаляемой книги : ";
        cin >> number_of_deleted_otdel;
        number_of_deleted_otdel--;
        for (int i = number_of_deleted_otdel; i < numberOfOtdel - 1; i++)
            arr_of_otdel[i] = arr_of_otdel[i + 1];
        numberOfOtdel--;
        cout << "Отдел удален!" << endl << endl;
    }
    void see() {
        for (int i = 0; i < numberOfOtdel; i++) {
            cout << arr_of_otdel[i].nameOfOtdel << endl;
        }
        cout << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "Russian");
    int kod;
    library n1;
    otdel n2;
    n1.set_nameOfLibrary();
    n1.get_nameOfLibrary();
    do {
        cout << "Добавить книгу => 1" << endl;
        cout << "Удалить книгу => 2" << endl;
        cout << "Просмотр => 3" << endl;
        cout << "Выход => 0" << endl;
        cin >> kod;
        switch (kod) {
        case 1: n2.add();  break;
        case 2: n2.del(); break;
        case 5: n2.see(); break;
        case 0: exit(0);
        }
    } while (kod != 0);
    return 0;
}