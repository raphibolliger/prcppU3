// Console.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Vector.h"


int main()
{

	Vector<int, 4> A({1, 2, 3, 4});
	cout << A;

	Vector<int, 0> D;
	cout << D;

    return 0;
}

