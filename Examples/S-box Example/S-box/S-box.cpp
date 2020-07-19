// S-box.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int Bin_to_Dec[8], K_K = 0;;
	int v;
	int flag = 0;
	int binar[8];
	int number = 0;
	char sen[37];
	int table[8][5] = { {0,0,0,1,1},{0,0,1,0,1},{0,1,0,0,0},{0,1,1,1,0},{1,0,0,0,1},{1,0,1,0,0},{1,1,0,1,1},{1,1,1,1,0}};
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
	v = sen[0];

	for (int i = 0; i < 8; i++)
	{
		binar[i] = v % 2;
		v = v / 2;

	}


	for (int i = 7; i >= 0; i--)
	{
		cout << binar[i];
	}

	int key[3];
	cout << " \n Enter Key 3 number" << endl;
	for (int i = 0; i < 3; i++)
		cin >> key[i];

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	loop:
	int binarr[4];
	int Count=0;
	int o = 7 , condition = 4;
	if (flag == 1)
	{
		o = 3;
		condition = 0;
	}
	for ( ; o >= condition; o--)                     // copy binary to anthor variable
	{
		binarr[Count] = binar[o];
		Count++;
		
	}

	int counter = 2;   // inslalzie to x3
	int T1_T2[3];
	for (int i = 0; i < 3; i++)
	{

		if (binarr[counter] == key[i])           //t1 t2 = S ( x3 x4 x3 exclusive or k1 k2 k3 )

		{
			T1_T2[i] = 0;
		}
		else {
			T1_T2[i] = 1;
		}

		if(i==0)
		  counter++;
		if (i == 1)
			counter--;
	}


	cout << " \n T1_T2 Before Table " << endl;
	for (int i = 0; i <3; i++)
	{
		cout << T1_T2[i];
	}

	
	counter = 0;
	
	for (int i = 0; i < 8; i++)         // search in the table for T1 T2
	{
		for (int y = 0; y < 3; y++)
		{
			if (y == 0)
			{
				
				if (table[i][y] == T1_T2[counter] && table[i][y+1] == T1_T2[counter+1] && table[i][y+2] == T1_T2[counter+2])
				{
					
					T1_T2[y] = table[i][y + 3];
					T1_T2[y+1] = table[i][y + 4];
					
					i = 7;
					break;
				}
			}

			else
			{
				break;
			}
		}
	}
	cout << " \n T1_T2 From Table " << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << T1_T2[i];
	}
	

	int U1_U2[2];

	
	for (int i = 0; i < 2; i++)     //   u1 u2 = x1 x2 exclusive or t1 t2

	{
	
			if (binarr[i] == T1_T2[i])
			{
				U1_U2[i] = 0;
			}
		
			else
			{
				U1_U2[i] = 1;
			}
			
	}
	cout << " \n U1_U2 " << endl;
	for (int i = 0; i < 2 ; i++)
	{
		cout << U1_U2[i];
	}


	
	int E[4];
	cout << "\n E" << endl;
	for (int i = 0; i < 4; i++)        //  E ( x1 x2 x3 x4 , k1 k2 k3 ) = x3 x4 u1 u2   // combine x3 x4 with U1 U2

	{
		if (i == 0 || i == 1)
		{
			E[i] = binarr[i+2];
			
		}

		else
		{
			E[i] = U1_U2[i - 2];
		}
	}

	for (int l = 0; l < 4; l++)
	{
		Bin_to_Dec[K_K] = E[l];
		K_K++;
	}


	for (int i = 0; i < 4; i++)
	{
		cout << E[i];
		
	}
	cout << endl;

	cout << "///////////////////////////////////////////////" << endl;
	flag++;
	if (flag == 1)
	{
		goto loop;
	}
	 
	int temp=0 , values =256;
	for (int l = 0; l < 8; l++)
	{
		cout << Bin_to_Dec[l];
		values = values / 2;
		temp = temp + (Bin_to_Dec[l] * values);
	}
	cout << "\n cipher Char of  "  << sen[0] <<" is = " <<temp << endl;
}
