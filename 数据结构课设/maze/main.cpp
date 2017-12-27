#include<cmath>
#include <iostream>
#include "Maze.h"
using namespace std;
int main()
{
    char Map[MAXN][MAXN];//用Map数组来储存迷宫
    int xStart,xEnd,yStart,yEnd;//(xStart,yStart)表示起始位置 (xEnd,yEnd)表示终点位置
    int m,n;//m代表迷宫宽度，n代表迷宫长度
    int i,j;
    cout << "请输入迷宫大小" << endl << "请输入行数m: ";
    cin >> m;
    cout << "请输入列数n: ";
    cin >> n;
    cout << "请输入迷宫: (0表示能通过，#表示不能通过）" << endl;
    //用0#的方式来代表迷宫的能走的位置及墙的位置
    while (true) {
        int flag=0;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++) {
                cin >> Map[i][j];
                if (Map[i][j] != '0' && Map[i][j] != '#') {
                    cout << "输入错误！请重新输入！" << endl;
                    flag=1;
                    cout << "请输入迷宫: (0表示能通过，#表示不能通过）" << endl;
                    break;
                }
            }
        if (flag==0) break;
    }
    cout << "请输入起始位置：\n(x,y)=";
    cin  >> xStart >> yStart ;
    cout << "请输入出口位置：\n(x,y)=";
    cin  >> xEnd >> yEnd ;
    BFS(m,n,xStart,yStart,xEnd,yEnd,Map);//调用广度优先搜索来寻找最佳迷宫路径
    return 0;
}
/*
 *
 0##0
 a0#0
 0000
 0000
 */