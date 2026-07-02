#include<stdio.h>
#include<stdlib.h>
void findMinTen(int *a){//时间复杂度:遍历一遍主数组a，时间为n，当每次发现小于tenMin的时候，需要找一次最小值，花费平均为5，时间复杂度为O(5n),空间复杂度为O(10)
    int tenMin[10];
    int max,max_;
    max=a[0];
    max_=0;
    for(int i=0;i<10;i++){//先把a里的前十个填进去
        tenMin[i]=a[i];
        if(a[i]>max){//顺便找出tenMin里的最大值max，最大值的角标max_
            max = a[i];
            max_=i;
        }
    }
    for(int i=10;i<100000;i++){//遍历剩下的a数组，遇到比tenMin里最大值大的值就把，a[i]放进tenMin，然后重新寻找tenMin里的最大值和最大值角标
        if(a[i]<max){//如果a[i]小于max，就把tenMin里的max换做a[i]
            max=a[i];
            tenMin[max_]=a[i];
            for(int j=0;j<10;j++){//找到新的最大值
                if(tenMin[j]>max){
                    max=tenMin[j];
                    max_=j;
                }
            }//默认到此，max为tenMin里最大值，max_为最大值角标
        }
    }
    for(int i=0;i<10;i++){
        printf("%d\n",tenMin[i]);
    }
}

int main(){
    int arr[100000];
    for (int i = 0; i < 100000; i++) {
        arr[i] = rand()%100000;
    }
    findMinTen(arr);
}