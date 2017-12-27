//
// Created by Logan luo on 2017/11/20.
//

#ifndef ELECTRICITYNET_PRIMTREE_H
#define ELECTRICITYNET_PRIMTREE_H
#include<iostream>
#include <climits>
#include <string>
#define MAXWEIGHT INT_MAX
typedef struct edge_tag
{
    int tail;
    int head;
}Edge;
//最近边
typedef struct closeedge_tag
{
    int nextPoint; //邻接点
    int diatance; //权值
}CloseEdge;

class ElectricityNet
{
private:
    //顶点数
    int numPoints;
    //边数
    int numEdges;
    //邻接矩阵
    int **matrix;

    std::string *sPoints;
public:
    ElectricityNet(){
        numPoints=0;
        numEdges=0;
    }
    void createElectricityNet(int numPoints);
    //建图
    void createNet();
    //析构方法
    ~ElectricityNet();
    //Prim算法
    void Prim(std::string);
    int minEdgeVex(CloseEdge*, bool*);
    void updateCloseEdge(CloseEdge*, bool*, int);
    //检查输入
};

void ElectricityNet::createElectricityNet(int numPoints) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    this->numPoints = numPoints;
    //构建邻接矩阵，并初始化
    matrix = new int*[numPoints];
    int i, j;
    for (i = 0; i < numPoints; i++) {
        matrix[i] = new int[numPoints];
        sPoints = new std::string[numPoints];
    }
    string points;
    cout << "请依次输入各顶点名称:" << endl;
    for (int i=0;i<numPoints;i++){
        cin >> points;
        sPoints[i]=points;
    }
    for (i = 0; i < numPoints; i++)
        for (j = 0; j < numPoints; j++)
        {
            if (i == j)
                matrix[i][i] = 0;
            else
                matrix[i][j] = MAXWEIGHT;
        }
}


void ElectricityNet::createNet() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    int numedges=0;
    int tail, head, diatance, i;
    string sTail,sHead;
    cout << "输入两个顶点及边:";
    cin >> sTail >> sHead >> diatance;
    while (sTail!="?" && sHead!="?" && diatance!=0)
    {
        for (int j=0;j<numPoints;j++)
        {
            if (sPoints[j]==sTail) tail=j;
            if (sPoints[j]==sHead) head=j;
        }
        //Prim算法主要针对的是无向图
        matrix[tail][head] = diatance;
        matrix[head][tail] = diatance;
        numedges++;
        cout << "输入两个顶点及边:";
        cin >> sTail >> sHead >> diatance;
    }
    this->numEdges = numedges;
}

ElectricityNet::~ElectricityNet()
{
    int i;
    for (i = 0; i < numPoints; i++)
        delete[] matrix[i];
    delete[]matrix;
}

void ElectricityNet::Prim(std::string startingPoints) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    int vertex;
    for (int j = 0; j < numPoints; j++)
        if (sPoints[j] == startingPoints) {
            vertex = j;
            break;
        }
    //有numV个顶点的图的最小生成树有numV-1条边
    Edge *edges = new Edge[numPoints - 1];
    //标记顶点是否加入
    bool *add = new bool[numPoints];
    memset(add, 0, numPoints);
    //先把vertex加入
    add[vertex] = true;
    //最近边
    CloseEdge *closeedge = new CloseEdge[numPoints];
    int i;
    //初始化最近边
    for (i = 0; i < numPoints; i++) {
        closeedge[i].diatance = matrix[vertex][i];
        if (!add[i] && matrix[vertex][i] > 0 && matrix[vertex][i] < MAXWEIGHT)
            closeedge[i].nextPoint = vertex;
    }
    int v, count = 0;
    while (count < numPoints - 1) {
        //获取最近边的邻接点
        v = minEdgeVex(closeedge, add);
        add[v] = true;
        //把最小权值边依次加入数组edges
        edges[count].tail = closeedge[v].nextPoint;
        edges[count].head = v;
        //更新最近边
        updateCloseEdge(closeedge, add, v);
        count++;
    }
    cout << "从顶点 " << sPoints[vertex] << " 开始，最小生成树的边是" << endl;
    for (i = 0; i < count; i++)
        cout << sPoints[edges[i].tail] << "-<" << matrix[edges[i].tail][edges[i].head] << ">->" << sPoints[edges[i].head] << endl;
    //释放空间
    delete[]edges;
    delete[]add;
    delete[]closeedge;
}
int ElectricityNet::minEdgeVex(CloseEdge *closeedge, bool *add)
{
    int i, v, w;
    v = 0;
    w = MAXWEIGHT;
    for (i = 0; i < numPoints ; i++)
        if (!add[i] && closeedge[i].diatance < w)
        {
            w = closeedge[i].diatance;
            v = i;
        }
    return v;
}
//顶点v的加入后，需要更新最近边
void ElectricityNet::updateCloseEdge(CloseEdge* closeedge, bool *add, int v)
{
    int i;
    for (i = 0; i < numPoints; i++)
        if (!add[i] && matrix[v][i] < closeedge[i].diatance)
        {
            closeedge[i].nextPoint = v;
            closeedge[i].diatance = matrix[v][i];
        }
}

void init(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    cout << "**\t\t\t\t电网造价模拟系统\t\t\t\t**" << endl;
    cout << "==============================================" << endl;
    cout << "**\t\t\t\tA---创建电网顶点\t\t\t\t**" << endl;
    cout << "**\t\t\t\tB---添加电网的边\t\t\t\t**" << endl;
    cout << "**\t\t\t\tC---构造最小生成树\t\t\t**" << endl;
    cout << "**\t\t\t\tD---显示最小生成树\t\t\t**" << endl;
    cout << "**\t\t\t\tE---退出  程序\t\t\t\t**" << endl;
    cout << "==============================================" << endl;
}
void createPrimTree(){
    using std::cout;
    using std::endl;
    using std::string;
    cout << "生成Prim最小生成树!"<< endl;
}
#endif //ELECTRICITYNET_PRIMTREE_H
