#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSubsequence(char *s, char *t){
	int len = strlen(s);
	int	i = 0;
	int	j = 0;
	int	 counter = 0;

	while (t[j] && s[i])
	{
		if (t[j] == s[i])
		{
			counter++;
			i++;
		}
		j++;
	}
	if (counter == len)
		return (true);
	return (false);
}


// int main(void)
// {
// 	char *s = "axc";
// 	char *t = "ahbgdc";
// 	int x = isSubsequence(s, t);
// 	printf("%s", x ? "true" : "false");
// 	return (0);
// }
