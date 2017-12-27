//
// Created by Logan luo on 2017/10/27.
//

#ifndef TEXTSEARCHING_CREATETXT_H
#define TEXTSEARCHING_CREATETXT_H
#include <fstream>
#include <iostream>
#include <string>
void createFile(){
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ofstream;
    //文件流 创建文件
    string sFile;
    cout << "输入要建立的文件名:";
    cin >> sFile;
    ofstream outfile(sFile,ofstream::app);
    ofstream out(sFile);
    char ch='n';
    while (ch!='y') {
        string sText;
        cout << "请输入一行文本" << endl;
        getchar();
        getline(cin,sText);
        if (sText.size()>110){
            int i=0,temp=0;
            while (i<sText.size()){
                if (sText[i]==' ') {
                    temp++;
                    if (temp % 110 == 0 && temp!=0){//temp记录字节数 超过110换行
                        out << "\n";
                        i++;
                    }
                }
                out << sText[i];
                i++;
            }
        }
        else out << sText << "\n";
        //将读入的字符串输出到文件中
        cout << "结束输入吗？y or n:";
        cin >> ch;
        while (ch!='y' && ch!='n') 
        //如果输入有误 让用户重新输入
        {
            string s;
            getline(cin,s);
            cout << "输入格式错误!" << endl;
            cout << endl;
            cout << "结束输入吗？y or n:";
            cin >> ch;
        }
    }
    out.close();
    //建立文件完毕后 关闭文件
    cout << "建立文件结束!" << endl;

}
#endif //TEXTSEARCHING_CREATETXT_H
