//使用sigqueue函数发送信号和附加数据
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void fa(int signo,siginfo_t *info,void *pv){
	printf("进程%d发来的信号是：%d,附加数据是%d\n",info->si_pid,signo,info->si_value);
}
int main(){
	//1.设置对信号进行40自定义处理
	struct sigaction action={0};
	action.sa_sigaction=fa;
	action.sa_flags=SA_SIGINFO;
	int res=sigaction(40,&action,NULL);
	if(-1==res){
		perror("sigaction"),exit(-1);;
	}
	//2.创建子进程，使用fork函数
	pid_t pid=fork();
	if(-1==pid){
		perror("fork"),exit(-1);
	}
	//3.子进程开始进行，发送1~100之间的数据
	if(0==pid){
		printf("子进程%d开始执行\n",getpid());
		int i=0;
		for(i=1;i<=100;i++){
			union sigval value;
			value.sival_int=i;
			sigqueue(getppid(),40,value);	
		}
		//终止子进程
		exit(0);
	}
	//4.父进程响应子进程发来的信号和数据
	while(1);
	return 0;
}
