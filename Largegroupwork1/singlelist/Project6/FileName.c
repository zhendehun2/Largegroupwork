#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
//������ͷ
struct Node* createhead()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
//�������
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//�������
void insertNodebyhead(struct Node* headNode, int data)
{
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//��ӡ���
void printflist(struct Node* headNode)
{
	struct Node* pmove = headNode->next;
	while (pmove != NULL)
	{
		printf("%d", pmove->data);
		pmove = pmove->next;
	}
	printf("\n");
}
//������
void insertnode(struct Node* newnode, struct Node* headNode, int x)
{
	struct Node* pmove = headNode;
	for (int i = 1; i <= x-1; i++)
	{
		pmove = pmove->next;
	}
	newnode->next = pmove->next;
	pmove->next = newnode;
}
//ɾ�����
void listdeleteall(struct Node* headNode, int x)
{
	struct Node* p;
	p = headNode;
	while (p->next != NULL)
	{
		if (x == p->next->data)
		{
			p->next = p->next->next;
			p = headNode;
			continue;
		}
		p = p->next;
	}
}
//��������
void destorylist(struct Node* headNode)
{
	struct Node* p = headNode;
	while (p)
	{
		headNode = headNode->next;
		free(p);
		p = headNode;
	}
}
//������� 
void clearList(struct Node* headNode)
{
	struct Node* p = headNode;
	while (headNode->next)
	{
		p = headNode->next;
		headNode->next = p->next;
		free(p);
	}
}
//Ѱ�ҽ��
int searchnode(struct Node* headnode, int x)
{
	struct Node* pmove = headnode;
	for (int i = 1; i <= x; i++)
	{
		pmove = pmove->next;
	}
	return(pmove->data);
}
//�ҵ���������е�
int findmiddle(struct Node* headnode)
{
	struct Node* pmove1 = headnode;//��ָ��
	struct Node* pmove2 = headnode;//��ָ��
	while (pmove1)
	{
		pmove1 = pmove1->next->next;
		pmove2 = pmove2->next;
	}
	return(pmove2->data);

}
//�жϵ������Ƿ�ɻ�
int isloop(struct Node* headnode)
{
	struct Node* pmove1 = headnode;//��ָ��
	struct Node* pmove2 = headnode;//��ָ��
	while (pmove1 != NULL && pmove1->next != NULL)
	{
		pmove1 = pmove1->next->next;
		pmove2 = pmove2->next;
		if (pmove1 == pmove2)
		{
			return 1;
		}
	}
	return 2;
	
}
//������ת(�ǵݹ�)
struct Node*reverselist(struct Node* headnode)
{
	struct Node* newlist = createhead();
	while (headnode->next!=NULL)
	{
		insertNodebyhead(newlist, headnode->next->data);
		headnode = headnode->next;
	}
	return newlist;
}
//��ż����
void chance(struct Node* headnode)
{
	
		

	
}
void menu()
{
	printf("*******************************************\n");
	printf("********1.�������      2.Ѱ�ҽ��*********\n");
	printf("********3.ɾ�����      4.������*********\n");
	printf("********5.��������      6.��������*********\n");
	printf("********7.������      8.�м�����*********\n");
	printf("********9.�����Ƿ�ɻ�  10.������ת******\n");
	printf("********11.��ż����     0.EXOT*************\n");
	printf("*******************************************\n");
}
int main(void)
{
	int x = 0;
	int a = 0;
	int b = 0;
	struct Node* list = createhead();
	//for (int i = 0; i < 3; i++)
	//{
	//	scanf("%d", &a);
	//	insertNodebyhead(list, a);
		//insertnode(list,a);
	//}
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//ͷ�巨����
			printf("����5������\n");
			int a = 0;
			for (int i = 0; i < 5; i++)
			{
				scanf("%d", &a);
				insertNodebyhead(list, a);
			}
			break;
		case 2:
		    printf("��������Ҫ�ҵĵڼ������\n");
			int b = 0;
			int c = 0;
			scanf("%d", &b);
			c = searchnode(list, b);
			printf("�˽������Ϊ%d\n", c);
			break;
		case 3:
			printf("��������Ҫɾ��������\n");
			int d = 0;
			scanf("%d", &d);
			listdeleteall(list, d);
			break;
		case 4:
			printf("������ӵ�����,�Ͳ����λ��\n");
			struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
			newnode->next = NULL;
			int x = 0;
			scanf("%d %d", &newnode->data,&x);
			insertnode(newnode,list, x);
			break;
		case 5:
			printflist(list);
			break;
		case 6:
			destorylist(list);
			break;
		case 7:
			clearList(list);
			break;
		case 8:
			printf("�м�����Ϊ%d\n", findmiddle(list));
			break;
		case 9:
			b = isloop(list);
			if (b == 2)
			{
				printf("���ɻ�\n");
			}
			if (b == 1)
			{
				printf("�ɻ�\n");
			}
			break;
		case 10:
			list = reverselist(list);
			break;
		case 11:
			chance(list);
			break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	
	return 0;
}