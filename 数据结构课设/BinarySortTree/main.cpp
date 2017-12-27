#include <iostream>
#include "binarySortTree.h"
#include "init.h"
int main() {
    using std::cin;
    BinarySortTree Tree;
    init();
    //初始化函数 输出开始界面
    int choice;
    cin >> choice;
    while (true) {
        switch (choice) {
            case 1:
            //建立二叉搜索树
                binarySortTreeInit(Tree);
                cin >> choice;
                break;
            case 2:
            //在建立的二叉搜索树上插入元素
                binarySortTreeInsertInit(Tree);
                cin >> choice;
                break;
            case 3:
            //查询二叉搜索树中的元素
                binarySortTreeSearchInit(Tree);
                cin >> choice;
                break;
            default:
            //其余情况 直接退出程序
                return 0;
        }
    }
}

//12 34 67 48 19 44 21 30 7 4 24 9 88 100 19 100 0