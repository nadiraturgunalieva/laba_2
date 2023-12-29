#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

// Функция инициализации векторов дефолтными значениями
void initDefault(vector<string>& names, vector<int>& grades) {
    names = { "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Henry", "Ingrid", "Jack" };
    grades = { 78, 85, 92, 67, 75, 88, 90, 82, 95, 79 };
}

// Функция инициализации векторов случайными значениями
void initRandom(vector<string>& names, vector<int>& grades) {
    int size;
    cout << "Введите желаемый размер выборки: ";
    cin >> size;

    // Словарь реалистичных имен
    vector<string> nameDict = { "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Henry", "Ingrid", "Jack" };

    // Заполнение векторов случайными значениями
    for (int i = 0; i < size; i++) {
        int randomIndex = rand() % nameDict.size();
        names.push_back(nameDict[randomIndex]);
        int grade = rand() % 101;
        grades.push_back(grade);
    }
}

// Функция инициализации векторов значениями, введенными пользователем
void initUserInput(vector<string>& names, vector<int>& grades) {
    int size;
    cout << "Введите желаемый размер выборки: ";
    cin >> size;

    cout << "Введите имена и оценки студентов (имя оценка):" << endl;
    for (int i = 0; i < size; i++) {
        string name;
        int grade;
        cin >> name >> grade;
        names.push_back(name);
        grades.push_back(grade);
    }
}

// Функция вывода содержимого векторов с использованием Range-based for-loop
void printWithRangeBasedForLoop(const vector<string>& names, const vector<int>& grades) {
    cout << "Содержимое векторов с использованием Range-based for-loop:" << endl;
    for (const auto& name : names) {
        cout << name << " ";
    }
    cout << endl;

    for (const auto& grade : grades) {
        cout << grade << " ";
    }
    cout << endl;
}

// Функция вывода содержимого векторов с использованием итератора
void printWithIterator(const vector<string>& names, const vector<int>& grades) {
    cout << "Содержимое векторов с использованием итератора:" << endl;
    for (auto it = names.begin(); it != names.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = grades.begin(); it != grades.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// Функция вывода содержимого векторов с использованием индексового цикла
void printWithIndexLoop(const vector<string>& names, const vector<int>& grades) {
    cout << "Содержимое векторов с использованием индексового цикла:" << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < grades.size(); i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}

// Функция подсчета среднего значения оценок
double calculateAverage(const vector<int>& grades) {
    int sum = 0;
    for (const auto& grade : grades) {
        sum += grade;
    }

    return static_cast<double>(sum) / grades.size();
}

// Функция подсчета медианы оценок
double calculateMedian(vector<int>& grades) {
    // Сортировка вектора
    bool sorted = false;
    int left = 0;
    int right = grades.size() - 1;

    while (!sorted) {
        sorted = true;

        // Проход слева направо
        for (int i = left; i < right; i++) {
            if (grades[i] > grades[i + 1]) {
                swap(grades[i], grades[i + 1]);
                sorted = false;
            }
        }
        right--;

        // Проход справа налево
        for (int i = right; i > left; i--) {
            if (grades[i - 1] > grades[i]) {
                swap(grades[i - 1], grades[i]);
                sorted = false;
            }
        }
        left++;
    }

    // Подсчет медианы
    if (grades.size() % 2 == 0) {
        int middleIndex1 = grades.size() / 2 - 1;
        int middleIndex2 = grades.size() / 2;
        return static_cast<double>(grades[middleIndex1] + grades[middleIndex2]) / 2;
    }
    else {
        int middleIndex = grades.size() / 2;
        return grades[middleIndex];
    }
}

// Функция подсчета моды оценок
vector<string> calculateMode(const vector<string>& names, const vector<int>& grades) {
    unordered_map<int, int> gradeCount;  // хранит количество каждой оценки
    int maxCount = 0;
    for (const auto& grade : grades) {
        gradeCount[grade]++;
        maxCount = max(maxCount, gradeCount[grade]);
    }

    vector<string> modeNames;  // имена студентов, у которых оценка соответствует моде
    for (const auto& pair : gradeCount) {
        if (pair.second == maxCount) {
            int grade = pair.first;
            for (int i = 0; i < grades.size(); i++) {
                if (grades[i] == grade) {
                    modeNames.push_back(names[i]);
                }
            }
        }
    }

    return modeNames;
}

// Функция добавления пары имя-значение в векторы
void addPair(vector<string>& names, vector<int>& grades) {
    string name;
    int grade;
    cout << "Введите имя и оценку студента (имя оценка): ";
    cin >> name >> grade;
    names.push_back(name);
    grades.push_back(grade);
}

// Функция удаления пары имя-значение из векторов по имени
void removePairByName(vector<string>& names, vector<int>& grades) {
    string name;
    cout << "Введите имя студента, которого нужно удалить: ";
    cin >> name;

    // Поиск индексов пар, соответствующих имени
    vector<int> indicesToDelete;
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == name) {
            indicesToDelete.push_back(i);
        }
    }

    // Удаление пар по индексам
    for (int i = indicesToDelete.size() - 1; i >= 0; i--) {
        int index = indicesToDelete[i];
        names.erase(names.begin() + index);
        grades.erase(grades.begin() + index);
    }
}

