#include "HitStand.h"
#include <xmemory>
using namespace std;

int HitStand::Hit()
{
	return (1 + (rand() % 10));
}
