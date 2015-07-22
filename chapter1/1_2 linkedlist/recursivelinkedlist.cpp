// bankwaitinglinkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// 은행대기자관리 링크드리스트
struct node
{
	int key;
	node* nextnode;
};

node* insertnode(node* tail, int number, int* nodecount);
node* deletenode(node* head, int* nodecount);
void print_list(node* head);
void reverseprint_list(node* head);

int _tmain(int argc, _TCHAR* argv[])
{
	node* root = new node;
	root->key = -1;
	root->nextnode = NULL;
	node* head = root;
	node* tail = root;
	int nodecount = 0;

	while( true )
	{
		printf( "input number : " );
		int input; scanf( "%d", &input );

		if( input > 0 )
			tail = insertnode( tail, input, &nodecount );
		else if( input == 0 )
			head = deletenode( head, &nodecount );
		else break;

		if( head == NULL )
		{
			root->nextnode = NULL;
			head = root;
			tail = root;
		}
	}
	// show remain node
	print_list( head );
	// reverse show remain node
	reverseprint_list( head );
	// list delete
	while( root )
	{
		node* deletenode = root->nextnode;
		if( deletenode )
		{
			root->nextnode = deletenode->nextnode;
			delete[] deletenode;
			deletenode = NULL;
		}
		else
		{
			delete[] root;
			root = NULL;
		}
	}

	return 0;
}

node* insertnode(node* tail, int number, int* nodecount)
{
	(*nodecount)++;
	printf( "wait number %d\n", *nodecount );

	node* insertnode = new node;
	insertnode->key = number;
	insertnode->nextnode = NULL;
	if( tail ) tail->nextnode = insertnode;
	return insertnode;
}

node* deletenode(node* head, int* nodecount)
{
	node* nextnode = NULL;
	if( *nodecount <= 0 )
	{
		printf( "empty node!\n" );
	}
	else
	{
		if( head )
		{
			node* deletenode = head->nextnode;
			if( deletenode == NULL ) deletenode = head;

			if( deletenode )
			{
				printf( "%d call number\n", deletenode->key );

				nextnode = deletenode->nextnode;
				head->nextnode = nextnode;

				delete[] deletenode;
				deletenode = NULL;
				(*nodecount)--;
			}
		}
	}
	return nextnode;
}

void print_list(node* head)
{
	if( head != NULL )
	{
		printf( "%d call number\n", head->key );
		print_list( head->nextnode );
	}
}

void reverseprint_list(node* head)
{
	if( head != NULL )
	{
		reverseprint_list( head->nextnode );
		printf( "%d call number\n", head->key );
	}
}