#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
	//1.获取key值，使用ftok函数
	key_t key=ftok(".",100);
	if(-1==key){
		perror("ftok"),exit(-1);
	}
	printf("key=%#x\n",key);
	//2.获取共享内存，使用shmget函数
	int shmid=shmget(key,0,0);
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
	//4.访问共享内存
	int *pi=pv;
	//char *pc=pv;
	int i;
	for(i=0;i<10;i++)
		printf("共享内存中的数据是：%d\n",*(pi+i));
	//5.脱接共享内存，使用shmdt函数
	int res=shmdt(pv);
	if(-1==res){
		perror("shmdt"),exit(-1);
	}
	printf("脱接共享内存成功\n");
	return 0;
}
