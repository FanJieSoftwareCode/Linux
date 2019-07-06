//基于tcp协议模型的一对多通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>

//定义全局变量，记录socket的描述符
int sockfd;

void fa(int signo){
	printf("正在关闭服务器，请稍后...\n");
	sleep(3);
	//关闭用于通信的socket，保留接待的socket
	int res=close(sockfd);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭服务器\n");
	exit(0);
}

int main(){
	//1.创建socket，使用socket函数
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sockfd){
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2.准备 通信地址，使用结构体类型
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
	//4.监听，使用listen函数
	res=listen(sockfd,100);
	if(-1==res){
		perror("listen"),exit(-1);
	}
	printf("监听成功\n");
	//设置对信号SIGINT的自定义处理
	printf("关闭服务器请按ctrl+c....\n");
	if(SIG_ERR==signal(SIGINT,fa)){
		perror("signal"),exit(-1);
	}
	//5.不断的响应客户端的连接请求，用 accept函数
	while(1){
	//准备变量作为下面参数的实参
		struct sockaddr_in recv_addr; 
		socklen_t  len=sizeof(recv_addr);
		int fd=accept(sockfd,(struct sockaddr*)&recv_addr,&len);
		if(-1==fd){
			perror("accept"),exit(-1);
		}
		char *ip=inet_ntoa(recv_addr.sin_addr);
		printf("客户端%s连接成功\n",ip);
		//采用多进程技术为多个客户端服务
		pid_t pid=fork();
		if(-1==pid){
			perror("fork"),exit(-1);
		}
		//子进程负责处理当前客户端
		if(0==pid){
			//设置对信号SIGINT进行默认处理
			if(SIG_ERR==signal(SIGINT,SIG_DFL)){
				perror("signal"),exit(-1);
			}
			//关闭用于接待的socket，保留通信的fd
			res=close(sockfd);
			if(-1==res){
				perror("close"),exit(-1);
			}
			//6.针对当前客户端可以不断的通信
			while(1){
				//接收客户端发来的消息
				char buf[100]={0};
				res=recv(fd,buf,sizeof(buf),0);
				if(-1==res){
					perror("recv"),exit(-1);
				}
				//判断客户端是否已经下线
				if(!strcmp(buf,"bye")){
					printf("客户端%s已下线\n",ip);
					break;
				}
				printf("客户端%s发来的数据内容 是：%s\n",ip,buf);
				//向客户端回发消息
				res=send(fd,"I receive!",12,0);
				if(-1==res){
					perror("send"),exit(-1);
				}
			}
			//执行break之后跳转到了这里
			//关闭用于通信的socket，也就是fd
			res=close(fd);
			if(-1==res){
				perror("close"),exit(-1);
			}
			//终止子进程
			exit(0);
		}
		}
	return 0;
}


