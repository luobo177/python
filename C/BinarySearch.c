#include<stdlib.h>
#include<stdio.h>

int binarySearch(int *array,int left,int right,int target){
    if(left>right){
        return 0;
    }
    int mid=left+right;
    mid/=2;
    if(array[mid]==target){
        return 1;
    }else if(array[mid]<target){
        return binarySearch(array,mid+1,right,target);
    }else{
        return binarySearch(array,left,mid-1,target);
    }
    return 0;
}

int main(){
    int A[] = {3, 7, 12, 18, 25, 31, 42, 56, 68, 79};
    int a=binarySearch(A,0,9,55);
    printf("%d",a);
}