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
	 // случайная инициализация rand() лучше использовать #include <random>
	std::srand(std::time(0));

	// часы эмуляции
	int hours = 100; 
	// Эмуляция будет запускать один цикл в минуту 
	long cyclelimit = MIN_PER_HR * hours; // количество циклов 

	double perhour = 0.0;         // среднее количество появлений за час 
	double min_per_cust = 0.0;    // среднее время между появлениями 
	Item temp; 					  // данные нового клиента 

	long turnaways = 0;     // не допущены в полную очередь 
	long customers = 0;     // присоединены к очереди 
	long served = 0;        // обслужены во время эмуляции 
	long sum_line = 0;      // общая длина очереди 
	int wait_time = 0;      // время до освобождения банкомата 
	long line_wait = 0;     // общее время в очереди 
	int i = 100; 			// знаем, что 100 человек в час
							// среднее время ожидания будет более продолжительным
							// чем 1 минута на человека.
	do
	{
		perhour = i--;	// мы будем обновлять i для каждого цикла
		Queue line(hours * perhour);
		// мы устанавливаем размер очереди на общее число
		// клиенты, которых мы ожидаем увидеть в нашей симуляции
		// чтобы ни один из них не отворачивался.
		min_per_cust = MIN_PER_HR / perhour;
		turnaways = 0;	
		customers = 0;    
		served = 0;    
		sum_line = 0;  
		wait_time = 0;     
		line_wait = 0;    

		// запуск моделирования
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))  // иметь нового клиента
			{
				if (line.isfull())
				{
					turnaways++;
				}
				else
				{
					customers++;
					temp.set(cycle);    // cycle = время прибытия 
					line.enqueue(temp); // добавление новичка в очередь 
				}
			}
			
			if (wait_time == 0 && !line.isempty())
			{
				line.dequeue(temp);      // обслуживание следующего клиента 
				wait_time = temp.ptime(); // в течение wait_time минут 
				line_wait += cycle - temp.when();
				served++;
			}
			
			if (wait_time > 0)
			{
				wait_time--;
			}
			sum_line += line.queuecount();
		}
		line.~Queue();
	} 
	while ((double)line_wait / served > 1.0);
	i++; //учитываем декремент i в последнем цикле

	// Вывод результатов 
	if (customers > 0)
	{
		std::cout << "customers per hours: " << customers << std::endl;	// клиентов в час
		std::cout << "customers accepted: " << customers << std::endl;	// принято клиентов 
		std::cout << "  customers served: " << served << std::endl;		// обслужено клиентов 
		std::cout << "         turnaways: " << turnaways << std::endl;	// не принято клиентов 
		std::cout << "average queue size: ";							// средний размер очереди 
		std::cout.precision(2);
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::cout.setf(std::ios_base::showpoint);
		std::cout << (double)sum_line / cyclelimit << std::endl;
		std::cout << " average wait time: ";							// среднее время ожидания (минут) 
		std::cout << (double)line_wait / served << " minutes\n";
	}
	else
	{
		std::cout << "No customers!\n";	// клиентов нет 
	}
	std::cout << "Done!\n";

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
//------------------------------------------------------------------------------------------------