//c语言中的错误表现形式
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
//返回1~10之间的随机数，如果是5则返回错误
int rand_num(void){
	//1.设置随机数种子
	//2.生成1~10之间的随机数
	//3.判断是否出错，并返回
	int num=rand()%10+1;
	if(5==num){
		return -1;
	}
	return num;
	//return 5==num? -1:num;
}
//返回两个参数之间的最大值，如果相等则返回错误
int max_num(int ia,int ib,int *pi){
	if(ia==ib){
		return -1;	//表示错误
	}
	*pi = ia > ib ? ia : ib;
	return 0;
}
//判断传入的字符串是否是error，若是，返回错误，若不是返回ok
char *judge_string(char *pc){
	if(0==strcmp(pc,"error")){
		return NULL;	
	}
	return "ok";
}
//打印传入的字符串即可
void print_string(char *pc){
	printf("%s\n",pc);
}

int main(){
	srand(time(0));
	printf("生成的随机数是：%d\n",rand_num());
	int res=0;
	if(0==max_num(-1,-2,&res)){
		printf("最大值：%d\n",res);
	}else{
		printf("两个参数相等\n");
	}
	char *ps=judge_string("error");
	if(NULL==ps){
		printf("函数调用出错\n");
	}else{
		printf("返回的字符串是：%s\n",ps);
	}
	print_string("good good study,day day up!");
	return 0;
}







/*
int ra(){
	int num=rand()%10+1;
	if(num==5){
		return -1;
	}else{
		return num;
	}
}

int max(int num1,int num2,int *p){
	if(num1>num2){
		*p=num1;
		return 0;
	}else if(num1<num2){
		*p=num2;
		return 0;
	}else{
		return -1;
	}
}

char *er(char *s){
	if(0==strcmp(s,"error")){
		return NULL;
	}else{
		char *s1="ok";
		return s1;
	}
}
void p(char *s){
	printf("%s\n",s);
}


int main(){
	srand(time(0));
	char *s="error";
	if(NULL==er(s)){
		printf("成功\n");
	}else{
		printf("%s\n",er(s));
	}
	int num=0;
	printf("%d\n",max(1,12,&num));
	printf("%d\n",num);
	p(s);
	return 0;
}*/
