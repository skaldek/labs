#include <iostream>
#include <string>
#include <fstream>
#include <cstring>


int main() {
    setlocale(LC_ALL, "ru");
    int c_letters[33] = {};
    char letters[33] = {'а', 'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т',
                        'у',
                        'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я', 'ё'};
    std::ifstream in("../input.txt");
    std::ofstream out("../output.txt");
    std::string array[1000];
    int ind_text = 0;
    while (!in.eof()) {
        char word[35];
        in >> word;
        array[ind_text] = word;

        for (int i = 0; i < strlen(word) - 1; i++) {
            char k = word[i];
            int index = (int) k;
            if (224 <= index and index <= 255) {
                index -= 32;
            }
            if (192 <= index and index <= 223) {
                c_letters[index - 192] += 1;
            }
            if (index == 184 or index == 168) {
                c_letters[32] += 1;
            }
        }
        ind_text += 1;
    }

    for (int i = 0; i < 32; i++) {
        for (int j = i + 1; j < 33; j++) {
            if (c_letters[i] < c_letters[j]) {
                std::swap(c_letters[i], c_letters[j]);
                std::swap(letters[i], letters[j]);
            }
        }

    }

    char max_cnt_letters[10];
    for (int i = 0; i < 10; i++) {
        max_cnt_letters[i] = letters[i];
    }

    for (int i = 0; i < 1000; i++) {
        char word[35];
        int current = 0;
        strcpy(word, array[i].c_str());
        char cur_letter;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 35; k++) {
                if (word[k] == max_cnt_letters[j]) {
                    current += 1;
                    cur_letter = word[k];
                    break;
                }
            }

        }
        if (current == 1) {
            char edited[35]{};
            for (int j = 0; j < 35; j++) {
                if (192 <= word[j] and
                    word[j] <= 223 or word[j] == 168) {
                    edited[j] = word[j];
                } else if (224 <= word[j] and
                           word[j] <= 255 or word[j] == 184) {
                    char cur_l;
                    cur_l = word[j] - 32;

                    edited[j] = cur_l;
                }
            }
            std::string brackets = edited;
            brackets = brackets + '(' + cur_letter + ')';
            array[i] = brackets;
        }
    }
    for (int i = 0; i < 1000; i++) {
        out << array[i] << ' ';
    }
}