#include <core/_time.h>

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