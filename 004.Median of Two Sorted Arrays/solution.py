class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums = []
        i, j = 0, 0
        max_i = len(nums1)
        max_j = len(nums2)
        while(i < max_i or j < max_j):
            if(i < max_i and j < max_j):
                if(nums1[i] < nums2[j]):
                    nums += [nums1[i]]
                    i += 1
                else:
                    nums += [nums2[j]]
                    j += 1
            elif (i < max_i):
                nums += nums1[i:]
                break
            else:
                nums += nums2[j:]
                break
        length = len(nums)
        mid = length / 2
        if length % 2 == 0:
            return (nums[mid] + nums[mid-1])/2.0
        else:
            return nums[mid]