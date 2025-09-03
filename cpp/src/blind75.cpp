// Copyright (c) 2025 Robert Srinivasiah

#include <set>
#include <vector>

#include <cstdio>

// DESCRIPTION
// https://leetcode.com/problems/longest-consecutive-sequence/
// Given an unsorted array of integers nums, return the length of the longest consecutive elements
// sequence. You must write an algorithm that runs in O(n) time.
//
// NOTES
// * I had another solution that used unordered_set, and that checked each value to see if it was
// the START of a sequence. Once catching a start, we scan for following numbers in the sequence.
// * I think a bitset would be easy. The bitset would cover the range of all possible int32,
//   and then offset int32_t into positive range to generate bitset indices. Then iterate over bits
//   for longest sequence of 1s.
// * If i want to go algorithmic way, it would be std::set or sorting the vector. Then adjacent
//   transform into 1s and 0s depending on whether the next number is +1. Then partial_sum that
//   writes out 0 when sequences break. Finally, get max value from resultant vector!
class Solution_LongestConsecutiveSequence
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        std::set<int> sorted_nums;
        for (auto i : nums)
        {
            sorted_nums.insert(i);
        }

        int cur_sequence_size = 0;
        int max_sequence_size = 0;
        int sequence_marker = INT_MAX - 1;

        for (auto num : sorted_nums)
        {
            if (sequence_marker + 1 == num)
            {
                sequence_marker = num;
                cur_sequence_size++;
            }
            else
            {
                // start new sequence
                max_sequence_size = std::max(max_sequence_size, cur_sequence_size);
                sequence_marker = num;
                cur_sequence_size = 1;
            }
        }

        max_sequence_size = std::max(max_sequence_size, cur_sequence_size);
        return max_sequence_size;
    }
};

int main(int argc, char** argv)
{
    {
        std::vector<int> test0{100, 4, 200, 1, 3, 2};
        const int test0_result = Solution_LongestConsecutiveSequence().longestConsecutive(test0);

        printf("Longest consecutive sequence: %d\n", test0_result);

        std::vector<int> test1{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        const int test1_result = Solution_LongestConsecutiveSequence().longestConsecutive(test1);

        printf("Longest consecutive sequence: %d\n", test1_result);
    }

    return 0;
}