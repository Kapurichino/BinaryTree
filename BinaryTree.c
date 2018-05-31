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

typedef struct listNode* treePointer;

typedef struct listNode
{
	char name;
	treePointer father;
	treePointer mother;
};

treePointer node[26];

treePointer top;

char input[6];

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

void findTree(char* input)
{
	int start = (int)(input[0] - 'a');
	int end = (int)(input[4] - 'a');
	treePointer find = top;
	char* x;
	while (1)
	{
		x = (char*)malloc(sizeof(char));
		x += find->name;
		printf("%s", x);
	}
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
			findTree(input);
		}
		preorder(top);
		printf("\n");
	} while (input[0] != '\0');

	//�޸𸮿��� ����.
}
