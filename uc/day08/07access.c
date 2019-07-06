//使用access函数判断文件是否存在以及权限信息
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	//1.判断文件是否存在
	if(0==access("a.txt",F_OK)){
		printf("文件存在\n");
	}
	//2.判断文件是否可读
	if(0==access("a.txt",R_OK)){
		printf("文件可读\n");
	}
	//3.判断文件是否可写
	if(0==access("a.txt",W_OK)){
		printf("文件可写\n");
	}
	//4.判断文件是否可执行
	if(0==access("b.out",X_OK)){
		printf("文件可执行\n");
	}
	return 0;
}
