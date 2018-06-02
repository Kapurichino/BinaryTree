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

typedef struct info
{
	int left;
	int right;
	char name;
	char parent;
}relation;

treePointer node[27];

treePointer path[27];

treePointer root;

char input[6];

int top = 0;

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

	if (root == NULL)
	{
		root = node[child];
	}

	if (root->name == input[4])
	{

		root = node[child];
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


void stackFull()
{
	printf("Stack is full, cannot add element");
	exit(EXIT_FAILURE);
};

treePointer stackEmpty()
{
	treePointer empty;
	printf("The stack is empty\n");
	return empty;
};

treePointer pop()
{
	if (top == -1)
		return stackEmpty();
	return path[top--];
};

void push(treePointer item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	path[++top] = item;
};

void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%c", ptr->name);
		preorder(ptr->father);
		preorder(ptr->mother);
	}
}

relation* stackReverse(relation* original)
{
	relation* reverse = (relation*)malloc(sizeof(relation) * 27);

	for (int x = 0; x < top; x++)
	{
		reverse[x] = original[(top - 1)- x];
	}
	return reverse;
}

relation* find(treePointer find, char* input)
{
	int count = 0;
	int discover = 0;

	relation* familly = (relation*)malloc(sizeof(relation) * 27);

	while (find)
	{
		if (!discover)
		{
			if (find->name == input[4]) 
			{
				push(find);
				familly[count++].name = find->name;
				break;
			}
			if (find->father && familly[(count)].left != 1) // ���� ���� �ƴϰ�, father ��尡 ���� ���
			{
				push(find);
				familly[count].name = find->name;
				familly[count].parent = 'F';
				familly[count].left = 1;
				familly[count++].right = 0;
				find = find->father;
			}
			else if (find->mother && familly[(count)].right != 1) // ���� ���� �ƴϰ�, mother ��尡 ���� ���
			{
				push(find);
				familly[count].name = find->name;
				familly[count].parent = 'M';
				familly[count].left = 0;
				familly[count].right = 1;
				find = find->mother;
			}
			else //�θ� ��尡 �ϳ��� ����. �׷��� �θ� �� ã��.
			{
				find = pop(); // �ٽ� �ڷ� ���ư�.
				--(count);
			}
		}
		/*
		else
			break;
		*/
	}
	return familly;
};

int main(void)
{
	relation* family;
	relation* result;
	treePointer get;
	int count = 0;

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
			preorder(root);
		}
		else if (input[2] == '?')
		{
			family = find(root, input);
			result = stackReverse(family);
			for (int x = 0; x < top; x++)
			{
				printf("%c - ", result[x].name);
				printf("%c - ", result[x].parent);
				pop();
			}
			count = 0;
		}
		printf("\n");
	} while (input[0] != '\0');

	//�޸𸮿��� ����.
}