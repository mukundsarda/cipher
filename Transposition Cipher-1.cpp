#include <iostream>
#include <string>
#include<stdio.h>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string text;
    int key,col,i,j;
    double l,x;
    int row;
    cout<<"enter text: ";
    getline(cin, text);
    cout<<"enter key: ";
    cin>>key;
    col=key;
    text.erase(remove(text.begin(), text.end(), ' '), text.end());
    l =text.length();
    x = l/col;
    x = ceil(x);
    row=int(x);
    int it=0;
    char m[row][col];
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            m[i][j]= text[it];
            it++;
        }
    }
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"----------ENCRYPTED ----------"<<endl;
    for(i=0; i<col; i++)
    {
        for(j=0; j<row; j++)
        {
            if (m[j][i]=='\0')
                break;
            cout<<m[j][i];
        }
    }
    cout<<endl<<"---- -----DECRYPTED ------- "<<endl;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if (m[i][j]=='\0')
                break;
            cout<<m[i][j];
        }
    }
    return 0;
}
