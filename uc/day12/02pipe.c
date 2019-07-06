//使用pipe函数实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	//1.创建无名管道，使用pipe函数
	int pipefd[2]; 
	int res=pipe(pipefd);
	if(-1==res){
		perror("pipe"),exit(-1);
	}
	//2.创建子进程,使用fork函数
	pid_t pid=fork();
	if(-1==res){
		perror("fork"),exit(-1);
	}
	//3.子进程开始启动，写入数据1~100
	if(0==pid){
		//关闭读端
		close(pipefd[0]);
		int i=0;
		for(i=1;i<=100;i++){
			write(pipefd[1],&i,sizeof(int));
		}
		close(pipefd[1]);
		printf("终止子进程\n");
		exit(0);
	}
	//4.父进程开始启动，读取管道中的数据
	close(pipefd[1]);
	int i=0,num=0;
	for(i=0;i<100;i++){
		read(pipefd[0],&num,sizeof(int));
		printf("%d ",num);
	}
	printf("\n");
	close(pipefd[0]);

	return 0;
}
