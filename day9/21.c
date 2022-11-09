#include "main.h"

int Question21()
{
	int year, mon, day, hours, minutes, seconds;
	int monArr[12] = { 31,30, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, };
	scanf("%d%d%d%d%d%d", &year, &mon, &day, &hours, &minutes, &seconds);
	seconds += 1;
	if (seconds >= 60) {
		seconds %= 60;
		minutes++;
		if (minutes >= 60)
		{
			minutes %= 60;
			hours++;
			if (hours >= 24)
			{
				hours %= 24;
				day++;
			}
		}
	}
	return 0;
}