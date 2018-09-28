//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()
#include <queue>

const int MIN_PER_HR = 60;
//-------------------------------------------------------------------------------------------------
class Customer
{
private:
	long arrive;        // время прибытия для клиента
	int processtime;    // время обработки для клиента
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
//-------------------------------------------------------------------------------------------------
// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
//-------------------------------------------------------------------------------------------------
bool newcustomer(double x); // есть ли новый клиент?
//-------------------------------------------------------------------------------------------------
int main()
{
	// Подготовка
	std::srand(std::time(0));    //  случайная инициализация из rand()

	std::cout << "Case Study: Bank of Heather Automatic Teller\n";
	std::cout << "Enter maximum size of queue: ";
	int qs = 0;
	std::cin >> qs;
	
	std::queue<Customer> line;         // очередь строк поддерживает до qs people

	std::cout << "Enter the number of simulation hours: ";
	int hours = 0;              // Моделирование часов
	std::cin >> hours;
	// Эмуляция будет запускать один цикл в минуту 
	long cyclelimit = MIN_PER_HR * hours; // количество циклов 

	std::cout << "Enter the average number of customers per hour: ";	// Ввод количества клиентов в час 
	double perhour = 0.0;         // среднее количество появлений за час 
	std::cin >> perhour;
	
	double min_per_cust = MIN_PER_HR / perhour; // среднее время между появлениями

	Customer temp;           // данные нового клиента 
	long turnaways = 0;      // не допущены в полную очередь
	long customers = 0;      // присоединены к очереди 
	long served = 0;         // обслужены во время эмуляции 
	long sum_line = 0;       // общая длина очереди 
	int wait_time = 0;       // время до освобождения банкомата 
	long line_wait = 0;      // общее время в очереди 

	// Запуск моделирования 
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust)) // есть подошедший клиент 
		{
			if (line.size() == (unsigned)qs)
			{
				turnaways++;
			}
			else
			{
				customers++;
				temp.set(cycle);    // cycle = время прибытия 
				line.push(temp);    // добавление новичка в очередь 
			}
		}
		if (wait_time <= 0 && !line.empty())
		{
			temp = line.front(); // обслуживание следующего клиента 
			line.pop();
			wait_time = temp.ptime(); // в течение wait_time минут 
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
		{
			wait_time--;
		}
		sum_line += line.size();
	}

	// Вывод результатов 
	if (customers > 0)
	{
		std::cout << "customers accepted: " << customers << std::endl;
		std::cout << "  customers served: " << served << std::endl;
		std::cout << "         turnaways: " << turnaways << std::endl;
		std::cout << "average queue size: ";
		std::cout.precision(2);
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::cout.setf(std::ios_base::showpoint);
		std::cout << (double)sum_line / cyclelimit << std::endl;
		std::cout << "average wait time: ";
		std::cout << (double)line_wait / served << " minutes\n";
	}
	else
	{
		std::cout << "No customers!\n";
	}
	std::cout << "Done!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
//-------------------------------------------------------------------------------------------------