// Console.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Vector.h"


int main()
{

	Vector<int, 4> A({1, 2, 3, 4});
	cout << A;

	Vector<double, 4> B({ 2, 1, 0, 1 });
	cout << B;

	auto e = (A - B) * (A + B);

	Vector<int, 0> D;
	cout << D;

    return 0;
}

