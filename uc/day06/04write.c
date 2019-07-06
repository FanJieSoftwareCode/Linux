//使用write函数写入数据到文件中
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	//1.清空/创建文件a.txt，使用open函数
//	int fd=open("a.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	//以追加的方式打开文件
	int fd=open("a.txt",O_RDWR|O_CREAT|O_APPEND,0664);
	//以只读的方式打开，写入数据失败
//	int fd=open("a.txt",O_RDONLY|O_CREAT|O_TRUNC,0664);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("清空/创建文件成功\n");
	//2.写入字符串hello到文件中，用write函数
	int res=write(fd,"hello",6);
	if(-1==res){
		perror("write"),exit(-1);
	}
	printf("成功写入数据到文件中，写入的数据大小是:%d\n",res);
	//3.关闭文件a.txt，使用close函数
 	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
