#include "stdio.h"
#include <locale>
#include <iostream>
#include <cstdlib>

using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Вычисление значений функций 1/(sqrt(1+x))\n\n";
	double x; // Значение аргумента
	double func; // Точное значение функции
	double sum; // Значение частичной суммы
	int n; // Число слогаемых в частичной сумме

	cout << "Задание 1" <<'\n';
	cout << "Введите значение аргумент > ";
	cin >> x;
	cout << "Задайте число слогаемых > ";
	cin >> n;
	func = 1/(sqrt(1 + x));// Вычисление "точного" значения
	double last;
	sum = sumN(x, n, last);
	cout << "Точное значение функции равно " << func <<'\n';
	cout << "Частичная сумма ряда равна " << sum <<'\n';
	cout << "Абсолютная погрешность равна " << fabs(func - sum) <<'\n';
	cout << "Последнее слогаемое равно " << last <<'\n';

	cout << "\n Задание 2" <<'\n';
	double E;
	cout << "Введите значение аргумента > ";
	cin >> x;
	cout << "Задайте точность вычислений > ";
	cin >> E;
	func = 1/(sqrt(1 + x));// Вычисление "точного" значения
	sum = sumE(x, E, n);
	cout << "Точное значение функции равно " << func <<'\n';
	cout << "Частичная сумма ряда с заданной точностью равна " << sum <<'\n';
	cout << "Учтено " << n << " членов ряда " <<'\n';
	sum = sumE(x, E / 10, n);
	cout << "Частичная сумма ряда с точностью, большей в 10 раз, равна " << sum <<'\n';
	cout << "Учтено " << n << " членов ряда " <<'\n';
	return 0;
}

double sumN(double x, int n, double &last)
{
	// Инициализация переменной last
	last = x;
	double sum = last;
	for (int i = 1; i < n; ++i)
	{
		double r; // Отношение i-го слогаемого к (i - 1)-му
       // Вычисление значения r
		r = -(i*2-1)*x*x*(i*2-1)/(2*i+1)/(i*2);
		last *= r;
		sum += last;
	}
	return sum;
}

double sumE(double x, double E, int &n)
{
	double last;
	// Инициализация переменной last
	last = x;
	double sum = last;
	for (n = 1; fabs(last) > E; ++n)
	{
		double r; // Отношение n-го слогаемого к (n - 1)-му
      // Вычисление значения r
		r = -(n*2-1)*x*x*(n*2-1)/(n*2+1)/(n*2);
		last *= r;
		sum += last;
	}
	return sum;
}