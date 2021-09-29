/*строка состоит из слов, разделенных одним или несколькими пробелами.
среди слов, состо€щих только из цифр, найти слово, содержащее максимальное число нулей.
если таких слов больше одного, найти предпоследнее из них.

при написании программы использовать нуль-терминированные строки и работать только с типом char.
длина каждой строки не превосходит 300 символовю
словом, вход€щим в состав строки, назовем последовательность символов, ограниченную символами-разделител€ми, началом и концом строки.
символы, относ€щиес€ к разделител€м, определ€ет пользователь, если иное не сказано в условии.
если решить задачу невозможно, программа должна выводить соответсвующее сообщение.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

char String[301];

int max(int a, int b) {
	return a > b ? a : b;
}

void null(int *begin) {
	for (int i = 0; i < 300; ++i) {
		begin[i] = -1;
	}
	return;
}

bool checkWord(int beginIt, int endIt) {
	for (int i = beginIt; i < endIt; ++i) {
		if (!isdigit(String[i])) {
			return 0;
		}
	}
	return 1;
}

int counter(int beginIt, int endIt) {
	int k = 0;
	for (int i = beginIt; i < endIt; ++i) {
		if (String[i] == '0') {
			k++;
		}
	}
	return k;
}

int main()
{ //написать сообщение дл€ строки пустой а не слов с нул€ми нет!!
	setlocale(LC_ALL, ".1251");
	int begin[300];
	int end[300];
	int numberNull[300];
	int numberOfDigitWords = 0;
	null(begin);
	cout << "ƒобрый день. ¬ведите слова." << endl;
	gets_s(String, 300);
	if (String[0] == '\0') {
		cout << "ѕустой ввод\n";
		system("pause");
		return 0;
	}
	int i = 0;
	while (String[i] != '\0') {
		if (String[i] != ' ') {
			int j = i + 1;
			while ((String[j] != ' ') && (String[j] != '\0')) {
				j++;
			}
			if (checkWord(i, j)) {
				if (counter(i, j) > 0) {
					begin[numberOfDigitWords] = i;
					end[numberOfDigitWords] = j;
					numberNull[numberOfDigitWords] = counter(i, j);
					numberOfDigitWords++;
				}
			}
			i = j;
		}
		else {
			i++;
		}
	}

	if (numberOfDigitWords > 0) {
		int maxNullPos = 0; // позици€ макс количества нулей
		for (int i = 0; i < numberOfDigitWords; ++i) {
			if (numberNull[i] >= numberNull[maxNullPos]) { // массив количества нулей
				maxNullPos = i;
			}
		}
		int numberOfMaxNull = 0; // кол-во слов с макс 0
		for (int i = 0; i < numberOfDigitWords; ++i) {
			if (numberNull[i] == numberNull[maxNullPos]) {
				numberOfMaxNull++;
			}
		}
		if (numberOfMaxNull == 1) { // вывести одно слово
			for (int j = begin[maxNullPos]; j < end[maxNullPos]; ++j) {
					cout << String[j];
			}cout << endl;
			cout << "¬ыше последнее слово" << endl;
		}
		else { // найти предпосленее 
			int k = numberNull[maxNullPos];
			numberNull[maxNullPos] = -1;
			for (int i = numberOfDigitWords - 1; i >= 0; --i) {
				if (numberNull[i] == k) {
					for (int j = begin[i]; j < end[i]; ++j) {
						cout << String[j];
					}
					break;
				}
			}
			cout << endl;
			cout <<"¬ыше предпоследнее слово"<< endl;
		}
	}
	else {
		cout << "—лов, содержащих нули, нет.\n";
	}

	system("pause");

	return 0;
}