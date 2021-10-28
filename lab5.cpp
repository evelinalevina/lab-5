#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	int n;
	std::cout<<"Введите количество символов: ";
	std::cin >> n;
	char stroka[100];
	for ( int i = 0; i < n; i++)
		std::cin>>stroka[i];
	for (int i = 0; i < strlen(stroka); i++)
	{
		if (stroka[i] > 'а' && stroka[i] < 'я' && stroka[i]!= 'е' && stroka[i] != 'и' && stroka[i] != 'ы' && stroka[i] != 'о' && stroka[i] != 'у' && stroka[i] != 'ю' && stroka[i] != 'э' && stroka[i] != 'ё')
			stroka[i] -= 32;
	}
	std::cout<<"Результат: "<<std::endl;
	for (int i = 0; i < n; i++)
		std::cout<<stroka[i] << " ";
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);  
	int n;
	char b1, b2;
	std::cout << "Введите 2 русских буквы: " << std::endl;
	std::cin >> b1 >> b2;
	std::cout << "Введите n: " << std::endl;
	std::cin >> n;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	std::string words[5000];
	int size = 0;
	while (!in.eof())
	{
		std::string word;
		in >> word;
		
		bool consistA = false;
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == b1)
				consistA = true;
			if (word[i] == b2)
				consistA = true;
		}
				
		bool isInWords=true;
		if (consistA)
		{
			for (int i = 0; i < size - 1; i++)
					if (words[i] == word)
						isInWords = false;			
			if (isInWords)
			{
				words[size] = word;
				size++;				
			}			
		}		
	}	
	for (int i = 0; i < size-1; i++)
		for (int j = i+1; j < size; j++)
			if (words[i].length() > words[j].length())
			{
				std::swap(words[i], words[j]);
			}
	for (int i = 0; i < n; i++)
		out << words[i] << " ";
}