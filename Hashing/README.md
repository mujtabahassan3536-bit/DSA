Subarray Sum Equals K

Problem

Given an integer array and an integer k, find the total number of continuous subarrays whose sum equals k.

Approach

The main pattern used here is Prefix Sum + HashMap.

We keep track of the current prefix sum and store how many times each prefix sum has appeared.

For every element:

1. Add the element to currentSum.

2. Calculate the required previous prefix:

   currentSum - k

3. Check how many times this required prefix already appeared.

4. Add that frequency to the answer.

5. Store the current prefix sum in the map.

Why does this work?

If:

currentSum - previousPrefix = k

then:

previousPrefix = currentSum - k

So instead of checking every possible subarray, we can use the HashMap to find the required previous prefix directly.

Example

Array:

[1, -1, 1, -1, 1]

k = 0

The valid subarrays with sum 0 are:

[1, -1]

[-1, 1]

[1, -1]

[-1, 1]

[1, -1, 1, -1]

Total:

5

Important Detail

We initialize:

map[0] = 1

This represents the prefix sum 0 before processing any element.

We also check the required prefix before storing the current prefix. This prevents the current prefix from being counted as a previous prefix.

Complexity

Time Complexity: O(n) average

Space Complexity: O(n)

Key Learning

The important idea is:

Current Prefix → Required Previous Prefix → Frequency → Count

Prefix Sum + HashMap is especially useful when the array can contain negative numbers, where a normal Sliding Window approach is not reliable.

