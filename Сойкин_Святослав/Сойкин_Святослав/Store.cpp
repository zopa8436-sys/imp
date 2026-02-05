#include "pch.h"
#include "Store.h"
#include "GameFactory.h"
#include "Utils.h"

// Конструктор по умолчанию с базовыми значениями названия и адреса магазина
Store::Store() : name_("Game Store"), address_("г. Москва, ул. Ленина, д. 10") {}

// Конструктор с загрузкой данных из CSV файла
Store::Store(const string& filename) : name_("Game Store"), address_("г. Москва, ул. Ленина, д. 10") {
    try {
        loadFromCSV(filename);  // Попытка загрузки данных из файла
    }
    catch (...) {
        // При неудачной загрузке создается новая коллекция с помощью фабрики
        games_ = GameFactory::createVector(12);
        try {
            saveToCSV(filename);  // Попытка сохранения созданной коллекции в файл
        }
        catch (...) {
            // Игнорирование ошибок сохранения
        }
    }
}

// Геттеры для доступа к приватным полям класса
const string& Store::name() const { return name_; }
const string& Store::address() const { return address_; }
const vector<Game>& Store::games() const { return games_; }

// Добавление новой игры в коллекцию магазина
void Store::addGame(const Game& game) {
    games_.push_back(game);  // Добавление игры в конец вектора
}

// Редактирование существующей игры по её идентификатору
void Store::editGame(int id) {
    // Поиск игры с указанным ID
    auto it = find_if(games_.begin(), games_.end(), [id](const Game& g) { return g.id() == id; });
    if (it == games_.end()) {
        throw exception("Игра с таким ID не найдена");
    }
    // Замена найденной игры на новую с тем же ID
    Game newGame = GameFactory::create(id);
    *it = newGame;
}

// Удаление игры из коллекции по её идентификатору
void Store::removeGame(int id) {
    // Перемещение всех игр с указанным ID в конец вектора
    auto it = remove_if(games_.begin(), games_.end(), [id](const Game& g) { return g.id() == id; });
    if (it != games_.end()) {
        games_.erase(it, games_.end());  // Удаление перемещённых элементов
    }
}

// Сортировка коллекции игр по возрастанию идентификатора
void Store::sortById() {
    sort(games_.begin(), games_.end(), [](const Game& a, const Game& b) { return a.id() < b.id(); });
}

// Сортировка коллекции игр по убыванию года выпуска
void Store::sortByYearDesc() {
    sort(games_.begin(), games_.end(), [](const Game& a, const Game& b) { return a.year() > b.year(); });
}

// Сортировка коллекции игр по возрастанию цены
void Store::sortByPriceAsc() {
    sort(games_.begin(), games_.end(), [](const Game& a, const Game& b) { return a.price() < b.price(); });
}

// Сортировка коллекции игр по убыванию количества проданных копий
void Store::sortBySoldDesc() {
    sort(games_.begin(), games_.end(), [](const Game& a, const Game& b) { return a.sold() > b.sold(); });
}

// Фильтрация игр по диапазону цен с сортировкой по возрастанию цены
vector<Game> Store::filterByPriceRange(double minPrice, double maxPrice) const {
    vector<Game> filtered;
    // Копирование игр, удовлетворяющих условию по цене
    copy_if(games_.begin(), games_.end(), back_inserter(filtered),
        [minPrice, maxPrice](const Game& g) { return g.price() >= minPrice && g.price() <= maxPrice; });
    // Сортировка отфильтрованных игр по возрастанию цены
    sort(filtered.begin(), filtered.end(), [](const Game& a, const Game& b) { return a.price() < b.price(); });
    return filtered;
}

// Фильтрация игр по году выпуска с сортировкой по жанру
vector<Game> Store::filterByYear(int year) const {
    vector<Game> filtered;
    // Копирование игр, выпущенных в указанном году
    copy_if(games_.begin(), games_.end(), back_inserter(filtered),
        [year](const Game& g) { return g.year() == year; });
    // Сортировка отфильтрованных игр по названию жанра
    sort(filtered.begin(), filtered.end(), [](const Game& a, const Game& b) { return a.genre() < b.genre(); });
    return filtered;
}

// Фильтрация игр по операционной системе с сортировкой по убыванию года выпуска
vector<Game> Store::filterByOs(const string& os) const {
    vector<Game> filtered;
    // Копирование игр для указанной операционной системы
    copy_if(games_.begin(), games_.end(), back_inserter(filtered),
        [os](const Game& g) { return g.os() == os; });
    // Сортировка отфильтрованных игр по убыванию года выпуска
    sort(filtered.begin(), filtered.end(), [](const Game& a, const Game& b) { return a.year() > b.year(); });
    return filtered;
}

// Вывод информации о магазине и его коллекции игр в табличном формате
void Store::print() const {
    cout << "Название: " << name_ << "\nАдрес: " << address_ << "\nИгры:\n";
    Game::header(cout);  // Вывод шапки таблицы
    int row = 1;
    for (const auto& game : games_) {
        cout << game.toTableRow(row++) << "\n";  // Вывод строк таблицы
    }
    Game::footer(cout);  // Вывод подвала таблицы
}

// Загрузка данных магазина из CSV файла
void Store::loadFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw exception(("Ошибка открытия файла: " + filename).c_str());
    }

    string line;
    // Чтение первой строки с информацией о магазине
    if (!getline(file, line)) {
        file.close();
        throw exception("Файл пустой или нечитаем");
    }

    // Разбор строки с названием и адресом магазина
    istringstream iss(line);
    string token;
    getline(iss, name_, ';');
    getline(iss, address_, ';');
    games_.clear();  // Очистка текущей коллекции

    // Чтение данных об играх
    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        int id, year;
        long long sold;
        double price;
        string name, os, genre, publisher, developer, players, age;

        // Разбор строки с данными об игре
        if (!getline(iss, token, ';')) break;
        id = stoi(token);
        getline(iss, name, ';');
        getline(iss, os, ';');
        getline(iss, token, ';'); year = stoi(token);
        getline(iss, genre, ';');
        getline(iss, publisher, ';');
        getline(iss, developer, ';');
        getline(iss, token, ';'); sold = stoll(token);
        getline(iss, players, ';');
        getline(iss, age, ';');
        getline(iss, token, ';'); price = stod(token);

        // Создание и добавление объекта Game в коллекцию
        games_.emplace_back(id, name, os, year, genre, publisher, developer, sold, players, age, price);
    }
    file.close();
}

// Сохранение данных магазина в CSV файл
void Store::saveToCSV(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        throw exception("Ошибка открытия файла для записи");
    }
    // Запись информации о магазине
    file << name_ << ";" << address_ << "\n";
    // Запись данных об играх
    for (const auto& game : games_) {
        file << game.id() << ";" << game.name() << ";" << game.os() << ";" << game.year() << ";" << game.genre() << ";"
            << game.publisher() << ";" << game.developer() << ";" << game.sold() << ";" << game.players() << ";"
            << game.age() << ";" << game.price() << "\n";
    }
    file.close();
}