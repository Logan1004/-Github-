//
// Created by Logan luo on 2017/11/4.
//

#ifndef UNTITLED55_QUICKSORT_H
#define UNTITLED55_QUICKSORT_H
#include <vector>
#include "time.h"
#include <iostream>
void qSort(std::vector<long>& num,long low,long high,long &changeTimes)
//快速排序 low表示搜索范围下限 high、表示上限
{
    int numStart,numEnd,numTemp;
    if (low >= high) return;
    numStart = low;
    numEnd = high;
    numTemp = num[low];
    //numTemp为比较的标准
    while (numStart <= numEnd)
    //首指针尾指针没有重合 说明还未完成排序                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    {
        while (num[numStart] < numTemp) numStart++;
        //从头开始找到一个比标准小的
        while (num[numEnd] > numTemp) numEnd--;
        //从尾开始找到一个比标准大的
        if (numStart<=numEnd){
            int temp;
            temp = num[numEnd];
            num[numEnd] = num[numStart];
            num[numStart] = temp;
            numStart++; numEnd--;
            changeTimes++;
            //将找到的两个数相互交换
        }
    }
    if (low < numEnd) qSort(num , low , numEnd , changeTimes);
    //从low到numEnd开始递归
    if (numStart < high) qSort(num , numStart , high , changeTimes);
    //从numStart到high开始递归
}


void quickSort(long size,std::vector<long>& num){
    using std::cout;
    using std::endl;
    long changeTimes=0;
    clock_t start = clock();
    qSort(num,0,size-1,changeTimes);
    clock_t ends = clock();
    cout << "快速排序所用时间：" << (double)(ends - start)/CLOCKS_PER_SEC << endl;
    cout << "快速排序交换次数：" << changeTimes << endl;
}

#endif //UNTITLED55_QUICKSORT_H
