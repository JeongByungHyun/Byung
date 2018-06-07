#include <stdio.h>
#include <string.h>
#define MAX 256 
void main()
{
	int count, len1, len2,i,j;
	char *ptr1, *ptr2, op;
	char input[513], num1[MAX + 1], num2[MAX + 1], sum[MAX + 2];

	gets(input);
	for (i = 0; i < strlen(input); i++)
	{
		num1[i] = input[i];
		if (!(input[i] >= '0' && input[i] <= '9'))
			break;
	}
	num1[i] = '\0';
	op = input[i];
	j = 0;
	for (i++; i < strlen(input); i++)
	{
		num2[j++] = input[i];
	}
	num2[j] = '\0';

	if (op == '+')
	{
		
		if (strlen(num1) < strlen(num2)) { ptr1 = num2; ptr2 = num1; }
		else { ptr1 = num1; ptr2 = num2; }

		len1 = strlen(ptr1); len2 = strlen(ptr2);
		
		sum[0] = '0'; sum[len1 + 1] = 0;
		
		for (count = 0; count < len2; count++)
			sum[len1 - count] = ptr1[len1 - count - 1] + (ptr2[len2 - count - 1] - '0');
		for (; count < len1; count++) sum[len1 - count] = ptr1[len1 - count - 1];

		
		for (count = len1; count > 0; count--)
			if (sum[count] > '9') { sum[count - 1]++; sum[count] -= 10; }

		
		printf("%s + %s = %s\n", num1, num2, (sum[0] == '0') ? &sum[1] : &sum[0]);
	}
	else if (op == '-')
	{
		
		if (strlen(num1) < strlen(num2)) { ptr1 = num2; ptr2 = num1; }
		else { ptr1 = num1; ptr2 = num2; }

		len1 = strlen(ptr1); len2 = strlen(ptr2);
		
		sum[0] = '0'; sum[len1 + 1] = 0x00;
		
		for (count = 0; count < len2; count++)
			sum[len1 - count] = ptr1[len1 - count - 1] - (ptr2[len2 - count - 1] - '0');
		for (; count < len1; count++) sum[len1 - count] = ptr1[len1 - count - 1];
		
			
			
			for ( count = len1; count > 0; count-- )
			if ( sum[count] < '0' ) { sum[count-1]--; sum[count] += 10; }
			if ( sum[0] < '0' ) sum[0] = '-';
			printf ( "%s - %s = %s\n", num1, num2, (sum[0] == '0') ? &sum[1] : &sum[0] );
	}

	system("pause");
}

