class Solution(object):
    def getConcatenation(self, nums):
        ans = []
        for i in range(2):
            for n in nums:
                ans.append(n)                  
        return ans


 #ALGORIGNTHM   
    #def resize(self):
        # Create new array of double capacity
    #    self.capacity = 2 * self.capacity
     #   newArr = [0] * self.capacity 
        
        # Copy elements to newArr
    #    for i in range(self.length):
     #       newArr[i] = self.arr[i]
    #    self.arr = newArr