#include "../sse.hpp"int main(){	float x = 23.45, y = 45.67, z = 67.8, f = 78.90078 ;	sse2 test1(x, y, z, f), test2(x+y, x-y, f, z);	sse2 test3 = test1 + test2 ;	sse2 test4 = test3 * test2 ; 	return 0; } 