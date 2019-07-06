#include"circle.h"

int main(){
	int num=0;
	printf("输入一个半径：");
	scanf("%d",&num);
	printf("面积是：%lg\n",circlr_area(num));
	printf("周长是：%lg\n",circle_length(num));
	return 0;
}
