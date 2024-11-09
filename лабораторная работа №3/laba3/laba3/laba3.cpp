#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> readDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    int count;
    file >> count;  // Считываем количество элементов

    std::vector<int> data(count);
    for (int i = 0; i < count; ++i) {
        file >> data[i];  // Считываем сами данные
    }

    file.close();
    return data;
}

std::vector<int> sumVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    size_t size = std::min(vec1.size(), vec2.size());
    std::vector<int> result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = vec1[i] + vec2[i];  // Суммируем соответствующие элементы
    }
    return result;
}

std::vector<int> subtractVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    size_t size = std::min(vec1.size(), vec2.size());
    std::vector<int> result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = vec1[i] - vec2[i];  // Суммируем соответствующие элементы
    }
    return result;
}

int multiplicationVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    size_t size = std::min(vec1.size(), vec2.size());
    std::vector<int> result(size);
    int mp_Vector = 0;
    for (size_t i = 0; i < size; ++i) {
        mp_Vector += vec1[i] * vec2[i];  // Суммируем соответствующие элементы
    }
    return mp_Vector;
}


void printVector(const std::vector<int>& vec) {
    for (int value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    system("chcp 1251");
    system("cls");
    try {
        std::vector<int> data1 = readDataFromFile("file1.txt");
        std::vector<int> data2 = readDataFromFile("file2.txt");

        std::vector<int> sum = sumVectors(data1, data2);
        std::vector<int> subt = subtractVectors(data1, data2);
        int multuplic = multiplicationVectors(data1, data2);

        std::cout << "Сумма векторов: ";
        printVector(sum);
        std::cout << "Разность векторов: ";
        printVector(subt);
        std::cout << "Скалярное проивзедение: ";
        std::cout << multuplic << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
