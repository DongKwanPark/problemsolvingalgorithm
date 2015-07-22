// Factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "float.h"

// factorial function
double factorial(int n);
double recursivefactorial(int n);

int _tmain(int argc, _TCHAR* argv[])
{
	int factorialvalue = 9;
	printf( "%d!of value = %g\n", factorialvalue, factorial(factorialvalue) );
	printf( "recursive %d!of value = %g\n", factorialvalue, recursivefactorial(factorialvalue) );

	return 0;
}


double factorial(int n)
{
	double result = 0, value = 1;
	for( int i = n; i > 0; i-- )
	{
		if( value >= DBL_MAX || value <= DBL_MIN )
		{
			printf( "after %d value over\n", i );
			break;
		}
		value *= i;
		result = value;
	}
	return result;
}

double recursivefactorial(int n)
{
	double result = 0, value = 1;
	if( n > 0 )
	{
		if( value >= DBL_MAX || value <= DBL_MIN )
			return value;
		value = n * recursivefactorial( n - 1 );
	}
	result = value;
	
	return result;
}

