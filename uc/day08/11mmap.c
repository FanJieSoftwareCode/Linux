//通过映射的机制将文件中的三个员工的信息打印出来
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

typedef struct{
	int id;
	char name[20];
	double salary;
}Emp;

int main(){
	//1.打开文件emp.dat，使用open函数
	int fd=open("emp.dat",O_RDONLY);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	printf("文件打开成功\n");
	//建立虚拟地址到文件的映射，使用mmap函数
	void *pv=mmap(NULL,3*sizeof(Emp),PROT_READ,MAP_SHARED,fd,0);
	if(MAP_FAILED==pv){
		perror("mmap"),exit(-1);
	}
	printf("建立映射成功\n");
	//3.使用虚拟地址打印文件中的数据
	Emp *pe=pv;
	int i;
	for(i=0;i<3;i++){
		printf("员工id：%d,员工姓名：%s,员工工资：%lg\n",pe[i].id,pe[i].name,pe[i].salary);
	}
	//4.解除虚拟地址到文件的映射，使用munmap函数
	int res=munmap(pv,3*sizeof(Emp));
	if(-1==res){
		perror("munmap"),exit(-1);
	}
	printf("解除虚拟映射成功\n");
	//5.关闭文件emp.dat，使用close函数
	res=close(fd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
