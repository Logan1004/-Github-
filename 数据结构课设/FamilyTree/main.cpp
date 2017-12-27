#include <iostream>
#include "FamilyTree.h"
#include <string>
using namespace std;
int main() {
    FamilyTree family;
    init();
    cout << "请输入祖先的姓名:";
    string ancestor;
    cin >> ancestor;
    family.FamilyTreeBuildRoot(ancestor);
    char choice;
    cout << "请选择要执行的操作:";
    cin >> choice;
    while(true) {
        switch (choice) {
            case 'A':
            //建立家谱
                family.SetUpFamilyTree();
                cout << "请选择要执行的操作:";
                cin >> choice;
                break;
            case 'B':
            //插入新成员
                family.TreeInsert();
                cout << "请选择要执行的操作:";
                cin >> choice;
                break;
            case 'C':
            //删除家庭成员
                family.TreeDelete();
                cout << "请选择要执行的操作:";
                cin >> choice;
                break;
            case 'D':
            //家庭成员改名
                family.ChangeName();
                cout << "请选择要执行的操作:";
                cin >> choice;
                break;
            default:
                return 0;
        }
    }
}