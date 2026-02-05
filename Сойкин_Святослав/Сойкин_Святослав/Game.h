#pragma once
#include "pch.h"

// Класс для хранения и управления информацией о компьютерной игре
class Game {
    int id_;                // Уникальный идентификатор игры
    string name_;           // Название игры
    string os_;             // Поддерживаемые операционные системы
    int year_;              // Год выпуска игры
    string genre_;          // Жанровая принадлежность игры
    string publisher_;      // Издатель игры
    string developer_;      // Разработчик игры
    long long sold_;        // Количество проданных копий
    string players_;        // Режим игры (Singleplayer/Multiplayer)
    string age_;            // Возрастное ограничение
    double price_;          // Цена игры

public:
    // Конструктор по умолчанию
    Game();
    // Основной конструктор с параметрами
    Game(int id, const string& name, const string& os, int year, const string& genre, const string& publisher,
        const string& developer, long long sold, const string& players, const string& age, double price);

    // Геттеры для доступа к приватным полям класса
    int id() const;
    const string& name() const;
    const string& os() const;
    int year() const;
    const string& genre() const;
    const string& publisher() const;
    const string& developer() const;
    long long sold() const;
    const string& players() const;
    const string& age() const;
    double price() const;

    // Сеттеры с проверкой валидности входных данных
    void year(int value);
    void sold(long long value);
    void price(double value);

    // Методы для форматированного вывода информации об игре
    string toString() const;  // Строковое представление объекта
    string toTableRow(int row) const;  // Форматирование строки для табличного вывода

    // Статические методы для отрисовки структуры таблицы
    static ostream& header(ostream& os);  // Вывод шапки таблицы
    static ostream& footer(ostream& os);  // Вывод подвала таблицы
};

// Перегрузка операторов ввода/вывода для работы с объектами класса Game
ostream& operator<<(ostream& os, const Game& game);
istream& operator>>(istream& is, Game& game);