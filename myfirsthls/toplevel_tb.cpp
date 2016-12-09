#include "toplevel.h"
#include <stdio.h>

int main()
{
    OrderLine orders[10] = {
    		OrderLine( 0,100,10 ),
    		OrderLine( 0,100,10 ),
    		OrderLine( 0,100,10 ),
    		OrderLine( 0,100,10 ),
    		OrderLine( 0,100,10 ),
    		OrderLine( 0,100,10 ),
    		OrderLine( 0,100,10 ),
    		OrderLine( 0,100,10 ),
    		OrderLine( 0,100,10 ),
    		OrderLine( 0,100,10 )
    };

    int result = test(orders);
    printf("result =%d ", result);
    if (result != 10000)
    {
        return 1;
    }
    return 0;
}
