#ifndef _ENUMDEF_H_INCLUDED_
#define _ENUMDEF_H_INCLUDED_

typedef enum 
{
	Callput,
	Call,
	Put
}EOptionType;

typedef enum 
{
	MONTH, 
	STRIKE
}EPriceType;

typedef enum 
{
	EQ_Type,
	MF_Type
}ESecurityType;

typedef enum 
{
	JANUARY = 1, 
	FEBRUARY, 
	MARCH, 
	APRIL, 
	MAY, 
	JUNE, 
	JULY, 
	AUGUST, 
	SEPTEMBER, 
	OCTOBER, 
	NOVEMBER, 
	DECEMBER
}EMonthType; 



typedef enum {
	CALLONLY,
	PUTONLY,
	SPREADS,
	CALLPUT
}EPairType;


typedef enum 
{
	ALL,
    FUNDAMENTAL,
    INTRADAY,
    OPTIONS,
    WEEK52
}EDetailFlag;
#endif//_ENUMDEF_H_INCLUDED_