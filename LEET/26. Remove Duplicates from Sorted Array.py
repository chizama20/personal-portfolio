class Solution(object):
    def removeDuplicates(self, nums):
        if not nums:
            return 0, []
        k = 1

        for index in range(1, len(nums)):
            if nums[index] != nums[index - 1]:
                nums[k] = nums[index]

                k +=1
        
        return k
    
    #       def removeMiddle(arr, i, length):
    #           for index in range(i + 1, length):
    #               arr[index - 1] = arr[index]     ***here is the algorithm***