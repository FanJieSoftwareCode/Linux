//修改文件的大小以及权限信息
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	struct stat st;
	//1.获取文件的大小，使用stat函数
	int res=stat("a.txt",&st);
	if(-1==res){
		perror("stat"),exit(-1);
	}
	//2.打印文件的权限和大小信息
	printf("文件的权限是：%o,文件的大小：%ld\n",st.st_mode&0777,st.st_size);
	//3.修改文件的权限为0600
	res=chmod("a.txt",0664);
	if(-1==res){
		perror("chmod"),exit(-1);
	}
	//4.修改文件的大小为100
	res=truncate("a.txt",100);
	if(-1==res){
		perror("truncate"),exit(-1);
	}
	//5.再次获取文件a.txt的状态信息
	res=stat("a.txt",&st);
	if(-1==res){
		perror("stat"),exit(-1);
	}
	//6.打印修改后获取的权限和大小信息
	printf("文件的权限是：%o,文件的大小：%ld\n",st.st_mode&0777,st.st_size);
	return 0;
}
