//使用fcntl函数给文件加锁
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	//1.打开文件a.txt，使用open函数
	int fd=open("a.txt",O_RDWR);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("文件打开成功\n");
	//2.准备一把锁的信息
	struct flock lock;
	lock.l_type=F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=2;
	lock.l_len=8;
	lock.l_pid=-1;
	//3.使用fcntl函数进行加锁
	int res=fcntl(fd,F_SETLK,&lock);
	if(-1==res){
		perror("fcntl"),exit(-1);
	}
	printf("文件加锁成功\n");
	//4.关闭文件a.txt，使用close函数
	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
