#include <stdio.h>
#include <string.h>

void open_tag(char *tag, char *attribute)
{
    char open[256];
    open[0] = '\0';

    strncat(open, "<", strlen("<"));
    strncat(open, tag, strlen(tag));
    if(strlen(attribute) > 1) {
	 strncat(open, " ", strlen(" "));
	 strncat(open, attribute, strlen(attribute));
    }
    strncat(open, ">", strlen(">"));

    printf("%s", open);
}

void close_tag(char *tag)
{
    char close[16];
    close[0] = '\0';
    
    strncat(close, "</", strlen("</"));
    strncat(close, tag, strlen(tag));
    strncat(close, ">", strlen(">"));
    
    printf("%s", close);
}

int main(int argc, char **argv)
{
    open_tag("html", ""); printf("\n");
    open_tag("body", ""); printf("\n");

    printf("  "); open_tag("p", "");
    printf("Hey There!");
    close_tag("p"); printf("\n");

    printf("  "); open_tag("p", "");
    printf("You can search for things on the internet at:\n");

    printf("    "); open_tag("ul", ""); printf("\n");
    printf("    "); open_tag("li", ""); printf(" ");
    open_tag("a", "href=\"http://www.google.com\"");
    printf("Google");
    close_tag("a");
    close_tag("li");  printf("\n");
    printf("    "); open_tag("li", ""); printf(" ");
    open_tag("a", "href=\"http://www.bing.com\"");
    printf("Bing");
    close_tag("a");
    close_tag("li");  printf("\n");
    printf("    "); close_tag("ul"); printf("\n");

    printf("  "); close_tag("p"); printf("\n");
    close_tag("body"); printf("\n");
    close_tag("html"); printf("\n");
					   
    return 0;
}
