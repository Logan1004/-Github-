#include <iostream>
using namespace std;
struct Node
{
    int num;
    struct Node *next;
};
int main() {
    long n,m,s,k;
    cout << "假如N个旅客排成一个环形，依"
            "次顺序编号1, 2, …, N。从某"
            "个指定的第S号开始。沿环计数"
            "，每数到第M个人就让器出列，且"
            "从下一个人开始重新计数，继续进"
            "行下去。这个过程一直进行到剩下K"
            "个旅客为止。"<< endl;
    struct Node *lifeOrDeath,*head= nullptr,*tail;
    //新建三个指针对象 head指向头节点 tail尾节点 lifeOrDeath代表存储的链表
    cout << "请输入生死游戏的总人数N:\t\t\t";
    cin >> n;
    cout << "请输入游戏开始的位置S:\t\t\t";
    cin >> s;
    while (s>n){
        cout << "输入有误 请重新输入！" << endl;
        cout << "请输入生死游戏的总人数N:\t";
        cin >> n;
        cout << endl;
        cout << "请输入游戏开始的位置S:\t\t\t";
        cin >> s;
        cout << endl;
    }
    cout << "请输入死亡数字M:\t\t\t\t";
    cin >> m;
    while (m<0) {
        cout << "输入死亡数字有误 请重新输入！" << endl;
        cout << "请输入死亡数字M:\t\t\t\t";
        cin >> m;
    }
    cout << "请输入剩余的生者人数K:\t\t\t";
    cin >> k;
    while (k<0) {
        cout << "输入剩余人数有误 请重新输入！" << endl;
        cout << "请输入剩余的生者人数K:\t\t\t";
        cin >> k;
    }
    for (int i=1;i<=n;i++)
    //链表类的实现
    {
        lifeOrDeath=(struct Node *)malloc(sizeof(struct Node));
        lifeOrDeath->num=i;
        if (head== nullptr)
        {
            head=lifeOrDeath; tail=lifeOrDeath;
        }
        else tail->next=lifeOrDeath;
        tail=lifeOrDeath;
    }
    //将尾节点的next指向头节点 实现循环操作
    tail->next=head;
    long t=n;
    for (int i=1;i<=n;i++)
    //找到游戏开始位置
    {
        if (lifeOrDeath->next->num==s) break;
        else lifeOrDeath=lifeOrDeath->next;
    }
    long num=0;
    t=m % n;
    //如果死亡数字大于总人数 可以对它取余数
    while (n>k)
    {
        for (int i=1;i<t;i++) lifeOrDeath=lifeOrDeath->next;
        //找到死亡的位置并输出
        Node *death = lifeOrDeath->next;
        num++;
        cout << "第" << num << "个死者的位置是:\t\t\t" <<death->num << endl;
        lifeOrDeath->next = death->next;
        n--;
    }
    cout << "最后剩下:\t\t\t"<< k << "人" << endl;
    if (k>0) {
        for (int i=0;i<k;i++){
            if (lifeOrDeath->num>lifeOrDeath->next->num) break;
            else
                lifeOrDeath = lifeOrDeath->next;
        }
        //找到生者的第一位
        lifeOrDeath=lifeOrDeath->next;
        cout << "剩余的生者的位置为:";
        for (int i = 0; i < k; i++) {
            cout << "\t\t" << lifeOrDeath->num;
            lifeOrDeath=lifeOrDeath->next;
        //用链表遍历的方法输出下一个
        }
    }
}