//基于udp协议的 网络通信模型
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
	//1.创建socket，使用socket函数
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(-1==sockfd){
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2.准备通信地址，使用结构体类型
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(8888);
	addr.sin_addr.s_addr=inet_addr("176.43.11.27");
	//3.绑定socket和通信地址，使用bind函数
	int res=bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1==res){
		perror("bind"),exit(-1);
	}
	printf("绑定socket和通信地址成功\n");
	//4.进行通信，使用send/recv函数
	char buf[100]={0};
	//准备变量
	struct sockaddr_in recv_addr;
	socklen_t len=sizeof(recv_addr);
//	res=recv(sockfd,buf,sizeof(buf),0);
	res=recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&recv_addr,&len);
	if(-1==res){
		perror("recv_addr"),exit(-1);	
	}
	char *ip=inet_ntoa(recv_addr.sin_addr);
	printf("客户端%s发来的数据内容：%s，数据大小是：%d\n",ip,buf,res);
	//向客户端回发消息
	res=sendto(sockfd,"I receive!",12,0,(struct sockaddr*)&recv_addr,len);
	if(-1==res){
		perror("sendto"),exit(-1);
	}
	printf("成功发送数据到客户端，数据大小是：%d\n",res);
	//5.关闭socket，使用close函数
	res=close(sockfd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭socket\n");
	return 0;
}
