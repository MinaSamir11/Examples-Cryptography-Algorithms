// Vinigere Cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<string.h>
using namespace std; 

int main()
{
	char key[5] = { 's','p','i','c','e' };
	char sen[15];


	int counter = 0;
	cout << "\n\tEnter sentence 15 char max use (_) End with (.)\n";

	for (int i = 0; i <= 15; i++)
	{
		cin >> sen[i];
		if (sen[i] == 46)
			break;
		if (sen[i] == 95)
			sen[i] = sen[i];
		else {
			sen[i] = sen[i];
			counter++;
		}
	}
	int keyy = 0;
	int count = 0;
	for (int i = 0; i < counter; i++)
	{
		int Character = sen[i];
		Character = Character - 97;  //diffrence betwwen A and  input character

		if (count > 4)
		{
			count = 0;
		}
		keyy = key[count];
		keyy = keyy + Character;
		if (keyy > 122)
		{
			keyy = (keyy % 122) + 96;
		}
		sen[i] = keyy;
		count++;
	}
	cout << "Encryption is : ";
	for (int i = 0; i < counter; i++)
	{
		cout << sen[i];
	}

	count = 0;
	keyy = 0;
	int CountChar = 0;
	for (int i = 0; i < counter; i++)
	{
		int Chara = sen[i];
		//diffrence betwwen A and  input character
		keyy = key[count];
		count++;
		if (count > 4)
		{
			count = 0;
		}

		for (; ; )
		{
			if (keyy == Chara)
			{
				break;
			}
			CountChar++;
			keyy++;

			if (keyy > 122)
			{
				keyy = (keyy % 122) + 96;
			}
		 	
		}
		
		sen[i] = 97+ CountChar;
		CountChar = 0;
		
	}
	cout << "\nDecrytion is :  ";
	for (int i = 0; i < counter; i++)
	{
		cout << sen[i];
	}

	

}




	






