readme.md

排序算法：

冒泡排序：O（n2） 思路：最大（最小的元素向后移）

 <img src="./sort_gif/bubbleSort.gif" width = "400" height = "%50" alt="冒泡排序" align=center />

```
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
 ```

选择排序：O（n2）思路：每次找最小值，从第一个位置开始放

 <img src="./sort_gif/selectSort.gif" width = "400" height = "%50" alt="选择排序" align=center />

 ```
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
 ```


插入排序：O（n2）思路：从前往后，向前插入

 <img src="./sort_gif/insertSort.gif" width = "400" height = "%50" alt="插入排序" align=center />

 ```
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
 ```


 快速排序：O(nlogn) 思路：找基准值，前部分比基准小，后部分比基准大，while循环将基准放在中间，返回基准值，对左右两边的无序数组进行类似排序

<img src="./sort_gif/quickSort.gif" width = "400" height = "%50" alt="快速排序" align=center />
 
 ```
int dived(int a[],int left,int right)//分割
 {
	 int i=left,j=right;
	 int x=a[left];////复制基准值
	 while(i<j)
	 {
		 while(a[j]>=x && i<j) j--;//右侧的值大于基准值
		 //右侧的值小于基准值，跳出循环了
		 //挖出该值，放在基准值的位置上  
		 a[i]=a[j];//左侧的值要小于基准值 向右寻找
		 while(a[i]<x && i<j) i++;
		 //该值大于基准值 放在之前被挖空出的位置上
		 a[j]=a[i];
	 }
	 //跳出循环的时候i==j 
	 //将该点设为基准点
	 a[i]=x;
	 return i;
 }
 void quickSort(int a[],int left,int right)
{
  if(left<right)
  {
	  int p=dived(a,left,right);//获取基准点
	  quickSort(a,left,p-1);
	  quickSort(a,p+1,right);//将基准点左右两边的值分别依赖基准点排序
  }
}
 ```

 归并排序：O（nlogn） 思路：先拆分，再按大小合并

 <img src="./sort_gif/mergeSort.gif" width = "400" height = "%50" alt="归并排序" align=center />

 ```
void merge(int a[],int left,int mid,int right)
{
 //将两个子段有序排在一起
 int i=left,j=mid+1;
 int len=right-left+1;
 int *temp=new int[len];//辅助空间  数组
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
 ```
 
