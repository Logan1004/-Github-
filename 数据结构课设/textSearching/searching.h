//
// Created by Logan luo on 2017/10/28.
//

#ifndef TEXTSEARCHING_SEARCHING_H
#define TEXTSEARCHING_SEARCHING_H
#include <iostream>
#include <vector>
#include <string>
#include "Init.h"
using std::string;
const std::vector<int> * kmp_next(string &s)
//建立next数组
{
    static std::vector<int> next(s.size());
    next[0]=0;
    int temp;
    for (int i=1;i<s.size();i++)
    {
        temp=next[i-1];
        //寻找重复的子串
        while (s[i]!=s[temp] && temp>0)
        {
            temp=next[temp-1];
            //如果不相同 那么temp记录next[temp-1]的值
        }
        if (s[i]==s[temp]) next[i]=temp+1;
        //如果相同 那么next[i]递加
        else next[i]=0;
    }
    return &next;
}

bool kmp_search(string text,string m,int pos[],int &sum)
{
    bool flag=false;
    const std::vector<int>* next=kmp_next(m);
    //新建next数组 用来记录移动位数 这里 移动位数 = 已匹配的字符数 - 对应的部分匹配值
    int tp=0; int mp=0; 
    for (tp=0;tp<text.size();tp++)
    {
        while (text[tp]!=m[mp] && mp)
        //如果字符串不匹配
        {
            mp=(*next)[mp-1];
            //mp记录当前可以向前移动的位数
        }
        if (text[tp]==m[mp]) mp++;
        //如果当前位字符相同 将mp指针后移
        if (mp==m.size())
        //如果指针移到最后一位了
        {
            if (text[tp+1]==' ' || tp+1>=text.size() && (text[tp-mp]==' ' || tp-mp+1==0))
            //如果找到了单词
            {
                pos[sum] = tp - mp + 1;
                //记录位置
                sum++;
                flag = true;
            }
        }
    }
    return flag;
}

void searching(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ifstream;
    searchStartingPage();
    int pos[MAXN];
    int sum=0;
    int Sum=0;
    char ch;
    cout << "请输入a或b";
    cin >> ch;
    cout << endl;
    string sFile;
    cout << "请输入文本文件名";
    cin >> sFile;
    ifstream myfile(sFile);
    string temp;
    while (!myfile.is_open())
    {
        cout << "未成功打开文件" << endl;
        return;
    }
    //判断文件有没有成功打开
    int line=0;
    string Search;
    cout << "请输入要检索的字符串:";
    cin >> Search;
    switch (ch) {
        case 'a':
        //搜索单词出现次数
            while(getline(myfile,temp))
            //通过文件读入 按行搜索
            {
                init(pos,sum);
                line++;
                //用kmp算法搜索单词
                if (kmp_search(temp,Search,pos,sum)) Sum+=sum;
            }
            if (Sum==0) cout << "所查的字符不存在！请重新输入！" << endl;
            else cout << "单词" << Search << "在文本文件" << sFile << "中共出现" << Sum << "次"<< endl;
            break;
        case 'b':
        //单词定位
            while(getline(myfile,temp))
            {
                init(pos,sum);
                line++;
                //用kmp算法搜索单词
                if (kmp_search(temp,Search,pos,sum)) {
                    cout << "行数: " << line << ",次数： " << sum << ",起始位置分别为:第";
                    for (int i = 0; i < sum; i++)
                        cout << "   " << pos[i]+1;
                    Sum+=sum;
                    cout << "个字符" << endl;
                }
            }
            //如果没有找到 最后输出找不到
            if (Sum==0) cout << "所查的字符不存在！请重新输入！" << endl;
            else cout << "本软件自定义110个字节为一行" << endl;
            break;
    }
}

#endif //TEXTSEARCHING_SEARCHING_H
