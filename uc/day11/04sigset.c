//信号集的概念和使用
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(){
	sigset_t set;
	printf("sizeof(sigset_t)=%d\n",sizeof(sigset_t));
	//打印信号集类型中的低4个字节的数据
	printf("set=%d\n",set);      //随机数
	//清空信号集
	if(-1==sigemptyset(&set)){
		perror("sigemptyset"),exit(-1);;
	}
	printf("set=%d\n",set);
	//增加信号2，3，7到信号集当中
	printf("------------------------------\n");
	if(-1==sigaddset(&set,2)){
		perror("sigaddset"),exit(-1);
	}
	//.........0010  打印2
	printf("set=%d\n",set);
	if(-1==sigaddset(&set,3)){
		perror("sigaddset"),exit(-1);
	}
	//............0110  打印6
	printf("set=%d\n",set);
	if(-1==sigaddset(&set,7)){
		perror("sigaddset"),exit(-1);
	}
	//..........0100 0110  打印70
	printf("set=%d\n",set);
	if(-1==sigdelset(&set,3)){
		perror("sigdelset"),exit(-1);
	}
	printf("set=%d\n",set);
	printf("--------------------------------\n");
	if(-1==sigismember(&set,3)){
		perror("sigismember"),exit(-1);
	}else if(0==sigismember(&set,3)){
		printf("存在\n");
	}else{
		printf("不存在\n");
	}
	printf("-------------------------------\n");
	if(-1==sigfillset(&set)){
		perror("sigfillset"),exit(-1);
	}
	printf("set=%d\n",set);			//很大的数
	return 0;
}
