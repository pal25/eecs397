#include <stdio.h>
#include "dmap_vector.h"

int main(int argc, char** argv)
{
    double vec[4] = {-1.0, 0.25, -0.2, 0.0625};
    printf("Initial Function\n");
    double_vector_display(vec, 4);
    double_vector_map(vec, 4, identity_f);
    printf("After Identity Function\n");
    double_vector_display(vec, 4);

    printf("Initial Function\n");
    double_vector_display(vec, 4);
    double_vector_map(vec, 4, negate_f);
    printf("After Negate Function\n");
    double_vector_display(vec, 4);

    printf("Initial Function\n");
    double_vector_display(vec, 4);
    double_vector_map(vec, 4, invert_f);
    printf("After Invert Function\n");
    double_vector_display(vec, 4);

    printf("Initial Function\n");
    double_vector_display(vec, 4);
    double_vector_map(vec, 4, mul_2_f);
    printf("After Multiple By 2 Function\n");
    double_vector_display(vec, 4);

    printf("Initial Function\n");
    double_vector_display(vec, 4);
    double_vector_map(vec, 4, div_2_f);
    printf("After Divide By 2 Function\n");
    double_vector_display(vec, 4);
    
    return 0;
}
