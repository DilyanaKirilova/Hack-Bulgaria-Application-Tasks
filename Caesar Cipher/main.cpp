#include<iostream>
using namespace std;

const int CAPACYTY = 100;
char* caesarEncrypt(char[CAPACYTY], int);
int main()
{
	char text[100];
	cout << "Enter text to be crypted: ";
	cin.getline(text, 100);
	
	
	int numShift;
	cout << "Enter number of shifts: ";
	cin>>numShift;

	char *p;
	p = caesarEncrypt(text, numShift);

	cout<<p<<endl;
	return 0;
}
char* caesarEncrypt(char arr[CAPACYTY], int num)
{
	for(int i = 0; arr[i] != '\0'; i++)
	{
		char currentLetter = arr[i];

		if(currentLetter >= 'a' && currentLetter <= 'z')
		{
		int letterNumber = currentLetter - 'a';
		int x = (letterNumber + num) % 26;
		arr[i] = (char)(x+97);
		}

		if(currentLetter >= 'A' && currentLetter <= 'Z')
		{
		int letterNumber = currentLetter - 'A';
		int x = (letterNumber + num) % 26;
		arr[i] = (char)(x + 65);
		}
	}
	return arr;
}