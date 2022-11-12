import unittest

# Step1: Read Questions
# three pairs: (), {}, []
# s.length >=1: edge case, string must not be empty

# Analysis: think about matching, I will consider Stack data structure.
# The idea is, when the bracket is matched, I will pop it out.
# Thus, the valid string, the stack is empty. (all matched)

# Step2: Dry Run
# ex1.    stack
#   (      it is empty, so I append '(' in
#   )      it is matched with '(', I pop it out. thus, the stack is empty.
#  return stack.isEmpty()

# ex2.
#  (    empty,thus, I append in
#  )    matched ...
#  Quite similar with ex1

# ex3.
# (,  empty, thus, I append in
# ],  not match, then I append in
# the stack is not empty, so return false.


class Solution20:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c is '[' or\
                    (c is '(') or \
                    (c is '{'):
                stack.append(c)
            elif c is ']':
                if len(stack) is 0:
                    return False
                if stack.pop() is not '[':
                    return False
            elif c is ')':
                if len(stack) is 0:
                    return False
                if stack.pop() is not '(':
                    return False
            elif c is '}':
                if len(stack) is 0:
                    return False
                if stack.pop() is not '{':
                    return False

        print(stack)
        return len(stack) == 0


class Lc20Test(unittest.TestCase):
    sln = Solution20()

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

# Review:
# Actually the dry run on the given examples doesn't help me too much.
# I still missed the case when array is empty. 

