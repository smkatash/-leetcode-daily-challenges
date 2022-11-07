#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int find_match(int *a,int *b)
{
	for(int i = 0; i < 26; i++)
    {
		if(a[i] != b[i])
			return (0);
    }
	return (1);
}

int* findAnagrams(char * s, char * p, int* returnSize){
    int p_len = strlen(p);
    int s_len = strlen(s);
    if (p_len > s_len)
    {
        *returnSize = 0;
        return (NULL);
    }
    int *arr = malloc(sizeof(int) * s_len);
    int s_counts[26] = {0};
    int p_counts[26] = {0};
    int len = 0;
    for(int i = 0; i < p_len; i++) {
        s_counts[s[i] - 'a']++;
        p_counts[p[i] - 'a']++;
    }
    for (int i = 0; i <= s_len - p_len; i++)
    {
        if (i != 0)
            s_counts[s[i + p_len - 1] - 'a']++;
        if (find_match(s_counts, p_counts))
        {
            arr[len] = i;
            len++;
        }
        s_counts[s[i] - 'a']--;
    }
    *returnSize = len;
    return (arr);
}

int main(void)
{
    char *s = "aaaaaaaaaa";
    char *p = "aaaaaaaaaaaaa";
    int size = 0;
    int *arr = findAnagrams(s, p, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return (0);
}
