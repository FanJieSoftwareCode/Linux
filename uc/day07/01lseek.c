//使用lseek函数调整文件的读写位置
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	//1.打开文件a.txt，使用open函数
	//默认的读写位置就是开头
	int fd=open("a.txt",O_RDWR); 
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("文件打开成功\n");
	//2.调整文件的读写位置，使用lseek函数
	printf("---------------------------------\n");
	char cv;
	read(fd,&cv,sizeof(char));
	printf("cv=%c\n",cv);
	write(fd,"B",sizeof(char));	//覆盖‘b’
	read(fd,&cv,sizeof(char));
	printf("cv=%c\n",cv);
	printf("-----------------------\n");

	//使用lseek函数向后偏移5个字节
	lseek(fd,5,SEEK_SET);
	read(fd,&cv,sizeof(char));
	printf("cv=%c\n",cv);
	
/*	//使用lseek函数向前偏移3个字节
	//是错误的
	int len=lseek(fd,-3,SEEK_SET);
	if(-1==len){
		perror("lseek"),exit(-1);
	}
	read(fd,&cv,sizeof(char));
	printf("cv=%c\n",cv);    */
	printf("-------------------------------\n");
	//使用lseek函数从当前位置向后偏移5个字节
	lseek(fd,5,SEEK_CUR);
	read(fd,&cv,sizeof(char));
	printf("cv=%c\n",cv);
	
	//使用lseek函数从当前位置向前偏移4个字节
	lseek(fd,-4,SEEK_CUR);
	read(fd,&cv,sizeof(char));
	printf("cv=%c\n",cv);
	
	printf("-------------------------------\n");
	//使用lseek函数调整位置到文件的末尾位置
	int len=lseek(fd,0,SEEK_END);
	printf("len=%d\n",len);
	read(fd,&cv,sizeof(char));

	//使用lseek函数从末尾位置向前偏移1个字节
	//  '\n'  10
	lseek(fd,-1,SEEK_END);
	read(fd,&cv,sizeof(char));
	printf("cv=%c[%d]\n",cv,cv);

	//使用lseek函数向后偏移3个字节
	len=lseek(fd,3,SEEK_END);
	if(-1==len){
		perror("lseek"),exit(-1);
	}
	len=write(fd,"hello",5);
	if(-1==len){
		perror("write"),exit(-1);
	}
	printf("写入数据成功\n");
	lseek(fd,20,SEEK_SET);
	read(fd,&cv,sizeof(char));
	printf("cv=%c[%d]\n",cv,cv);
	//3.关闭文件a.txt，使用close函数
	int res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}

