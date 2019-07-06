//使用有名管道实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	//1.打开文件
	int fd=open("a.pipe",O_RDONLY,0664);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	//读取文件，打印
	int num=0;
	int i=0;
	for(i=0;i<100;i++){
		read(fd,&num,sizeof(int));
		printf("%d ",num);
	}
	//3.关闭文件，使用close函数
	int res=close(fd);
	if(-1==res){
		perror("clsoe"),exit(-1);
	}
}
