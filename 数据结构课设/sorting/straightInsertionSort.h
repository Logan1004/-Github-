//
// Created by Logan luo on 2017/11/4.
//

#ifndef UNTITLED55_STRAIGHTINSERTIONSORT_H
#define UNTITLED55_STRAIGHTINSERTIONSORT_H
#include <vector>
#include "time.h"
#include <iostream>
void straightInsertionSort(long size,std::vector<long>& num){
    using std::cout;
    using std::endl;

    int changeTimes=0;
    clock_t start = clock();
    for (int i=0;i<size;i++)
    {
        int temp=num[i];
        int j=i-1;
        while (j>0 && (temp<num[j]))
        //找到要插入的位置
        {
            changeTimes++;
            num[j+1]=num[j];
            j--;
            //将插入位置后的所有元素都向后推一位 把相应位置空出来给要插入的元素
        }
        num[j+1]=temp;
        //将该元素插入
    }
    clock_t ends = clock();
    cout << "直接插入排序所用时间：" << (double)(ends - start)/CLOCKS_PER_SEC  << endl;
    cout << "直接插入排序交换次数：" << changeTimes << endl;
}
#endif //UNTITLED55_STRAIGHTINSERTIONSORT_H
