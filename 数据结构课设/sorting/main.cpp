#include <iostream>
#include <vector>
#include "init.h"
#include "quickSort.h"
#include "selectionSort.h"
#include "bubbleSort.h"
#include "straightInsertionSort.h"
#include "shellInsertionSort.h"
#include "heapSort.h"
#include "mergeSort.h"
#include "radixSort.h"
using namespace std;

int main() {
    long size;
    init();
    cout << "请输入要产生的随机数个数n：";
    cin >> size;
    //输入生成的随机数个数
    vector<long> randomArray=ran(size);
    vector<long> num;
    long choice;
    cout << "请选择排序算法:";
    cin >> choice;
    //根据choice选择排序方式
    while (1) {
        switch (choice) {
            case 1:
            //冒泡排序
                num = randomArray;
                bubbleSort(size, num);
                //只传值 不传参 保证每一个排序都用的是相同的元素
                cout << "请选择排序算法:";
                cin >> choice;
                break;
            case 2:
            //选择排序
                num = randomArray;
                selectionSort(size, num);
                cout << "请选择排序算法:";
                cin >> choice;
                break;
            case 3:
            //插入排序
                num = randomArray;
                straightInsertionSort(size, num);
                cout << "请选择排序算法:";
                cin >> choice;
                break;
            case 4:
            //希尔排序
                num = randomArray;
                shellInsertionSort(size, num);
                cout << "请选择排序算法:";
                cin >> choice;
                break;
            case 5:
            //快速排序
                num = randomArray;
                quickSort(size, num);
                cout << "请选择排序算法:";
                cin >> choice;
                break;
            case 6:
            //堆排
                num = randomArray;
                heapSort(size, num);
                cout << "请选择排序算法:";
                cin >> choice;
                break;
            case 7:
            //归并排序
                num = randomArray;
                mergeSort(size, num);
                cout << "请选择排序算法:";
                cin >> choice;
                break;
            case 8:
            //基数排序
                num = randomArray;
                radixSort(size, num);
                cout << "请选择排序算法:";
                cin >> choice;
                break;
            case 9:
            //退出程序
                cout << "谢谢使用！" << endl;
                return 0;
            default:
                cout << "输入有误！请重新输入！" << endl;
                cout << "请选择排序算法:";
                cin >> choice;
                break;
        }
    }
}