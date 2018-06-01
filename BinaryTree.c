/*
���ϸ� : BinaryTree.c
���α׷� ���� : BinaryTree�� ���� �θ�� �ڽ� ������ ���踦 Ȯ���ϴ� ���α׷�.
�Է� : x-F-b or a-M-j�� �Է��Ͽ� parent�� child ���踦 ����. w-?-k�� �Է��Ͽ� w�� k���̿� �ִ� ��� ���踦 Ȯ��.
��� : �� �Է¸��� preorder�� ���� ������ ��Ÿ��. �ٸ�, w-?-k�� ��� w���� k������ ��� ���踦 ���.
�Ϸᳯ¥ : 2018 | 05 | 31 | 18:14PM
�ۼ��� : �漺�� (Student ID : 20173239)

--History--

# 20180531 18:15PM

�뷫���� ������ ����.
MALLOC�� ��ũ�� ����.

# 

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MALLOC(x, y) (x = (treePointer)malloc(y))
#define MAX_STACK_SIZE 27

typedef struct listNode* treePointer;

typedef struct listNode
{
	char name;
	treePointer father;
	treePointer mother;
};

typedef struct
{
	char name;
}element;

element stack[MAX_STACK_SIZE];

treePointer node[27];

treePointer top;

char input[6];

char* relation;

int stackTop = 0;

void setAlphabet()
{
	for (int x = 0; x < 26; x++)
	{
		MALLOC(node[x], sizeof(*node[x]));
		node[x]->father = NULL;
		node[x]->mother = NULL;
		node[x]->name = (char)('a' + x);
	}
}

void insert(char* input)
{
	int parent = input[4] - 'a';
	int child = input[0] - 'a';
	
	if (top == NULL)
	{
		top = node[child];
	}

	if (top->name == input[4])
	{
		
		top = node[child];
	}

	if (input[2] == 'F')
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
	if (ptr)
	{
		printf("%c", ptr->name);
		preorder(ptr->father);
		preorder(ptr->mother);
	}
}

void findTree(char* input, treePointer ptr)
{
	if (ptr)
	{
		relation = (char*)malloc(sizeof(char));
		if (ptr->name == input[0])
		{
			relation += ptr->name;
			printf("%s", relation);
		}
		else
		{
			relation += ptr->name; 
		}
	}
	else
	{
		pop();
	}
};


void stackFull()
{
	printf("Stack is full, cannot add element");
	exit(EXIT_FAILURE);
};

element stackEmpty()
{
	element empty;
	printf("The stack is empty\n");
	return empty;
};

element pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[stackTop--];
};

void push(element item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++stackTop] = item;
};

int main(void)
{
	int jump = 0;

	//���ĺ� ����ֱ�
	setAlphabet();

	//���� 
	do
	{
		printf(">>");
		scanf(" %s", input);
		if (input[2] == 'F' || input[2] == 'M')
		{
			insert(input);
		}
		else if (input[2] == '?')
		{
			findTree(input, top);
		}
		preorder(top);
		printf("\n");
	} while (input[0] != '\0');

	//�޸𸮿��� ����.
}
