//
// Created by Logan luo on 2017/11/18.
//

#ifndef BINARYSORTTREE_INIT_H
#define BINARYSORTTREE_INIT_H

#include <iostream>
void init(){
//输出开始界面
    using std::cout;
    using std::endl;
    cout << "**\t\t\t\t\t\t\t\t\t\t二叉排序树\t\t\t\t\t\t\t\t**" << endl;
    cout << "==================================================================================" << endl;
    cout << "**\t\t\t\t\t\t\t1\t---\t建立二叉排序树\t\t\t\t\t\t\t\t**" << endl;
    cout << "**\t\t\t\t\t\t\t2\t---\t插入元素\t\t\t\t\t\t\t\t\t\t**" << endl;
    cout << "**\t\t\t\t\t\t\t3\t---\t查询元素\t\t\t\t\t\t\t\t\t\t**" << endl;
    cout << "**\t\t\t\t\t\t\t4\t---\t退出程序\t\t\t\t\t\t\t\t\t\t**" << endl;
    cout << "==================================================================================" << endl;
    cout << "Please select:";
}

void binarySortTreeInit(BinarySortTree &Tree){
//建立搜索二叉树
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Please input key to create Bsort_Tree (End with number 0):" << endl;
    int key;
    cin >> key;
    while (key != 0){
        Tree.TreeInsert(key);
        //调用TreeInsert来插入元素key
        cin >> key;
    }
    cout << "Bsort_Tree is:" << endl;
    Tree.Inorder(Tree.Getroot());
    //通过中序遍历来输出整棵二叉搜索树
    cout << endl;
    cout << endl;
    cout << "Please select:";
}

void binarySortTreeInsertInit(BinarySortTree &Tree){
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Please input the key which inserted :";
    int key;
    cin >> key;
    Tree.TreeInsert(key);
    //调用TreeInsert来插入元素key
    cout << "Bsort_Tree is:" << endl;
    Tree.Inorder(Tree.Getroot());
    //通过中序遍历来输出整棵二叉搜索树
    cout << endl;
    cout << endl;
    cout << "Please select:";
}

void binarySortTreeSearchInit(BinarySortTree &Tree){
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Please input the key which searched :";
    int key;
    cin >> key;
    Tree.TreeSearch(Tree.Getroot(),key);
    //调用TreeSearch来搜索元素key
    cout << endl;
    cout << "Please select:";
}



#endif //BINARYSORTTREE_INIT_H
