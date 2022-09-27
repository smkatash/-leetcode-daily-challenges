#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int	self_loop(char *str, char c, int pos)
{
	for (int i = 0; i < pos; i++)
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int	scanner(char *s, char c, int pos)
{
	for (int i = 0; i < pos; i++)
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}

bool isIsomorphic(char * s, char * t){
	int	count_1 = 0;
	int	count_2 = 0;
	int	pos_1 = 0;
	int	pos_2 = 0;

	if (strlen(s) != strlen(t))
		return (false);
	for (int i = 0; s[i] && t[i]; i++)
	{
		pos_1 = scanner(s, s[i], i);
		pos_2 = scanner(t, t[i], i);
		count_1 += self_loop(s, s[i], i);
		count_2 += self_loop(t, t[i], i);
		if (count_1 != count_2 || pos_1 != pos_2)
			return (false);
	}
	return (true);
}

// int main(void)
// {
// 	char *s = "bbbaaaba";
// 	char *t = "aaabbbba";
// 	int x = isIsomorphic(s, t);
// 	printf("%s", x ? "true" : "false");
// 	return (0);
// }
