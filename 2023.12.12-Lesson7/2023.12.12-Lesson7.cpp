#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

#include<cstring>
#include<string>

void CountSize(char* filename, int& lines, int& maxLine)
{
	FILE* file = fopen(filename, "r");

	int currentLen = 0;
	while (!feof(file))
	{
		char c = 0;
		fscanf_s(file, "%c", &c);
		if (c == '\n')
		{
			lines++;
			currentLen = 0;
		}
		else
		{
			currentLen++;
		}
		maxLine = (maxLine > currentLen ? maxLine : currentLen);
	}
	lines++;
	fclose(file);
}

int StrLen(char* str)
{
	int res = 0;
	while (str[res++] != '\0');
	return res;
}

void ReadLines(char* filename, char** lines, int maxlen)
{
	FILE* file = fopen(filename, "r");

	int ind = 0;
	while (!feof(file))
	{
		fgets(lines[ind], maxlen, file);
		ind++;
	}

	fclose(file);
}

int main(int argc, char** argv)
{
	int w = 0;
	int h = 0;
	char filename[255];
	strcpy(filename, "in.txt");
	CountSize(filename, h, w);
	char** lines = (char**)malloc(sizeof(char*) * h);
	for (int i = 0; i < h; ++i)
	{
		lines[i] = (char*)malloc(sizeof(char) * w);
	}
	ReadLines(filename, lines, w);


	for (int i = 0; i < h; ++i)
	{
		free(lines[i]);
	}
	free(lines);
	return 0;
}

char* strcat(char* str1, char* str2)
{
	char* ptr = str1;
	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*str2 != '\0')
	{
		*ptr = *str2;
		ptr++;
		str2++;
	}
	*ptr = '\0';
	return str1;
}

int StrCmp(char* str1, char* str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	if (*str1 > *str2)
	{
		return 1;
	}
	else if (*str1 < *str2)
	{
		return -1;
	}

	return 0;
}

int StrStr(const char* str, const char* substr)
{
	int str_len = strlen(str);
	int substr_len = strlen(substr);

	for (int i = 0; i <= str_len - substr_len; i++)
	{
		int j = 0;
		while (j < substr_len && str[i + j] == substr[j])
		{
			j++;
		}
		if (j == substr_len)
		{
			return i;
		}
	}

	return -1;
}

bool isLetter(char c)
{
	return (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я') ||
		(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isSyntax(char c)
{
	return (c == '.' || c == ',' ||
		c == ';' || c == ':' ||
		c == '!' || c == '?');
}