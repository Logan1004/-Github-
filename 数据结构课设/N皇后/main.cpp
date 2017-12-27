#include <iostream>
#include "Queen.h"
using namespace std;
int main() {
    int chess[size][size];
    long n;
    cout << "现有NxN的棋盘，放入N个皇后，要求所有的皇后不在同一行，列和同一斜线上！" << endl;
    cout << endl;
    cout << "请输入皇后的个数:" << endl;
    cin >> n;
    cout << endl;
    cout << "皇后摆法：" << endl;
    cout << endl;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            chess[i][j]=0;
    //初始化整个棋盘
    dfs(0,n,chess);
    //运用深度优先搜索来模拟放子
    cout << "共有" << sum << "种解法！" << endl;
}