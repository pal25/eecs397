#include "dmap_vector.h"

int main(int argc, char** argv)
{

    double vec = {1.0, 2.0, 3.0, 4.0};
    double_vector_map(vec, 4, identift_f);
    double_vector_display(vec, 4);
    
    return 0;
}
