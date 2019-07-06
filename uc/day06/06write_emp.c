#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
typedef struct{
	int id;		//员工编号
	char name[20];	//员工姓名
	int salary;		//员工工资
}p;

int main(){
	int fd=open("emp.dat",O_RDWR|O_CREAT|O_TRUNC,0664);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("打开/创建文件成功\n");
	p p1={0};
	p1.id=1;
	strcpy(p1.name,"Alice");
	p1.salary=100;
	int res=write(fd,(void*)&p1,sizeof(p));
	if(-1==res){
		perror("write"),exit(-1);
	}
	printf("写入成功,写入%d\n",res);
	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("关闭文件\n");
	return 0;
}
