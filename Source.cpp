#include "TVector.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int count = 1;
	std::cout << "Введите вектор : " << std::endl << "Введите размерность' : ";
	int n = 0;
	std::cin >> n;
	std::cout << "Введите вектор размерности " << n << " : ";
	double *mas = new double[n];
	for (int i = 0; i < n; i++) std::cin >> mas[i];
	TVector vector(n, mas);
	_flushall();
	std::cout << "Введите массив размерности " << n << " : ";
	for (int i = 0; i < n; i++) std::cin >> mas[i];
	std::cout << vector << " * ";
	std::cout << '{';
	for (int i = 0; i < n; i++)
	{
		std::cout << mas[i];
		if (i != n - 1) std::cout << "; ";
	}
	std::cout << "} = ";
	double result = vector * mas;
	delete[] mas;
	std::cout << result << std::endl;
	system("pause");
	return 0;
}
