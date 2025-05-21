class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m, n = len(matrix), len(matrix[0])  
        low, high = 0, m * n - 1
    
        while low <= high:
          mid = low + (high - low) // 2
          row, col = divmod(mid, n)  
          value = matrix[row][col]
        
          if value == target:
            return True
          elif value < target:
            low = mid + 1
          else:
            high = mid - 1
    
        return False
        