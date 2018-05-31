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
		}
		else if (input[2] == '?')
		{
			findTree(input);
		}
		preorder(top);
		printf("\n");
	} while (input[0] != '\0');

	//메모리에서 해제.
}
