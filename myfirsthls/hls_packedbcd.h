#pragma once

// hls_packedbcd.h
//
// header for packed binary coded decimal (packed BCD)
//
// using namespace hlspackedbcd;
//
// packed_decimal<4>( 100 )
//
//   initialize 4 bytes of packed decimal
//    contains bytes : 0x00 0x00 0x10 0x0c
//
// if you include guard by including source
//
// #ifndef HLS_PACKEDBCD_H
// #include "hls_packedbcd.h"
// #endif // not defined HLS_PACKEDBCD_H
//
#define HLS_PACKEDBCD_H

namespace hlspackedbcd
{
template <int bytelen>
class packed_decimal
{
  private:
    char bytes[bytelen];

  public:
    packed_decimal() : packed_decimal(0)
    {
    }

    template <int x>
    packed_decimal(packed_decimal<x> other)
    {
        for (int i = bytelen - 1, j = x - 1; i >= 0; i--, j--)
        {
            if (i >= 0 && j >= 0)
            {
                bytes[i] = other.bytes[j];
            }
            else
            {
                if (i >= 0)
                {
                    bytes[i] = 0;
                }
            }
        }
    }

    packed_decimal(int value)
    {
        bool minus = false;
        if (value < 0)
        {
            value = -value;
            minus = true;
        }

        for (int i = bytelen - 1; i >= 0; i--)
        {
            if (i == bytelen - 1)
            {
                bytes[i] = (value % 10) << 4 | (minus ? 0x0d : 0x0c);
                value /= 10;
            }
            else
            {
                bytes[i] = (((value / 10) % 10) << 4) | value % 10;
                value /= 100;
            }
        }
    }

    inline int toInt()
    {
        int result = 0;
        char current = 0;

        for (int i = 0; i < bytelen; i++)
        {
            current = bytes[i];

            if (i == bytelen - 1)
            {
                result *= 10;
                result += (current >> 4) & 0x0f;
                if ((current & 0x0f) == 0x0d)
                {
                    result -= result;
                }
            }
            else
            {
                result *= 100;
                result += ((current >> 4) & 0x0f) * 10 + (current & 0x0f);
            }
        }
        return result;
    }
};
}
