//使用wait函数等待子进程结束
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	//1.创建子进程，使用fork函数
	pid_t pid=fork();
	if(-1==pid){
		perror("fork"),exit(-1);
	}
	//2.子进程开始执行，20秒后结束
	if(0==pid){
		printf("子进程%d开始执行\n",getpid());
		sleep(20);
		printf("子进程终止\n");
		exit(100);
	}
	//3.父进程等待子进程结束，获取退出状态信息
	printf("父进程%d开始等待\n",getpid());
	int status=0;
	pid_t res=wait(&status);
	if(-1==res){
		perror("wait"),exit(-1);
	}
	//判断子进程是否正常终止
	if(WIFEXITED(status)){
		printf("子进程%d正常终止,终止时的退出状态信息是：%d\n",res,WEXITSTATUS(status));
	}
	return 0;
}
