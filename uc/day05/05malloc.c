//使用malloc申请动态内存的一般性原则
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	printf("当前进程的进程号：%d\n",getpid());
	int *pi=(int *)malloc(sizeof(int));
	printf("pi=%p\n",pi);
	//十六进制的21000，本质上就是33个内存页
	//十六进制的1000，本质上就是一个内存页
	//故意越界一下试试，不超过33个内存页的范围,int类型是四个字节，所有相当于加上了30个内存页
	*(pi+1024*30)=250;
	printf("*(pi+1024*30)=%d\n",*(pi+1024*30));
	//故意越界，超过33个内存页的范围
	*(pi+1024*33)=250;
	printf("*(pi+1024*33)=%d\n",*(pi+1024*33));
	while(1);
	return 0;
}
