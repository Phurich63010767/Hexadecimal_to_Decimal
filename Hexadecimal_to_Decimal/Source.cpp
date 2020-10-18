#include<iostream>
using namespace std;

void convert(string x, int e, int i, int sum)
{
	int y;
	while (e >= 0)
	{
		char* p = &x[e];
		int pw = pow(16, i);
		if (*p >= 48 && *p <= 57)
		{
			y = *p - 48;
		}
		else if (*p >= 65 && *p <= 70)
		{
			y = *p - 55;
		}
		else if (*p >= 97 && *p <= 102)
		{
			y = *p - 87;
		}
		sum = sum + (y * pw);
		i++;
		e--;
	}
	cout << "Decimal = " << sum << endl;
}

int main()
{
START:
	string x;
	cout << "Enter characters: ";
	cin >> x;
	int s = x.size();
	int e = s - 1;
	int i = 0, c = 0;
	int sum = 0;

	while (c < s)
	{
		char* p = &x[c];
		if (*p < 48 || (*p > 57 && *p < 65) || (*p > 70 && *p < 97) || *p > 102)
		{
			cout << "Can enter only 0-1 and A-F." << endl;
			system("pause");
			system("CLS");
			goto START;
		}
		c++;
	}

	convert(x, e, i, sum);

	return 0;
}