#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int longestPalindrome(char * s)
{
    int letters[52] = {0};
    bool is_odd = false;
    int longpalindrome = 0;
    
    for (int i = 0; i < strlen(s); i++)
    {
        if(s[i] <= 'Z')
            letters[s[i] - 'A']++;
        else 
            letters[s[i] - 'a' + 26]++;
    }
    for (int i = 0; i < 52; i++) 
    {
        longpalindrome += letters[i] / 2;
        if (letters[i] % 2 == 1)
            is_odd = true;
    }
    if (is_odd)
        longpalindrome = longpalindrome * 2 + 1;
    else
        longpalindrome = longpalindrome * 2;
    return (longpalindrome);
}
    
int main(void) 
{
    char s[] = "abccccdd";
    int i = longestPalindrome(s);
    printf("%d\n", i);
    return (0);
}