//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <ctime> // для time() 
#include "queue.h" 

const int MIN_PER_HR = 60;
//-------------------------------------------------------------------------------------------------
bool newcustomer(double x); // появился ли новый клиент? 
//-------------------------------------------------------------------------------------------------
int main()
{
	std::srand(std::time(0));    // случайная инициализация rand() 

	int hours = 100; // часы эмуляции 
	// Эмуляция будет запускать один цикл в минуту 
	long cyclelimit = MIN_PER_HR * hours; // количество циклов 

	double perhour = 0.0;         // среднее количество появлений за час 
	double min_per_cust = 0.0 ;   // среднее время между появлениями 
	Item temp; 					  // данные нового клиента 

	long turnawaysL1 = 0;     // не допущены в полную очередь 
	long customersL1 = 0;     // присоединены к очереди 
	long servedL1 = 0;        // обслужены во время эмуляции 
	long sum_lineL1 = 0;      // общая длина очереди 
	int wait_timeL1 = 0;      // время до освобождения банкомата 
	long line_waitL1 = 0;     // общее время в очереди 

	long turnawaysL2 = 0;     // не допущены в полную очередь 
	long customersL2 = 0;     // присоединены к очереди 
	long servedL2 = 0;        // обслужены во время эмуляции 
	long sum_lineL2 = 0;      // общая длина очереди 
	int wait_timeL2 = 0;      // время до освобождения банкомата 
	long line_waitL2 = 0;     // общее время в очереди 

	double average_wait;
	int i = 100; 	// знаем, что 100 человек в час
					// среднее время ожидания будет более продолжительным
					// чем 1 минута на человека.

	do
	{
		perhour = i--;	// мы будем обновлять i для каждого цикла
		Queue line1(hours * perhour / 2);
		Queue line2(hours * perhour / 2);
		// мы устанавливаем размер очереди на общее число
		// клиенты, которых мы ожидаем увидеть в нашей симуляции
		// чтобы ни один из них не отворачивался.
		min_per_cust = MIN_PER_HR / perhour;
		turnawaysL1 = turnawaysL2 = 0;
		customersL1 = customersL2 = 0;
		servedL1 = servedL2 = 0;
		sum_lineL1 = sum_lineL2 = 0;
		wait_timeL1 = wait_timeL2 = 0;
		line_waitL1 = line_waitL2 = 0;
		
		// запуск моделирования
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))  // иметь нового клиента
			{
				if (line1.queuecount() <= line2.queuecount())
				{
					if (line1.isfull())
					{
						turnawaysL1++;
					}
					else
					{
						customersL1++;
						temp.set(cycle);    // cycle = time of arrival
						line1.enqueue(temp); // add newcomer to line
					}
				}
				else
				{
					if (line2.isfull())
					{
						turnawaysL2++;
					}
					else
					{
						customersL2++;
						temp.set(cycle);    // cycle = time of arrival
						line2.enqueue(temp); // add newcomer to line
					}
				}
			}
			if (wait_timeL1 == 0 && !line1.isempty())
			{
				line1.dequeue(temp);      // attend next customer
				wait_timeL1 = temp.ptime(); // for wait_time minutes
				line_waitL1 += cycle - temp.when();
				servedL1++;
			}
			
			if (wait_timeL2 == 0 && !line2.isempty())
			{
				line2.dequeue(temp);      // attend next customer
				wait_timeL2 = temp.ptime(); // for wait_time minutes
				line_waitL2 += cycle - temp.when();
				servedL2++;
			}
			
			if (wait_timeL1 > 0)
			{
				wait_timeL1--;
			}
			
			if (wait_timeL2 > 0)
			{
				wait_timeL2--;
			}
			sum_lineL1 += line1.queuecount();
			sum_lineL2 += line2.queuecount();
		}
		line1.~Queue();
		line2.~Queue();
		average_wait = double(line_waitL1 + line_waitL2) / (servedL1 + servedL2);
	} 
	while (average_wait > 1.0);
	i++; // account for decrement of i on last loop

	// Вывод результатов 
	if (customersL1 + customersL2 > 0)
	{
		std::cout << "customers per hour: " << i << std::endl;
		std::cout << "customers accepted: " << customersL1 + customersL2 << std::endl;
		std::cout << " customers served: " << servedL1 + servedL2 << std::endl;
		std::cout << " turnaways: " << turnawaysL1 + turnawaysL2 << std::endl;
		std::cout << "average queue size: ";
		std::cout.precision(2);
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::cout.setf(std::ios_base::showpoint);
		std::cout << (double)(sum_lineL1*sum_lineL1 + sum_lineL2*sum_lineL2) / 
		(cyclelimit * (sum_lineL1 + sum_lineL2)) << std::endl;
		std::cout << " average wait time: ";
		std::cout << average_wait << " minutes\n";
	}
	else
	{
		std::cout << "No customers!\n";
	}

	std::cout << "We see that the average wait time is approximately" << std::endl;
	std::cout << "one minute when there are " << i;
	std::cout << " customers per minute." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
// x = среднее время в минутах между клиентами 
// возвращается значение true, если в эту минуту появляется клиент 
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
//-------------------------------------------------------------------------------------------------