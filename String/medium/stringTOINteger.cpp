/*
LeetCode 8 : String to Integer (atoi)

Steps:
1. Skip leading spaces.
2. Check sign (+ or -).
3. Read digits one by one.
4. Build number:
      ans = ans * 10 + digit
5. Stop when non-digit is found.
6. Handle overflow before multiplication:
      if(ans > INT_MAX/10 ||
        (ans == INT_MAX/10 && digit > 7))
      {
          return sign == 1 ? INT_MAX : INT_MIN;
      }
7. Return ans * sign.

Overflow Logic:
INT_MAX = 2147483647

214748364 -> first 9 digits
7         -> last allowed digit

If:
    ans > 214748364
OR
    ans == 214748364 && digit > 7

then next operation:
    ans*10 + digit

will exceed INT_MAX,
so return INT_MAX or INT_MIN.

Time Complexity : O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

int myAtoi(string s)
{
    int i = 0;
    int n = s.size();

    // Skip leading spaces
    while(i < n && s[i] == ' ')
    {
        i++;
    }

    // Check sign
    int sign = 1;

    if(i < n && (s[i] == '+' || s[i] == '-'))
    {
        if(s[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    int ans = 0;

    // Read digits
    while(i < n && s[i] >= '0' && s[i] <= '9')
    {
        int digit = s[i] - '0';

        // Overflow check
        if(ans > INT_MAX / 10 ||
          (ans == INT_MAX / 10 && digit > 7))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        ans = ans * 10 + digit;
        i++;
    }

    return ans * sign;
}

int main()
{
    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Integer value = " << myAtoi(s);

    return 0;
}