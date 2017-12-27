//
// Created by Logan luo on 2017/11/4.
//

#ifndef UNTITLED55_SHELLINSERTIONSORT_H
#define UNTITLED55_SHELLINSERTIONSORT_H
#include <vector>
#include "time.h"
#include <iostream>
void shellInsertionSort(long size,std::vector<long>& num){
    using std::cout;
    using std::endl;
    long changeTimes=0;
    clock_t start = clock();
    for (int len=size / 2; len > 0; len /=2)
    // len为步长，每次减为原来的一半。
    {
        for (int i=0;i<len;i++)
         // 共i个组，对每一组都执行直接插入排序
        {
            for (int j=i+len;j<size;j+=len){
                if (num[j] < num[j - len])
                // 如果num[j] < num[j-len]，则寻找num[j]位置，并将后面数据的位置都后移。
                {
                    int temp = num[j];
                    int cur = j - len;
                    while (cur >= 0 && num[cur] > temp)
                    {
                        num[cur + len] = num[cur];
                        cur -= len;
                        changeTimes++;
                    }
                    num[cur + len] = temp;
                }
            }
        }
    }

    clock_t ends = clock();
    cout << "希尔插入排序所用时间：" << (double)(ends - start)/CLOCKS_PER_SEC  << endl;
    cout << "希尔插入排序交换次数：" << changeTimes << endl;
}
#endif //UNTITLED55_SHELLINSERTIONSORT_H
