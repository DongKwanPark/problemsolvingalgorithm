// Combination.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// 이항계수 점화식
// nCr = n-1Cr-1 + n-1Cr
__int64 ExBinomialCoefficient(int** arr, int n, int r);
__int64 BinomialCoefficient(__int64** arr, int n, int r);
__int64 Combination(int n, int r);
long long choose(int n, int r);

static __int64 countBinomialCoefficient = 0;
static __int64 countCombination = 0;
static __int64 countchoose = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0, r = 0;
	printf( "input n, r : " );
	scanf( "%d %d", &n, &r );
	__int64** arr = new __int64 * [n * r];
	for( int i = 0; i < n; i++ )
	{
		arr[i] = new __int64[r];
		for( int j = 0; j < r; j++ )
			arr[i][j] = 0;
	}
	printf( "(%d,%d) of ExBinomialCoefficient = %I64d\n", n, r, BinomialCoefficient( arr, n, r) );
// 	printf( "(%d,%d) of BinomialCoefficient = %I64d\n", n, r, ExBinomialCoefficient(n, r) );
 	printf( "(%d,%d) of ExBinomialCoefficient = %lld\n", n, r, choose(n, r) );
 	printf( "method run count ExBinomialCoefficient = %I64d, choose = %I64d\n", countBinomialCoefficient, countchoose );

	for( int i = 0; i < n; i++ )
		delete[] arr[i];
	delete[] arr;

	return 0;
}

__int64 ExBinomialCoefficient(int n, int r)
{
	countBinomialCoefficient++;
	if( r <= 0 || n == r ) return 1;
	return ExBinomialCoefficient( n - 1, r - 1 ) + ExBinomialCoefficient( n - 1, r );
}

__int64 BinomialCoefficient(__int64** arr, int n, int r)
{
	countBinomialCoefficient++;
	if( r <= 0 || n == r ) return 1;
	if( arr[n-1][r-1] > 0 ) return arr[n-1][r-1];
	arr[n-1][r-1] = BinomialCoefficient( arr, n - 1, r - 1 ) + BinomialCoefficient( arr, n - 1, r );
	return arr[n-1][r-1];
}

__int64 Combination(int n, int r)
{
	countCombination++;
	if( r <= 1 ) return n;
	__int64 result = 0;
	result = n * Combination( n - 1, r - 1 ) / r;
	return result;
}

long long choose(int n, int r)
{
	countchoose++;
	if( r == 0 || n == r )
		return 1;
	return choose( n - 1, r - 1 ) + choose( n - 1, r );
}

