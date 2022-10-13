#include <iostream>
typedef struct
{
	int *a;
	int length;
}SqList;
void InitSqList1(SqList &L);				 //功能：初始化顺序表
void InitSqList2(SqList& L);				 //功能：初始化顺序表
void Print(SqList L);						 //功能：输出顺序表元素 
void PrintArray(int a[], int n);			 //功能：输出数组元素 
void Arithmetic1(SqList &L);				 //算法：数组元素 奇数在前 偶数在后
void Arithmetic2(SqList &L);				 //算法：倒置数组
SqList Arithmetic3(SqList  &L1, SqList &L2); //算法：合并有序数组
int DeleteMinNumber(SqList L);               //算法：删除最小元素
int GetContinueLength(int a[], int n);       //算法：求平台最大长度
bool DeleteTheX(SqList& L, int x);           //算法：删除所有X值
bool DeleteTheXtoY(SqList& L, int x,int y);  //算法：删除所有(x--y)值
bool MoveLeft(int a[], int n, int p);        //算法：数组循环左移p位
int main()
{
	SqList L1 ;
	SqList L2 ;
	InitSqList1(L1);
	InitSqList2(L2);

	//算法：求“平台”最大长度
	//int a[12] = { 0,1,1,2,2,2,3,3,3,3,1,1 };
	//printf("最大平台长度为%d",GetContinueLength(a, 12));

    //算法：奇数在前偶数在后
    //Arithmetic1(L1);
    //Arithmetic1(L2);

	//算法：合并有序数组并返回
	//Print(Arithmetic3(L1, L2));
	
	//算法：删除最小元素
	//DeleteMinNumber(L1);
	//DeleteMinNumber(L2);

	//算法：删除所有X值
	//DeleteTheX(L1, 3);         
	//DeleteTheX(L2, 3);   
	   
	//算法：删除所有(x--y)值
	//DeleteTheXtoY(L1, 3, 5);  
	//DeleteTheXtoY(L2, 3, 5);

	//算法：数组循环左移p位
	int a1[8] = { 1,2,3,4,5,6,7,8};
	MoveLeft(a1, 8, 2);
	PrintArray(a1, 8);

    //Print(L1);
    //Print(L2);
	
   
   

	return 0;
}

void InitSqList1(SqList& L)			 //功能：初始化顺序表
{
	L.a = new  int[8];
	L.length = 8;
	
	for (int i = 0; i < L.length; i++)
	{
		
		L.a[i] = i+1;
	}

}
void InitSqList2(SqList& L)			 //功能：初始化顺序表
{
	L.a = new  int[7];
	L.length = 7;

	for (int i = 0; i < L.length; i++)
	{
		
			L.a[i] = i+2;
	}

}
void Print(SqList L) //功能：输出数组元素
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.a[i]);
	}
	printf("\n");
}
void PrintArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}


}
void Arithmetic1(SqList &L)//功能：将数组元素 奇数在前 偶数在后
{
	/*
	 第一次写：
	   错误1: 奇偶交换时，没有加条件判断（i<j）
	*/
	int i = 0, j = L.length - 1;
	int temp;
	while (i < j)
	{
		while (L.a[i] % 2 == 1)
		{
			i++;
		}
		while (L.a[j] % 2 == 0)
		{
			j--;
		} 
		//此时需要进行奇偶交换
		if (i < j)// *必需* 条件判断
		{
			temp = L.a[i];
			L.a[i] = L.a[j];
			L.a[j] = temp;
		}
		
	}
		
}
void Arithmetic2(SqList &L)//算法：倒置数组
{
	/*
	 第一次写时：
       错误1：交换元素忘记用中间变量temp;
	*/
	int i,temp;
	for (i = 0; i < L.length / 2; i++)
	{
		temp=L.a[L.length-i-1]; //元素互换
		L.a[L.length - i - 1] = L.a[i];
		L.a[i] = temp;
	}

}
SqList Arithmetic3(SqList &L1, SqList &L2)//算法：合并有序数组
{
	int i, j, x;
	SqList L3;
	L3.a = new int[30];
	L3.length = 0;
	i = 0, j = 0,x=0;
	while (i < L1.length && j < L2.length)
	{
		if (L1.a[i] <= L2.a[j])
		{
			L3.a[x++] = L1.a[i++];
			L3.length++;
		}
		else
		{
			L3.a[x++] = L2.a[j++];
			L3.length++;
		}
	}
	if (i == L1.length)
	{
		while (j<L2.length)
		{
			L3.a[x++] = L2.a[j++];
			L3.length++;
		}
	}
	else
	{
		while (i<L1.length)
		{
			L3.a[x++] = L1.a[i++];
			L3.length++;
		}
	}
	
	return L3;
}
int DeleteMinNumber(SqList L)               //算法：删除最小元素
{
	int i, min = L.a[0];
	int index=0 ;
	for ( i = 0; i < L.length; i++)
	{
		if (L.a[i] < min)
		{
			min = L.a[i];
			index = i;
		}
	}
	L.a[index] = L.a[L.length - 1];//删除的元素位置由最后一个元素代替
	return min;

}
int GetContinueLength(int a[], int n)       //算法：求平台最大长度
{
	int i,j, max = 0, table;
	for (i = 0; i < n; i++)
	{
		j = i + 1;
		table = 1;
		while (a[i] == a[j])
		{
			table++;
			j++;
		}
		if (table > max)
		{
			max = table;
		}
	}
	return max;
}
bool DeleteTheX(SqList& L, int x)           //算法：删除所有X值
{
	int i = 0, j, k = 0;
	for ( i = 0; i < L.length; i++)
	{
		if (L.a[i] != x)  //不等于x就重新存入L.a[k],从而让x全部排除在外
		{
			L.a[k] = L.a[i];
			k++;
		}
		
	}
	L.length =  k;
	return true;
}
bool DeleteTheXtoY(SqList& L, int x, int y)           //算法：删除所有(x--y)值
{
	int i, k=0;
	for ( i = 0; i < L.length; i++)
	{
		if (L.a[i]<x || L.a[i]>y)
		{
			L.a[k] = L.a[i];
			k++;
		}
	}
	L.length = k;
	return true;
}
bool MoveLeft(int a[], int n, int p)        //算法：数组循环左移p位
{
	//1 2 3 4 5     5  2
	//0 1 2 3 4
	int i;
	//定义数组b存储前p位数组值
	int *b = new int[p];
	for (i = 0; i < p; i++)
	{
		b[i] = a[i];
	}
	//前n-p位循环左移
	for ( i = 0; i < n-p; i++)
	{
		a[i] = a[i + p];
	}
	//后p位循环左移
	for ( i = n-p; i < n; i++)
	{
		a[i] = b[i - n + p];
	}
	return true;
	}
