// Ceasar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;
int main()
{

	int key = 3;
	char sen[15];

	cout << "\n\tEnter sentence 15 char max use (_) End with (.)\n";

	for (int i = 0; i <= 15; i++)
	{
		cin >> sen[i];
		if (sen[i] == 46)
			break;
		if (sen[i] == 95)
			sen[i] = sen[i];
		else
			sen[i] = (((sen[i] - 96 + key) % 26) + 96);
	}
	cout << "Engyrpted word : ";
	for (int i = 0; i <= 15; i++)
	{
		cout << sen[i];
	}
	cout << endl;
	for (int i = 0; i < 15; i++)
	{
		if (sen[i] == 46)
		{
			sen[i] = sen[i];
			cout << sen[i];
			break;
		}
		if (sen[i] == 95)
			sen[i] = sen[i];
		else
			if (((sen[i] - 96 - key) % 26) == 0)
				sen[i] = (((sen[i] - 96 - key) % 26) + 26 + 96);
			else
				sen[i] = (((sen[i] - 96 - key) % 26) + 96);
		cout << sen[i];
	}
	cout << endl;
}

