#include <stdint.h>
#include <stdio.h>

enum fruits {
    APPLE=0,
    BLACKBERRY,
    BLUEBERRY,
    GRAPE,
    LYCHEE,
    ORANGE,
    PEAR,
    POMEGRANATE,
    GRAPEFRUIT,
    KIWI,
    LEMON,
    LIME,
    RASPBERRY,
    STRAWBERRY,
    TANGERINE,
    WATERMELON
};

// return the intersection of sets a and b
uint16_t set_intersection(uint16_t a, uint16_t b)
{
    return a & b;
}

// return the union of sets a and b
uint16_t set_union(uint16_t a, uint16_t b)
{
    return a | b;
}

// return the symmetric difference of sets a and b
uint16_t set_symmetric_difference(uint16_t a, uint16_t b)
{
    return a ^ b;
}

// return 0 if the member specified is not in the set provided, 1 otherwise
int is_member(uint16_t set, enum fruits member)
{
    return (set & (1 << member)) != 0;
}

// add the member provided to the set and return the new set value
uint16_t add_member(uint16_t set, enum fruits member)
{
    return set | (1 << member);
}

// remove the member provided from the set provided and return the new set value
uint16_t remove_member(uint16_t set, enum fruits member)
{
    return set & (0 << member);
}

int main(int argc, char **argv)
{
#define EMPTY_SET 0x0000
    
    uint16_t citrus_set;
    citrus_set = add_member( EMPTY_SET, GRAPEFRUIT);
    citrus_set = add_member( citrus_set, LEMON);
    citrus_set = add_member( citrus_set, LIME);
    citrus_set = add_member( citrus_set, ORANGE);
    citrus_set = add_member( citrus_set, TANGERINE);
    printf("Set representing all citrus fruits: %#x\n", citrus_set);
    
    uint16_t response_1;
    uint16_t response_2;

    response_1 = add_member( EMPTY_SET, GRAPEFRUIT);
    response_1 = add_member( response_1, LEMON);
    response_1 = add_member( response_1, WATERMELON);
    response_1 = add_member( response_1, TANGERINE);
    response_1 = add_member( response_1, APPLE);
    
    response_2 = add_member( EMPTY_SET, POMEGRANATE);
    response_2 = add_member( response_2, WATERMELON);
    response_2 = add_member( response_2, APPLE);
    response_2 = add_member( response_2, LIME);
    response_2 = add_member( response_2, APPLE);
   
    printf("Intersection of 1 and 2: %#x\n", set_intersection(response_1, response_2));

    if( is_member( set_intersection(response_1, response_2), APPLE )) {
	printf("Everyone likes Apples!\n");
    } else {
	printf("Everyone does not like Apples!\n");
    }

    printf("Union of 1 and 2: %#x\n", set_union(response_1, response_2));

    if( is_member( set_union(response_1, response_2), GRAPE )) {
	printf("Someone likes Grapes!\n");
    } else {
	printf("No one likes Grapes!\n");
    }

    return 0;
}
