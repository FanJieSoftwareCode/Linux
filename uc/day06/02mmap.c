//建立虚拟地址到真实物理地址的映射
#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<unistd.h>

int main(){
	//1.建立虚拟地址到物理内存的映射
	void *pv=mmap(NULL,4,
			PROT_READ|PROT_WRITE, //可读可写
			MAP_PRIVATE|MAP_ANONYMOUS, //物理内存
			0,0);
	if(MAP_FAILED==pv){
		perror("mmap"),exit(-1);
	}
	printf("建立虚拟地址到真实物理内存的映射成功\n");
	//2.使用虚拟地址存放数据，并打印
	int *pi=pv;
	*pi=100;
	printf("虚拟内存地址的数据是：%d\n",*pi);
	//3.解除虚拟地址到物理内存的映射
	int res=munmap(pv,4);
	if(-1==res){
		perror("munmap"),exit(-1);
	}
	printf("解除映射成功\n");
	return 0;
}
