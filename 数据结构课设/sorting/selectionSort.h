//
// Created by Logan luo on 2017/11/4.
//

#ifndef UNTITLED55_SELECTIONSORT_H
#define UNTITLED55_SELECTIONSORT_H
#include <vector>
#include "time.h"
#include <iostream>
void selectionSort(long size,std::vector<long>& num){
    using std::cout;
    using std::endl;
    int changeTimes=0;
    clock_t start = clock();
    for (int i=0;i<size;i++)
    {
        long min=num[i],present=i;
        //min记录从第i后的最小的元素
        for (int j=i;j<size;j++)
        {
            if (min>num[j])
            {
                min=num[j];
                present=j;
                changeTimes++;
                
            }
        }
        long t;
        t=num[i]; num[i]=num[present]; num[present]=t;
        //找到最小的元素 和第i位交换 以此第i位已经确定
    }
    clock_t ends = clock();
    cout << "选择排序所用时间：" << (double)(ends - start)/CLOCKS_PER_SEC << endl;
    cout << "选择排序交换次数：" << changeTimes << endl;
}
#endif //UNTITLED55_SELECTIONSORT_H
