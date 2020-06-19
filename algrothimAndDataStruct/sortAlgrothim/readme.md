readme.md

排序算法：

冒泡排序：O（n2） 思路：最大（最小的元素向后移）

1、比较相邻的元素。如果第一个比第二个大，就交换它们两个；

2、对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；

3、针对所有的元素重复以上的步骤，除了最后一个；

重复步骤1~3，直到排序完成。

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

选择排序：O（n2）

思路：

1、在未排序序列中找到最小（大）元素，存放到排序序列的起始位置

2、从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。

以此类推，直到所有元素均排序完毕。 

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


插入排序：O（n2）

思路：
从前往后，向前插入

1、从第一个元素开始，该元素可以认为已经被排序；

2、取出下一个元素，在已经排序的元素序列中从后向前扫描；

3、如果该元素（已排序）大于新元素，将该元素移到下一位置；

4、重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；

5、将新元素插入到该位置后；

重复步骤2~5。


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


 快速排序：O(nlogn) 
 
 思路：
 
 找基准值，前部分比基准小，后部分比基准大，while循环将基准放在中间，返回基准值，对左右两边的无序数组进行类似排序

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

归并排序：O（nlogn） 
 
思路：

1、把长度为n的输入序列分成两个长度为n/2的子序列；

2、对这两个子序列分别采用归并排序；

3、将两个排序好的子序列合并成一个最终的排序序列。

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
 
 堆排序：O（nlogn）

 堆是具有以下性质的完全二叉树：
 
 每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；
 
 每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆。

我们用简单的公式来描述一下堆的定义就是：

大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  

小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]  
 思路：

1、构造初始堆。将给定无序序列构造成一个大顶堆（一般升序采用大顶堆，降序采用小顶堆)。

2、将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端;

3、重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素，反复执行调整+交换步骤，直到整个序列有序。

```
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
```


参考来源：https://www.cnblogs.com/onepixel/articles/7674659.html