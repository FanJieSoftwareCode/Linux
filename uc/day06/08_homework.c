#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int i=0;
	int fd=open("a.dat",O_WRONLY|O_CREAT);
	if(-1==fd){
		perror("open"),exit(-1);
	}
	for(i=1;i<=1000000;i++){
		int res=write(fd,&i,i);
		if(-1==res){
			perror("write"),exit(-1);
		}
	}
//	printf("%d\n",res);
	close(fd);
}
