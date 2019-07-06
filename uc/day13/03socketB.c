#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<string.h>

int main(){
	//创建socket，使用socket函数
	int sockfd=socket(AF_UNIX,SOCK_DGRAM,0);
	if(-1==sockfd){
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//连接socket和通信地址，使用connect函数
	struct sockaddr_un addr;
    addr.sun_family=AF_UNIX;
	strcpy(addr.sun_path,"a.sock");	
	int res=connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1==res){
		perror("connect"),exit(-1);
	}
	//写入数据，使用write函数
	res=write(sockfd,"hello",5);
	if(-1==res){
		perror("write"),exit(-1);
	}
	printf("成功发送数据，数据大小是：%d\n",res);
	//关闭socket，使用close函数
	res=close(sockfd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭socket\n");
	return 0;
}
