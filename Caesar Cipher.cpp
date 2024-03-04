#include <iostream>
using namespace std;
string encrypt(string text, int s)
{
	string result = "";
	for (int i = 0; i < text.length(); i++) {
		if (isupper(text[i]))
			result += char(int(text[i] + s - 65) % 26 + 65);
		else
			result += char(int(text[i] + s - 97) % 26 + 97);
	}
	return result;
}
string decrypt(string text, int s)
{
    s=26-s;
	string result = "";
	for (int i = 0; i < text.length(); i++) {
		if (isupper(text[i]))
			result += char(int(text[i] + s - 65) % 26 + 65);
		else
			result += char(int(text[i] + s - 97) % 26 + 97);
	}
	return result;
}
int main()
{
	string text = "CAESAR";
	int s = 4;
	cout << "Text : " << text;
	cout << "\nShift: " << s;
	string cipher=encrypt(text, s);
	cout << "\nEncrypted Message: " << cipher;
	cout << "\nDecrypted Message: " << decrypt(cipher, s);
	return 0;
}
