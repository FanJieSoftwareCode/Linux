//使用sigaction函数设置信号的处理
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void fa(int signo,siginfo_t *info,void *pv){
	printf("进程%d发来了信号%d\n",info->si_pid,signo);
}
int main(){
	//1.打印当前进程号
	printf("pid=%d\n",getpid());
	//2.设置对信号2的处理方式为自定义处理
	//准备结构体，并进行初始化
	struct sigaction action={0};
	action.sa_sigaction=fa;
	//设置第二个函数指针作为信号处理函数
	action.sa_flags=SA_SIGINFO; 
	int res=sigaction(2,&action,NULL);
	if(-1==res){
		perror("sigaction"),exit(-1);
	}
	printf("设置信号2的自定义处理成功\n");
	while(1);
	return 0;
}
