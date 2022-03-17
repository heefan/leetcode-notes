# KMP 算法

思路：
1. 建立 prefix table
   * 对于任意子串，求出公共前缀和后缀的数量
2. for-for 进行匹配，当发现不匹配时，查表


| index | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   |
|-------|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| p     | a   | b   | a   | b   | c   | a   | b   | a   | a   |
| pi    | 0   | 0   | 1   | 2   | ?   | ?   | ?   | ?   | ?   |

如果要求index=4时
len=2
p[len] = a
if(p[len] == c) ? 不等于， 所以

KMP字符串匹配算法1    
https://www.youtube.com/watch?v=dgPabAsTFa8&t=347s    
KMP字符串匹配算法1    
https://www.youtube.com/watch?v=3IFxpozBs2I    
