/*������ ������� �� ����, ����������� ����� ��� ����������� ���������.
����� ����, ��������� ������ �� ����, ����� �����, ���������� ������������ ����� �����.
���� ����� ���� ������ ������, ����� ������������� �� ���.

��� ��������� ��������� ������������ ����-��������������� ������ � �������� ������ � ����� char.
����� ������ ������ �� ����������� 300 ���������
������, �������� � ������ ������, ������� ������������������ ��������, ������������ ���������-�������������, ������� � ������ ������.
�������, ����������� � ������������, ���������� ������������, ���� ���� �� ������� � �������.
���� ������ ������ ����������, ��������� ������ �������� �������������� ���������.
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
{ //�������� ��������� ��� ������ ������ � �� ���� � ������ ���!!
	setlocale(LC_ALL, ".1251");
	int begin[300];
	int end[300];
	int numberNull[300];
	int numberOfDigitWords = 0;
	null(begin);
	cout << "������ ����. ������� �����." << endl;
	gets_s(String, 300);
	if (String[0] == '\0') {
		cout << "������ ����\n";
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
		int maxNullPos = 0; // ������� ���� ���������� �����
		for (int i = 0; i < numberOfDigitWords; ++i) {
			if (numberNull[i] >= numberNull[maxNullPos]) { // ������ ���������� �����
				maxNullPos = i;
			}
		}
		int numberOfMaxNull = 0; // ���-�� ���� � ���� 0
		for (int i = 0; i < numberOfDigitWords; ++i) {
			if (numberNull[i] == numberNull[maxNullPos]) {
				numberOfMaxNull++;
			}
		}
		if (numberOfMaxNull == 1) { // ������� ���� �����
			for (int j = begin[maxNullPos]; j < end[maxNullPos]; ++j) {
					cout << String[j];
			}cout << endl;
			cout << "���� ��������� �����" << endl;
		}
		else { // ����� ������������ 
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
			cout <<"���� ������������� �����"<< endl;
		}
	}
	else {
		cout << "����, ���������� ����, ���.\n";
	}

	system("pause");

	return 0;
}