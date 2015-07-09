// bankwaiting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// 은행대기번호관리
int pushqueue(int arr[], int size, int tail, int number);
int popqueue(int arr[], int size, int head, int number);

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[10];
	int head = 0, tail = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
	while( true )
	{
		printf( "input number : " );
		int input; scanf( "%d", &input );
		if( input > 0 )
			tail = pushqueue( arr, size, tail, input );
		else if( input == 0 )
			head = popqueue( arr, (tail - head), head, input );
		else
			break;
	}

	return 0;
}

int pushqueue(int arr[], int size, int tail, int number)
{
	int result = tail;
	if( tail >= size )
	{
		printf( "queue full!\n" );
	}
	else
	{
		arr[tail] = number;
		printf( "wait number %d\n", arr[tail] );
		result = ++tail;
	}
	return result;
}

int popqueue(int arr[], int size, int head, int number)
{
	int result = head;
	if( size < 1 )
	{
		printf( "queue empty!\n" );
	}
	else
	{
		printf( "%d call number\n", arr[head] );
		result = ++head;
	}
	return result;
}

