#ifndef _ORDER_ENUMDEF_H_INCLUDED_
#define _ORDER_ENUMDEF_H_INCLUDED_

typedef enum 
{
    ORDER_EQ,
    ORDER_OPTN,
    ORDER_ADVANCE_EQ,
    ORDER_ADVANCE_OPTN,
    ORDER_SPREADS,
    ORDER_BUY_WRITES,
    ORDER_CONTINGENT,
    ORDER_ONE_CANCELS_ALL,
    ORDER_ONE_TRIGGERS_ALL,
    ORDER_ONE_TRIGGERS_OCO,
    ORDER_BRACKETED
}EViewOrderType; 

typedef enum 
{
    OPEN,
    EXECUTED,
    CANCELLED,
    CANCEL_REQUESTED,
    EXPIRED,
    REJECTED
}EOrderStatus; 

typedef enum 
{
    GOOD_UNTIL_CANCEL,
    GOOD_FOR_DAY,
    GOOD_TILL_DATE,
    IMMEDIATE_OR_CANCEL,
    FILL_OR_KILL
}EOrderTerm ;

typedef enum 
{
    ORDER_MARKET,
    ORDER_LIMIT,
    ORDER_STOP,
    ORDER_STOP_LIMIT,
    ORDER_TRAILING_STOP_CNST_BY_LOWER_TRIGGER,
    ORDER_UPPER_TRIGGER_BY_TRAILING_STOP_CNST,
    ORDER_TRAILING_STOP_PRCT_BY_LOWER_TRIGGER,
    ORDER_UPPER_TRIGGER_BY_TRAILING_STOP_PRCT,
    ORDER_TRAILING_STOP_CNST,
    ORDER_TRAILING_STOP_PRCT,
    ORDER_HIDDEN_STOP,
    ORDER_HIDDEN_STOP_BY_LOWER_TRIGGER,
    ORDER_UPPER_TRIGGER_BY_HIDDEN_STOP,
    ORDER_NET_DEBIT,
    ORDER_NET_CREDIT,
    ORDER_NET_EVEN,
    ORDER_MARKET_ON_OPEN,
    ORDER_MARKET_ON_CLOSE,
    ORDER_LIMIT_ON_OPEN,
    ORDER_LIMIT_ON_CLOSE
}EOrderPriceType;
	
typedef enum 
{
    ORDER_AUTO,
    ORDER_ATIN,
    ORDER_SELN,
    ORDER_MKXT,
    ORDER_REDI,
    ORDER_INCA,
    ORDER_ARCA,
    ORDER_ISLD,
    ORDER_BETA,
    ORDER_SOES,
    ORDER_ADP,
    ORDER_RTEX,
    ORDER_INST,
    ORDER_BRUT,
    ORDER_INET,
    ORDER_NSDQ,
    ORDER_NYSE,
    ORDER_AMEX,
    ORDER_BOX,
    ORDER_CBOE,
    ORDER_ISE,
    ORDER_NOM,
    ORDER_PHX
}EOrderRoutingDestination;

typedef enum 
{
    CONTINGENT_GTE,
    CONTINGENT_LTE
}EConditionType;

typedef enum 
{
    ASK,
    BID,
    LAST
}EConditionFollowPrice;

typedef enum 
{
    BUY,
    SELL,
    BUY_TO_COVER,
    SELL_SHORT,
    BUY_OPEN,
    SELL_OPEN,
    BUY_CLOSE,
    SELL_CLOSE
}EOrderAction;

typedef enum 
{
    ORDER_CALL,
    ORDER_PUT
}ECallOrPut;

typedef enum 
{
    EquityOrderAction_BUY,
    EquityOrderAction_SELL,
    EquityOrderAction_BUY_TO_COVER,
    EquityOrderAction_SELL_SHORT
}EEquityOrderAction;

typedef enum 
{
    EquityOrderRoutingDestination_AUTO,
    EquityOrderRoutingDestination_ARCA,
    EquityOrderRoutingDestination_NSDQ,
    EquityOrderRoutingDestination_NYSE
}EEquityOrderRoutingDestination;

typedef enum 
{
    EquityOrderTerm_GOOD_UNTIL_CANCEL,
    EquityOrderTerm_GOOD_FOR_DAY,
    EquityOrderTerm_IMMEDIATE_OR_CANCEL,
    EquityOrderTerm_FILL_OR_KILL
}EEquityOrderTerm;

typedef enum 
{
    EquityPriceType_MARKET,
    EquityPriceType_LIMIT,
    EquityPriceType_STOP,
    EquityPriceType_STOP_LIMIT,
    EquityPriceType_MARKET_ON_CLOSE
}EEquityPriceType;

typedef enum 
{
    REGULAR,
    EXTENDED
}EMarketSession;

typedef enum 
{
    ORDER_JAN,
    ORDER_FEB,
    ORDER_MAR,
    ORDER_APR,
    ORDER_MAY,
    ORDER_JUN,
    ORDER_JUL,
    ORDER_AUG,
    ORDER_SEP,
    ORDER_OCT,
    ORDER_NOV,
    ORDER_DEC
}EMonth;

typedef enum 
{
    OptionOrderAction_BUY_OPEN,
    OptionOrderAction_SELL_OPEN,
    OptionOrderAction_BUY_CLOSE,
    OptionOrderAction_SELL_CLOSE
}EOptionOrderAction;

typedef enum 
{
    OptionOrderRoutingDestination_AUTO,
    OptionOrderRoutingDestination_AMEX,
    OptionOrderRoutingDestination_BOX,
    OptionOrderRoutingDestination_CBOE,
    OptionOrderRoutingDestination_ISE,
    OptionOrderRoutingDestination_NOM,
    OptionOrderRoutingDestination_NYSE,
    OptionOrderRoutingDestination_PHX
}EOptionOrderRoutingDestination;

typedef enum 
{
    OptionOrderTerm_GOOD_UNTIL_CANCEL,
    OptionOrderTerm_GOOD_FOR_DAY,
    OptionOrderTerm_IMMEDIATE_OR_CANCEL,
	OptionOrderTerm_FILL_OR_KILL
}EOptionOrderTerm;

typedef enum 
{
    OptionPriceType_MARKET,
    OptionPriceType_LIMIT,
    OptionPriceType_STOP,
    OptionPriceType_STOP_LIMIT
}EOptionPriceType;


typedef enum 
{
    BASIC_EQUITY,
    BASIC_OPTION
}EOrderType;

#endif//_ORDER_ENUMDEF_H_INCLUDED_