import unittest

class Solution20i:
    def isValid(self, s: str) -> bool:
        d = {'(': ')', '{': '}', '[': ']'}
        stack = []
        for c in s:
            if c in d:
                stack.append(c)
            elif len(stack) == 0 or d[stack.pop()] != c:
                return False

        return len(stack) == 0


class Lc20iTest(unittest.TestCase):
    sln = Solution20i()

    def test_case1(self):
        s = "(]"
        assert (self.sln.isValid(s) is False)

    def test_case2(self):
        s = "()[]{}"
        assert (self.sln.isValid(s) is True)

    def test_case3(self):
        s = "([)]"
        assert (self.sln.isValid(s) is False)

    def test_case4(self):
        s = "]"
        assert (self.sln.isValid(s) is False)


if __name__ == '__main__':
    unittest.main()


