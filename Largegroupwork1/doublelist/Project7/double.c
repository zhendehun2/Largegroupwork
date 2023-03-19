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
//表头插入结点
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
//向右打印
void printflistbyright(struct list* list)
{
	if (list->size == 0)
	{
		printf("链表中无数据\n");
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
//任意位置插入,插入到任意数据左侧
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
//删除结点
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
			printf("未存在该数据，无法删除\n");
		}
	}
	list->size--;
}
//清除链表
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
//销毁链表
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
//寻找结点
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
	printf("********1.插入结点      2.寻找结点*********\n");
	printf("********3.删除结点      4.清空链表*********\n");
	printf("********5.销毁链表      6.遍历链表*********\n");
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
		printf("现存有%d个数据\n", list->size);
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("表头插入选1 表中插入选2\n");
			int a = 0;
			scanf("%d", &a);
			printf("输入你想要插入的数据\n");
			int data = 0;
			scanf("%d", &data);
			if(a==1)
			{
				insertnodebyhead(list, data);
			}
			else if(a==2)
			{
				printf("请选择你要插入于哪个数据前面\n");
				int posdata = 0;
				scanf("%d", &posdata);
				insertNodeByAppoin(list, data, posdata);
			}
			else
			{
				printf("选择错误");
			}
			break;
		case 2:
			printf("请输入你想要查询的第几个结点的数据\n");
			scanf("%d", &x);
			int c = 0;
			c=searchnode(list, x-1);
			printf("%d\n", c);
			break;
		case 3:
			printf("请选择你要删除的数据\n");
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
			printf("退出程序\n");
			break;
		default:
			printf("请重新选择\n");

		}
	} while (input);
	return 0;

}