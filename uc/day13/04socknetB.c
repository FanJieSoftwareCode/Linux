//编程实现基于socket的网络通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
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
	addr.sin_addr.s_addr=inet_addr("176.43.1.29");
	//3.绑定socket和通信地址，使用bind函数
	int res=connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1==res){
		perror("bind"),exit(-1);
	}
	printf("绑定socket和通信地址成功\n");
	//4.进行通信，使用read/write函数
	res=write(sockfd,"hello",5);
	if(-1==res){
		perror("read"),exit(-1);
	}
	printf("成功发送数据到服务器，数据大小是：%d\n",res);
	//5.关闭socket，使用close函数
	res=close(sockfd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭socket\n");
	return 0;
}
