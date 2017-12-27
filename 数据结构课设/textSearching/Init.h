//
// Created by Logan luo on 2017/10/28.
//

#ifndef TEXTSEARCHING_INIT_H
#define TEXTSEARCHING_INIT_H
#define MAXN 10000
void init(int pos[],int &sum)
//初始化 用于记录字符串的数组
{
    for (int i=0;i<MAXN;i++) pos[i]=0;
    sum=0;
}

void startingPage()
//项目开始界面
{
    std::cout<<("==============================================\n");
    std::cout<<("||\t\t\t\t文本文件单词的检索与计数\t\t||\n");
    std::cout<<("||==========================================||\n");
    std::cout<<("||\t\t\t\t1.     建立文本文件\t\t\t||\n");
    std::cout<<("||\t\t\t\t2.     文本单词汇总\t\t\t||\n");
    std::cout<<("||\t\t\t\t3.     单词定位\t\t\t\t||\n");
    std::cout<<("||\t\t\t\t4.     退出整个程序\t\t\t||\n");
    std::cout<<("==============================================\n");
    std::cout<<("                请选择(1--4):");
}

void searchStartingPage()
//单词定位开始界面
{
    std::cout<<("==============================================\n");
    std::cout<<("||\t\t\t文本文件单词字串的定位统计及定位\t\t||\n");
    std::cout<<("||==========================================||\n");
    std::cout<<("||\t\t\ta.     单词出现次数\t\t\t\t||\n");
    std::cout<<("||                                          ||\n");
    std::cout<<("||\t\t\tb.     单词出现位置\t\t\t\t||\n");
    std::cout<<("||                                          ||\n");
    std::cout<<("==============================================\n");
    std::cout<<("                请选择(a或b):\n");
}

#endif //TEXTSEARCHING_INIT_H
