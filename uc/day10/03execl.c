//使用excel函数执行指定的文件
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	//1.创建子进程，使用vfork函数
	pid_t pid=vfork();
	if(-1==pid){
		perror("vfork"),exit(-1);
	}
	//2.子进程开始执行，10秒后跳转执行ls文件
	if(0==pid){
		printf("子进程%d开始执行\n",getpid());
		printf("10秒后跳转出去执行\n");
		sleep(10);
	//	int res=execl("/bin/ls","ls","-l",NULL);
		int res=execl("./proc","proc",NULL);
		if(-1==res){
			perror("excel"),_exit(-1);
		}
	}
	//3.父进程开始执行
	printf("父进程%d开始执行\n",getpid());
	printf("父进程结束\n");
	return 0;
}
