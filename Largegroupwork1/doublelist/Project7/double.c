#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* createnode(int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
struct list
{
	int size;
	struct Node* firstnode;
	struct Node* lastnode;
};
struct list* createlist()
{
	struct list* list = (struct list*)malloc(sizeof(struct list));
	list->size = 0;
	list->firstnode	=list->lastnode  = NULL;

	return list;
}
//��ͷ������
void insertnodebyhead(struct list* list, int data)
{
	struct Node* newnode = createnode(data);
	if (list->firstnode == NULL)
	{
		list->lastnode = newnode;
	}
	else
	{
		list->firstnode->left = newnode;
		newnode->right = list->firstnode;
	}
	list->firstnode = newnode;
	list->size++;
}
//���Ҵ�ӡ
void printflistbyright(struct list* list)
{
	if (list->size == 0)
	{
		printf("������������\n");
	}
	else
	{
		struct Node* pmove = list->firstnode;
		while (pmove)
		{
			printf("%d", pmove->data);
			pmove = pmove->right;
		}
		printf("\n");
	}
}
//����λ�ò���,���뵽�����������
void insertNodeByAppoin(struct list* list, int data, int posData)
{
	if (list->size == 0)
	{
		printf("error");
		return;
	}
	else if (list->firstnode->data == posData)
	{
		insertnodebyhead(list, data);
		list->size++;
	}
	else
	{
		struct Node* posNode = list->firstnode->right;
		struct Node* posNodeLeft = list->firstnode;
		while (posNode != NULL && posNode->data != posData)
		{
			posNodeLeft = posNode;
			posNode = posNodeLeft->right;
		}
		if (posNode == NULL)
		{
			printf("error");
			return;
		}
		else
		{
			struct Node* newNode = createnode(data);
			posNodeLeft->right = newNode;
			newNode->left = posNodeLeft;
			newNode->right = posNode;
			posNode->left = newNode;
			list->size++;
		}
	}
}
//ɾ�����
void deletenode(struct list* list, int data)
{
	struct Node* pmove = list->firstnode;
	if (pmove->data == data)
	{
		list->firstnode = pmove->right;
	}
	else
	{
		while (pmove->right != NULL)
		{
			if (data == pmove->right->data)
			{
				pmove->right = pmove->right->right;
				pmove = list->firstnode;
				continue;
			}
			pmove = pmove->right;
		}
		if (pmove->right = NULL)
		{
			printf("δ���ڸ����ݣ��޷�ɾ��\n");
		}
	}
	list->size--;
}
//�������
void clearnodeall(struct list* list)
{
	struct Node* pmove = list->firstnode;
	while (list->firstnode->right != NULL)
	{
		pmove = list->firstnode;
		list->firstnode = pmove->right;
		free(pmove);
	}
	list->size = 0;
}
//��������
void destorynode(struct list* list)
{
	struct Node* pmove = list->firstnode;
	while (list->firstnode)
	{
		list->firstnode = list->firstnode->right;
		free(pmove);
		pmove = list->firstnode;
	}
}
//Ѱ�ҽ��
int searchnode(struct list* list, int x)
{
	struct Node* pmove = list->firstnode;
	for (int i = 1; i <= x; i++)
	{
		pmove = pmove->right;
	}
	return(pmove->data);
}




void menu()
{
	printf("*******************************************\n");
	printf("********1.������      2.Ѱ�ҽ��*********\n");
	printf("********3.ɾ�����      4.�������*********\n");
	printf("********5.��������      6.��������*********\n");
	printf("********0.EXIT                    *********\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
}
int main(void)
{
	struct list* list = createlist();
	int input = 0;
	do {
		int x = 0;
		printf("�ִ���%d������\n", list->size);
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ͷ����ѡ1 ���в���ѡ2\n");
			int a = 0;
			scanf("%d", &a);
			printf("��������Ҫ���������\n");
			int data = 0;
			scanf("%d", &data);
			if(a==1)
			{
				insertnodebyhead(list, data);
			}
			else if(a==2)
			{
				printf("��ѡ����Ҫ�������ĸ�����ǰ��\n");
				int posdata = 0;
				scanf("%d", &posdata);
				insertNodeByAppoin(list, data, posdata);
			}
			else
			{
				printf("ѡ�����");
			}
			break;
		case 2:
			printf("����������Ҫ��ѯ�ĵڼ�����������\n");
			scanf("%d", &x);
			int c = 0;
			c=searchnode(list, x-1);
			printf("%d\n", c);
			break;
		case 3:
			printf("��ѡ����Ҫɾ��������\n");
			int y = 0;
			scanf("%d", &y);
			deletenode(list, y);
			break;
		case 4:
			clearnodeall(list);
			break;
		case 5:
			destorynode(list);
			break;
		case 6:
			printflistbyright(list);
			break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("������ѡ��\n");

		}
	} while (input);
	return 0;

}