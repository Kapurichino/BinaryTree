#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MALLOC(x, y) (x = (treePointer)malloc(y))

typedef struct listNode* treePointer;

typedef struct listNode
{
	char name;
	treePointer father;
	treePointer mother;
}Node;

treePointer node[25];

void setAlphabet()
{
	for (int x = 0; x < 25; x++)
	{
		MALLOC(node[x], sizeof(Node));
		node[x]->name = 'a' + x;
	}
}

void insert(char* input)
{
	int parent = (int)(input[0] - 'a');
	int child = (int)(input[4] - 'a');
	if (input[3] == "F")
	{
		node[child]->father = node[parent];
	}
	else
	{
		node[child]->mother = node[parent];
	}
};

/*
void delete()
{
	if (trail)
	{
		trail->link = x->link;
	}
	else
	{
		*first = (*first)->link;
	}
	free(x);
};
*/

void preorder(treePointer ptr)
{
	printf("%c", ptr->name);
	preorder(ptr->father);
	preorder(ptr->mother);
}

void findTree(char* input)
{
	while ()
	{
		printf("%3d", first->data);
		first = first->link;
	}
};



int main(void)
{
	int jump = 0;
	char input[6];

	//알파벳 집어넣기
	setAlphabet(node);

	//구동 
	do
	{
		printf(">>");
		scanf(" %s", input);
		if (input[3] == "F" || input[3] == "M")
		{
			insert(input);
		}
		else if (input[3] == "?")
		{
			findTree(input);
		}
		preorder();
	} while (input[0] = '\0');

	//메모리에서 해제.
}
