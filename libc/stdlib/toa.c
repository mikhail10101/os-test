#include <stdlib.h>

char int_to_ascii_hex_digit(int value) {
    if (value >= 0 && value <= 9)
        return '0' + value;         
    else if (value >= 10 && value <= 15)
        return 'a' + (value - 10);  
    else
        return '?'; // Invalid input
}

char* itoa(int value, char* str, int base) {
	char* buff = str;
	int len = 0;

	if (value == 0) {
		len = 1;
		str[0] = '0';
	}

	while (value > 0) {
		*str = int_to_ascii_hex_digit(value % base);

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

char* ltoa(uint64_t value, char* str, int base) {
	char* buff = str;
	int len = 0;

	if (value == 0) {
		len = 1;
		str[0] = '0';
	}
	
	while (value > 0) {
		*str = int_to_ascii_hex_digit(value % base);

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
