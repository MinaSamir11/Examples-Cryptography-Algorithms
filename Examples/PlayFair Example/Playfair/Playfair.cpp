// Playfair.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


int main()
{
	char table[5][5];
	int count1 = 0, count2 = 0, saved[26], count_saved = 0, number = 0;

	char b;
	char sen[37];
	cout << "Enter Key char max use (_) End with (.)\n " << endl;
	for (int i = 0; i < 37; i++)
	{
		cin >> sen[i];
		if (sen[i] == 46)
			break;
		if (sen[i] == 95)
		{
			sen[i] = sen[i];
			number++;

		}
		else {
			sen[i] = sen[i];
			number++;
		}
	}

	for (int w = 0; w < number; w++)
	{

		for (int a = 97; a <= 122; a++)
		{

			b = a;
			if (sen[w] == b)
			{
				for (int x = 0; x <= count_saved; x++)
				{

					if (saved[x] == a)
					{

						break;
					}

					if (saved[x] == 105 && a == 106)
					{

						break;
					}
					else if (saved[x] == 106 && a == 105)
					{

						break;

					}
					else if (count_saved == x)
					{



						table[count1][count2] = sen[w];
						a = sen[w];
						saved[count_saved] = a;
						cout << "a = " << a << " saved " << saved[count_saved] << endl;
						if (count2 >= 4)
						{
							count1++;
							count2 = 0;
						}
						else
						{
							count2++;
						}
						count_saved++;
						break;
					}


				}
				break;
			}

		}
		if (w == (number - 1))
		{
			for (int a = 97; a <= 122; a++)
			{
				for (int x = 0; x <= count_saved; x++)
				{

					if (saved[x] == a)
					{
						break;
					}
					if (saved[x] == 105 && a == 106)
					{
						break;
					}
					else if (saved[x] == 106 && a == 105)
					{

						break;

					}
					else if (count_saved == x)
					{


						b = a;
						saved[count_saved] = a;
						table[count1][count2] = b;

						if (count2 >= 4)
						{
							count1++;
							count2 = 0;
						}
						else
						{
							count2++;
						}
						count_saved++;
						break;
					}


				}
			}
		}
	}
	for (int l = 0; l < 5; l++)
	{
		for (int k = 0; k < 5; k++)
		{
			cout << "\n Table index " << l << "Index " << k << endl;
			cout << table[l][k];
		}

	}

	number = 0;
	

	cout << "Enter Plan text char max use (_) End with (.)\n " << endl;
	for (int i = 0; i < 37; i++)
	{
		cin >> sen[i];
		if (sen[i] == 46)
			break;
		if (sen[i] == 95)
		{
			sen[i] = sen[i];
			number++;

		}
		else {
			sen[i] = sen[i];
			number++;
		}
	}

	for (int x =0; ; x+2) 
	{
		count1 = 0;
		count2 = 0;
		if (number%2==0)
		{
			for (;;)       ////////   to determine condtion 
			{
				if (table[count1][count2] == sen[x])
				{
					int countterr1 = count1;
					int countterr2 = 0;
					for (;;)     //// case of the condition 1 
					{
						cout << "flag 0000 " << endl;
						if (table[count1][countterr2] == sen[x + 1] && count1==countterr1)
						{
							cout << "flag saved -- counterr1 & count 1 " <<countterr1<< "  "<< count1  << endl;

							sen[x] = table[count1][count2+1];
							if (countterr2 == 4) {

								sen[x + 1] = table[count1][countterr2 -4];
								break;
							}
							else
							{
								sen[x + 1] = table[count1][countterr2 + 1];
								break;
							}
						}
					
						else
						{
							if (countterr2 <= 4 )
							{
								countterr2++;
							}
							else
							{

								countterr1++;
								countterr2 = 0;
							}
							
						}
					}
					for (int i = 0; i < number; i++)
					{
						cout << sen[i] << endl;
					}
					return 1;
				}
				else
				{
					if (count2 >= 4)
					{
						count1++;
						count2 = 0;
					}
					else
					{
						count2++;
					}
				}

			}
		}
		else
		{

			sen[number + 1] = 'x';
			number++;
			
		}
	}

	
}