int main() {

    setlocale(LC_ALL, "RU");

    vector<string> names;
    vector<int> grades;

    cout << "1) Инициализация векторов" << endl;
    cout << "Выберите способ инициализации:" << endl;
    cout << "1. Демонстрационный анализ на дефолтных входных значениях" << endl;
    cout << "2. Анализ на случайных входных значениях" << endl;
    cout << "3. Анализ на входных значениях от пользователя" << endl;
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        initDefault(names, grades);
        break;
    case 2:
        initRandom(names, grades);
        break;
    case 3:
        initUserInput(names, grades);
        break;
    default:
        cout << "Некорректный выбор" << endl;
        return 0;
    }

    cout << endl;


    cout << "Выберите способ вывода содержимого векторов:" << endl;
    cout << "1. Range-based for-loop" << endl;
    cout << "2. Итератор" << endl;
    cout << "3. Индексовый цикл" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        printWithRangeBasedForLoop(names, grades);
        break;
    case 2:
        printWithIterator(names, grades);
        break;
    case 3:
        printWithIndexLoop(names, grades);
        break;
    default:
        cout << "Некорректный выбор" << endl;
        return 0;
    }

    cout << endl;

    cout << "3) Функции вывода среднего значения, медианы и моды оценок" << endl;
    cout << "Среднее значение оценок: " << calculateAverage(grades) << endl;
    cout << "Медиана оценок: " << calculateMedian(grades) << endl;
    vector<string> modeNames = calculateMode(names, grades);
    cout << "Мода оценок:" << endl;
    for (const auto& name : modeNames) {
        cout << name << " ";
    }
    cout << endl;

    cout << endl;

    cout << "3.1) Своя сортировка: Shaker sort" << endl;
    // Реализация Shaker sort
    bool sorted = false;
    int left = 0;
    int right = grades.size() - 1;

    while (!sorted) {
        sorted = true;

        // Проход слева направо
        for (int i = left; i < right; i++) {
            if (grades[i] > grades[i + 1]) {
                swap(grades[i], grades[i + 1]);
                sorted = false;
            }
        }
        right--;

        // Проход справа налево
        for (int i = right; i > left; i--) {
            if (grades[i - 1] > grades[i]) {
                swap(grades[i - 1], grades[i]);
                sorted = false;
            }
        }
        left++;
    }

    cout << "Отсортированные оценки:" << endl;
    for (const auto& grade : grades) {
        cout << grade << " ";
    }
    cout << endl;

    cout << endl;

    cout << "4) Подсчет моды оценок для многомодального распределения" << endl;
    // Модифицированная функция подсчета моды для многомодального распределения
    unordered_map<int, int> gradeCount;
    int maxCount = 0;
    for (const auto& grade : grades) {
        gradeCount[grade]++;
        maxCount = max(maxCount, gradeCount[grade]);
    }

    cout << "Оценки с наибольшим количеством повторений (мода):" << endl;
    for (const auto& pair : gradeCount) {
        if (pair.second == maxCount) {
            cout << pair.first << " ";
        }
    }
    cout << endl;

    cout << endl;

    cout << "4.1) Добавление и удаление пар имя-значение" << endl;
    cout << "Выберите действие:" << endl;
    cout << "1. Добавить пару имя-значение" << endl;
    cout << "2. Удалить пару имя-значение" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        addPair(names, grades);
        break;
    case 2:
        removePairByName(names, grades);
        break;
    default:
        cout << "Некорректный выбор" << endl;
        return 0;
    }

    cout << "Обновленное содержимое векторов:" << endl;
    printWithRangeBasedForLoop(names, grades);

    return 0;
}
