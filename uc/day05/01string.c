//存放字符串不同形式之间的比较
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	//pc指针指向只读常量区，pc本身在栈区
	char *pc="hello";
	//本质上就是将字符串”hello“复制到字符数组中
	//ps本身在栈区，ps指向栈区
	char ps[6]="hello";

	printf("pc=%p,&pc=%p\n",pc,&pc);
	printf("ps=%p,&ps=%p\n",ps,&ps);
	printf("------------------------------\n");
	//试图修改
//	strcpy(pc,"1234");	//error,引发段错误
	strcpy(ps,"1234");
	printf("pc=%s,ps=%s\n",pc,ps);

	printf("------------------------------\n");
	//试图修改指针的指向
	pc="world";		//ok
//	ps="world";		//error,常量，不可改变
	printf("pc=%s,ps=%s\n",pc,ps);
	
	printf("---------------------------------\n");
	pc=(char *)malloc(sizeof(char)*10);
	//试图修改指针指向的内容
	strcpy(pc,"GoodMorning");
	char *pt=pc;
	//试图修改指针的指向
	pc="GoodAfternoon";
	free(pt);
	pt=NULL;

	return 0;
}










