//建立/解除文件到虚拟内存的映射
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

typedef struct {
	int id;
	char name[20];
	double salary;
}Emp;

int main(){
	//1.清空/创建文件，使用creat函数
	int fd=open("emp.dat",O_RDWR|O_CREAT|O_TRUNC,0664);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("清空/创建文件成功\n");
	//2.调整文件的大小为3个员工信息的大小
	int res=ftruncate(fd,3*sizeof(Emp));
	if(-1==res){
		perror("ftruncate"),exit(-1);
	}
	printf("调整文件大小成功\n");
	//3.建立虚拟地址到文件的映射，用mmap函数
	void *pv=mmap(NULL,3*sizeof(Emp),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(MAP_FAILED==pv){
		perror("mmap"),exit(-1);
	}
	printf("建立映射成功\n");
	//4通过虚拟地址，存放三个员工信息
	Emp *pe=pv;
	pe[0].id=1001;
	strcpy(pe[0].name,"zhangfei");
	pe[0].salary=3000;

	pe[1].id=1002;
	strcpy(pe[1].name,"guanyu");
	pe[1].salary=3500;

	pe[2].id=1003;
	strcpy(pe[2].name,"liubei");
	pe[2].salary=4000;
	
	//5.解除虚拟地址到文件的映射，使用munmap函数
	res=munmap(pv,3*sizeof(Emp));
	if(-1==res){
		perror("munmap"),exit(-1);
	}
	//6.关闭文件emp.dat，使用close函数
	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
