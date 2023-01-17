#include <iostream>
#include <cstring>
using namespace std;

int main() {
	const unsigned int ALPHABET_SIZE = 26;
	unsigned long long num = 0;
	long long arrChars[ALPHABET_SIZE];
	char* str1;
	char* str2;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		arrChars[i] = 0;

	cin >> num;
	if (num == 0)
	{
		cout << "yes" << endl;
		return 0;
	}

	str1 = new char[num + 1];
	str2 = new char[num + 1];

	cin.ignore();
	cin.getline(str1, num + 1);
	cin.getline(str2, num + 1);

	unsigned long long len1 = strlen(str1);
	unsigned long long len2 = strlen(str2);

	for (long long i = 0; i < len1; i++)
	{
		arrChars[(int)(str1[i] - 'a')]++;
	}

	for (long long i = 0; i < len2; i++)
	{
		arrChars[(int)(str2[i] - 'a')]--;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (arrChars[i] != 0)
		{
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes";

	delete[] str1;
	delete[] str2;
	return 0;
}
