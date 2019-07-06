#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	int r=0;
	pid_t pid=fork();
	if(-1==pid){
		perror("fork"),exit(-1);
	}
	if(0==pid){
		printf("输入半径：");
		scanf("%d",&r);
		printf("周长：%d\n",3.14*r*2);
		exit(10);
	}
	int status=0;
	int res=wait(&status);
	if(WIFEXITED(status)){
		printf("子进程正常结束\n");
	}
	return 0;
}
