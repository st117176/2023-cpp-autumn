#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int strlen(char* str)
{
	int res = 0;
	while (str[++res] != 0);
	return res;
}

char* strcat(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len2 + 1; i++)
	{
		str1[len1] = str2[i];
		len1++;
	}

	return str1;
}

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");
	char str1[255] = { 0 };
	fscanf(f, "%s", &str1);
	char str2[255] = { 0 };
	fscanf(f, "%s", &str2);
	fclose(f);

	char* newstr = strcat(str1, str2);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", newstr);
	fclose(f);

	return 0;
}