//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

const int SIZE = 2;
//-------------------------------------------------------------------------------------------------
struct Review 
{
	std::string title;
	int rating;
	int price;
};
//-------------------------------------------------------------------------------------------------
bool operator < (const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool sortByTitle(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool sortByRating(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool sortByPrice(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool FillReview(Review & rr);
void ShowReview(const std::shared_ptr<Review> & rr);
void print_menu();
//-------------------------------------------------------------------------------------------------
int main()
{
	// your code goes here
	std::vector<std::shared_ptr<Review> > books;
	Review temp;
	
	while (FillReview(temp))
	{
		std::shared_ptr<Review> t(new Review);
		t->title = temp.title;
		t->rating = temp.rating;
		t->price = temp.price;
		books.push_back(t);
	}
	print_menu();
	
	char select;
	while (std::cin >> select && select != 'q')
	{
		switch (select)
		{
		case 'f':
			std::cout << "Title reserve output:\nRating\tTitle\tPrice" << std::endl;
			for_each(books.rbegin(), books.rend(), ShowReview);
			print_menu();
			break;
		case 't':
			std::cout << "Sort by title:\nRating\tTitle\tPrice" << std::endl;
			sort(books.begin(), books.end(), sortByTitle);
			for_each(books.begin(), books.end(), ShowReview);
			print_menu();
			break;
		case 'r':
			std::cout << "Sort by rating:\nRating\tTitle\tPrice" << std::endl;
			sort(books.begin(), books.end(), sortByRating);
			for_each(books.begin(), books.end(), ShowReview);
			print_menu();
			break;
		case 'p':
			std::cout << "Sort by price:\nRating\tTitle\tPrice" << std::endl;
			sort(books.begin(), books.end(), sortByPrice);
			for_each(books.begin(), books.end(), ShowReview);
			print_menu();
			break;
		default:
			std::cout << "quit.";
			break;
		}
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
	if (r1->title < r2->title)
	{
		return true;
	}
	else 
	if (r1->title == r2->title && r1->rating < r2->rating)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
bool sortByTitle(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
	if (r1->title < r2->title)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
bool sortByRating(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
	if (r1->rating < r2->rating)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
bool sortByPrice(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
	if (r1->price < r2->price)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
bool FillReview(Review & rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	
	if (rr.title == "quit")
	{
		return false;
	}

	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	
	if (!std::cin)
	{
		return false;
	}

	std::cout << "Enter book price: ";
	std::cin >> rr.price;
	
	if (!std::cin)
	{
		return false;
	}

	// Избавиться от остальной части строки ввода 
	while (std::cin.get() != '\n')
	{
		continue;
	}
	return true;
}
//-------------------------------------------------------------------------------------------------
void ShowReview(const std::shared_ptr<Review> &rr)
{
	std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}
//-------------------------------------------------------------------------------------------------
void print_menu()
{
	std::cout << "Please select the sort:" << std::endl;
	std::cout << "t.sort by title       r.sort by rating" << std::endl;
	std::cout << "p.sort by price       f.sort by title reserve" << std::endl;
	std::cout << "q.quit" << std::endl;
}
//-------------------------------------------------------------------------------------------------