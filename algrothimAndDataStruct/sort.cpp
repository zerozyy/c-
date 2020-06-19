

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
 int *temp=new int[len];//辅助空间
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
	delete []temp;
 }
void mergeSort(int a[],int left,int right)
{
	if(left>=right) return;
     int mid=(left+right)/2;
     mergeSort(a,left,mid);
     mergeSort(a,mid+1,right);
     merge(a,left,mid,right);
 }

//6、堆排序
//构造大顶堆  根节点大于 左右子节点
void maxheap(int a[],int start,int end)
{
	int l=2*start+1;//该根节点的左节点
	for(;l<=end;start=l,l=2*l+1)
	//将最大值交换到根节点，同时根节点更新为被交换的值  防止被交换下去的节点不满足其子树的根节点最大  
	{
		if(l<end && a[l]<=a[l+1]) l++;//只跟最大的比较
		if(a[l]<=a[start]) break;
		else
		{
			swap(a[l],a[start]);//交换
		} 
	}
}
 void heapSort(int a[],int n)
{
  for(int i=n/2-1;i>=0;i--)
  {
	  maxheap(a,i,n-1);//构造大顶堆
  }
  for(int i=n-1;i>0;--i)
  {//从最后一个元素开始调整
	swap(a[i],a[0]);//a[0] 一直是当前最大值
	maxheap(a,0,i-1);//调整过的排除
  }

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
