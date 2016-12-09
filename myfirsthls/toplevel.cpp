#include "toplevel.h"

int test(OrderLine orderLines[10])
{
#pragma HLS INTERFACE m_axi depth=1 port=orderLines

    int result = 0;
    for (int i = 0; i < 10; i++)
    {
#pragma HLS PIPELINE
        result += orderLines[i].unit_price.toInt() *
                  orderLines[i].amount.toInt();
    }
    return result;
}
