/*
Funktion.cpp
Hier wird die Funktion definiert, mit der die zu zeichnenden Funktionswerte 
berechnet werden.
*/
#include "stdafx.h"
#include <cmath>

double f(double x, unsigned int iFun)
{
	double value = 0.0;

	switch (iFun)
	{
	case 1:
		value = sin(x);
		break;
	case 2:
		value = cos(x);
		break;
	case 3:
		value = x * exp(x);
		break;
	case 4:
		value = log(x);
		break;
	default:
		value = x;
		break;
	}
	return value;
}
