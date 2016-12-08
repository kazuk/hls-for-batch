#include "toplevel.h"

int test( packed_decimal<6> values[10] )
{
#pragma HLS INTERFACE ap_memory port=values

	int result =0;
	for(int i=0;i<10;i++ ) {
#pragma HLS PIPELINE
		// HLS PIPELINE off : Latency 221  on : Latency 38
		result += values[i].toInt();
	}
	return result;
}
