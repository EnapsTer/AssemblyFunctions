#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char 	*ft_strdup(const char *s1);

#define STRLEN(s)					printf("own    = '%d'\norigin = '%d'\n\n", (int)ft_strlen(s), (int)strlen(s));
#define STRCPY(d, s)				printf("own    = '%s'\norigin = '%s'\n\n", ft_strcpy(d, s), strcpy(d, s));
#define STRCMP(s1, s2)				printf("own    = '%d'\norigin = '%d'\n\n", ft_strcmp(s1, s2), strcmp(s1, s2));
#define WRITE(fd, buf, bytes, fd2)	printf("own = %d\norigin = %d\n\n", (int)ft_write(fd, buf, bytes), (int)write(fd2, buf, bytes));
#define READ(fd, buf, bytes, fd2)	printf("-------------\nown = '%d'\n|%s|\n\norigin = '%d'\n|%s|\n-------------\n\n", (int)ft_read(fd, buf, bytes), buf, (int)read(fd2, buf, bytes), buf);
#define STRDUP(s)					printf("own = '%s'\norigin = '%s'\n\n", ft_strdup(s), strdup(s));

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
	free(d);
	d = NULL;
}

void	test_strcmp()
{
	printf("=============== strcmp ===============\n\n");
	STRCMP("", "");
	STRCMP("1", "1");
	STRCMP("123123", "123123");
	STRCMP("31111", "22222");
	STRCMP("232324", "232323");
	STRCMP("\200", "\0");
	STRCMP("123123123123123123123123123123123123123123123", "1231231231231231231231231231231231231231231231");
	STRCMP("2\0", "2\200");
	STRCMP("\n\n\n\n\n\0", "\n\n\n\n\n");
	printf("======================================");
}

void	test_write()
{
	char *s1 = "'1231231231231231232131231231223'\n";
	char *s2 = "'1112333ooooasdfffgg\nwe rgrgrgg'\n";
	char *s3 = "'\0\0\0\0\0\0\0\0'\n";
	char *s4 = "'euihgiuerhgiuhb ugb eubg uhadbf jhadfb jhbfdh b\n\n\n\n\nfjbuy rbfauoyd uaodhfbv ouadhfbv ouahdbfv ouhadv buhadfv'\n";
	char *s5 = "'qwerty qwerty qwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwertyqwerty qwerty'\n";

	int fd1 = open("temp1.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	int fd2 = open("temp2.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	printf("================ write ===============\n\n");
	WRITE(1, s1, ft_strlen(s1), 1);
	WRITE(1, s2, ft_strlen(s2), 1);
	WRITE(1, s3, ft_strlen(s3), 1);
	WRITE(1, s4, ft_strlen(s4), 1);
	WRITE(1, s5, ft_strlen(s5), 1);

	WRITE(fd1, s1, ft_strlen(s1), fd2);
	WRITE(fd1, s2, ft_strlen(s2), fd2);
	WRITE(fd1, s3, ft_strlen(s3), fd2);
	WRITE(fd1, s4, ft_strlen(s4), fd2);
	WRITE(fd1, s5, ft_strlen(s5), fd2);
	printf("======================================");
	close(fd1);
	close(fd2);
}

void	test_read()
{
	printf("================= read ===============\n\n");
	for (int i = 0; i < 20; i++)
	{
		char *buf = malloc(3000);
		int fd1 = open("temp1.txt", O_RDWR);
		int fd2 = open("temp2.txt", O_RDWR);
		if (i == 0)
		{
			READ(-1, buf, i * i, -1);
		}
		else
		{
			READ(fd1, buf, i * i, fd2);
		}
		close(fd1);
		close(fd2);
		free(buf);
		buf = NULL;
	}
	printf("======================================");
}

void	test_strdup()
{
	char *strs[] = {
			"123456",
			"12312312312312",
			"qwehtgeruytghweruyighuiwyrthgu wbghubw uhfdgb hwdbg jhdbfv jdg ",
			"\0\0\0\0\0",
			"00yuygyugyruyfuyga uhdfb jhadfbhjv b ahdfby ugerg y euirhfeiruygerhuieghurigeiuhgueihrgkughveufruygvfgrygyfhgfhgfhffhfhhfhfhfhfhhfhfhffhdjhifhaur gauhfvhasvdf hvsyF YUveyufv hsdvf hvsdhfv ysGF sdbvhjfv bdvbc bavhfrvfuyv uyvDGVFB RYE GT819T3478T 6G Y VGQ387GYUGR YG  goyagdfyh bvahdfjv ahdfg hv ahdgkv adfhgv ahdfvg khjadfgv hadfgvhadkgvdf hgva dfv ghafg h favgkha fva uyrvau yar787r7ar7r r7g 78g 8r7gad 87b aybryvfg adfhgv ahdjfgv h a84t ahfbdghb aydrug abdhfjgbuabrhgbfhgbf gb gb gbf ajbfg habdfghj abfd ghadbf gkjhadfbfguh abdlufbvadflhjbv aubfdv iuadbfv yabugbv adlkjvb adlv jhdabv jahbf vh bafhbv jhabd fhv"};
	printf("================= strdup ===============\n\n");
	for (int i = 0; i < 5; i++)
	{
		char *str = strs[i];
//		STRDUP(str);
		char *s = ft_strdup(str);
		printf("|%s|  %d\n", s, (int)ft_strlen(s));
		free(s);
		s = NULL;
	}
	printf("========================================\n");
}

int main(void)
{
//	test_strlen();
//	printf("\n\n");
//	test_strcpy();
//	printf("\n\n");
//	test_strcmp();
//	printf("\n\n");
//	test_write();
//	printf("\n\n");
//	test_read();
	test_strdup();
}