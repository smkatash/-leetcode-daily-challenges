#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int characterReplacement(char *s, int k){
	int counts[26] = {0};
	int left = 0;
	int right = 0;
	int max_idx = 0;

	while (right < strlen(s))
	{
		counts[s[right] - 'A']++;
		max_idx = max(max_idx, counts[s[right] - 'A']);
		right++;
		if (right - left > max_idx + k)
		{
			counts[s[left] - 'A']--;
			left++;
		}
	}
	return (right - left);
}

int main(void) 
{
	char *s = "AABABBA";
	int k = 2;
	int	output = characterReplacement(s, k);
	printf("%d\n", output);
	return (0);
}