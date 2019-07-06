//观察父子进程写入文件数据的关系
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int res;
	//1.清空/创建一个文件
	int fd=open("a.txt",O_RDWR|O_TRUNC|O_CREAT,0664);
	if(-1==fd){
		perror("creat"),exit(-1);
	}
	printf("清空/创建文件成功\n");
	//2.创建子进程，使用fork函数
	pid_t pid=fork();
	if(-1==pid){
		perror("fork"),exit(-1);
	}
	//3.子进程写入数据world
	if(0==pid){
		printf("子进程%d开始启动\n",getpid());
		res=write(fd,"world",5);
		if(-1==res){
			perror("write"),exit(-1);
		}
		//关闭文件描述符
		res=close(fd);
		if(-1==res){
			perror("close"),exit(-1);
		}
		printf("子进程结束成功\n");
		exit(0);
	}
		//4.父进程写入“hello”
	res=write(fd,"hello",5);
	if(-1==res){
		perror("write"),exit(-1);
	}
	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("父进程结束成功\n");
}
