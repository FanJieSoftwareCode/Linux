//观察父子进程对信号处理方式的不同
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

void fa(int signo){
	printf("捕捉信号%d\n",signo);
}

int main(){
	//1.设置对信号2进行自定义处理
	if(SIG_ERR==signal(2,fa)){
		perror("signal"),exit(-1);
	}
	printf("设置对信号2处理成功\n");
	//2.设置对信号3的忽略处理
	if(SIG_ERR==signal(3,SIG_IGN)){
		perror("signal"),exit(-1);
	}
	printf("设置对信号3的处理成功\n");
	//3.创建子进程，使用vfork函数
	pid_t pid=vfork();
	if(-1==pid){
		perror("vfork"),exit(-1);
	}
	//4.子进程启动，跳转执行process文件
	if(0==pid){
		printf("子进程%d开始执行\n",getpid());
		int res=execl("./process","process",NULL);
		if(-1==res){
			perror("execl"),exit(-1);
		}
		_exit(-1);
	}
	//5。父进程结束
	printf("父进程结束\n");
	return 0;
}
