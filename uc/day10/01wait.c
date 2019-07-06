//使用waitpid函数等待指定的子进程结束
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	//1.创建两个子进程，一共三个子进程
	pid_t pid1=-1,pid2=-1;
	pid1=fork();
	if(-1==pid1){
		perror("fork"),exit(-1);
	}
	if(pid1>0){
		pid2=fork();
		if(-1==pid2){
			perror("fork"),exit(-1);
		}
	}
//	printf("是否有三个进程了呢？\n");
	//2.子进程一开始执行，20秒后结束
	if(0==pid1){
		printf("子进程一%d开始执行\n",getpid());
		sleep(20);
		printf("子进程一结束\n");
		exit(200);
	}	
	//3.子进程二开始执行，15秒后结束
	if(0==pid2){
		printf("子进程二%d开始执行\n",getpid());
		sleep(15);
		printf("子进程二结束\n");
		exit(100);
	}
	//4.父进程等待子进程终止，打印退出状态信息
	printf("父进程%d开始等待\n",getpid());
	//等待任意一个子进程
	int status=0;
//	int res=waitpid(-1,&status,0);
	//等待子进程2
//	int res=waitpid(pid2,&status,0);
	//等待子进程1
	int res=waitpid(pid1,&status,0);
	if(WIFEXITED(status)){
		printf("父进程等待结束，子进程%d结束，该进程的退出状态信息是：%d\n",res,WEXITSTATUS(status));
	}
	return 0;
}
