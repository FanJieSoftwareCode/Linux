//使用sigprocmask函数设置信号的屏蔽
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void fa(int signo){
	printf("捕获到信号%d\n",signo);
}

int main(){
	//1.打印当前进程的进程号
	printf("当前进程的进程号是：%d\n",getpid());
	//2.设置对信号2，4，50进行自定义处理
	if(SIG_ERR==signal(2,fa)){
		perror("signal"),exit(-1);
	}
	printf("设置对信号2的自定义处理成功\n");
	if(SIG_ERR==signal(3,fa)){
		perror("signal"),exit(-1);
	}
	printf("设置对信号3的自定义处理成功\n");
	if(SIG_ERR==signal(50,fa)){
		perror("signal"),exit(-1);
	}
	printf("设置对信号50的自定义处理成功\n");
	//3.睡眠20秒，并判断是否被打断
	int res=sleep(20);
	if(0==res){
		printf("美美的睡了一觉\n");
	}else{
		printf("睡眠被打断,睡了%d秒\n",20-res);
	}
	
	printf("------------------------\n");
	printf("下面进行信号的屏蔽\n");
	//准备信号集类型的变量
	sigset_t set,oldset;
	if(-1==sigemptyset(&set)){
		perror("sigemptyset"),exit(-1);
	}
	if(-1==sigemptyset(&oldset)){
		perror("sigemptyset"),exit(-1);
	}
	printf("清空信号集成功\n");
	//设置屏蔽的信号集中有：2，3，50
	if(-1==sigaddset(&set,2)){
		perror("sigaddset"),exit(-1);
	}
	if(-1==sigaddset(&set,3)){
		perror("sigaddset"),exit(-1);
	}
	if(-1==sigaddset(&set,50)){
		perror("sigaddset"),exit(-1);
	}
	printf("准备屏蔽的信号集成功\n");
	res=sigprocmask(SIG_SETMASK,&set,&oldset);	
	if(-1==res){
		perror("sigprocmask"),exit(-1);
	}
	printf("设置信号的屏蔽成功,屏蔽的信号有：2，3，50，原来屏蔽的信号集是：%d\n",oldset);
	res=sleep(20);
	if(0==res){
		printf("信号屏蔽果然任性，美美的睡了一觉\n");
	}else{
		printf("估计是没有屏蔽的信号到达了，睡眠被打断\n");
	}
	//获取新来屏蔽期间来过但没有处理的信号
	sigset_t pend;
	sigemptyset(&pend);
	res=sigpending(&pend);
	if(-1==res){
		perror("sigpending"),exit(-1);
	}
	//判断信号2是否来过
	if(1==sigismember(&pend,2)){
		printf("信号2来过\n");
	}
	//判断信号3是否来过
	if(1==sigismember(&pend,3)){
		printf("信号3来过\n");
	}
	//判断信号50是否来过
	if(1==sigismember(&pend,50)){
		printf("信号50来过\n");
	}
	
	//恢复系统默认的信号屏蔽
	res=sigprocmask(SIG_SETMASK,&oldset,NULL);
	if(-1==res){
		perror("sigprocmask"),exit(-1);
	}
	printf("回复系统默认的信号屏蔽成功\n");
	return 0;
}
