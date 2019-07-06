#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
	//创建socket
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(-1==sockfd){
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//准备通信地址，使用服务器地址
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(8888);
	addr.sin_addr.s_addr=inet_addr("176.43.11.27");
	//进行通信，使用send/recv函数
	int res=sendto(sockfd,"hello",6,0,(struct sockaddr*)&addr,sizeof(addr));
	if(-1==res){
		perror("send"),exit(-1);
	}
	printf("发送数据成功，发送的数据大小是：%d\n",res);
	//接受服务器回发的消息
	char buf[100]={0};
	res=recv(sockfd,buf,sizeof(buf),0);
	if(-1==res){
		perror("recv"),exit(-1);
	}
	printf("服务器发来的数据是：%s，数据大小是：%d\n",buf,res);
	//关闭sockfd，使用close函数
	res=close(sockfd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭sockfd\n");
	return  0;
}
