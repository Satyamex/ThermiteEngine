#include <core/_time.h>
#include <pyb>

namespace thermite::time
{
	double getTime()
	{
		return time_gettime();
	}

	double getDeltaTime()
	{
		return time_getdeltatime();
	}
}