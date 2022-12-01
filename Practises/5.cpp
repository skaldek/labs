#include <iostream>

class DynamicArray {
private:
    int *m_array = NULL;
    int m_size = 0;
public:

    void print() {
        for (int i = 0; i < m_size; i++) {
            std::cout << m_array[i] << std::endl;
        }
    }

    void push(int num) {
        int prevSize = size();
        int *newArray = new int[prevSize + 1];
        for (int i = 0; i < prevSize; i++) {
            newArray[i] = m_array[i];
        }
        newArray[prevSize] = num;
        m_array = newArray;
        m_size++;
    }

    int size() {
        return m_size;
    }

    int getByIndex(int index) {
        return m_array[index];
    }

    void changeByIndex(int index, int num) {
        m_array[index] = num;
    }

    void removeByIndex(int index) {
        int prevSize = size();
        int *newArray = new int[prevSize - 1];
        for (int i = 0; i < prevSize; i++) {
            if (i < index) {
                newArray[i] = m_array[i];
            } else {
                newArray[i] = m_array[i + 1];
            }
        }
        m_array = newArray;
        m_size--;
    }

    void insertByIndex(int index, int num) {
        int prevSize = size();
        int *newArray = new int[prevSize + 1];
        for (int i = 0; i < prevSize + 1; i++) {
            if (i < index) {
                newArray[i] = m_array[i];
            } else if (i > index) {
                newArray[i] = m_array[i - 1];
            }
        }
        newArray[index] = num;
        m_array = newArray;
        m_size++;
    }
};

int main() {
    DynamicArray dynamicArray;
    dynamicArray.push(1);
    dynamicArray.push(2);
    dynamicArray.push(3);
    dynamicArray.push(4);
    dynamicArray.print();
    std::cout << "Size: " << dynamicArray.size() << std::endl;
    std::cout << dynamicArray.getByIndex(2) << std::endl;
    dynamicArray.changeByIndex(2, 999);
    dynamicArray.print();
    dynamicArray.removeByIndex(2);
    std::cout << "Remove" << std::endl;
    dynamicArray.print();
    dynamicArray.insertByIndex(2, 555);
    std::cout << "Insert" << std::endl;
    dynamicArray.print();
}