//各种id的获取
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	printf("pid=%d\n",getpid());
	printf("ppid=%d\n",getppid());
	printf("uid=%d\n",getuid());
	printf("gid=%d\n",getgid());
	return 0;
}
