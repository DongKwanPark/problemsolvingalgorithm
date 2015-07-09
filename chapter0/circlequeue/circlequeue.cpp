// bankwaiting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// ¿øÇüÅ¥
int pushqueue(int arr[], int size, int pushindex, int number, int* queuecount);
int popqueue(int arr[], int size, int popindex, int number, int* queuecount);

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[10];
	int queuecount = 0;
	int pushindex = -1, popindex = -1;
	int size = sizeof(arr)/sizeof(arr[0]);
	while( true )
	{
		printf( "input number : " );
		int input; scanf( "%d", &input );
		if( input > 0 )
			pushindex = pushqueue( arr, size, pushindex, input, &queuecount );
		else if( input == 0 )
			popindex = popqueue( arr, size, popindex, input, &queuecount );
		else
			break;
	}

	return 0;
}

int pushqueue(int arr[], int size, int pushindex, int number, int* queuecount)
{
	int result = pushindex;
	if( *queuecount >= size )
	{
		printf( "queue full!\n" );
	}
	else
	{
		pushindex++;
		if( pushindex >= size )
			pushindex = pushindex % size;
				
		arr[pushindex] = number;
		printf( "wait number %d\n", arr[pushindex] );
		result = pushindex;
		(*queuecount)++;
	}
	return result;
}

int popqueue(int arr[], int size, int popindex, int number, int* queuecount)
{
	int result = popindex;
	if( *queuecount < 1 )
	{
		printf( "queue empty!\n" );
	}
	else
	{
		popindex++;
		if( popindex >= size )
			popindex = popindex % size;

		printf( "%d call number\n", arr[popindex] );
		result = popindex;
		(*queuecount)--;
	}
	return result;
}

