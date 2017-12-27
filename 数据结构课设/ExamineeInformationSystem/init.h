//
// Created by Logan luo on 2017/11/11.
//

#ifndef EXAMINEEINFORMATIONSYSTEM_INIT_H
#define EXAMINEEINFORMATIONSYSTEM_INIT_H
#include <iostream>
#include "examineeInformationSystem.h"

void init(examineeInformationSystem &examineeStu , int & choice) 
//初始化系统 通过引用 来构造examineeStu
{
    using std::cout;
    using std::cin;
    using std::endl;
    exam stu;
    int stuNum;
    cout << "首先请建立考生信息系统！\n";
    cout << "请输入考生人数:";
    cin >> stuNum;
    while (stuNum<0){
        cout << "请输入正整数" << endl;
        cout << "首先请建立考生信息系统！\n";
        cout << "请输入考生人数:";
        cin >> stuNum;
    }
    //stuNum储存考生人数
    cout << "请依次输入考生的考号，姓名，性别，年龄以及报考科目！" << endl;
    for (int i = 0; i < stuNum; i++) {
        string name, sex, course;
        int num,age;
        cin >> num >> name >> sex >> age >> course;
        stu.examineeCourse = course;
        stu.examineeSex = sex;
        stu.examineeAge = age;
        stu.examineeName = name;
        stu.examineeNum = num;
        examineeStu.examineeInsert(stu, i);
        //将当前元素插入链表中的第i个位置
    }
    examineeStu.examineeShow();
    //显示当前链表
    cout << "请选择你要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作" << endl;
    cout << "请选择你要进行的操作:";
    cin >> choice;
}

void insertInit(examineeInformationSystem &examineeStu , int & choice) 
//输入初始化 通过引用 来完善examineeStu
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "请输入你要插入的考生位置:";
    int position;
    //position代表了要插入考生的位置
    cin >> position;
    cout << "请依次输入要插入的考生的考号，姓名，性别，年龄以及报考科目！" << endl;
    string name, sex, course;
    int num,age;
    exam stu;
    cin >> num >> name >> sex >> age >> course;
    stu.examineeCourse = course;
    stu.examineeSex = sex;
    stu.examineeAge = age;
    stu.examineeName = name;
    stu.examineeNum = num;
    examineeStu.examineeInsert(stu, position);
    //将当前元素插入链表中的第position个位置
    cout << "插入完毕！" << endl;
    examineeStu.examineeShow();
    //显示插入后链表
    cout << "请选择你要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作" << endl;
    cout << "请选择你要进行的操作:";
    cin >> choice;
}

void removeInit(examineeInformationSystem &examineeStu , int & choice) 
//删除初始化 通过引用 来完善examineeStu
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "请输入你要删除的考生考号:";
    int testNum;
    //testNum代表要删除的考生的考号
    cin >> testNum;
    exam stu;
    //用stu记录被删除考生的信息
    examineeStu.examineeRemove(stu, testNum);
    cout << "你删除的考生信息为:" << stu.examineeNum << "\t\t\t" << stu.examineeName << "\t\t\t" << stu.examineeSex << "\t\t\t"
         << stu.examineeAge
         << "\t\t\t" << stu.examineeCourse << endl;
    cout << "删除完毕！" << endl;
    cout << "请选择你要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作" << endl;
    cout << "请选择你要进行的操作:";
    cin >> choice;
}

void searchInit(examineeInformationSystem &examineeStu , int & choice) 
//搜索初始化 
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "请输入要查找的考生的考号:";
    int testNum;
    //testNum代表要搜索的考生的考号
    cin >> testNum;
    if (!examineeStu.examineeSearch(testNum)) cout << "输入有误！请重新输入！\n";
    //如果没有搜到该元素 输出 “输入有误”
    else cout << "查找完毕！" << endl;
    cout << "请选择你要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作" << endl;
    cout << "请选择你要进行的操作:";
    cin >> choice;
}

void earaseInit(examineeInformationSystem &examineeStu , int & choice) 
//修改初始化 通过引用 来完善examineeStu
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "请输入要修改的考生的考号:";
    int testNum;
    //testNum代表要删除的考生的考号
    cin >> testNum;
    cout << "请依次输入该考生的考号，姓名，性别，年龄以及报考科目！" << endl;
    string name, sex, course;
    int num,age;
    exam stu;
    cin >> num >> name >> sex >> age >> course;
    stu.examineeCourse = course;
    stu.examineeSex = sex;
    stu.examineeAge = age;
    stu.examineeName = name;
    stu.examineeNum = num;
    //用stu记录修改的信息
    if (!examineeStu.examineeEarase(testNum, stu)) cout << "输入有误！请重新输入！\n";
    //如果没有找到该元素 输出 “输入有误 请重新输入”
    else {
        cout << "修改完毕！" << endl;
        examineeStu.examineeShow();
    //输出当前链表
    }
    cout << "请选择你要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作" << endl;
    cout << "请选择你要进行的操作:";
    cin >> choice;
}

void countingInit(examineeInformationSystem &examineeStu , int & choice) 
//统计元素初始化
{
    using std::cout;
    using std::cin;
    using std::endl;
    examineeStu.examineeShow();
    cout << "请选择你要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作" << endl;
    cout << "请选择你要进行的操作:";
    cin >> choice;
}

void restartInit(int &choice) 
//构造系统错误初始化
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "输入有误请重新输入！" << endl;
    cout << "请选择你要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作" << endl;
    cout << "请选择你要进行的操作:";
    cin >> choice;
}
#endif //EXAMINEEINFORMATIONSYSTEM_INIT_H
