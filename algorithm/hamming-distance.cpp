/* Description

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.
*/

class Solution1 {
public:
    int hammingDistance(int x, int y) {
        int p1, p2;
        int res = 0;
        while(x != 0 or y != 0)
        {
            p1 = 0;
            p2 = 0;
            if (x != 0)
            {
                p1 = x % 2;
                x /= 2;
            }
            if (y != 0)
            {
                p2 = y % 2;
                y /= 2;
            }
            res += (p1 ^ p2);
        }
        return res;
        
    }
};


class Solution2 {
public:
    int hammingDistance(int x, int y) {
		unsigned int r = x ^ y;
		int res = 0;
		while(r)
		{
            if (r & 1) res ++;
            r = r >> 1;
		}
        return res;
    }
};