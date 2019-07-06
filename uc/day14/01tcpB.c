#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){
    //1.创建socket
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sockfd){
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2.准备通信地址
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(8888);
	addr.sin_addr.s_addr=inet_addr("176.43.11.23");
	int res=connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1==res){
		perror("connect"),exit(-1);
	}
	printf("连接socket和通信地址成功\n");
	//4.进行通信，使用send/recv
	res=send(sockfd,"hello",6,0);
	if(-1==res){
		perror("send"),exit(-1);
	}
	printf("成功发送数据到服务器,数据大小:%d\n",res);
	char buf[100]={0};
	res=recv(sockfd,buf,sizeof(buf),0);
	if(-1==res){
		perror("recv"),exit(-1);
	}
	printf("服务器发来的数据内容是：%s,数据大小：%d\n",buf,res);
	res=close(sockfd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功删除socket\n");
	return 0;
}
