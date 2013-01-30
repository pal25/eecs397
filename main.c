#include "number_to_word.h"
#include <stdio.h>


int main(int argc, char **argv)
{

    printf("0.19 -> "); print_words_for_amount(0, 19);
    printf("1.00 -> "); print_words_for_amount(1, 0);
    printf("5.35 -> "); print_words_for_amount(5, 35);
    printf("34.34 -> "); print_words_for_amount(34, 34);
    printf("150.10 -> "); print_words_for_amount(150, 10);
    printf("520.84 -> "); print_words_for_amount(520, 84);
    printf("634.50 -> "); print_words_for_amount(634, 50);
    printf("789.74 -> "); print_words_for_amount(789, 74);
    printf("900.99 -> "); print_words_for_amount(900, 99);
    printf("112.00 -> "); print_words_for_amount(112, 0);
    printf("11.00 -> "); print_words_for_amount(11, 0);


    return 0;
}
