#include <stdio.h>

int main(void) {

	int i = 0;
	int j = 0;
	int value;

	printf("Insert an integer: \n");
	scanf("%d", &value);

	while (i <= value) {

	j = j + (i * i);

	i = i + 1;
	
	}

	printf("The value of the sum is %d", j);
	
	return 0;

}