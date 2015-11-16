//www.reddit.com/r/dailyprogrammer Easy 11-13-2015
//Solution by Benjamin LaFeldt
//Typoglycemia.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>


using namespace std;


int main()
{
	string line;
	ifstream myfile("Input.txt");
	if (myfile.is_open())
	{
		while(getline(myfile, line))
		{
			string word;
			int r1 = 0;
			int r2 = 0;
			int size = line.size() - 1;
			while (r1 < size)
			{
				if ((bool)isalpha(line[r1]))
				{
					r2 = r1;
					if (r2 != line.size() - 1) {
						while ((bool)isalpha(line[r2]))
						{

							r2++;
						}
					}
					word = line.substr(r1, (r2-r1)); //good to here
					if (word.size() > 2) {
						vector<char> middle;
						for (int i = 1; i < word.size() - 1; i++)
						{
							middle.push_back(word[i]);
							word[i] = '0';
						}
						for (int j = 1; j < word.size() - 1; j++)
						{
							int r = rand() % middle.size();
							word[j] = middle[r];
							middle.erase(middle.begin() + r);
						}
					}
					for (int k = r1; k < r2; k++)
					{
						line[k] = word[k - r1];
					}
					r1 = r2;
				}
				else
				{
					r1++;
				}
			}
			cout << line << '\n';
		}
	}
    return 0;
}

