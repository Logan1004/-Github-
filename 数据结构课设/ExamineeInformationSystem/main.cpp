#include <iostream>
#include "examineeInformationSystem.h"
#include "init.h"

using namespace std;
int main() {
    examineeInformationSystem examineeStu;
    int choice;
    //choice记录选择
    init(examineeStu,choice);
    //初始化系统
    while (choice != 0){
        switch (choice) {
            case 1:
            //插入元素
                insertInit(examineeStu,choice);
                break;
            case 2:
            //删除元素
                removeInit(examineeStu,choice);
                break;
            case 3:
            //搜索元素
                searchInit(examineeStu,choice);
                break;
            case 4:
            //更正元素
                earaseInit(examineeStu,choice);
                break;
            case 5:
            //统计元素
                countingInit(examineeStu,choice);
                break;
            default:
            //输入其他的就重新开始项目
                restartInit(choice);
                break;
        }
        //输入0 退出程序
        if (choice==0) cout << "谢谢使用！" << endl;
    }
}
/*
 *
1 zhaosi 男 19 数学
2 李四娃 男 20 英语
3 Alice 女 21 英语
4 ppap 男 22 语文
5 张老师 男 30 数据结构
 */