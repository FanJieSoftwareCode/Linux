#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

typedef struct{
	int id;
	char name[20];
	char num[20];
}tt;

int main(){
	int fd=open("a.dat",O_RDWR|O_CREAT,0664);
	if(-1==res){
		perror("open"),exit(-1);
	}

	return 0;
}
