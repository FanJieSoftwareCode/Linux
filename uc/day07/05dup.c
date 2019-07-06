//使用dup函数实现文件描述符的复制
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	//1.清空/打开一个文件，使用creat函数
	int fd=creat("a.txt",0664);
	if(-1==fd){
		perror("creat"),exit(-1);
	}
	printf("清空/打开一个文件成功\n");
	printf("fd=%d\n",fd);
	//2.复制文件描述符，使用dup函数
	int fd2=dup(fd);
	if(-1==fd2){
		perror("dup"),exit(-1);
	}
	printf("复制文件描述符成功，fd=%d,fd2=%d\n",fd,fd2);
	//使用两个文件描述符写入数据
	write(fd,"A",sizeof(char));
	write(fd2,"a",sizeof(char));
	//3.关闭文件，使用close函数
	int res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	res=close(fd2);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
