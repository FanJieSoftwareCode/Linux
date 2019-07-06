//使用system函数执行具体的shell命令
#include<stdio.h>
#include<stdlib.h>

int main(){
	int res=system("ls -l");
	if(-1==res){
		perror("system"),exit(-1);
	}
	return 0;
}
