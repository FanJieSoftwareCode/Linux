//使用open函数打开文件，使用close关闭文件
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	//1.打开文件b.txt，使用open函数
	//若文件存在则打开，若不存在创建
//	int fd=open("./b.txt",O_RDWR|O_CREAT,0664);
	//若文件不存在则创建，若存在则清空文件内容
	int fd=open("./b.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
	//若文件不存在则创建，存在则创建失败
//	int fd=open("./b.txt",O_RDWR|O_CREAT|O_EXCL,0664);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("打开/创建文件成功\n");
	printf("O_RDWD=%d,O_CREAT=%d,O_TRUNC=%d,O_EXCL=%d",O_RDWR,O_CREAT,O_TRUNC,O_EXCL);
	//2.关闭文件，使用close函数
	int res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
