#include <iostream>
#include <string>
#include<stdio.h>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
void keymatrix_generation(string key,char km[5][5])
{
    int i,j;
    key += "abcdefghiklmnopqrstuvwxyz";
    string str="";
    for( string::iterator it = key.begin(); it != key.end(); it++ )
    {
        if( str.find( *it ) == -1 )
        {
            str += *it;
        }
    }
    copy( str.begin(), str.end(), &km[0][0] );
    cout<<"key matrix: "<<endl;
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            cout<<km[i][j]<<" ";
        }
        cout<<endl;
    }
}
void find_pos(char km[5][5],char a,char b,int arr[])
{
    int i,j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (km[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (km[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}
string encrypt(char km[5][5],string text,int tl)
{
    int i,arr[4];
    for (i = 0; i < tl; i += 2)
    {
        find_pos(km, text[i], text[i + 1], arr);
        if (arr[0] == arr[2])
        {
            text[i] = km[arr[0]][(arr[1] + 1)%5];
            text[i + 1] = km[arr[0]][(arr[3] + 1)%5];
        }
        else if (arr[1] == arr[3])
        {
            text[i] = km[(arr[0] + 1)%5][arr[1]];
            text[i + 1] = km[(arr[2] + 1)%5][arr[1]];
        }
        else
        {
            text[i] = km[arr[0]][arr[3]];
            text[i + 1] = km[arr[2]][arr[1]];
        }
    }
    return text;
}
void decrypt(string text, char km[5][5], int tl)
{
    int i, a[4];
    for (i = 0; i < tl; i += 2)
    {
        find_pos(km, text[i], text[i + 1], a);
        if (a[0] == a[2])
        {
            text[i] = km[a[0]][(a[1] - 1)%5];
            text[i + 1] = km[a[0]][(a[3] - 1)%5];
        }
        else if (a[1] == a[3])
        {
            text[i] = km[(a[0] - 1)%5][a[1]];
            text[i + 1] = km[(a[2] - 1)%5][a[1]];
        }
        else
        {
            text[i] = km[a[0]][a[3]];
            text[i + 1] = km[a[2]][a[1]];
        }
    }
    cout<<"deciphered text: "<<text<<endl;
}
void play(string key,string text,int tl)
{
    char km[5][5];
    string v;
    keymatrix_generation(key,km);
    v=encrypt(km,text, tl);
    cout<<"cipher text: "<<v<<endl;
    decrypt(v,km,tl);
}
int main()
{
    string text, key;
    int tl,kl;
    cout<<"enter plain text: ";
    getline(cin, text);
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    text.erase(remove(text.begin(), text.end(), ' '), text.end());
    tl=text.length();
    if (tl%2!=0)
    {
        text[tl++]='z';
        text[tl]='\0';
    }
    cout<<"enter key: ";
    getline(cin, key);
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    kl =key.length();
    play(key,text, tl);
    return 0;
}
