//使用常用的基本操作函数错做环境变量表
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main(){
	//使用getenv函数获取“SHELL”的变量值
	char *pc=getenv("SHELL");
	if(NULL==pc){
		printf("环境变量 不存在\n");
		return -1;
	}
	printf("SHELL=%s\n",pc);
	printf("------------------------------\n");
	//使用setenv修改SHELL的值为“abcd”，不修改
	int res=setenv("SHELL","abcd",0);
	if(-1==res){
		perror("setenv"),exit(-1);
	}
	printf("SHELL=%s\n",getenv("SHELL"));
	//用setenv修改SHELL的值为“abcd”，修改
	res=setenv("SHELL","abcd",1);
	if(-1==res){
		perror("setenv"),exit(-1);
	}
	printf("SHELL=%s\n",getenv("SHELL"));
	//使用setenv增加环境变量MARK到环境表
	res=setenv("MARK","marz",1);
	if(-1==res){
		perror("setenv"),exit(-1);
	}
	printf("MARK=%s\n",getenv("MARK"));
	printf("----------------------------\n");
	res=unsetenv("MARK");
	if(-1==res){
		perror("unsetenv"),exit(-1);
	}
	pc=getenv("MARK");
	if(NULL==pc){
		printf("该环境变量不存在\n");
	}
	printf("----------------------\n");
	//使用putenv增加环境变量到环境表中
	res=putenv("WUHUSHANGJIANG=zhangfei");
	if(res){
		perror("purenv"),exit(-1);
	}
	printf("%s\n",getenv("WUHUSHANGJIANG"));
	//使用putenv修改环境表中的环境变量
	res=putenv("SHELL=1234");
	if(res){
		perror("putenv"),exit(-1);
	}
	printf("%s\n",getenv("SHELL"));
	printf("---------------------------------\n");
	//使用clearenv函数清空环境表
	res=clearenv();
	if(res){
		perror("cleasrenv"),exit(-1);
	}
	pc=getenv("PATH");
	if(NULL==pc){
		printf("环境表确定被清空了\n");
	}
	extern char **environ;
	if(NULL==environ){
		printf("全局变量也被置为空指针了\n");
	}
	return 0;
}
