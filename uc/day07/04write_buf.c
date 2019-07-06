//使用uc文件操作函数写入数据1~100万
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	//1.创建文件num2.dat
	int fd=creat("num2.dat",0664);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("成功打开/创建文件\n");
	//自定义缓冲区来提高效率
	int buf[10000];
	int pos=0;
	//2.写入数据
	int i;
	for(i=1;i<=1000000;i++){
		buf[pos++]=i;
		if(10000==pos){
			write(fd,buf,sizeof(buf));
			//清空缓冲区
			pos=0;
		}
	}
	printf("写入数据成功\n");
	//3.关闭文件num2.dat
	int res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
