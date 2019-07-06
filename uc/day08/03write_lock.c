//测试文件在加写锁的情况下能否写入数据
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd=open("a.txt",O_WRONLY);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//准备一把锁的信息
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=5;
	lock.l_pid=-1;
	//尝试能否加锁成功，若不能则不再执行写操作
	int res=fcntl(fd,F_SETLK,&lock);
	if(-1==res){
		printf("文件已被加锁，无法执行写操作\n");
	}else{
		//若能则进行写操作
		res=write(fd,"hello",5);
		if(-1==res){
			perror("write"),exit(-1);
		}
	}
	printf("写入数据成功,写入的数据大小是%d\n",res);
	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
