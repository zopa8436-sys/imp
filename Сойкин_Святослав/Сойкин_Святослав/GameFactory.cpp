#include "pch.h"
#include "GameFactory.h"
#include "Utils.h"

// Статические коллекции данных для случайной генерации игровых объектов
static vector<string> names = {
    "The Witcher 3", "Cyberpunk 2077", "GTA V", "Minecraft", "Fortnite", "Among Us", "Doom Eternal",
    "Assassin's Creed", "FIFA 23", "Call of Duty", "The Legend of Zelda", "Super Mario"
};

static vector<string> oses = { "Windows", "Linux", "macOS", "PlayStation", "Xbox" };

static vector<string> genres = { "RPG", "Action", "Adventure", "Shooter", "Sports", "Strategy" };

static vector<string> publishers = { "CD Projekt", "Rockstar", "EA", "Activision", "Nintendo", "Bethesda" };

static vector<string> developers = { "CD Projekt RED", "Rockstar Games", "Mojang", "Epic Games", "id Software", "Ubisoft" };

static vector<string> ages = { "3+", "7+", "12+", "16+", "18+" };

static vector<string> playersTypes = { "Singleplayer", "Multiplayer" };

// Создание одного игрового объекта со случайными характеристиками
Game GameFactory::create(int id) {
    // Генерация случайных значений для всех полей объекта Game
    string name = names[getRand(0, names.size() - 1)];
    string os = oses[getRand(0, oses.size() - 1)];
    int current = getCurrentYear();
    int year = current - getRand(0, 20);  // Год выпуска в пределах последних 20 лет
    string genre = genres[getRand(0, genres.size() - 1)];
    string publisher = publishers[getRand(0, publishers.size() - 1)];
    string developer = developers[getRand(0, developers.size() - 1)];
    long long sold = getRand(10'000, 10'000'000);  // Количество продаж от 10k до 10M
    string players = playersTypes[getRand(0, playersTypes.size() - 1)];
    string age = ages[getRand(0, ages.size() - 1)];
    double price = getRand(10.0, 100.0);  // Цена от 10 до 100 условных единиц

    // Создание и возврат объекта Game
    return Game(id, name, os, year, genre, publisher, developer, sold, players, age, price);
}

// Создание коллекции игровых объектов заданного размера
vector<Game> GameFactory::createVector(int n, int startId) {
    vector<Game> games;
    // Последовательное создание n игровых объектов
    for (int i = 0; i < n; ++i) {
        games.emplace_back(create(startId + i));  // Использование emplace_back для эффективного добавления
    }
    return games;
}