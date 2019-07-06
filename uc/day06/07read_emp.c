#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
typedef struct{
	int id;
	char name[10];
	int salary;
}p;
int main(){
	int fd=open("emp.dat",O_RDONLY);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	p p1={0};
	int res=read(fd,(void*)&p1,sizeof(p));
	if(-1==res){
		perror("read"),exit(-1);
	}
//	printf("%d\n",p1.id);
	printf("%d,%s,%d\n",p1.id,p1.name,p1.salary);
	printf("读出数据成功,一共有%d\n",res);
	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	return 0;
}
