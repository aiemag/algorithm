#include <stdio.h>

int atoi(char* str) {

	int value = 0;
	int sign = 1;

	if (*str == '-') {
		sign *= -1;
		str++;
	}

	while (*str) {
		if ('0' <= *str && *str <= '9') {
			value = value*10 + (*str - '0');
		}

		str++;
	}

	return sign*value;
}

void itoa(int value, char buf[]) {

	char* p = buf;
	char* p_firstdigit;
	char temp;

	if (value < 0) {
		value *= -1;
		*p++ = '-';
	}

	p_firstdigit = p;

	while (value) {
		*p++ = value % 10 + '0';
		value /= 10;
	}

	*p-- = 0;

	do {
		temp = *p;
		*p-- = *p_firstdigit;
		*p_firstdigit++ = temp;
	}while(p_firstdigit < p);
}

int main(void) {

	char str[10] = "-123";
	printf("atoi() result : %d\n", atoi(str));

	int value = -123;
	char buf[10];
	itoa(value, buf);
	printf("itoa() result : %s\n", buf);
}