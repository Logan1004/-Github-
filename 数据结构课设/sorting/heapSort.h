//
// Created by Logan luo on 2017/11/4.
//

#ifndef UNTITLED55_HEAPSORT_H
#define UNTITLED55_HEAPSORT_H
#include <vector>
#include "time.h"
#include <iostream>
void swap(std::vector<long>& num,long i , long j , long &changeTimes)
//交换函数
{
    long temp=num[i-1];
    num[i-1]=num[j-1];
    num[j-1]=temp;
    changeTimes++;
}

void heapAdjust(std::vector<long>& num,long i,long size,long &changeTimes) {
    long leftChild = 2*i;
    long rightChild = 2*i+1;
    //在堆中 左孩子和右孩子 分别位于数组 2*i 和 2*i+1 的位置
    long maxPosition = i;
    if ( leftChild <= size && num[leftChild-1] > num[maxPosition-1] ) maxPosition =  leftChild;
    if (rightChild <= size && num[rightChild-1] > num[maxPosition-1]) maxPosition = rightChild;
    //如果左或者右孩子比根节点大 那么准备交换
    if (maxPosition != i) {
        swap(num, i, maxPosition, changeTimes);
        heapAdjust(num, maxPosition, size, changeTimes);
    }
}

void buildHeap(long size,std::vector<long>& num,long &changeTimes) {
    for (long i = size / 2; i >= 1; i--) heapAdjust(num, i, size, changeTimes);
//从下向上建立堆
}

void heapSort(long size,std::vector<long>& num) {
    using std::cout;
    using std::endl;
    long changeTimes = 0;
    clock_t start = clock();
    buildHeap(size, num,changeTimes);
    for (long i = size; i >= 2; i--) {
        swap(num, 1, size, changeTimes);
        size--;
        heapAdjust(num, 1, size, changeTimes);
    }
    clock_t ends = clock();
    cout << "堆排序所用时间：" << (double)(ends - start)/CLOCKS_PER_SEC << endl;
    cout << "堆排序交换次数：" << changeTimes << endl;
}
#endif //UNTITLED55_HEAPSORT_H
