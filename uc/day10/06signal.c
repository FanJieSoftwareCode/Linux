//使用signal函数设置信号的处理方式
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

void fa(int signo){
	printf("捕获到了信号%d\n",signo);
	//设置信号的处理方式为默认处理
	if(SIG_ERR==signal(signo,SIG_DFL)){
		perror("signal"),exit(-1);
	}
}
int main(){
	//1.打印当前进程的进程号
	printf("当前进程的进程号是：%d\n",getpid());
	//2.设置对信号SIGINT进行忽略处理
	if(SIG_ERR==signal(SIGINT,SIG_IGN)){
		perror("signal"),exit(-1);;
	}
	printf("设置对SIGINT的处理成功\n");
	//3.设置对信号3进行自定义处理
	if(SIG_ERR==signal(3,fa)){
		perror("signal"),exit(-1);
	}
	printf("设置对信号3的处理方式成功\n");
	//4.让当前进程进入无限循环
	while(1);
	return 0;
}

