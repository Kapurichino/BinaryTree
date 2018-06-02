/*
파일명 : BinaryTree.c
프로그램 설명 : BinaryTree를 만들어서 부모와 자식 사이의 관계를 확인하는 프로그램.
입력 : x-F-b or a-M-j를 입력하여 parent와 child 관계를 만듦. w-?-k를 입력하여 w와 k사이에 있는 모든 관계를 확인.
출력 : 매 입력마다 preorder를 통해 순서를 나타냄. 다만, w-?-k의 경우 w에서 k까지의 모든 관계를 출력.
완료날짜 : 2018 | 05 | 31 | 18:14PM
작성자 : 방성원 (Student ID : 20173239)
--History--
# 20180531 18:15PM
대략적인 구조를 만듦.
MALLOC을 매크로 선언.
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
			if (find->father && familly[(count)].left != 1) // 갔던 곳이 아니고, father 노드가 있을 경우
			{
				push(find);
				familly[count].name = find->name;
				familly[count].parent = 'F';
				familly[count].left = 1;
				familly[count++].right = 0;
				find = find->father;
			}
			else if (find->mother && familly[(count)].right != 1) // 갔던 곳이 아니고, mother 노드가 있을 경우
			{
				push(find);
				familly[count].name = find->name;
				familly[count].parent = 'M';
				familly[count].left = 0;
				familly[count].right = 1;
				find = find->mother;
			}
			else //부모 노드가 하나도 없음. 그런데 부모를 못 찾음.
			{
				find = pop(); // 다시 뒤로 돌아감.
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

	//알파벳 집어넣기
	setAlphabet();

	//구동 
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

	//메모리에서 해제.
}