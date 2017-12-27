#include <iostream>
#include "createTxt.h"
#include "Init.h"
#include "searching.h"
#include "counting.h"
#define MAXN 10000
using namespace std;

int main()
{
    long n;
    startingPage();
    //开始页面
    cin >> n;
    //n代表选择的功能序号
    while(1) {
        switch (n) {
            case 1:
            //新建立文件 并输入文本
                createFile();
                startingPage();
                cin >> n;
                break;
            case 2:
            //文本单词汇总
                counting();
                startingPage();
                cin >> n;
                break;
            case 3:
            //单词定位
                searching();
                startingPage();
                cin >> n;
                break;
            case 4:
            //退出
                cout << "谢谢使用!" << endl;
                return 0;
            default:
                cout << "输入错误！！请重新输入！！" << endl;
                startingPage();
                cin >> n;
                break;
        }
    }
}
/*
 * cs sau cjs xjs xaiox sxjs xism ixap xjskna sxjnz xsoi alxo xsj xoz csjx zjnxs zii zii xii xii zii zii xsuo zii xii ico cxj xii
 */