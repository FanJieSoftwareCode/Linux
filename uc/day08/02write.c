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
	int res=write(fd,"hello",5);
	if(-1==res){
		perror("write"),exit(-1);
	}
	printf("写入数据成功,写入的数据大小是%d\n",res);
	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
