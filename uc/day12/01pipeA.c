//使用有名管道实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	//1.打开文件a.pipe，使用open函数
	int fd=open("a.pipe",O_WRONLY,0664);
	if(-1==fd){
		perror("open"),exit(-1);;
	}  
	//2.分别写入1~100之间的数据到文件
	int i=0;
	for(i=1;i<=100;i++){
		write(fd,&i,sizeof(int));
	}
	printf("写入数据成功\n");
	//3.关闭问及那a.pipe，使用close函数
	int res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	return 0;
}
