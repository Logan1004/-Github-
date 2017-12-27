//
// Created by Logan luo on 2017/11/4.
//

#ifndef UNTITLED55_BUBBLESORT_H
#define UNTITLED55_BUBBLESORT_H
#include <vector>
#include "time.h"
#include <iostream>
void bubbleSort(long size,std::vector<long>& num)
//冒泡排序
{
    using std::cout;
    using std::endl;
    int changeTimes=0;
    clock_t start = clock();
    //clock（）函数用来记时 start记录开始时间
    for (int i=0;i<size-1;i++)
        for (int j=i+1;j<size;j++)
        {
            long t=0;
            if (num[i]>num[j])
            //将元素交换 把元素交换到应在的位置
            {
                t=num[i];
                num[i]=num[j];
                num[j]=t;
                changeTimes++;
            }
        }
    clock_t ends = clock();
    //ends记录结束时间
    cout << "冒泡排序所用时间：" << (double) (ends - start)/CLOCKS_PER_SEC << endl;
    cout << "冒泡排序交换次数：" << changeTimes << endl;
}
#endif //UNTITLED55_BUBBLESORT_H
