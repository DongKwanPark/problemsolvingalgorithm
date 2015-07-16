// exerciseproblem00.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void countofone(int number);
void stacklinkedlist();
void binaryprint(int number);

int _tmain(int argc, _TCHAR* argv[])
{
	// 0.c 문제
	countofone( 1000 );
	// 0.d 문제
	stacklinkedlist();
	// 0.g 문제
	binaryprint( 600 );		// 1001011000
	binaryprint( 1000 );	// 1111101000

	return 0;
}



void countofone(int number)
{
	int count = 0;
	int value = number;
	while( value > 1 )
	{
		if( value % 2 == 1 )
			count++;
		value /= 2;
	}
	if( value == 1)
		count++;

	printf( "이진수로 변환한 1의 개수는 %d개\n", count );
}

struct node
{
	int value;
	node* prev;
};

int stackpop(node*& top);
node* stackpush(node* top, int input);

void stacklinkedlist()
{
	node* top = NULL;
	while( true )
	{
		printf( "input number (exit = -1) : " );
		int input; scanf( "%d", &input );

		if( input < 0 )
			break;
		else if( input == 0 )
		{
			if( top == NULL )
				printf( "stack is empty!\n" );
			else
				printf( "get number : %d\n", stackpop( top ) );
		}
		else
		{
			top = stackpush( top, input );
			//if( top ) printf( "set number : %d\n", top->value );
		}
	}
	while( top )
	{
		node* prev = top->prev;
		delete[] top;
		top = prev;
	}
}

int stackpop(node*& top)
{
	int value = 0;
	if( top )
	{
		value = top->value;
		node* prev = top->prev;
		delete[] top;
		top = prev;
	}
	else
		top = NULL;
	return value;
}

node* stackpush(node* top, int input)
{
	node* data = new node;
	data->value = input;
	data->prev = top;
	return data;
}

void binaryprint(int number)
{
	int digit = 1;
	int value = number;
	unsigned long binary = 0;
	while( value > 0 )
	{
		binary += ( value % 2 * digit );
		value /= 2;
		digit *= 10;
	}
	printf( "%ld\n", binary );
}