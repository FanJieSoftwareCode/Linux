//使用信号量集实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main(){
	//1.获取key值，使用ftok函数
	key_t key=ftok(".",200);
	if(-1==key){
		perror("ftok"),exit(-1);
	}
	printf("key=%#x\n",key);
	//2.获取信号量集，使用semget函数
	int semid=semget(key,0,0);
	if(-1==semid){
		perror("semget"),exit(-1);
	}
	printf("semid=%d\n",semid);
	//3.创建10个子进程，模拟抢占共享资源的过程
	int i=0;
	for(i=0;i<10;i++){
		pid_t pid=fork();
		if(-1==pid){
			perror("fork"),exit(-1);
		}
		if(0==pid){
			//模拟申请到共享资源的过程
			struct sembuf buf;
			buf.sem_num=0;  //信号量集的下标
			buf.sem_op=-1;  //信号量减一
			buf.sem_flg=0; //操作的标志，默认为0
			//4.操作信号量集，使用semop函数
			int res=semop(semid,&buf,1/*结构体变量的个数*/);
			if(-1==res){
				perror("semop"),exit(-1);
			}
			printf("申请共享资源成功\n");
			sleep(10);  //模拟占用共享资源
			//模拟释放共享资源
			buf.sem_op=1;
			res=semop(semid,&buf,1/*结构体变量的个数*/);
			if(-1==res){
				perror("semop"),exit(-1);
			}
			printf("释放共享资源成功\n");
			exit(0);
		}
	}
	return 0;
}
