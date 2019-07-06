#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

int main(){
	//1.创建scket，使用socket函数
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sockfd){
		perror("sockfd"),exit(-1);
	}
	printf("创建socket成功\n");
	//2.准备通信地址，使用你服务器地址
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(8888);
	addr.sin_addr.s_addr=inet_addr("176.43.11.27");
	//连接socket和通信地址，使用connect函数
	int res=connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1==res){
		perror("connect"),exit(-1);
	}
	printf("连接socket和通信地址成功\n");
	//不断的和服务器进行通信，send/recv函数
	while(1){
		char msg[100]={0};
		printf("请输入要发送的内容:\n");
		scanf("%s",msg);
		res=send(sockfd,msg,strlen(msg),0);
		if(-1==res){
			perror("send"),exit(-1);
		}
		if(!strcmp(msg,"bye")){
			break;
		}
		//接收服务器发来的数据
		char buf[100]={0};
		res=recv(sockfd,buf,sizeof(buf),0);
		if(-1==res){
			perror("recv"),exit(-1);
		}
		printf("服务器发来的数据内容是：%s\n",buf);
	}
	//关闭socket，使用close函数
	res=close(sockfd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭socket\n");
	return 0;
}
