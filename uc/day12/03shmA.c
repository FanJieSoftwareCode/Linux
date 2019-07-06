//使用 共享内存实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<signal.h>
#include<string.h>
int shmid;
void fa(int signo){
	printf("正在删除共享内存,请稍后...\n");
	sleep(3);
	//调用删除共享内存的shmctl函数
	int res=shmctl(shmid,IPC_RMID,NULL);
	if(-1==res){
		perror("shmctl"),exit(-1);
	}
	printf("删除共享内存成功\n");
	exit(0);
}
int main(){
	//1.创建key，使用ftok函数 
	key_t key=ftok(".",100);
	if(-1==key){
		perror("ftok"),exit(-1);
	}
	printf("key=%#x\n",key);
	//2.创建共享内存，使用shmget函数
	shmid=shmget(key,40,IPC_CREAT|IPC_EXCL|0664);
	if(-1==shmid){
		perror("shmget"),exit(-1);
	}
	printf("shmid=%d\n",shmid);
	//3.挂接共享内存，使用shmat函数
	void *pv=shmat(shmid,NULL,0);
	if(pv==(void*)-1){
		perror("shmat"),exit(-1);
	}
	printf("挂接共享内存成功\n");
	//4.访问共享内存，存放100
	//int *pi=pv;
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	memcpy(pv,arr,40);
	/*
	for(i=0;i<10;i++){
			*(pi+i)=i*10;
			sleep(1);
		}*/
//	char *pc=pv;
	//strcpy(pc,"hello");
	
	//5.脱接共享内存，使用shmdt函数
	int res=shmdt(pv);
	if(-1==res){
		perror("shmdt"),exit(-1);
	}
	printf("脱接共享内存成功\n");
	//6.如果不再使用 ，删除共享内存，shmctl函数
	printf("删除共享内存请按ctrl+c...\n");
	if(SIG_ERR==signal(SIGINT,fa)){
		perror("signal"),exit(-1);
	}
//	shmctl(shmid,IPC_RMID,NULL);
	while(1);
	return 0;
}
