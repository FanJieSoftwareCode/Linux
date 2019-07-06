//终止进程函数的使用
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
void fa(){
	printf("所有需要善后处理的工作都可以交给我哦\n");
}
int main(){
	//注册一个自定义函数，使用atexit函数
	//注册并不会调用
	int res=atexit(fa);
	if(0!=res){
		perror("atexit"),exit(-1);
	}
	printf("main函数开始执行\n");
	//调用函数进行终止
//	_exit(0);		//立即终止
	exit(0);		//正常结束
	printf("main函数结束\n");
	return 0;
}
