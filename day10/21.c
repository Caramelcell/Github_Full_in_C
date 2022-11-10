#include "main.h"

int Question21()
{
	int year, mon, day, hours, minutes, seconds;
	int monArr[12] = { 31,30 , 31, 30, 31, 30, 31, 31, 30, 31, 30,31 };
	scanf("%d%d%d%d%d%d", &year, &mon, &day, &hours, &minutes, &seconds);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) { monArr[1] -= 1; }
	seconds += 1;
	if (seconds >= 60) {
		seconds -= 60;
		minutes++;
		if (minutes >= 60)
		{
			minutes -= 60;
			hours++;
			if (hours >= 24)
			{
				hours -= 24;
				day++;
				if (day > monArr[mon - 1])
				{
					day -= monArr[mon - 1];
					mon++;
					if (mon > 12)
					{
						mon -= 12;
						year++;
					}
				}
			}
		}
	}
	printf("下一秒是%d年%02d月%02d日%02d时%02d分%02d秒\n", year, mon, day, hours, minutes, seconds);
	return 0;
}