#include <math.h>

#define climbStairs climb_stairs

// Never returns zero steps
// If n is even, then we have atleast 2 steps
// If n is odd, then we have atleast 1 step
//
// If n is even, then n / 2 tells us the least amount of steps needed
// to climb the stairs
// If n is odd, then n / 2 + 1 (Integer math) tells us the least amount
// of steps needed to climb the stairs
//
// If n is odd, then x = n / 2 + 1 (Integer math) and the least amount
// of steps needed to climb the stairs will have x distinct ways
// If n is even, then the least amount of steps needed to climb the
// stairs will have 1 distinct way
int climb_stairs(int n)
{
	int amt = 1;
	for (n -= 1;n > ceil(n / 2.0f); --n) amt += n;
	return amt + (n % 2 == 0) ? 1 : ceil(n / 2.0f);	
}
