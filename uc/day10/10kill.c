//使用kill函数发送信号
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void fa(int signo){
	printf("捕获到信号%d\n",signo);
}
int main(){
	//1.创建子进程，使用fork函数
	pid_t pid=fork();
	if(-1==pid){
		perror("fork"),exit(-1);
	}
	//2.子进程开始执行，设置对信号40自定义处理
	if(0==pid){
		if(SIG_ERR==signal(40,fa)){
			perror("signal"),exit(-1);
		}
		while(1);
	}
	//3.父进程判断子进程是否存在，发信号40
	sleep(1);
	int res=kill(pid,0);
	if(0==res){
		printf("父进程开始发送信号\n");
		if(-1==kill(pid,40)){
			perror("kill"),exit(-1);
		}
	}
	return 0;
}
