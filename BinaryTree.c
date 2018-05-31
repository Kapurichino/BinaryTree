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
}Node;

treePointer node[25];

treePointer top;

void setAlphabet()
{
	for (int x = 0; x < 25; x++)
	{
		MALLOC(node[x], sizeof(Node));
		node[x]->name = (char)('a' + x);
	}
}

void insert(char* input)
{
	int parent = 'a' - input[0];
	int child = 'a' - input[4];
	
	if (top == NULL)
	{
		top = node[child];
	}

	if (top->name == input[0])
	{
		top = node[child];
	}

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
	int start = (int)(input[0] - 'a');
	int end = (int)(input[4] - 'a');
	char* x = (char*)malloc(sizeof(char));
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

	//���ĺ� ����ֱ�
	setAlphabet();

	//���� 
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
		preorder(top);
	} while (input[0] = '\0');

	//�޸𸮿��� ����.
}
