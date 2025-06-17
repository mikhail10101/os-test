#include <stdlib.h>

char* itoa(int value, char* str) {
	int base = 10;

	char* buff = str;

	int len = 0;
	while (value > 0) {
		*str = value % base + '0';

		value /= base;
		len++;
		str++;
	}

	int i = 0; int j = len - 1;
	while (i < j) {
		char temp = buff[i];
		buff[i] = buff[j];
		buff[j] = temp;

		i++;
		j--;
	}

	buff[len] = '\0';
	return buff;
}
