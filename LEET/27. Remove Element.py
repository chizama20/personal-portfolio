class Solution(object):
    def removeElement(self, nums, val):
        k = 0 
        for e in nums:
            if e != val:
                nums[k] = e
                k += 1
        return k

 #       def removeMiddle(arr, i, length):
 #           for index in range(i + 1, length):
 #               arr[index - 1] = arr[index]     ***here is the algorithm***