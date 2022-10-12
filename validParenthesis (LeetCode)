class Solution:
    def isValid(self, s: str) -> bool:
        d = {']' : '[', '}' : '{', ')' : '('}
        stack = []
        for char in s:
            if char not in d:
                stack.append(char)
            else:
                if not stack:
                    return False
                if stack[-1] != d[char]:
                    return False
                stack.pop()
        return False if stack else True
