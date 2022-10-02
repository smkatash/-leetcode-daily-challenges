#include <stdio.h>

int firstBadVersion(int n) {
    size_t	left = 1;
	size_t	right = n;
	size_t middle = 0;
	while (left <= right) 
    {
		middle = (left + right) / 2;
		if (isBadVersion(middle)) {
			if (!isBadVersion(middle - 1))
				return (middle);
			right = middle - 1;
		}
		else {
			left = middle + 1;
        }
	}
	return (0);
}