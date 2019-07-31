#include "stdio.h"
#define MaxSize 50
typedef int ElemType;

typedef struct{
	ElemType data[MaxSize];
	int Length;
}SqList;

//插入操作
bool ListInsert(SqList &L,int i,ElemType e){
	if(i<1||i>L.Length-1)
		return false;
	if(L.Length>=MaxSize)
		return false;
	for(int j=L.Length;j>=i;j--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.Length++;
	return true;
}

//删除操作
bool ListDelete(SqList &L,int i){
	int e;
	if(i<1||i>L.Length)
		return false;
	e=L.data[i-1];
	for(int j=i;j<L.Length;j++)
		L.data[j-1]=L.data[j];
	L.Length--;
	return true;
}

//按值查找
int LocalElem(SqList &L,ElemType e){
	int i;
	for(i=0;i<L.Length;i++){
		if(L.data[i]==e)
			return i+1;
	}
	return 0;
}

//显示函数
void look(SqList L){
	//printf("线性表中的元素为:\n");
	for(int i=0;i<L.Length;i++){
		printf("%6d",L.data[i]);
	}
	printf("\n");
}

//创建函数
void CreatList(SqList &L){
	int a;
	printf("请输入要创建的顺序表大小:");
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		printf("请输入第%i个元素:",i);
		scanf("%d",&L.data[i-1]);
		L.Length++;
	}
	printf("顺序表创建成功\n");
}

//主函数
void main(){
	int x,a,b;
	SqList L;
	L.Length=0;
	CreatList(L);
	look(L);
	printf("请输入对应的编号->1:插入,2:删除,3:查找\n");
	while(true){
		printf("请输入指令:");
		scanf("%d",&x);
		if(x==1){
			printf("                       欢迎进入插入操作模块!\n");
			printf("请输入插入的位置:");
			scanf("%d",&a);
			printf("请输入插入的元素:");
			scanf("%d",&b);
			ListInsert(L,a,b);
			printf("插入后的顺序表:\n");
			look(L);
		}	
		if(x==2){
			printf("                       欢迎进入删除操作模块!\n");
			printf("请输入要删除的位置:");
			scanf("%d",&a);
			ListDelete(L,a);
			printf("删除后的顺序表:\n");
			look(L);
		}
		if(x==3){
			printf("                       欢迎进入查找模块!\n");
			while(true){
			printf("请输入要查找的值:");
			scanf("%d",&a);
			if(a==-1){
				printf("                        退出查找模块!\n");
				break;
			}
			b=LocalElem(L,a);
			if(b!=0){
				printf("查找成功!,元素位于%i号位置\n",b);
				printf("\n");
			}
			else{
				printf("查找失败!");
				printf("\n");
			}
			}
		}
	}

}

