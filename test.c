#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);

#define STRLEN(S)		printf("own    = %d\norigin = %d\n\n", (int)ft_strlen(S), (int)strlen(S));
#define STRCPY(D, S)		printf("own    = '%s'\norigin = '%s'\n\n", ft_strcpy(D, S), strcpy(D, S));


void	test_strlen()
{
	printf("=============== strlen ===============\n\n");
	STRLEN("");
	STRLEN("1");
	STRLEN("jsdhfkjsdhfjsdhfkjs");
	STRLEN("-1");
	STRLEN("1010101010101010101010101010");
	STRLEN("sdlfjsdojfsffshgiudhgiudhguhoriuheaoiughfiudghiuyarh8othaigfhuayrg87ohfhga7rgfahjarg");
	printf("======================================");
}

void	test_strcpy()
{
	char *d = malloc(3000);
	printf("=============== strcpy ===============\n\n");
	STRCPY(d, "6");
	STRCPY(d, "172361876367328567324yt8247weuygfiuweyrfg7934tg72rgef67gf n7yewbr f7yeb g97yb24567 6rebv 79246g2v4tv79b24796b429756b 27vy 47ytv 74vb 724bv 7624v765 7 246bv 7bv247 v2v 4v v4 v49 4v v");
	STRCPY(d, "");
	STRCPY(d, "\n\n\n");
	STRCPY(d, "\0");
	STRCPY(d, "123");
	STRCPY(d, "123456");
	printf("======================================");

}

int main(void)
{
	test_strlen();
	printf("\n\n");
	test_strcpy();
}