#include <iostream>
#include <queue>
class cmp
{
public:
    bool operator()(const long a,const long b)
    //更改比较方式 把较小的元素放在前面 较大的元素放在后面
    {
        return a>b;
    }
};
using namespace std;
int main() {
    long n;
    cout << "请输入木头被锯成的块数N:   ";
    cin >> n;
    cout << endl;
    priority_queue<long,vector<long>,cmp> wood;
    //wood为优先队列 小元素在队首 大元素在队尾
    long sum=0;
    for (long i=0;i<n;i++){
        long t;
        cout << "第" << i+1 << "块木头的长度为:";
        cin >> t;
        while (t<0) {
            cout << "输入有误 请重新输入！！" << endl;
            cout << "第" << i+1 << "块木头的长度为:";
            cin >> t;
        }
        wood.push(t);
        //将元素压入队列
    }
    long Sum=0;
    while (wood.size()>1)
    {
        sum=0;
        sum+=wood.top(); wood.pop();
        sum+=wood.top(); wood.pop();
        //将两个队首元素输出 相加合并后 压入队列
        wood.push(sum);
        Sum+=sum;
    }
    cout << "最小的花费为:          " << Sum << endl;
}