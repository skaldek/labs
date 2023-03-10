#include <iostream>
#include <vector>

std::vector<int> vec = {1, 2, 3, 4, 5, 6};

void print() {
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::cout << "Size: " << vec.size() << std::endl;
    vec.push_back(
            111); // Значение n будет вставлено в конец вектора, если тип данных вектора поддерживает тип данных n. Ничего не возвращает.
    vec.erase(vec.begin()); // Удаляет элемент или диапазон элементов в векторе из заданных позиций
    vec.insert(vec.begin(), 222); // Вставляет элемент или несколько элементов в вектор по заданной позиции
    print();
    vec.at(0) = 333; // Операция присвания
    vec[1] = 444;
    print();

    vec.emplace_back(
            555); // Добавляет элемент, созданный на месте, в конец вектора.
    vec.resize(6, 10); // Определяет новый размер вектора.
    print();

    vec.reserve(
            9); // Резервирует минимальную длину хранилища для объекта вектора. Вызов reserve() не влияет на size.
    vec.shrink_to_fit(); // Эта функция уменьшает количество используемой памяти нашего вектора (иначе говоря, у нас есть вектор из 10 элементов, но он пустой, эта функция возвращает память системе, которую занимал наш пустой вектор)
    vec.capacity(); // Возвращает число элементов, которое вектор может содержать без выделения дополнительного пространства.
    vec.clear(); // Очистка вектора
    std::cout << "Size: " << vec.size();
    return 0;
}