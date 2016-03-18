/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<math.h>
#include<string.h>

void reverse(char *str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}


int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}


	while (i < d)
		str[i++] = '0';

	reverse(str, i);
	str[i] = '\0';
	return i;
}
void number_to_str(float number, char *str, int afterdecimal){
	if (number == 0)
	{
		str = NULL;
	}
	int flag = 0;
	if (number < 0)
	{
		flag = 1;
	}
	number = abs(number);
	int ipart = (int)number;


	float fpart = number - (float)ipart;


	int i = intToStr(ipart, str, 0);


	if (afterdecimal != 0)
	{
		str[i] = '.';


		fpart = fpart * pow(10.0, afterdecimal);

		intToStr((int)fpart, str + i + 1, afterdecimal);
	}
	if (flag == 1)
	{
		int l = strlen(str);
		while (l >= 0)
		{
			str[l] = str[l - 1];
			l--;
		}
		str[0] = '-';
	}
}