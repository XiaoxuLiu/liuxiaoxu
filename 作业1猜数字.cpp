//
//  main.cpp
//  猜数字
//
//  Created by 刘晓旭 on 15/3/25.
//  Copyright (c) 2015年 刘晓旭. All rights reserved.
//

#include<stdlib.h>
#include<time.h>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
int main()
{
    //用户选择是否进行游戏
    int total_times = 0, win_times = 0, lose_times = 0;
    char CHOICE;
    ++ total_times;
    cout<<"请选择是否进行游戏(Y/N)"<<endl;
    cin>>CHOICE;
    while (CHOICE == 'Y')
    {
        //产生三个不同的10以内的随机数
        int num1,num2,num3,result,num,c1,c2,c3,i = 1,count1 = 0,count2 = 0,op;
        srand((unsigned)time(NULL));
        num1 = rand() % 10;
        num2 = rand() % 10;
        num3 = rand() % 10;
        //检验是否有重复数字
        op = (num1 - num2) * (num1 - num3) * (num2 - num3);
        //若有重复数字，则重新产生随机数
        while(op == 0)
        {
            srand((unsigned)time(NULL));
            num1 = rand() % 10;
            num2 = rand() % 10;
            num3 = rand() % 10;
            op=(num1 - num2) * (num1 - num3) * (num2 - num3);
        }
        //得到电脑生成的结果
        result = 100 * num1 + 10 * num2 + 1 * num3;
        while(i <= 7)
        {
            //用户输入
            cout<<"请输入您猜测的数字："<<endl;
            cin>>num;
            c1 = num / 100;
            c2 = num / 10 - 10 * c1;
            c3 = num - 100 * c1 - 10 * c2;
            if(c1 == num1)
                ++count1;
            if(c2 == num2)
                ++count1;
            if(c3 == num3)
                ++count1;
            if(count1 == 3)
            {
                cout<<"恭喜您，猜对了！"<<endl;
                ++win_times;
                break;
            }
            else
            {
                if(c1 == num2 || c1 == num3)
                    ++count2;
                if(c2 == num1 || c2 == num3)
                    ++count2;
                if(c3 == num2 || c3 == num1)
                    ++count2;
                cout<<count1<<"A"<<count2<<"B"<<endl;
            }
            count1 = 0;
            count2 = 0;
            ++i;
            if(i == 8)
            {
                cout<<"抱歉，您未能在规定的次数内猜中，答案是"<<result<<endl;
                ++lose_times;
                break;
            }
        }
    cout<<"请选择是否进行游戏(Y/N)"<<endl;
    cin>>CHOICE;
    }
    while (CHOICE == 'N')
    {
        cout<<"你一共玩了"<<total_times<<"局,"<<"赢了"<<win_times<<"局，"<<"输了"<<lose_times<<"局。"<<endl;
    }
    
    return 0;
}















