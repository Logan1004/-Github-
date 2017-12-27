//
// Created by Logan luo on 2017/11/19.
//

#ifndef FAMILYTREE_FAMILYTREE_H
#define FAMILYTREE_FAMILYTREE_H
#include <iostream>
#include <string>
struct FamilyTreeNode {
    std::string name; 
    //name记录家庭成员名字
    FamilyTreeNode *firstChild, *nextSibling, *parent;
    //采用左长子 右兄弟的方式 来储存森林 其中firstChild代表长子 nextSibling代表兄弟  parent代表父亲节点
    FamilyTreeNode(std::string value = "", FamilyTreeNode *fc = nullptr, FamilyTreeNode *ns = nullptr,
                   FamilyTreeNode *par = nullptr) : name(value), firstChild(fc), nextSibling(ns), parent(par) {}
    //初始化家谱树节点类
};
class FamilyTree
{
public:
    FamilyTree() {
        root = current = nullptr;
    }
    //家谱树初始化（无参构造方法）
    FamilyTreeNode* Getroot() {
        return root;
    }
    //返回私有成员根节点

    void FamilyTreeBuildRoot(std::string ancestor);
    //添加祖先名字
    void SetUpFamilyTree();
    //建立家族树
    void TreeInsert();
    //添加家庭成员
    void TreeDelete();
    //删除家庭成员（解散局部家庭）
    void ChangeName();
    //为家庭成员修改名字
    bool TreeSearch(FamilyTreeNode *par,std::string name);
    //搜素家庭成员位置
    void FirstChildPrint(FamilyTreeNode *par);
    //输出家庭树

private:
    FamilyTreeNode *root,*current;
    //私有成员变量 root代表根节点 current代表当前节点
};


void FamilyTree::FamilyTreeBuildRoot(std::string ancestor) {
    root = current = new FamilyTreeNode(ancestor);
    //新建节点 将数据放入节点 把当前节点作为根节点
    std::cout << "此家谱的祖先是:" << ancestor << std::endl;
    //输出根节点
}

void FamilyTree::SetUpFamilyTree() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    string familySetUper;
    cout << "请输入要建立家族的人的姓名:";
    cin >> familySetUper;
    //familySetUper代表建立家族成员的人姓名
    int familyMemberNum;
    //familyMemberNum代表该子家族成员数量
    cout << "请输入" << familySetUper << "的儿女个数:";
    cin >> familyMemberNum;
    if (TreeSearch(root,familySetUper)) 
    //在家族树中先找到建立家庭的成员 如果没找到输出 输入错误
    {
        FamilyTreeNode *cur = current;
        //cur记录当前元素
        cout << "请依次输入" << familySetUper << "儿女的姓名:";
        string son;
        cin >> son;
        //son记录子女姓名
        FamilyTreeNode *curSon = new FamilyTreeNode(son);
        //curSon为当前子女节点
        current->firstChild = curSon;
        //首节点（长子）插入 放在firstChild位置
        current = current->firstChild;
        for (int i = 1; i < familyMemberNum; i++) {
            cin >> son;
            FamilyTreeNode *curSon = new FamilyTreeNode(son);
            //curSon为当前子女节点
            current->nextSibling = curSon;
            //兄弟节点放入当前节点的右节点
            current = current->nextSibling;
            //更新current
        }
        FirstChildPrint(cur);
        //输出新建家庭
    }
    else {
        cout << "不存在！请重新输入！" << endl;
    }
}

bool FamilyTree::TreeSearch(FamilyTreeNode *par, std::string name) 
//寻找家族树中的节点
{
    bool flag = false;
    if (par->name== name) 
    //找到了返回当前节点 用current记录
    {
        current = par; flag= true;
    }
    else{
        FamilyTreeNode *cur = par->firstChild;
        //寻找长子
        while (cur!= nullptr){
            if (TreeSearch(cur,name)) 
            //找到了就标记一下
            {
                flag=true;
                break;
            }
            cur=cur->nextSibling;
            //在兄弟节点中寻找
        }
    }
    return flag;
}

void FamilyTree::FirstChildPrint(FamilyTreeNode *par) 
//输出子家庭
{
    using std::cout;
    using std::endl;
    using std::string;
    if (par->firstChild== nullptr)
    //如果长子为空 说明家庭不存在 直接输出错误
    {
        cout << "不存在！" << endl;
    }else {
        cout << par->name << "的第一代子孙是:";
        par = par->firstChild;
        //先找到长子 
        while (par != nullptr) {
            cout << " " << par->name;
            par = par->nextSibling;
            //然后找兄弟
        }
        cout << endl;
    }
}

void FamilyTree::TreeInsert() 
//插入元素
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    string familySetUper;
    cout << "请输入要添加儿子（或女儿）的人的姓名:";
    cin >> familySetUper;
    cout << "请输入" << familySetUper << "新添加的儿子（或女儿）的姓名:";
    string son;
    cin >> son;
    FamilyTreeNode *curSon = new FamilyTreeNode(son);
    if (TreeSearch(root,familySetUper))
    //找到要插入元素的父节点
    {
        FamilyTreeNode *cur=current;
        if (cur->firstChild== nullptr) {
            cur->firstChild=curSon;
            FirstChildPrint(cur);
            //输出新建的子家庭
        }
        //如果没有长子 那么插入的元素喂长子 放在长子节点
        else {
            current = current->firstChild;
            while (current->nextSibling != nullptr) current = current->nextSibling;
            current->nextSibling = curSon;
            //插入兄弟节点 不断搜寻右子树 找到第一个空节点 把当前元素放入
            FirstChildPrint(cur);
            //输出新建的子家庭
        }
    }
    else{
        cout << "不存在！请重新输入！" << endl;
    }
}
void FamilyTree::ChangeName() 
//更改名字
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    string parPast, parNow;
    cout << "请输入要更改姓名的人的目前的姓名:";
    cin >> parPast;
    if (!TreeSearch(root,parPast))
    //找到要改名字的节点
    {
        cout << "不存在！请重新输入！" << endl;
    }
    else {
        cout << "请输入更改以后的名字:";
        cin >> parNow;
        current->name=parNow;
        cout << parPast << "已更名为" << parNow << endl;
    }
}

void FamilyTree::TreeDelete() 
//删除节点
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    cout << "请输入要解散家庭的人的姓名";
    string familyDeleter;
    cin >> familyDeleter;
    cout << "要解散家庭的人是" << familyDeleter << endl;
    TreeSearch(root,familyDeleter);
    //找到要删除的节点
    FirstChildPrint(current);
    current->firstChild= nullptr;
}
void init()
//初始化函数
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    cout << "**\t\t\t家谱管理系统\t\t\t**" << endl;
    cout << "==================================" << endl;
    cout << "**\t\t请选择要执行的操作\t\t\t**" << endl;
    cout << "**\t\tA---完善家谱\t\t\t\t**" << endl;
    cout << "**\t\tB---添加家庭成员\t\t\t**" << endl;
    cout << "**\t\tC---解散局部家庭\t\t\t**" << endl;
    cout << "**\t\tD---更改家庭成员姓名\t\t**" << endl;
    cout << "**\t\tE---退出程序\t\t\t\t**" << endl;
    cout << "==================================" << endl;
    cout << "首先建立一个家谱！";

}
#endif //FAMILYTREE_FAMILYTREE_H
