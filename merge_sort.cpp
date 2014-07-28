#include<stdio.h>

void merge(int *a,int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    int b[max_size];
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }

    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=high)
    {
        b[k++]=a[j++];
    }
    k--;
    while(k>=0)
    {
        a[low+k]=b[k];
        k--;
    }


}
void merge_sort(int *a,int low,int high)
{
    if(low<high)
    {
        int mid= (low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

main()
{
    int n,i;
    scanf("%d",&n);
    int a[n+1];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
return 0;
}
