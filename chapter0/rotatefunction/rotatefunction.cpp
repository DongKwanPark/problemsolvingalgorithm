// rotatefunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//////////////////////////////////////////////////////////////////////////
// 문제로 풀어보는 알고리즘
// 0.3 25Page 생각해보기
// k를 인자로 받아서 k만큼 오른쪽으로 회전시키는 함수
// s : Rotate 배열의 첫 위치
// t : Rotate 배열의 마지막 위치
// k : 오른쪽으로 Rotate시키는 값


void rightrotate(int arr[], int s, int t, int k);

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	int s = 2;
	int t = 9;
	int k = 12;
	rightrotate( arr, s, t, k );

	printf( "풀이 : " );
	int count = sizeof(arr) / sizeof(arr[0]);
	for( int i = 0; i < count; i++ )
		printf( "%d, ", arr[i] );

	printf( "\n" );
	printf( "해답 : 1, 2, 7, 8, 9, 10, 3, 4, 5, 6, 11," );

	return 0;
}

void rightrotate(int arr[], int s, int t, int k)
{
	if( k > (t-s+1) )
		k = k % (t-s+1);

	int* temp = new int[k];
	
	for( int i = 0; i < k; i++ )
		temp[i] = arr[s+k+i];
	for( int i = t; i - k >= s; i-- )
		arr[i] = arr[i-k];
	for( int i = 0; i < k; i++ )
		arr[i+s] = temp[i];

	delete[] temp;
}

