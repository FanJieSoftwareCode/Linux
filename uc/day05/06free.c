//使用free函数释放动态内存的一般性原则
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	printf("当前进程的进程编号:%d\n",getpid());
	void *p1=malloc(4096);
	printf("申请了一个内存页的内存空间\n");
	getchar();
	void *p2=malloc(3*4096);
	printf("申请了三个内存页大小的内存空间,此时一共申请了四个内存页大小的内存空间\n");
	getchar();

	void *p3=malloc(30*4096);
	printf("申请了30个内存页大小的动态内存，此时总共申请了34个内存页大小的动态内存\n");
	getchar();

	free(p3);
	p3=NULL;
	printf("释放了30个内存页大小的动态内存\n");
	getchar();

	free(p2);
	p2=NULL;
	printf("释放了3个内存页大小的动态内存\n");
	getchar();

	free(p1);
	p1=NULL;
	printf("所有动态内存释放完毕\n");
	getchar();
	while(1);
	return 0;
}

