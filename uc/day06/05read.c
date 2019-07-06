//使用read函数读取文件中的内容 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	//1.打开文件a.txt，使用open函数
	int fd=open("a.txt",O_RDONLY);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.读取文件的内容并打印，使用read函数
	char buf[20]={0};
	int res=read(fd,buf,sizeof(buf));
	if(-1==res){
		perror("read"),exit(-1);
	}
	printf("%s\n",buf);
	printf("数字大小：%d\n",res);
	//3.关闭文件a.txt，使用close函数
	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("关闭文件\n");
	return 0;
}
