class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        current = ""
        
        for char in path + "/":  
            if char == "/":
                if current:
                    if current == "..":
                        if stack:
                            stack.pop()
                    elif current != ".":
                        stack.append(current)
                current = ""
            else:
                current += char
        
        return "/" + "/".join(stack)
        