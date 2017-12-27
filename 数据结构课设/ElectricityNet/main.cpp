#include <iostream>
#include "PrimTree.h"
using namespace std;
int main() {
    init();
    int numPoints;
    char choices;
    string startingPoint;
    cout << "请选择操作:" ;
    cin >> choices;
    ElectricityNet electricityNet;
    while (true) {
        switch (choices) {
            case 'A':
                cout << "请输入顶点的个数:";
                cin >> numPoints;
                electricityNet.createElectricityNet(numPoints);
                cout << "请选择操作:";
                cin >> choices;
                break;
            case 'B':
                electricityNet.createNet();
                cout << "请选择操作:";
                cin >> choices;
                break;
            case 'C':
                cout << "请输入起始顶点:";
                cin >> startingPoint;
                createPrimTree();
                cout << "请选择操作:";
                cin >> choices;
                break;
            case 'D':
                electricityNet.Prim(startingPoint);
                cout << "请选择操作:";
                cin >> choices;
                break;
            default:
                return 0;
        }
    }
}
/*
a b 8
b c 7
c d 5
d a 11
a c 18
b d 12
*/