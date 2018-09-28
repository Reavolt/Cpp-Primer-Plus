//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#include <vector>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::ifstream myfile("Text.txt");

	if (!myfile.good())
	{
		std::cout << "Unable to open Text.txt" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::vector<std::string> wordlist;
	std::string word;
	while (myfile >> word)
	{
		wordlist.push_back(word);
	}
	myfile.close();

	long num = wordlist.size();

	std::srand(std::time(0));
	
	char play;
	std::cout << "Will you play a word game? <y/n> ";	// запуск игры в слова 
	std::cin >> play;
	play = std::tolower(play);
	
	while (play == 'y')
	{
		std::string target = wordlist[std::rand() % num];
		int length = target.length();
		std::string attempt(length, '-');
		std::string badchars;
		int guesses = 6;
		
		std::cout << "Guess my secret word. It has " << length;
		std::cout << " letters, and you guess\n";
		std::cout << "one letter at a time. You get " << guesses;
		std::cout << " wrong guesses.\n";
		std::cout << "Your word: " << attempt << std::endl;	// вывод слова 
		
		while (guesses > 0 && attempt != target)
		{
			char letter;
			std::cout << "Guess a letter: ";
			std::cin >> letter;
			
			if (badchars.find(letter) != std::string::npos
				|| attempt.find(letter) != std::string::npos)
			{
				std::cout << "You already guessed that. Try again.\n";
				continue;
			}
			
			int loc = target.find(letter);
			if (loc == std::string::npos)
			{
				std::cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter; // добавить к строке 
			}
			else
			{
				std::cout << "Good guess!\n";
				attempt[loc] = letter;
				// Проверить, не появляется ли буква еще раз 
				loc = target.find(letter, loc + 1);
				
				while (loc != std::string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			std::cout << "Your word: " << attempt << std::endl;
			
			if (attempt != target)
			{
				if (badchars.length() > 0)
				{
					std::cout << "Bad choices: " << badchars << std::endl;
				}
				std::cout << guesses << " bad guesses left\n";
			}
		}
		
		if (guesses > 0)
		{
			std::cout << "That's right!\n";
		}
		else
		{
			std::cout << "Sorry, the word is " << target << ".\n";
		}
		
		std::cout << "Will you play another? <y/n> ";
		std::cin >> play;
		play = std::tolower(play);
	}
	std::cout << "Bye\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------