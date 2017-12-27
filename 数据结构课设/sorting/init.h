//
// Created by Logan luo on 2017/11/4.
//

#ifndef UNTITLED55_INIT_H
#define UNTITLED55_INIT_H
#include <iostream>
#include <vector>
#include <time.h>
std::vector<long> ran(long size)
//随机函数 生成随机数 用于排序
{
    srand((unsigned)time(NULL));
    std::vector<long> ran;
    long number;
    for (int i=0;i<size;i++) {
        number = rand();
        ran.push_back(number);
        //将随机数插入ran的vector里
    }
    return ran;
}

void init()
//初始化界面函数
{
    using std::cout;
    using std::endl;
    cout << "*\t\t\t\t\t排序算法比较\t\t\t\t\t*" << endl;
    cout << "==================================================" << endl;
    cout << "**\t\t\t\t\t1 --- 冒泡排序\t\t\t\t**" << endl;
    cout << "**\t\t\t\t\t2 --- 选择排序\t\t\t\t**" << endl;
    cout << "**\t\t\t\t\t3 --- 直接插入排序\t\t\t**" << endl;
    cout << "**\t\t\t\t\t4 --- 希尔排序\t\t\t\t**" << endl;
    cout << "**\t\t\t\t\t5 --- 快速排序\t\t\t\t**" << endl;
    cout << "**\t\t\t\t\t6 --- 堆排序\t\t\t\t\t**" << endl;
    cout << "**\t\t\t\t\t7 --- 归并排序\t\t\t\t**" << endl;
    cout << "**\t\t\t\t\t8 --- 基数排序\t\t\t\t**" << endl;
    cout << "**\t\t\t\t\t9 --- 退出程序\t\t\t\t**" << endl;
    cout << "==================================================" << endl;
}
#endif //UNTITLED55_INIT_H
