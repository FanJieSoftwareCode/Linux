#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/time.h>
#include<signal.h>

void fa(){
	printf("贪吃蛇移动了一步\n");
}
void fun(){
	//1.设置对信号SIGNAL进行自定义处理
	if(SIG_ERR==signal(SIGALRM,fa)){
		perror("signal"),exit(-1);
	}
	//2.准备结构体变量
	struct itimerval timer;
	//设置间隔时间
	timer.it_interval.tv_sec=0;
	timer.it_interval.tv_usec=30000;
	//设置启动时间
	timer.it_value.tv_sec=2;
	timer.it_value.tv_usec=0;
	//设置计时器参数信息
	int res=setitimer(ITIMER_REAL,&timer,NULL);
	if(-1==res){
		perror("setitimer"),exit(-1);
	}
//	printf("你踩踩\n");
	getchar();
	timer.it_interval.tv_sec=0;
	timer.it_interval.tv_usec=600000;
	res=setitimer(ITIMER_REAL,&timer,NULL);
	getchar();
	//关闭计时器
	timer.it_value.tv_sec=0;
	setitimer(ITIMER_REAL,&timer,NULL);
//	while(1);
//	return 0;
}

int main(){
	fun();
	printf("你踩踩\n");
	return 0;
}
