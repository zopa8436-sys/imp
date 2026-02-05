#include "pch.h"
#include "App.h"
#include "Utils.h"
#include "GameFactory.h"

// Статический объект магазина и флаг инициализации
Store App::store_;
bool App::initialized_ = false;

// Инициализация приложения с загрузкой данных из файла
void App::initialize(const string& filename) {
    store_ = Store(filename);  // Создание магазина с загрузкой данных из CSV файла
}

// Вспомогательная функция для вывода коллекции игр в табличном формате
void showAsTable(const vector<Game>& games) {
    Game::header(cout);  // Вывод шапки таблицы
    int row = 1;
    for (const auto& game : games) {
        cout << game.toTableRow(row++) << "\n";  // Вывод строки таблицы для каждой игры
    }
    Game::footer(cout);  // Вывод подвала таблицы
}

// Вывод информации о магазине и его коллекции игр
void App::printStore() {
    store_.print();  // Вызов метода print объекта Store
}

// Инициализация коллекции игр с использованием фабрики
void App::initCollection() {
    if (store_.games().empty()) {
        store_ = Store("games.csv");  // Пересоздание магазина с данными из файла
    }
    cout << cls << "Коллекция сформирована.\n";
    printStore();  // Вывод обновленной коллекции
}

// Добавление новой игры в коллекцию магазина
void App::addGame() {
    printStore();  // Вывод текущего состояния коллекции
    // Определение следующего доступного ID
    int nextId = store_.games().empty() ? 1 : max_element(store_.games().begin(), store_.games().end(),
        [](const Game& a, const Game& b) { return a.id() < b.id(); })->id() + 1;

    Game newGame = GameFactory::create(nextId);  // Создание новой игры через фабрику
    store_.addGame(newGame);  // Добавление игры в коллекцию

    cout << cls << "Игра добавлена: " << newGame << "\n";

    // Сохранение позиции курсора для выделения добавленной игры
    COORD startPos;
    getXY(&startPos);
    printStore();  // Вывод обновленной коллекции

    // Поиск и выделение добавленной игры
    auto it = max_element(store_.games().begin(), store_.games().end(), [](const Game& a, const Game& b) { return a.id() < b.id(); });
    size_t index = it - store_.games().begin();
    short highlightY = startPos.Y + 6 + static_cast<short>(index);
    cout << pos(0, highlightY) << color(infoColor) << it->toTableRow(static_cast<int>(index + 1)) << color(mainColor)
        << pos(0, highlightY + 1 + store_.games().size() - index);
}

// Редактирование существующей игры по ID
void App::editGame() {
    printStore();  // Вывод текущего состояния коллекции
    cout << "Введите ID для редактирования: ";
    int id = getInt();  // Получение ID от пользователя
    getKey("Нажмите для редактирования...");
    store_.editGame(id);  // Вызов метода редактирования
    cout << cls << "Игра отредактирована.\n";
    printStore();  // Вывод обновленной коллекции
}

// Удаление игры из коллекции по ID
void App::removeGame() {
    printStore();  // Вывод текущего состояния коллекции
    cout << "Введите ID для удаления: ";
    int id = getInt();  // Получение ID от пользователя
    getKey("Нажмите для удаления...");
    store_.removeGame(id);  // Вызов метода удаления
    cout << cls << "Игра удалена.\n";
    printStore();  // Вывод обновленной коллекции
}

// Сортировка коллекции игр по возрастанию ID
void App::sortById() {
    printStore();  // Вывод текущего состояния коллекции
    getKey("Нажмите для сортировки...");
    store_.sortById();  // Вызов метода сортировки
    cout << cls << "Отсортировано по ID.\n";
    printStore();  // Вывод отсортированной коллекции
}

