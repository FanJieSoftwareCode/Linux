//共享库的动态加载
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
int main(){
	//1.打开共享库文件libadd.so，用dlopen函数打开
	void *haddle=dlopen("./add_share/libadd.so",RTLD_NOW);
	//2.判断是否失败，若失败打印错误信息
	if(NULL==haddle){
		printf("%s\n",dlerror());
		return -1;//表示出错结束
	}
	//定义函数指针
	int (*p_add_int)(int,int);
	//3.查找共享库文件中名字为“add_int”函数的地址
	p_add_int=(int (*)(int,int))dlsym(haddle,"add_int");
	//4.判断查找是否成功，若失败，打印错误信息
	if(NULL==p_add_int){
		printf("%s\n",dlerror());
	}
	//5.调用add_int函数计算20和30的和，并打印
	int res=p_add_int(20,30);
	printf("结果是%d\n",res);
	//6.关闭共享库文件libadd.so，用dlclose函数
	res=dlclose(haddle);
	//7.判断关闭是否失败，若失败并打印错误信息
	if(0!=res){
		printf("%s\n",dlerror());	
	}
	return 0;
}
