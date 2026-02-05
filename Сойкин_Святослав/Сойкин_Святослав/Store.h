#pragma once
#include "pch.h"
#include "Game.h"

// Класс для управления магазином компьютерных игр
class Store {
    string name_;      // Название магазина
    string address_;   // Адрес магазина
    vector<Game> games_; // Коллекция игр в магазине

public:
    Store();  // Конструктор по умолчанию
    Store(const string& filename);  // Конструктор с загрузкой данных из файла

    // Геттеры для доступа к данным магазина
    const string& name() const;
    const string& address() const;
    const vector<Game>& games() const;

    // Методы управления коллекцией игр
    void addGame(const Game& game);  // Добавление игры в коллекцию
    void editGame(int id);  // Редактирование игры по ID
    void removeGame(int id);  // Удаление игры по ID

    // Методы сортировки коллекции игр
    void sortById();  // Сортировка по возрастанию ID
    void sortByYearDesc();  // Сортировка по убыванию года выпуска
    void sortByPriceAsc();  // Сортировка по возрастанию цены
    void sortBySoldDesc();  // Сортировка по убыванию количества продаж

    // Методы фильтрации коллекции игр
    vector<Game> filterByPriceRange(double minPrice, double maxPrice) const;  // Фильтрация по диапазону цен
    vector<Game> filterByYear(int year) const;  // Фильтрация по году выпуска
    vector<Game> filterByOs(const string& os) const;  // Фильтрация по операционной системе

    // Вывод информации о магазине и его коллекции
    void print() const;

    // Методы работы с файлами
    void loadFromCSV(const string& filename);  // Загрузка данных из CSV файла
    void saveToCSV(const string& filename) const;  // Сохранение данных в CSV файл
};