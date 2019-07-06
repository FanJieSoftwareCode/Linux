#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

void fa(int signo){
	printf("捕捉信号%d\n",signo);
}
int main(){
	//1.对信号2进行自定义处理
	if(SIG_ERR==signal(2,fa)){
		perror("signal"),exit(-1);
	}
	//设置对信号3进行忽略处理
	if(SIG_ERR==signal(3,SIG_IGN)){
		perror("signal"),exit(-1);
	}
	//使用fork函数创建子进程
	pid_t pid=vfork();
	if(-1==pid){
		perror("vfork"),_exit(-1);
	}
	if(0==pid){
		printf("进程号：%d\n",getpid());
		while(1);
	}
	printf("父进程结束\n");
	return 0;
}
