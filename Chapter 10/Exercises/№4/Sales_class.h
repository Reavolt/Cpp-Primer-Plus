#ifndef SALES_CLASS_H_
#define SALES_CLASS_H_

//-------------------------------------------------------------------------------------------------
namespace SALES
{
	static const int QUARTERS = 4;

	class Sales 
	{
	private:
		double sales[QUARTERS];
		double average;
		double max;
		double min;
		double find_avg(const double arr[], int size);
		double find_max(const double arr[], int size);
		double find_min(const double arr[], int size);
	public:
		Sales();
		Sales(const double arr[], const int n);
		~Sales();
		void showSales();
		void setSales();
	};
}
//-------------------------------------------------------------------------------------------------
#endif // SALES_CLASS_H_