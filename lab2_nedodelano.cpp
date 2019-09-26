#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int sort(int a[100], int m) {
	int n, s, w;
	//n - номер ячейки, m - длина массива, w - индикатор готовности сортировки
	do {
		w = 0;
		for (n = 1; n < m; n++) {
			if (a[n - 1] > a[n]) {
				w++;
				s = a[n - 1];
				a[n - 1] = a[n];
				a[n] = s;
			}
		}
		m--;
	} while (w != 0);
	return 0;
}

int main() {
	setlocale(LC_ALL, "");
	int arr[100], m;	//m - длина массива

	//пользователь определяет длину массива от 1 до 100
	do {
		cout << "Введите длину массива от 2 до 100: ";
		cin >> m;
		if (m <= 1)	cout << "\nНедостаточная длина массива.\n";
		else if (m > 100) cout << "\nЧрезмерная длина массива.\n";
	} while ((1 >= m) || (100 < m));
	cout << endl;

	int n;
	srand(time(NULL));
	for (n = 0; n < m; n++) {
		arr[n] = rand() % 99;
		cout << arr[n] << " ";
	}

	sort(arr, m);
	cout << endl << endl;

	for (n = 0; n < m; n++) {
		cout << arr[n] << " ";
	}

	//вывод максимального и минимального элементов массива
	cout << endl << "\nМинимальный элемент массива : " << arr[0] <<
		"\nМаксимальный элемент массива : " << arr[m - 1];

	//вывод элементов меньших чем a
	cout << "\nВведите a: ";
	int a;
	cin >> a;
	cout << "\nЭлементы, меньшие чем " << a << ":\n";
	for (n = 0; n < m; n++) {
		if (arr[n] < a) cout << arr[n] << " ";
	}

	//вывод элементов больших чем b
	cout << "\nВведите b: ";
	int b;
	cin >> b;
	cout << "\nЭлементы, большие чем " << b << ":\n";
	for (n = 0; n < m; n++) {
		if (arr[n] > b) cout << arr[n] << " ";
	}

	return 0;
}
