# 1. Two Sum

# Difficulty : Easy

# Given an array of integers nums and an integer target, 
# return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, 
# and you may not use the same element twice.

# You can return the answer in any order.

# Example 1:
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

# Example 2:
# Input: nums = [3,2,4], target = 6
# Output: [1,2]

# Example 3:
# Input: nums = [3,3], target = 6
# Output: [0,1]
 
# Constraints:

# 2 <= nums.length <= 104
# -109 <= nums[i] <= 109
# -109 <= target <= 109
# Only one valid answer exists.
 
# Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

# Time Complexity is : O(n)
# Space Complexity is : O(n)

def two_sum(arr,target):
    targetValue = {}
    for pos in range(len(arr)):
        item = arr[pos]
        if item in targetValue:
            return [targetValue[item],pos]
        res = target - item
        targetValue[res] = pos

def test(arr,target,result):
    try:
        assert two_sum(arr,target) == result
    except AssertionError:
        return ("test : failed")
    return("test : pass")

if __name__ == "__main__":

    print(test(arr=[2,7,11,15], target=9, result=[0,1]))
    print(test(arr=[3,2,4], target=6, result=[1,2]))
    print(test(arr=[3,3], target=6, result=[0,1]))

