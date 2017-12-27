//
// Created by Logan luo on 2017/11/4.
//

#ifndef UNTITLED55_RADIXSORT_H
#define UNTITLED55_RADIXSORT_H
#include <vector>
#include "time.h"
#include <iostream>
long maxBit(long size,std::vector<long>& num) {
    long len = 1; //保存最大的位数
    long stand = 10;
    for (long i = 0; i < size; ++i) {
        while (num[i] >= stand) {
            stand *= 10;
            ++len;
        }
    }
    return len;
}
void radixSort(long size,std::vector<long>& num) {
    using std::cout;
    using std::endl;
    long changeTimes = 0;
    clock_t start = clock();

    long Time = maxBit(size, num);
    long temp[size];
    long count[10]; // 计数器
    long radix = 1;
    for (long i = 1; i <= Time; i++) // 进行Time次排序
    {
        for (long j = 0; j < 10; j++) count[j] = 0; //每次分配前清空计数器
        for (long j = 0; j < size; j++) {
            long bit = (num[j] / radix) % 10;
            count[bit]++;
        }
        for (long j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将temp中的位置依次分配给每一个桶
        for (long j = size - 1; j >= 0; j--)  // 将所有桶中的记录依次收集到temp中
        {
            long bit = (num[j] / radix) % 10;
            temp[count[bit] - 1] = num[j];
            count[bit]--;
        }
        for (long j = 0; j < size; j++) num[j] = temp[j]; //将临时数组的内容复制到num中
        radix *= 10;
    }


    clock_t ends = clock();
    cout << "基数排序所用时间：" << (double)(ends - start)/CLOCKS_PER_SEC << endl;
    cout << "基数排序交换次数：" << changeTimes << endl;
}
#endif //UNTITLED55_RADIXSORT_H
