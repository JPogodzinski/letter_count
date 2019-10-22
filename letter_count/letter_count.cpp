#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main()
{
	string plaintext;
	map <char, double> counter;
	ifstream plaintext_file;
	string name_of_file;
	string line;
	std::cout << "Podaj nazwe pliku do zakodowania" << endl;
	std::cin >> name_of_file;
	plaintext_file.open(name_of_file);
	if (plaintext_file.is_open())
	{
		while (getline(plaintext_file, line))
		{
			plaintext += line;
		}
		plaintext_file.close();
	}
	int length = plaintext.length();
	for (int i = 0; i < length; i++)
	{
		counter[plaintext[i]]++;
	}
	for (std::map<char, double>::iterator it = counter.begin(); it != counter.end(); ++it)
		it->second=it->second / length * 100;
	for (std::map<char, double>::iterator it = counter.begin(); it != counter.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';


}

