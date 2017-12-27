//
// Created by Logan luo on 2017/10/26.
//

#ifndef N_QUEEN_H
#define N_QUEEN_H
#include <iostream>
#define size 50
//#define的形式 便于后期的修改
long sum=0;
bool check(int x,int y,long n,int chess[][size])
//check函数主要用来判断当前位置是否满足放置的要求
{
    //在这里因为是逐行放置皇后 因此不用考虑当前行内皇后的冲突问题了
    for (int i=0;i<x;i++)
        if (chess[i][y]==1) return false;
    //如果当前列内已经有皇后了 那么该行不能再放皇后了
    for (int i=x, j=y;i>=0,j>=0;i--,j--)
    {
        if (i<0 || j>=n) ;
        else if (chess[i][j]==1) return false;
    }
    //从放置点左上45度判断斜线上有没有冲突的皇后
    for (int i=x, j=y;i>=0,j<n;i--,j++)
    {
        if (i<0 || j>=n) ;
        else if (chess[i][j]==1) return false;
    }
    //从放置点右上45度判断斜线上有没有冲突的皇后
    return true;
    //如果上述情况都没有冲突的皇后 那么这个点是可以放置皇后的
}
void Output(long n,int chess[][size])
//输出函数 chess数组存储皇后的位置 1表示有皇后 0表示没有 分别用x/o表示
{
    sum++;
    //sum记录不同的排列个数
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            if (chess[i][j]==1) std::cout << "x" << " ";
            else std::cout << 'o' << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void dfs(long roll,long n,int chess[][size])
{
    if (roll==n)
    //按行填入皇后 当最后一行也被填好时 所有的皇后已经被放置完毕了 那么输出
    {
        Output(n,chess);
        return;
    }
    for (int i=0;i<n;i++)
    {
        if (check(roll,i,n,chess) || (i==0 && roll==0))
        //如果该点能够放置皇后 
        {
            chess[roll][i]=1;
            //假设在该点放上皇后 并进行递归 进入下一行的放置
            dfs(roll+1,n,chess);
            chess[roll][i]=0;
            //该点放置皇后会产生冲突 那么把这个点清0
        }
    }

}
#endif //N_QUEEN_H
