//使用fcntl函数给文件中指定的内容加锁
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	//1.打开文件a.txt，使用open函数
	int fd=open("a.txt",O_RDWR);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.准备一把锁信息
	struct flock lock;
	lock.l_type=F_RDLCK; 	//锁的类型
	lock.l_whence=SEEK_SET;	//加锁的开始位置
	lock.l_start=0;			//解锁的偏移量
	lock.l_len=10;			//加锁的字节数长度
	lock.l_pid=-1;			//加锁的进程号
	//3.使用fcntl函数，对文件进行加锁
	int res=fcntl(fd,F_SETLK,&lock);
	if(-1==res){
		perror("fcntl"),exit(-1);
	}
	printf("加锁成功，开始占用文件 \n");
	//4.模拟占用文件20秒
	sleep(20);
	printf("使用文件完毕\n");
	//5.关闭文件a.txt，使用close函数
	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
	
}
