//使用sigaction函数设置信号的处理
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void fa(int signo){
	printf("正在处理信号，请稍后...\n");
	sleep(10);
	printf("处理信号完毕\n");
}

int main(){
	//1.打印当前的进程号：
	printf("pid=%d\n",getpid());
	//2.设置对信号2的自定义处理，屏蔽信号3
	struct sigaction action={0};
	action.sa_handler=fa;
	//清空信号集，屏蔽的信号是3
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask,3);
	//设置结构体的第四个成员
	//解除对信号2的屏蔽
//	action.sa_flags=SA_NODEFER;
	//信号处理函数之后，恢复默认处理方式
	action.sa_flags=SA_RESETHAND;

	int res=sigaction(2,&action,NULL);
	if(-1==res){
		perror("sigaction"),exit(-1);
	}
	printf("设置信号的处理方式成功\n");
	while(1);

	return 0;
}
