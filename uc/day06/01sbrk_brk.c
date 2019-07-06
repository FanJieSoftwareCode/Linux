//使用sbrk函数和brk函数调整动态内存
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
	//1.申请int类型大小的存储空间，存放66
	int *pi=(int*)sbrk(sizeof(int));
	if((int*)-1==pi){
		perror("sbrk"),exit(-1);
	}
	*pi=66;
	//2.申请double类型的存储空间，存放3.14
	double *pd=(double*)sbrk(sizeof(double));
	if((double*)-1==pd){
		perror("sbrk"),exit(-1);
	}
	*pd=3.14;
	//3.申请10个字节的存储空间，存放hello
	char *pc=(char*)sbrk(sizeof(char)*10);
	if((char*)-1==pc){
		perror("sbrk"),exit(-1);
	}
	//试图修改pc的指向
	//pc="hello";
	//试图修改pc指针的指向的内容
	strcpy(pc,"hello");
	//4.打印以上数据
	printf("%d\n",*pi);
	printf("%lg\n",*pd);
	printf("%s\n",pc);
	//5.释放所有动态内存
	int res=brk((void*)pi);
	if(-1==res){
		perror("brk"),exit(-1);
	}
	return 0;
}
