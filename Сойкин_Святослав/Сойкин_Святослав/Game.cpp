#include "pch.h"
#include "Game.h"
#include "Utils.h"

// Конструктор по умолчанию с инициализацией полей базовыми значениями
Game::Game() : Game(0, "Unknown", "Windows", getCurrentYear(), "Action", "Unknown", "Unknown", 100000, "Singleplayer", "3+", 10.0) {}

// Основной конструктор с валидацией входных параметров
Game::Game(int id, const string& name, const string& os, int year, const string& genre, const string& publisher,
    const string& developer, long long sold, const string& players, const string& age, double price) {
    id_ = id;
    name_ = name;
    os_ = os;
    this->year(year);  // Вызов сеттера для валидации года
    genre_ = genre;
    publisher_ = publisher;
    developer_ = developer;
    this->sold(sold);  // Вызов сеттера для валидации количества продаж
    players_ = players;
    age_ = age;
    this->price(price);  // Вызов сеттера для валидации цены
}

// Геттеры для доступа к приватным полям класса
int Game::id() const { return id_; }
const string& Game::name() const { return name_; }
const string& Game::os() const { return os_; }
int Game::year() const { return year_; }
const string& Game::genre() const { return genre_; }
const string& Game::publisher() const { return publisher_; }
const string& Game::developer() const { return developer_; }
long long Game::sold() const { return sold_; }
const string& Game::players() const { return players_; }
const string& Game::age() const { return age_; }
double Game::price() const { return price_; }

// Сеттер для года выпуска с проверкой допустимости значения
void Game::year(int value) {
    if (value < 1900 || value > getCurrentYear()) {
        throw exception("Недопустимый год издания");
    }
    year_ = value;
}

// Сеттер для количества проданных копий с проверкой на отрицательные значения
void Game::sold(long long value) {
    if (value < 0) {
        throw exception("Количество проданных копий не может быть отрицательным");
    }
    sold_ = value;
}

// Сеттер для цены с проверкой на положительное значение
void Game::price(double value) {
    if (value <= 0.0) {
        throw exception("Цена не может быть нулевой или отрицательной");
    }
    price_ = value;
}

// Формирование строкового представления объекта для вывода
string Game::toString() const {
    ostringstream oss;
    oss << setw(4) << id_ << " | " << setw(25) << left << name_ << " | " << setw(10) << left << os_ << " | "
        << setw(4) << year_ << " | " << setw(10) << left << genre_ << " | " << setw(15) << left << publisher_
        << " | " << setw(15) << left << developer_ << " | " << setw(12) << sold_ << " | "
        << setw(12) << left << players_ << " | " << setw(6) << left << age_ << " | "
        << fixed << setprecision(2) << setw(8) << price_;
    return oss.str();
}

// Вспомогательная функция для обрезки длинных строк при выводе в таблицу
static string truncateString(const string& str, size_t maxLen) {
    if (str.length() > maxLen) {
        return str.substr(0, maxLen - 3) + "...";  // Обрезка с добавлением многоточия
    }
    return str;
}

// Формирование строки таблицы с оптимальными ширинами колонок для консольного вывода
string Game::toTableRow(int row) const {
    const int colWidths[] = { 4, 4, 25, 10, 6, 12, 15, 15, 12, 12, 6, 10 }; // Оптимальные ширины колонок

    ostringstream oss;
    oss << "\t| " << setw(colWidths[0]) << right << row << " | "
        << setw(colWidths[1]) << right << id_ << " | "
        << setw(colWidths[2]) << left << truncateString(name_, colWidths[2]) << " | "
        << setw(colWidths[3]) << left << truncateString(os_, colWidths[3]) << " | "
        << setw(colWidths[4]) << right << year_ << " | "
        << setw(colWidths[5]) << left << truncateString(genre_, colWidths[5]) << " | "
        << setw(colWidths[6]) << left << truncateString(publisher_, colWidths[6]) << " | "
        << setw(colWidths[7]) << left << truncateString(developer_, colWidths[7]) << " | "
        << setw(colWidths[8]) << right << sold_ << " | "
        << setw(colWidths[9]) << left << truncateString(players_, colWidths[9]) << " | "
        << setw(colWidths[10]) << left << truncateString(age_, colWidths[10]) << "  | "
        << setw(colWidths[11]) << right << fixed << setprecision(2) << price_ << " |";

    return oss.str();
}

// Вывод шапки таблицы с игровыми данными
ostream& Game::header(ostream& os) {
    os << "\t+------+------+---------------------------+------------+--------+--------------+-----------------+-----------------+--------------+--------------+--------+------------+\n"
        << "\t|  №   |  ID  |         Название          |     ОС     |  Год   |     Жанр     |    Издатель     |   Разработчик   |   Проданно   |    Игроки    | Возр. |    Цена    |\n"
        << "\t+------+------+---------------------------+------------+--------+--------------+-----------------+-----------------+--------------+--------------+--------+------------+\n";
    return os;
}

// Вывод подвала таблицы с игровыми данными
ostream& Game::footer(ostream& os) {
    os << "\t+------+------+---------------------------+------------+--------+--------------+-----------------+-----------------+--------------+--------------+--------+------------+\n";
    return os;
}

// Перегрузка оператора вывода для удобного отображения объекта Game
ostream& operator<<(ostream& os, const Game& game) {
    os << game.toString();
    return os;
}

// Перегрузка оператора ввода (не реализована по условию задачи)
istream& operator>>(istream& is, Game& game) {
    return is;
}