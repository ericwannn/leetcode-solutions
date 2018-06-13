"""https://leetcode.com/problems/palindromic-substrings/solution/#

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters. 

"""

class Solution:

  #Expand around center
  def countSubstrings(self, S):
    N = len(S)
    ans = 0
    for center in range(2*N - 1):
      left = center / 2
      right = left + center % 2
      while left >= 0 and right < N and S[left] == S[right]:
        ans += 1
        left -= 1
        right += 1
    return ans

  # Manacher algorithm
  def countSubstrings2(self, s):
      s = "@#" + "#".join(s) + "#$"
      center = right = 0
      z = [0] * len(s)
      for i in range(len(s) - 1):
        if i < right:
          z[i] = min(z[2 * center - i], right - i)
        while s[i + z[i] + 1] == s[i - z[i] - 1]:
          z[i] += 1
        if i + z[i] > right:
          center, right = i, i + z[i]
      return sum((i + 1) // 2 for i in z)