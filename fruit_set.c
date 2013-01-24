#include <stdint.h>
#include <stdio.h>

enum fruits {
    APPLE = 0x0001,
    BLACKBERRY = 0x0002,
    BLUEBERRY = 0x0004,
    GRAPE = 0x0008,
    LYCHEE = 0x0010,
    ORANGE = 0x0020,
    PEAR = 0x0040,
    POMEGRANATE = 0x0080,
    GRAPEFRUIT = 0x0100,
    KIWI = 0x0200,
    LEMON = 0x0400,
    LIME = 0x0800,
    RASPBERRY = 0x1000,
    STRAWBERRY = 0x2000,
    TANGERINE = 0x4000,
    WATERMELON = 0x8000
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
    return (set & member) != 0;
}

// add the member provided to the set and return the new set value
uint16_t add_member(uint16_t set, enum fruits member)
{
    return set | member;
}

// remove the member provided from the set provided and return the new set value
uint16_t remove_member(uint16_t set, enum fruits member)
{
    return set & ~member;
}

int main(int argc, char **argv)
{
#define EMPTY_SET 0x0000
    
    uint16_t citrus_set = GRAPEFRUIT | KIWI | LEMON | LIME;
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
