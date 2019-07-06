//观察父子进程之间的内存资源关系
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int i1=1;  //数据区


int main(){
	int i2=1;    //局部变量   栈区
	//pc指向堆区，pc本身在栈区
	char *pc=(char*)malloc(sizeof(char)*10);
	strcpy(pc,"hello");

	//创建子进程，使用fork函数
	pid_t pid=fork();
	if(-1==pid){
		perror("fork"),exit(-1);
	}
	//子进程
	if(0==pid){
		i1=2;
		i2=2;
		strcpy(pc,"world");
		printf("子进程%d开始启动,i1=%d,i2=%d,pc=%s\n",getpid(),i1,i2,pc);
		//终止子进程
		exit(0);
	}
	//父进程
	sleep(1);
	printf("父进程%d开始启动,i1=%d,i2=%d,pc=%s\n",getpid(),i1,i2,pc);
	return 0;
}
