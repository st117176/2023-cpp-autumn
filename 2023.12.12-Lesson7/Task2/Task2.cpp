#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int strlen(char* str)
{
	int res = 0;
	while (str[++res] != 0);
	return res;
}

int strstr(char* str1, char* str2)
{
	if (str1 == str2 || *str2 == '\0')
	{
		return 0;
	}

	int i = 0;
	int j = 0;
	while (str2[i] != '\0')
	{
		if (str1[j] == '\0')
		{
			j = -1;
			break;
		}

		else if (str1[j + i] == str2[i])
		{
			i++;
		}
		else
		{
			j++;
			i = 0;
		}
	}

	return j;
}

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");
	char str1[255] = { 0 };
	fscanf(f, "%s", &str1);
	char str2[255] = { 0 };
	fscanf(f, "%s", &str2);
	fclose(f);

	int index = strstr(str1, str2);

	f = fopen("out.txt", "w");
	fprintf(f, "%d", index);
	fclose(f);

	return 0;
}