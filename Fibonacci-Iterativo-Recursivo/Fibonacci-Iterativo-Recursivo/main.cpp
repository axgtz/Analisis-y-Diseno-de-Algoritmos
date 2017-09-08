//Roberto Alejandro Gutiérrez Guillén			A0101908
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int FibonacciIterativo(int n)
{
	int suma, x, y;
	if (n <= 1) return 1;
	else {
		x = 1;
		y = 1;
		for (int i = 2; i < n; ++i)
		{
			suma = x + y;
			y = x;
			x = suma;
		}
		return suma;
	}
}

int FibonacciRecursivo(int x) {
	if (x == 0)
		return 0;

	if (x == 1)
		return 1;

	return FibonacciRecursivo(x - 1) + FibonacciRecursivo(x - 2);
}

int main() {
	cout << "1,000" << endl;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	FibonacciIterativo(1000);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
	cout << "Tiempo de ejecucion Iterativo: " << time_span.count() << " segundos" << endl;

	//No sirve el recursivo
	t1 = high_resolution_clock::now();
	FibonacciRecursivo(1000);
	t2 = high_resolution_clock::now();
	time_span = (t2 - t1);
	cout << "Tiempo de ejecucion Recursivo: " << time_span.count() << " segundos" << endl <<endl;


	
	cout << "100,000" << endl;

	t1 = high_resolution_clock::now();
	FibonacciIterativo(100000);
	t2 = high_resolution_clock::now();
	time_span = (t2 - t1);
	cout << "Tiempo de ejecucion Iterativo: " << time_span.count() << " segundos" << endl;

	t1 = high_resolution_clock::now();
	FibonacciRecursivo(100000);
	t2 = high_resolution_clock::now();
	time_span = (t2 - t1);
	cout << "Tiempo de ejecucion Recursivo: " << time_span.count() << " segundos" << endl;

	
	int x;
	cin >> x;
	return 0;
}