#include "main.h"

int Question23(int argc, char* argv[])
{
	ARGS_CHECK(argc, 2);
	FILE* fp;
	char filebuf[1000] = { 0 };
	int ret, word, i;
	fp = fopen(argv[1], "rb");
	ERROR_CHECK(fp, NULL, "fopen");
	ret = fgets(filebuf, 1000, fp);
	ERROR_CHECK(ret, NULL, "fgets");
	word = 0;
	for (i = 0; i < 1000; i++)
	{
		if (!filebuf[i]) break;
		if (isalpha(filebuf[i]))
		{
			for (i += 1; i < 1000; i++)
			{
				if (isalpha(filebuf[i]))
				{
					continue;
				}
				else {
					break;
				}
			}
			word += 1;
		}
	}
	fclose(fp);
	puts(filebuf);
	printf("该文件包含的单词个数为%d个\n", word);
	return 0;
}