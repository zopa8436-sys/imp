#pragma once
#include "pch.h"
#include "Store.h"

// Класс приложения для управления магазином игр
class App {
private:
    static Store store_;  // Статический объект магазина
    static bool initialized_;  // Флаг инициализации приложения

public:
    // Инициализация приложения с загрузкой данных из файла
    static void initialize(const string&);

    // Вывод информации о магазине и его коллекции игр
    static void printStore();

    // Инициализация коллекции игр с использованием фабрики
    static void initCollection();

    // Добавление новой игры в коллекцию магазина
    static void addGame();

    // Редактирование существующей игры по ID
    static void editGame();

    // Удаление игры из коллекции по ID
    static void removeGame();

    // Сортировка коллекции игр по возрастанию ID
    static void sortById();

    // Сортировка коллекции игр по убыванию года выпуска
    static void sortByYearDesc();

    // Сортировка коллекции игр по возрастанию цены
    static void sortByPriceAsc();

    // Сортировка коллекции игр по убыванию количества проданных копий
    static void sortBySoldDesc();

    // Фильтрация игр по диапазону цен
    static void filterByPriceRange();

    // Фильтрация игр по году выпуска
    static void filterByYear();

    // Фильтрация игр по операционной системе
    static void filterByOs();

    // Сохранение данных магазина в CSV файл
    static void saveStore();

    // Загрузка данных магазина из CSV файла
    static void loadStore();
};