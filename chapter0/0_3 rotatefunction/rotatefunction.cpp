// rotatefunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//////////////////////////////////////////////////////////////////////////
// ������ Ǯ��� �˰���
// 0.3 25Page �����غ���
// k�� ���ڷ� �޾Ƽ� k��ŭ ���������� ȸ����Ű�� �Լ�
// s : Rotate �迭�� ù ��ġ
// t : Rotate �迭�� ������ ��ġ
// k : ���������� Rotate��Ű�� ��


void rightrotate(int arr[], int s, int t, int k);

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	int s = 2;
	int t = 9;
	int k = 12;
	rightrotate( arr, s, t, k );

	printf( "Ǯ�� : " );
	int count = sizeof(arr) / sizeof(arr[0]);
	for( int i = 0; i < count; i++ )
		printf( "%d, ", arr[i] );

	printf( "\n" );
	printf( "�ش� : 1, 2, 7, 8, 9, 10, 3, 4, 5, 6, 11," );

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

