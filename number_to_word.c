#include "number_to_word.h"
#include <stdio.h>

char *map_0to19[] = {"zero", "one", "two", "three", "four", "five",
		     "six", "seven", "eight", "nine", "ten", "eleven",
		     "twelve", "thirteen", "fourteen", "fifteen",
		     "sixteen", "seventeen", "eighteen", "ninteen"};

char *map_tens[] = {"zero", "ten", "twenty", "thirty", "fourty",
		    "fifty", "sixty", "seventy", "eighty", "ninety"};

void print_words_for_amount(int dollars, int cents)
{

    int hundreds = dollars / 100;
    if(hundreds > 0)
	printf("%s hundred ", map_0to19[hundreds]);

    int tens = (dollars % 100) / 10;
    if(tens == 1) {
	printf("%s ", map_0to19[dollars%100]);
    } else if(tens > 1) {
	printf("%s ", map_tens[tens]);
    }
    
    int ones = (dollars % 10);
    if(ones > 0 && tens != 1)
	printf("%s ", map_0to19[ones]);

    if(dollars != 0)
	printf("and ");
    else
	printf("zero and ");

    printf("%d/100 dollars\n", cents);

}
