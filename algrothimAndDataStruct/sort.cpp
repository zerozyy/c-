

#include<iostream>
using namespace std;
//1、冒泡排序
void bubbleSort(int a[],int n)
{
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-1-i;++j)
		{
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
	}

}
//2、选择排序
void selectSort(int a[],int n)
{
	for(int i=0;i<n-1;++i)
	{
		int minn=i;
		for(int j=i+1;j<n;++j)
		{
			if(a[j]<a[minn]) minn=j;
		}
		if(minn!=i) swap(a[i],a[minn]);
	}
}
//3、插入排序
void insertSort(int a[],int n)
{
	for(int i=1;i<n;++i)
	{
		int it=a[i];
		int j=i-1;
		while(j>=0 && a[j]>it)
		{
			//元素后移
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=it;
	}
}
//4、快排
int parition(int a[],int low,int high)
{
	int pivot=a[low];
	
	while(low<high)
	{
		while(a[high]>=pivot && low<high) high--;
		a[low]=a[high];
		while(a[low]<=pivot && low<high) low++;
		a[high]=a[low];
	}
	a[low]=pivot;
	return low;
	
}
void quickSort(int a[],int low,int high)
{
	if(low<high)
	{
		int q=parition(a,low,high);	
		quickSort(a,low,q-1);
		quickSort(a,q+1,high);
	}
}
//5、归并排序
void merge(int a[],int left,int mid,int right)
{
 //将两个子段有序排在一起
 int i=left,j=mid+1;
 int len=right-left+1;
 int *temp=new int(len);//辅助空间
 int index=0;
     while(i<=mid && j<=right)
     {
          if(a[i]>a[j]) temp[index++]=a[j++];
          else temp[index++]=a[i++];
      }
     while(i<=mid) temp[index++]=a[i++];
     while(j<=right) temp[index++]=a[j++];
     for(int i=0;i<len;++i)
     {
      a[left++]=temp[i];
      }
 }
void mergeSort(int a[],int left,int right)
{
	if(left>=right) return;
     int mid=(left+right)/2;
     mergeSort(a,left,mid);
     mergeSort(a,mid+1,right);
     merge(a,left,mid,right);
 }
//测试主函数
int main()
{
	int a[]={6,5,4,1,2,8,3};
	int n=sizeof(a)/sizeof(int);
	mergeSort(a,0,n-1);
	for(int i=0;i<n;++i)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
