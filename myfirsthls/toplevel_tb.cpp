#include "toplevel.h"
#include <stdio.h>

int main()
{
    packed_decimal<6> values[10] = {packed_decimal<6>(1),
                                    packed_decimal<6>(2),
                                    packed_decimal<6>(3),
                                    packed_decimal<6>(4),
                                    packed_decimal<6>(5),
                                    packed_decimal<6>(6),
                                    packed_decimal<6>(7),
                                    packed_decimal<6>(8),
                                    packed_decimal<6>(9),
                                    packed_decimal<6>(10)};
    int result = test(values);
    printf("result =%d ", result);
    if (result != 55)
    {
        return 1;
    }
    return 0;
}
