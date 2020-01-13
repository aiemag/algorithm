#include <stdio.h>

int strlen(char* str) {
	int n = -1;
	while (str[++n]);

	return n;
}

int mstrcmp(char* s1, char* s2) {
	int n = -1;
	while (s1[++n] && s2[n] && s1[n] == s2[n]);

	return s1[n] - s2[n];
}

void mstrcpy(char* dst, const char* src) {
	while (*dst++ = *src++);
}

void split_str(char* str, char delimeter) {
	int i, s_i = 0;
	char buf[100];

	for (i = 0; i < str[i]; i++) {
		if (str[i] == delimeter) {
			buf[s_i] = 0;
			s_i = 0;
			printf("split str : %s\n", buf);
		}
		else {
			buf[s_i++] = str[i];
		}
	}
	buf[s_i] = 0;
	printf("split str : %s\n", buf);
}

int main(void) {
	char str1[] = "-123";
	char str2[] = "123";
	char buf[100];

	printf("str1 : %s\n", str1);
	printf("str2 : %s\n", str2);
	printf("str1 length : %d\n", strlen(str1));
	printf("str1 & str2 mstrcmp : %d\n", mstrcmp(str1, str2));
	mstrcpy(buf, str1);
	printf("buf : %s\n", buf);

	char str3[] = "123.456";
	printf("str3 : %s\n", str3);
	split_str(str3, '.');

	return 0;
}