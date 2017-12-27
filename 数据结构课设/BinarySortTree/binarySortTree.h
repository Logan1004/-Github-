//
// Created by Logan luo on 2017/11/17.
//

#ifndef BINARYSORTTREE_BINARYSORTTREE_H
#define BINARYSORTTREE_BINARYSORTTREE_H
#include <iostream>

struct BinarySortTreeNode
//二叉搜索树节点类型
{
    int element;
    //element用来存放元素的值
    BinarySortTreeNode *parent, *lnode, *rnode;
    //parent存父节点 lnode存左节点  rnode存右节点
    BinarySortTreeNode(){ parent = lnode = rnode = nullptr; }
    //构造函数初始化
    BinarySortTreeNode(const int& key)
    {
        element = key;
        parent = lnode = rnode = nullptr;
    }
    //构造函数
};

class BinarySortTree
{
public:
    BinarySortTree() :root(nullptr){}
    //构造函数
    BinarySortTreeNode* Getroot(){ return root; }
    //获取根结点
    void Inorder(BinarySortTreeNode*node);
    //中序遍历
    BinarySortTreeNode* TreeSearch(BinarySortTreeNode*node, int key);
    //递归查找
    void TreeInsert(int key);
    //插入元素

private:
    BinarySortTreeNode* root;
    //root存根节点
};

bool TreeCheck(BinarySortTreeNode*node, int key) 
//TreeCheck函数主要用来判断元素是否已经被插入二叉搜索树（去除重复）
{
    using std::cout;
    using std::endl;
    bool nodeExist = false;
    //布尔类型的nodeExist用来记录key元素是否在二叉树中存在
    while (node != nullptr) {
        if (key < node->element)
            node = node->lnode;
        //如果key的值小于当前节点的element值 那么去搜索它的左子树
        else if (key > node->element)
            node = node->rnode;
        //如果key的值大于当前节点的element值 那么去搜索它的右子树
        else {
            nodeExist = true;
            break;
        }
        //如果key的值等于当前节点的element值 则该元素已经存在
    }
    return nodeExist;
}

void BinarySortTree::TreeInsert(int key) {
//TreeInsert函数主要用来建立二叉树及插入元素
    using std::cout;
    using std::endl;
    BinarySortTreeNode *temp = nullptr;
    BinarySortTreeNode *curParent = root;
    if (TreeCheck(root, key)) 
    //用TreeCheck来判断key元素是否存在 如果存在了就跳过
    {
        cout << "The input Key<" << key << "> iS have in!" << endl;
        return;
    } else{
        BinarySortTreeNode *cur = new BinarySortTreeNode(key); 
        //将需要插入的元素放入新建立的结点中
        while (curParent != nullptr) {
        //找到要插入位置的双亲结点
            temp = curParent;
            //temp去记录最终cur的parent节点
            if (curParent->element > cur->element) curParent = curParent->lnode;
            else curParent = curParent->rnode;
        }
        cur->parent = temp;
        if (temp == nullptr) root = cur;  
        // 判断要插入的是：左 或 右结点
        else if (cur->element > temp->element) temp->rnode = cur;
        else temp->lnode = cur;
    }
}

void BinarySortTree::Inorder(BinarySortTreeNode*node)
//对整棵二叉树进行中序遍历并输出
{
    using std::cout;
    using std::endl;
    if (node == nullptr)
        return;
    else
    {
        Inorder(node->lnode);
        cout << node->element << "->";
        Inorder(node->rnode);
    //中序遍历 左节点->父节点->右节点
    }
}

BinarySortTreeNode* BinarySortTree::TreeSearch(BinarySortTreeNode*node, int key)
//用递归的方式 去搜索元素key
{
    using std::cout;
    using std::endl;
    if ((node == nullptr) || (key == node->element))
    {
        if (node == nullptr)
            cout << key << " not exist!" << endl;
        else
            cout << "search success!" << endl;
        return node;
    }

    if (key > node->element)
        return TreeSearch(node->rnode,key);
    else
        return TreeSearch(node->lnode,key);
    //如果key的值小于当前节点的element值 那么去搜索它的左子树
    //如果key的值大于当前节点的element值 那么去搜索它的右子树
    //如果key的值等于当前节点的element值 则该找到该元素
}








#endif //BINARYSORTTREE_BINARYSORTTREE_H
