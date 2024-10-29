#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція, яка перевіряє наявність пари "no" або "on" у рядку
bool ContainsPair(const char* str) {
    const char* pos = str;
    while ((pos = strchr(pos, 'n')) != nullptr) {
        if (*(pos + 1) == 'o') return true; // знайдено "no"
        pos++;
    }
    pos = str;
    while ((pos = strchr(pos, 'o')) != nullptr) {
        if (*(pos + 1) == 'n') return true; // знайдено "on"
        pos++;
    }
    return false;
}

// Функція, яка замінює всі підрядки "no" на "***" у рядку
char* ReplaceNoWithStars(const char* str) {
    int len = strlen(str);
    char* result = new char[len * 3 + 1]; // виділяємо місце для результату
    result[0] = '\0'; // ініціалізуємо пустим рядком
    const char* pos = str;
    const char* next;

    while ((next = strstr(pos, "no")) != nullptr) {
        strncat(result, pos, next - pos); // додаємо частину перед "no"
        strcat(result, "***"); // додаємо заміну для "no"
        pos = next + 2; // пропускаємо "no"
    }

    strcat(result, pos); // додаємо решту рядка після останньої заміни
    return result;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Перевірка на наявність пар "no" або "on"
    bool hasPair = ContainsPair(str);
    cout << "String contains pairs 'no' or 'on': " << (hasPair ? "Yes" : "No") << endl;

    // Замінюємо всі пари "no" на "***"
    char* modifiedStr = ReplaceNoWithStars(str);
    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr; // звільняємо пам'ять
    return 0;
}
