#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
//创建表头
struct Node* createhead()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
//创建结点
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//填充链表
void insertNodebyhead(struct Node* headNode, int data)
{
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//打印结点
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
//插入结点
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
//删除结点
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
//销毁链表
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
//清空链表 
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
//寻找结点
int searchnode(struct Node* headnode, int x)
{
	struct Node* pmove = headnode;
	for (int i = 1; i <= x; i++)
	{
		pmove = pmove->next;
	}
	return(pmove->data);
}
//找到单链表的中点
int findmiddle(struct Node* headnode)
{
	struct Node* pmove1 = headnode;//快指针
	struct Node* pmove2 = headnode;//慢指针
	while (pmove1)
	{
		pmove1 = pmove1->next->next;
		pmove2 = pmove2->next;
	}
	return(pmove2->data);

}
//判断单链表是否成环
int isloop(struct Node* headnode)
{
	struct Node* pmove1 = headnode;//快指针
	struct Node* pmove2 = headnode;//慢指针
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
//单链表反转(非递归)
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
//奇偶调换
void chance(struct Node* headnode)
{
	
		

	
}
void menu()
{
	printf("*******************************************\n");
	printf("********1.填充链表      2.寻找结点*********\n");
	printf("********3.删除结点      4.插入结点*********\n");
	printf("********5.遍历链表      6.销毁链表*********\n");
	printf("********7.清除结点      8.中间数据*********\n");
	printf("********9.链表是否成环  10.单链表反转******\n");
	printf("********11.奇偶调换     0.EXOT*************\n");
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
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//头插法插入
			printf("插入5个数字\n");
			int a = 0;
			for (int i = 0; i < 5; i++)
			{
				scanf("%d", &a);
				insertNodebyhead(list, a);
			}
			break;
		case 2:
		    printf("输入你想要找的第几个结点\n");
			int b = 0;
			int c = 0;
			scanf("%d", &b);
			c = searchnode(list, b);
			printf("此结点数据为%d\n", c);
			break;
		case 3:
			printf("输入你想要删除的数据\n");
			int d = 0;
			scanf("%d", &d);
			listdeleteall(list, d);
			break;
		case 4:
			printf("输入添加的数据,和插入的位置\n");
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
			printf("中间数据为%d\n", findmiddle(list));
			break;
		case 9:
			b = isloop(list);
			if (b == 2)
			{
				printf("不成环\n");
			}
			if (b == 1)
			{
				printf("成环\n");
			}
			break;
		case 10:
			list = reverselist(list);
			break;
		case 11:
			chance(list);
			break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	
	return 0;
}