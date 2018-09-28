#ifndef DMA_H_     
#define DMA_H_     
#include <iostream>
#include <cstring> 

//-------------------------------------------------------------------------------------------------
class abcDMA
{
private:
	char* label;
	int rating;
protected:
	const char* showLabel() const { return label; }
	int showRating() const { return rating; }
public:
	abcDMA(const char* l = "NULL", int r = 0);
	abcDMA(const abcDMA & rs);
	virtual void View() const = 0;
	virtual ~abcDMA();
	abcDMA & operator = (const abcDMA & rs);
	friend std::ostream & operator << (std::ostream & os, const abcDMA & rs);
};
//-------------------------------------------------------------------------------------------------
class baseDMA : public abcDMA
{
private:
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA & rs);
	virtual ~baseDMA();
	baseDMA & operator = (const baseDMA & rs);
	friend std::ostream & operator << (std::ostream & os, const baseDMA & rs);
	virtual void View() const;
};
//-------------------------------------------------------------------------------------------------
class lacksDMA : public abcDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char* с = "blank", const char* l = "null", int r = 0);
	friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
	virtual void View() const;
};
//-------------------------------------------------------------------------------------------------
class hasDMA : public abcDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char * l = "null", int r = 0);
	hasDMA(const hasDMA & hs);
	~hasDMA();
	hasDMA & operator = (const hasDMA & rs);
	friend std::ostream & operator << (std::ostream & os, const hasDMA & hs);
	virtual void View() const;
};
//-------------------------------------------------------------------------------------------------
#endif //DMA_H_