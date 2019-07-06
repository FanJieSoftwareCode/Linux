//使用信号量集实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<signal.h>

int semid;
void fa(){
	printf("正在删除，请稍后...\n");
	sleep(3);
	int res=semctl(semid,0,IPC_RMID);
	if(-1==res){
		perror("semctl"),exit(-1);
	}
	printf("删除成功\n");
	exit(0);
}
int main(){
	//1.获取key值，使用ftok函数
	key_t key=ftok(".",200);
	if(-1==key){
		perror("ftok"),exit(-1);
	}
	printf("key=%#x\n",key);
	//2.创建信号量集，使用semget函数
	//int arr[1];
	//arr[0]=5;
	semid=semget(key,1,IPC_CREAT|0664);
	if(-1==semid){
		perror("semget"),exit(-1);
	}
	printf("semid=%d\n",semid);
	//3.初始化信号量集，使用semctl函数
	int res=semctl(semid,0,SETVAL,5);
	if(-1==res){
		perror("semctl"),exit(-1);
	}
	printf("初始化信号量成功\n");

	printf("删除信号量集请按ctrl+c...\n");
	if(SIG_ERR==signal(SIGINT,fa)){
		perror("signal"),exit(-1);
	}
	while(1);
	return 0;
}
