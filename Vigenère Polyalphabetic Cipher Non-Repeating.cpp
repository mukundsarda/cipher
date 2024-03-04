#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
string createKey(string);
class Vigenere
{
public:
    string key;
    Vigenere(string key)
    {
        for (int i = 0; i < key.size(); ++i)
        {
            if (key[i] >= 'A' && key[i] <= 'Z')
                this->key += key[i];
            else if (key[i] >= 'a' && key[i] <= 'z')
                this->key += key[i] + 'A' - 'a';
        }
    }
    string encrypt(string text)
    {
        string out;
        for (int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];
            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            out += (c + key[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % key.length();
        }
        return out;
    }
    string decrypt(string text)
    {
        string out;
        for (int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];
            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            out += (c - key[j] + 26) % 26 + 'A';
            j = (j + 1) % key.length();
        }
        return out;
    }
};
string createKey(string original)
{
    string key = "deceptive" + original; //27
    int it = 9;
    while(it > 0)
    {
        key.erase(key.length()-1);
        --it;
    }
    return key;
}
int main()
{
    string original =
        "wearediscoveredsaveyourself";
    string key;
    key = createKey(original);
    Vigenere cipher(key);
    string encrypted = cipher.encrypt(original);
    string decrypted = cipher.decrypt(encrypted);
    cout << original << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
}