// Сортировка коллекции игр по убыванию года выпуска
void App::sortByYearDesc() {
    printStore();  // Вывод текущего состояния коллекции
    getKey("Нажмите для сортировки...");
    store_.sortByYearDesc();  // Вызов метода сортировки
    cout << cls << "Отсортировано по убыванию года.\n";
    printStore();  // Вывод отсортированной коллекции
}

// Сортировка коллекции игр по возрастанию цены
void App::sortByPriceAsc() {
    printStore();  // Вывод текущего состояния коллекции
    getKey("Нажмите для сортировки...");
    store_.sortByPriceAsc();  // Вызов метода сортировки
    cout << cls << "Отсортировано по возрастанию цены.\n";
    printStore();  // Вывод отсортированной коллекции
}

// Сортировка коллекции игр по убыванию количества проданных копий
void App::sortBySoldDesc() {
    printStore();  // Вывод текущего состояния коллекции
    getKey("Нажмите для сортировки...");
    store_.sortBySoldDesc();  // Вызов метода сортировки
    cout << cls << "Отсортировано по убыванию проданных копий.\n";
    printStore();  // Вывод отсортированной коллекции
}

// Фильтрация игр по диапазону цен
void App::filterByPriceRange() {
    printStore();  // Вывод текущего состояния коллекции
    cout << "Введите мин. цену: ";
    double minPrice;
    cin >> minPrice;  // Получение минимальной цены
    checkInputFormat(cin);  // Проверка формата ввода
    cout << "Введите макс. цену: ";
    double maxPrice;
    cin >> maxPrice;  // Получение максимальной цены
    checkInputFormat(cin);  // Проверка формата ввода
    getKey("Нажмите для фильтра...");

    vector<Game> filtered = store_.filterByPriceRange(minPrice, maxPrice);  // Фильтрация игр
    cout << cls << "Отфильтровано по диапазону цены (" << minPrice << "-" << maxPrice << "):\n";

    if (filtered.empty()) {
        cout << "Игры не найдены.\n";  // Сообщение об отсутствии результатов
    }
    else {
        showAsTable(filtered);  // Вывод отфильтрованных игр
    }
}

// Фильтрация игр по году выпуска
void App::filterByYear() {
    printStore();  // Вывод текущего состояния коллекции
    cout << "Введите год: ";
    int year = getInt();  // Получение года от пользователя
    getKey("Нажмите для фильтра...");

    vector<Game> filtered = store_.filterByYear(year);  // Фильтрация игр
    cout << cls << "Отфильтровано по году " << year << " (sorted по жанру):\n";

    if (filtered.empty()) {
        cout << "Игры не найдены.\n";  // Сообщение об отсутствии результатов
    }
    else {
        showAsTable(filtered);  // Вывод отфильтрованных игр
    }
}

// Фильтрация игр по операционной системе
void App::filterByOs() {
    printStore();  // Вывод текущего состояния коллекции
    string os;
    cout << "Введите ОС (например, Windows): ";
    getline(cin >> ws, os);  // Получение операционной системы от пользователя
    getKey("Нажмите для фильтра...");

    vector<Game> filtered = store_.filterByOs(os);  // Фильтрация игр
    cout << cls << "Отфильтровано по ОС " << os << " (sorted по убыванию года):\n";

    if (filtered.empty()) {
        cout << "Игры не найдены.\n";  // Сообщение об отсутствии результатов
    }
    else {
        showAsTable(filtered);  // Вывод отфильтрованных игр
    }
}

// Сохранение данных магазина в CSV файл
void App::saveStore() {
    printStore();  // Вывод текущего состояния коллекции
    getKey("Нажмите для сохранения...");
    store_.saveToCSV("games.csv");  // Сохранение в файл
    cout << cls << "Магазин сохранен.\n";
    printStore();  // Вывод текущего состояния коллекции
}

// Загрузка данных магазина из CSV файла
void App::loadStore() {
    store_.loadFromCSV("games.csv");  // Загрузка из файла
    cout << cls << "Магазин загружен.\n";
    printStore();  // Вывод загруженной коллекции
}