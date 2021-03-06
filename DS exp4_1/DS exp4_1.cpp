// DS exp4_1.cpp: 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_SIZE 100 //宏定义树中结点的最大数量

typedef struct PTNode {
	char data[50]; //树中结点的数据类型
	int parent; //结点的父结点在数组中的位置下标
}PTNode;

typedef struct {
	PTNode nodes[MAX_TREE_SIZE]; //存放树中所有结点
	int r, n; //根的位置下标和结点数
}PTree;

//初始化文件目录
void init(PTree *filesys)
{
	strcpy(filesys->nodes[filesys->r + 0].data, "U:");
	filesys->nodes[filesys->r + 0].parent = -1;
	strcpy(filesys->nodes[filesys->r + 1].data, "文档");
	filesys->nodes[filesys->r + 1].parent = 0;
	strcpy(filesys->nodes[filesys->r + 2].data, "文献");
	filesys->nodes[filesys->r + 2].parent = 0;
	strcpy(filesys->nodes[filesys->r + 3].data, "课件");
	filesys->nodes[filesys->r + 3].parent = 0;
	strcpy(filesys->nodes[filesys->r + 4].data, "1.lsx");
	filesys->nodes[filesys->r + 4].parent = 1;
	strcpy(filesys->nodes[filesys->r + 5].data, "2.txt");
	filesys->nodes[filesys->r + 5].parent = 1;
	strcpy(filesys->nodes[filesys->r + 6].data, "3.doc");
	filesys->nodes[filesys->r + 6].parent = 1;
	strcpy(filesys->nodes[filesys->r + 7].data, "f1.pdf");
	filesys->nodes[filesys->r + 7].parent = 2;
	strcpy(filesys->nodes[filesys->r + 8].data, "ch1.ppt");
	filesys->nodes[filesys->r + 8].parent = 3;
	strcpy(filesys->nodes[filesys->r + 9].data, "ch2.ppt");
	filesys->nodes[filesys->r + 9].parent = 3;
}

//元素elem进栈
int push(int * a, int top, int elem)
{
	top++;
	a[top] = elem;
	return top;
}

//数据元素出栈并输出结果
int pop(PTree *filesys, int * a, int top)
{
	if (top == -1) {
		printf("empty stack\n");
		return -1;
	}
	printf("%s\\", filesys->nodes[filesys->r + a[top]].data);
	top--;
	return top;
}

//遍历查找元素
void find(PTree *filesys)
{
	int num = -1;
	int top = -1;
	char input[50]; //存储输入的字符串
	int stack[10]; //定义大小为10的顺序栈
	scanf("%s", &input);
	for (int i = 0;i < 10;i++) {
		if (strcmp(input, filesys->nodes[filesys->r + i].data) == 0) {
			num = i;
		}
	}
	//若没有找到该元素，跳出函数
	if (num == -1) {
		printf("文件未找到\n");
	}
	//若找到该元素，将该元素和它的双亲结点的序号依次入栈
	else {
		while (filesys->nodes[filesys->r + num].parent >= -1) {
			top = push(stack, top, num);
			num = filesys->nodes[filesys->r + num].parent;
		}
	}
	//将栈中的元素依次弹栈并输出
	while (top >= 0) {
		top = pop(filesys, stack, top);
	}
}

int main()
{
	PTree filesys;
	filesys.r = 7; //根的位置下标
	filesys.n = 10;

	init(&filesys);
	find(&filesys);
	printf("\n");
	return 0;
}
