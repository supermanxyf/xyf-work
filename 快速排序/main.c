#include <stdio.h>
void paixu(int *arr,int start,int end)
{
    if(start>=end)
        return;
    int left=start;
    int right=end;
    int p=arr[left];
    while(left<right)
    {
        while(arr[right]>p&&left<right)
            right--;
        if(left<right)
        {
            arr[left]=arr[right];
            left++;
        }
        while(arr[left]<p&&left<right)
            left++;
        if(left<right)
        {
            arr[right]=arr[left];
            right--;
        }
    }
    arr[left]=p;
    paixu(arr,start,left-1);
    paixu(arr,right+1,end);
}
int main() {
    int arr[]={7,1,2,5,4,6,9,3};
    paixu(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf("%d ",arr[i]);
    return 0;
}
