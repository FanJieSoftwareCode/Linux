//使用dup2函数	实现文件描述符的复制
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	//1.清空/创建文件a.txt
	int fd=creat("a.txt",0664);
	if(-1==fd){
		perror("creat"),exit(-1);
	}
	printf("创建文件成功\n");
	//2.清空/创建文件b.txt
	int fd2=creat("b.txt",0664);
	if(-1==fd2){
		perror("creat"),exit(-1);
	}
	printf("创建文件成功\n");
	//3.打印两次creat得到的文件描述符
	printf("fd=%d,fd2=%d\n",fd,fd2);
	//4.复制文件描述符，使用dup2
	int fd3=dup2(fd,5);
	if(-1==fd3){
		perror("dup2"),exit(-1);
	}
	int f2=dup2(fd2,6);
	if(-1==f2){
		perror("dup2"),exit(-1);
	}
	printf("fd3=%d,f2=%d\n",fd3,f2);
	//分别向fd，fd2，fd3写入数据
	write(fd,"A",sizeof(char));
	write(fd2,"a",sizeof(char));
	write(fd3,"1",sizeof(char));
	//5.关闭两个文件描述符
	int res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	res=close(fd2);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭两个文件\n");
	return 0;
}
