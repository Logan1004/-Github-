//
// Created by Logan luo on 2017/11/11.
//

#ifndef EXAMINEEINFORMATIONSYSTEM_EXAMINEEINFORMATIONSYSTEM_H
#define EXAMINEEINFORMATIONSYSTEM_EXAMINEEINFORMATIONSYSTEM_H
#include <iostream>
#include <string>
using std::string;
struct exam 
//自定义类型 用来存储考生信息
{
    int    examineeNum;     //记录考生考号
    string examineeName;    //记录考生姓名
    string examineeSex;     //记录考生性别
    int    examineeAge;     //记录考生年龄
    string examineeCourse;  //记录考生报考科目
    exam()                  
    //无参构造方法（初始化）
    {
        examineeNum = 0;
        examineeAge = 0;
        examineeName = "";
        examineeSex = "";
        examineeCourse = "";
    }
    exam(const int num, const string name,const string sex, const int age, const string course) 
    //有参构造方法
    {
        examineeNum  = num;
        examineeAge  = age;
        examineeName = name;
        examineeSex  = sex;
        examineeCourse = course;
    }
};

class examinee
//自定义类型 考生的链表类
{
public:
    exam info;
    examinee * next;
};

class examineeInformationSystem 
//考试信息管理系统类
{
private:
    examinee *head;
// 头指针 用head来记录
public:
    examineeInformationSystem() { head = nullptr; }
    //构造函数 将头指针清空

    bool examineeInsert(exam stu, int position);
    //插入函数 position代表插入的位置 stu存储所要插入考生的信息

    bool examineeRemove(exam &stu, int testNum);
    //删除函数 testNum代表所要删除的考号 stu存储被删除考生的信息

    bool examineeSearch(int testNum) const;
    //搜索函数 testNum代表被搜索的考生的考号

    bool examineeEarase(int testNum, exam &stu);
    //更正函数 testNum代表所要更正的考生的考号 stu代表更正考生的信息

    void examineeShow();
    //显示函数 显示已存储的信息

};

bool examineeInformationSystem::examineeInsert(const exam stu,int position) 
//插入函数 position代表插入的位置 stu存储所要插入考生的信息
{
    if (head == nullptr || position == 0) 
    //如果当前插入的是第一个元素 或者 插入的元素要放在队首的位置
    {
        examinee *newExaminee = new examinee;
        //新建examinee类型变量 存储考生信息 作为要插入的节点
        newExaminee->info = stu;
        if (newExaminee == nullptr) 
        //如果examinee指针为空 那么输出储存分配错误 直接退出程序
        {
            std::cerr << "储存分配错误！\n";
            exit(1);
        }
        newExaminee->next = head;
        head = newExaminee;
        //把newExaminee放到头指针的位置
    } 
    else
    //如果当前插入的不是第一个元素 
    {
        examinee *curExaminee = head;
        //新建examinee类型变量指针curExaminee 先指向头指针 用来寻找要插入的位置
        for (int k = 1; k < position; k++)
        //通过循环遍历 寻找插入的位置
            if (curExaminee == nullptr) break;
            //如果当前位置已经是空指针了 说明插入位置有误
            else curExaminee = curExaminee->next;
        if (curExaminee == nullptr) {
            std::cerr << "无效位置！\n";
            return false;
            //插入失败 返回false
        } else {
            examinee *newExaminee = new examinee;
            //新建newExaminee类型变量 存储考生信息 作为要插入的节点
            newExaminee->info = stu;
            newExaminee->next = curExaminee->next;
            curExaminee->next = newExaminee;
            //插入元素
        }
    }
    return true;
    //插入成功 返回true
}

bool examineeInformationSystem::examineeRemove(exam &stu, int testNum) 
//删除函数 testNum代表所要删除的考号 stu存储被删除考生的信息（引用）
{
    examinee *cur, *del;
//新建两个examinee类型指针cur和del cur用来寻找所要删除的考生的前一位 del记录所要删除考生的节点
    int position=0;
    //position记录所删除的考生在链表中的位置
    cur=head;
    while (cur != nullptr)
        if (cur->info.examineeNum == testNum) break;
        else {
            cur = cur->next;
            position++;
        }
    //循环去寻找删除的考生的位置
    if (position <= 1) 
    //如果删除的是首节点
    {
        del = head;
        head = head->next;
        //把头指针向后移动一位 用del保存原来的头指针
    } else {
        cur = head;
        for (int i = 1; i < position ; i++)
            if (cur == nullptr) break;
            else cur = cur->next;
        if (cur == nullptr || cur->next == nullptr) {
        //cur记录被删除考生的前一个位置 如果cur或者cur->next为空指针 说明删除的元素不存在
            std::cerr << "无效的删除位置\n";
            return false;
            //删除失败 返回false
        } else {
            del = cur->next;
            cur->next = del->next;
            //找到删除位置 删除该元素
        }
    }
    stu = del->info;
    //记录被删除元素的信息  
    delete del;
    //删除del 释放空间
    return true;
    //删除成功 返回true
}

bool examineeInformationSystem::examineeSearch(int testNum) const 
//搜索函数 testNum代表被搜索的考生的考号
{
    examinee *point = head;
    //新建examinee类型变量指针point 先指向头指针 用来寻找相应元素
    bool flag = false;
    //布尔类型变量 用来记录是否找到元素
    while (point != nullptr)
    //循环搜索 找到所需要寻找的考号
        if (point->info.examineeNum == testNum) break;
        else point = point->next;
    if (point != nullptr) {
    //如果找到了该考生 那么输出该考生的相关信息
        flag = true;
        //将flag设为true 表示已经找到
        std::cout << "考号\t\t\t姓名\t\t\t\t性别\t\t\t年龄\t\t\t报考科目" << std::endl;
        std::cout << point->info.examineeNum << "\t\t\t" << point->info.examineeName << "\t\t\t"
                  << point->info.examineeSex << "\t\t\t" << point->info.examineeAge
                  << "\t\t\t" << point->info.examineeCourse << std::endl;
    }
    return flag;
    //返回标志
}

bool examineeInformationSystem::examineeEarase(int testNum, exam & stu) 
//更正函数 testNum代表所要更正的考生的考号 stu代表更正考生的信息
{
    examinee *point = head;
    //新建examinee类型变量指针point 先指向头指针 用来寻找相应元素
    bool flag = false;
    //布尔类型变量 用来记录是否找到元素
    while (point != nullptr)
    //循环搜索 找到所需要寻找的考号
        if (point->info.examineeNum == testNum) break;
        else point = point->next;
    if (point != nullptr) 
    //如果找到了该考生 那么修改该考生的相关信息
    {
        flag = true;
        //将flag设为true 表示已经修改完毕
        point->info = stu;
    }
    return flag;
    //返回标志
}

void examineeInformationSystem::examineeShow() 
//显示函数 显示已存储的信息
{
    examinee *point = head;
    //新建examinee类型变量指针point 先指向头指针 用来遍历输出链表中所有元素
    std::cout << "考号\t\t\t姓名\t\t\t\t性别\t\t\t年龄\t\t\t报考科目" << std::endl;
    while (point != nullptr) {
        std::cout << point->info.examineeNum << "\t\t\t" << point->info.examineeName << "\t\t\t"
                  << point->info.examineeSex << "\t\t\t" << point->info.examineeAge
                  << "\t\t\t" << point->info.examineeCourse << std::endl;
        point = point->next;
    }
}
#endif //EXAMINEEINFORMATIONSYSTEM_EXAMINEEINFORMATIONSYSTEM_H
