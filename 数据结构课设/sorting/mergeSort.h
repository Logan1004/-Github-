//
// Created by Logan luo on 2017/11/4.
//

#ifndef UNTITLED55_MERGESORT_H
#define UNTITLED55_MERGESORT_H
#include <vector>
#include "time.h"
#include <iostream>
//left为第一个有序区间的起始地址
//center为第一个有序区间的结束地址，也是第二个有序区间的起始地址
//right为第二个有序区间的结束地址
void merge(std::vector<long>& num,long left,long center,long right,long len,long &changeTimes) {
    long *temp=new long[len];
    long start=left;
    long end=center+1;
    long cur=0;
    //start为第一个有序区的索引
    //end为第二个有序区的索引
    //cur为临时区域的索引
    while (start<=center && end <=right){
        changeTimes++;
        if (num[start]<=num[end]) temp[cur++]=num[start++];
        else temp[cur++]=num[end++];
    }
    if (start==center+1) 
        while (end<=right) {
            temp[cur++]=num[end++];
            changeTimes++;
        }
    else
        while (start<=center) {
            temp[cur++]=num[start++];
            changeTimes++;
        }
    for (long i=left,cur=0;i<=right;i++,cur++) num[i]=temp[cur];
    //将排序以后的值合并
    delete[] temp;
}

void mSort(std::vector<long>& num,long left,long right,long &changeTimes){
    if (left < right){
        long center=(left+right)/2;
        mSort(num,left,center,changeTimes);
        //递归 num[left 到 center]
        mSort(num,center+1,right,changeTimes);
        //递归 num[center+1 到 right]
        merge(num,left,center,right,right-left+1,changeTimes);
        //把上面两个有序空间 合并排序成一个有序空间
    }

}
void mergeSort(long size,std::vector<long>& num) {
    using std::cout;
    using std::endl;
    long changeTimes = 0;
    clock_t start = clock();
    mSort(num,0,size-1,changeTimes);
    clock_t ends = clock();
    cout << "归并排序所用时间：" << (double)(ends - start)/CLOCKS_PER_SEC  << endl;
    cout << "归并排序比较次数：" << changeTimes << endl;
}

#endif //UNTITLED55_MERGESORT_H
