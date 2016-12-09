#include <hls_stream.h>

#ifndef HLS_PACKEDBCD_H
#include "hls_packedbcd.h"
#endif // not defined HLS_PACKEDBCD_H
using namespace hlspackedbcd;

struct OrderLine
{
    int itemId;
    packed_decimal<6> unit_price;
    packed_decimal<4> amount;

    OrderLine( int itemId, int unit_price, int amount ):
    	itemId(itemId), unit_price(unit_price), amount(amount)
    {
    }
};

int test(OrderLine orderLines[10]);
