//使用vfork函数创建子进程
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	int num=100;		//局部变量
	//1.创建子进程，使用vfork函数
	pid_t pid=vfork();
	if(-1==pid){
		perror("vfork"),exit(-1);
	}
	//2.子进程开始执行，10秒后结束
	if(0==pid){
		printf("子进程%d开始执行\n",getpid());
		num=200;
		printf("子进程中：num=%d\n",num);
		sleep(10);
		printf("子进程结束\n");
		_exit(0);
	}
	//3.父进程开始执行
	printf("父进程%d开始执行\n",getpid());
	printf("父进程中：num=%d\n",num);
	printf("父进程结束\n");
	return 0;
}
