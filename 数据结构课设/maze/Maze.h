//
// Created by Logan luo on 2017/10/26.
//

#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H
#define MAXN 100 //用define的形式定义 便于修改
#include <iostream>
#include <queue>
struct node
{
    int x,y,step;
};//自定义node类型 分别用来存储走到该点所用的步数step以及该点的位置(x,y)

void Direction(int m,int n,int xStart,int yStart,int xEnd,int yEnd,node ans[][MAXN],char Map[][MAXN])
{
    node path[MAXN];
    //path数组 用来记录最后的路径
    int x=xEnd,y=yEnd;
    int k=1,xTemp,yTemp;
    //xTemp与yTemp分别
    Map[xStart][yStart]='*';
    Map[xEnd][yEnd]='*';
    std::cout << "迷宫：（路径用*表示）\n";
    while(x!=xStart || y!=yStart)//通过回溯的过程得到我走过的路径
    {
        xTemp=x;
        yTemp=y;
        path[k].x=ans[x][y].x;
        path[k].y=ans[x][y].y;
        //path记录路径
        x=ans[xTemp][yTemp].x;
        y=ans[xTemp][yTemp].y;
        //用ans数组回溯上一步经过的点
        k++;
    }
    for (int i=k-1;i>=1;i--) Map[path[i].x][path[i].y]='*';
    //用*表示最后走出迷宫的路径
    std::cout << "  ";
    for (int i=0;i<n;i++) std::cout << "     " << i << "列";

    std::cout << std::endl;
    for (int i=0;i<m;i++)
    {
        std::cout << i << "行     ";
        for (int j=0;j<n;j++)
            if (Map[i][j]=='$') std::cout << '0' << "       ";
            else std::cout << Map[i][j]<< "       ";
        std::cout << std::endl;
    }
    //输出迷宫及路径
    std::cout << "路径：";
    for (int i=k-1;i>=1;i--)
        std::cout << '<' << path[i].x << ',' << path[i].y << '>' << " ---> ";
    std::cout << '<' << xEnd << ',' << yEnd << '>';
}

void BFS(int m,int n,int xStart,int yStart,int xEnd,int yEnd,char Map[MAXN][MAXN])
{
    std::queue<node>Que;//用队列存储所有可能走到的位置
    node cur,next;//cur表示当前所走到的位置
    cur.x=xStart;
    cur.y=yStart;
    cur.step=0;
    Que.push(cur);//把当前所在的位置压入队列
    Map[xStart][yStart]='#';
    node ans[MAXN][MAXN];
    int dx[4]={-1, 0, 0, 1};
    int dy[4]={ 0, 1,-1, 0};
    //dx dy分别为两个方向数组（-1，0）（0，1）（0，-1）（1，0）代表四个方向
    while(!Que.empty())
    //当Que队列为空时，代表所有能走的点已经备全部遍历过了
    {
        cur=Que.front();
        Que.pop();
        if(cur.x==xEnd && cur.y==yEnd)
        //如果当前已经遍历到了终点，调用Direction函数来回溯路径
        {
            Direction(m,n,xStart,yStart,xEnd,yEnd,ans,Map);
            return;
        }
        for(int i=0;i<4;i++)
        //i从0到3代表了下一步能走的四个方向
        {
            next.x=cur.x+dx[i];
            next.y=cur.y+dy[i];
            //next记录了从cur开始下一步能走到的位置
            if(next.x>=0 && next.x<m && next.y>=0 && next.y<n && Map[next.x][next.y]=='0')
            //判断条件 下一步的位置（next）应该在合理的范围内 并且下一步是可走的路径
            {
                Map[next.x][next.y]='$';
                //用$表示该点已经被遍历过了 方便遍历
                next.step=cur.step+1;
                //下一步(next)是这一步(cur)的步数加一
                ans[next.x][next.y].x=cur.x;
                ans[next.x][next.y].y=cur.y;
                //ans数组记录走到这一位置的上一位置 方便最后的回溯
                Que.push(next);
                //将next压入队列
            }
        }
    }
    if (Que.empty()) std::cout << "不存在路径！" << std::endl;
}
#endif //MAZE_MAZE_H
