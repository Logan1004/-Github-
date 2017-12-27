//
// Created by Logan luo on 2017/10/28.
//

#ifndef TEXTSEARCHING_COUNTING_H
#define TEXTSEARCHING_COUNTING_H
struct Word{
    string word="";
    int num=0;
};
//自定义类型Word 用来统计单词名称和出现的数量
void counting(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ifstream;
    using std::string;
    Word fWord[MAXN];
    cout << endl;
    string sFile;
    cout << "请输入文本文件名:";
    getchar();
    getline(cin,sFile);
    ifstream myfile(sFile);
    //文件流 读入文件  
    string temp;
    while (!myfile.is_open())
    {
        cout << "未成功打开文件" << endl;
        return;
    }
    //判断文件是否成功打开
    int aNum=0;
    int notWord=0;
    while(getline(myfile,temp)) 
    //将每一行的文本读取到temp中
    {
        int i=0; int j=0;
        while (i<=temp.size()){
            char s[MAXN]="";
            bool flag=true;
            bool wFlag=true;
            if (temp[i]==' ' || i==temp.size()){
                for (int num=j;num<=i-1;num++) {
                    if ((temp[num]<='z' && temp[num]>='a') || (temp[num]<='Z' && temp[num]>='A'))
                    //判断是不是单词
                        s[num - j] = temp[num];
                        //存储单词
                    else {
                        wFlag=false;
                        notWord++;
                        break;
                    }
                }
                if (wFlag) {
                //判断单词有没有出现过
                    string str=s;
                    for (int num = 0; num <= aNum; num++) {
                        if (s==fWord[num].word) {
                            fWord[num].num++;
                            //找到单词 把统计数加一
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        //没有这个单词 新建空间
                        fWord[aNum].word = s;
                        fWord[aNum].num++;
                        aNum++;
                    }
                }
                j=i+1;
            }
            i++;
        }
    }
    //以下为输出
    cout << "\t\t\t\t单词：\t\t\t\t个数" << endl;
    int Sum=0;
    for (int i=0;i<aNum;i++)
    {
        Sum+=fWord[i].num;
        cout << "\t\t\t\t"<<fWord[i].word;
        for (int j=20;j>=fWord[i].word.size();j--)
        cout << " " ;
        cout << fWord[i].num << endl;
    }

    cout << sFile << "的单词总数为" << Sum << "个" << endl;
    cout << sFile << "的非单词总数为" << notWord << "个" << endl;
}

#endif //TEXTSEARCHING_COUNTING_H
