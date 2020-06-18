readme.md

排序算法：
冒泡排序：O（n2） 思路：最大（最小的元素向后移）

'''

void sort1(int* a,int n)
{
  for(int i=0;i<n-1;++i)
  {
    for(int j=0;j<n-1-i;++j)
    {
      if(a[j]>a[j+1]) swap(a[i],a[j]);
    }
  }
}

'''
