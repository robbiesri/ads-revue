// Copyright (c) 2025 Robert Srinivasiah

#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include <cassert>
#include <cstdint>
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

// DESCRIPTION
// https://leetcode.com/problems/two-sum
// Given an array of integers nums and an integer target, return indices of the two numbers such
// that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same
// element twice. You can return the answer in any order.

// NOTES
// * You have to go thru just once, to handle repeated elements. If you just filter out repeats by
//   pushing everything into map, this won't work.

class Solution_TwoSum
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, uint32_t> num_matcher;
        for (uint32_t i = 0; i < nums.size(); i++)
        {
            const int match = target - nums[i];
            if (num_matcher.contains(match))
            {
                return {static_cast<int>(i), static_cast<int>(num_matcher[match])};
            }

            num_matcher.emplace(nums[i], i);
        }

        return {0, 0};
    }
};

// DESCRIPTION
// https://leetcode.com/problems/longest-substring-without-repeating-characters
// Given a string s, find the length of the longest substring without duplicate characters.

// NOTES
// * First idea is to have a sliding window. If character is new, insert into map. Map tracks
//   character + location in substring. If character repeats, cut off current list. Split string
//   at repeated location and keep going with 'new' repeated character.
// * Nothing comes to mind to use built-in algorithms. MAYBE distances between current and previous
//   instance of character? Then some kind of accumulate?
// * Previous solution of mine was clever. Using vector and proper sliding window.
// vector<int> charLocationMap(256, -1);
//
// int longestSoFar = 0;
// int startOfCurrentSubstring = -1; // so the math works for the first search
// for (int c = 0; c < s.size(); c++) {
//     if (charLocationMap[s[c]] > startOfCurrentSubstring) {
//         startOfCurrentSubstring = charLocationMap[s[c]];
//     }
//     charLocationMap[s[c]] = c;
//
//     longestSoFar = std::max(longestSoFar, c - startOfCurrentSubstring);
// }
//
// return longestSoFar;

class Solution_LongestSubstringWithoutRepeating
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, size_t> char_loc;

        size_t substring_start = 0;
        size_t max_length = 0;
        size_t i = 0;
        for (; i < s.length(); i++)
        {
            if (char_loc.contains(s[i]))
            {
                const size_t current_length = i - substring_start;
                max_length = std::max(max_length, current_length);
                substring_start = std::max(char_loc[s[i]] + 1, substring_start);
                char_loc[s[i]] = i;
            }
            else
            {
                // I always assign updated location between branches??
                char_loc.emplace(s[i], i);
            }

            // I should just always update max length
        }
        return std::max(max_length, i - substring_start);
    }
};

// DESCRIPTION
// http://leetcode.com/problems/longest-palindromic-substring
// Given a string s, return the longest palindromic substring in s.

// NOTES
// * there's a variety of approaches.
// * brute force is check every range of substrings - n**2 ranges, n time to scan each range
// * simpler way is to treat each character as the possible _center_ of a palindrome. the TRICK here
//   is that each character isn't really the center. It's the character and the character +
//   neighbor! We could pre-process to insert gaps to have the actual center, but w/e
// * If we wanted, we could keep a 2D table that tracks endpoints for valid palindromes. I've done
//   it like this before. Then we can quickly compute palindromes based on what we've seen already

class Solution_LongestPalindromicSubstring
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::string_view longest_p = std::string_view(s).substr(0, 1);

        auto check_palindrome = [&s](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }
            return std::string_view(s).substr(left + 1, (right - 1) - left);
        };
        for (int start = 0; start < s.length() - 1; start++)
        {
            std::string_view single_center = check_palindrome(start, start);
            std::string_view double_center = check_palindrome(start, start + 1);

            if (single_center.size() > longest_p.size())
            {
                longest_p = single_center;
            }

            if (double_center.size() > longest_p.size())
            {
                longest_p = double_center;
            }
        }

        return std::string(longest_p);
    }
};

// DESCRIPTION
// https://leetcode.com/problems/clone-graph
// Given a reference of a node in a connected undirected graph.
// Return a deep copy (clone) of the graph.
// Constraints:
// The number of nodes in the graph is in the range [0, 100].
// 1 <= Node.val <= 100
// Node.val is unique for each node.
// There are no repeated edges and no self-loops in the graph.
// The Graph is connected and all nodes can be visited starting from the given node.

// NOTES
// * initial thought is to do a depth first scan, creating a graph as we go along.
//   We need a map in order to prevent re-creation of nodes. This feels kinda complicated...

class Solution_CloneGraph
{
public:
    class Node
    {
    public:
        int val;
        std::vector<Node*> neighbors;
        Node()
        {
            val = 0;
            neighbors = std::vector<Node*>();
        }
        Node(int _val)
        {
            val = _val;
            neighbors = std::vector<Node*>();
        }
        Node(int _val, std::vector<Node*> _neighbors)
        {
            val = _val;
            neighbors = _neighbors;
        }
    };

    Node* cloneGraph(Node* source_root)
    {
        if (source_root == nullptr)
        {
            return nullptr;
        }

        std::vector<Node*> source_to_visit;
        source_to_visit.push_back(source_root);

        // assert(source_root->val == 1);
        Node* cloned_root = new Node(1);
        std::unordered_map<int, Node*> cloned_node_map;
        cloned_node_map[1] = cloned_root;

        while (source_to_visit.size() > 0)
        {
            const Node* source_node = source_to_visit.back();
            source_to_visit.pop_back();
            Node* cloned_node = cloned_node_map[source_node->val];
            for (Node* source_node_neighbor : source_node->neighbors)
            {
                if (!cloned_node_map.contains(source_node_neighbor->val))
                {
                    cloned_node_map.emplace(source_node_neighbor->val,
                                            new Node(source_node_neighbor->val));
                    source_to_visit.push_back(source_node_neighbor);
                }
                cloned_node->neighbors.push_back(cloned_node_map[source_node_neighbor->val]);
            }
        }

        return cloned_root;
    }

    static Node* generateGraphFromAdjList(const std::vector<std::vector<int>>& adj_list)
    {
        if (adj_list.size() == 0)
        {
            return nullptr;
        }

        std::unordered_map<int, Node*> node_map;
        for (int i = 0; i < adj_list.size(); i++)
        {
            node_map.emplace(i + 1, new Node(i + 1));
        }

        for (int i = 0; i < adj_list.size(); i++)
        {
            Node* cur_node = node_map.at(i + 1);
            for (int edge_val : adj_list[i])
            {
                cur_node->neighbors.push_back(node_map.at(edge_val));
            }
        }

        return node_map[1];
    }
};

int main(int argc, char** argv)
{
    {
        Solution_CloneGraph::Node* original_graph =
            Solution_CloneGraph::generateGraphFromAdjList({{2, 4}, {1, 3}, {2, 4}, {1, 3}});
        Solution_CloneGraph::Node* cloned_graph = Solution_CloneGraph().cloneGraph(original_graph);
        printf("cloned!");
    }

    // {
    //     auto res = Solution_LongestPalindromicSubstring().longestPalindrome(std::string("bb"));
    //     printf("%s\n", res.c_str());
    // }

    // {
    //     std::vector<int> test0{100, 4, 200, 1, 3, 2};
    //     const int test0_result = Solution_LongestConsecutiveSequence().longestConsecutive(test0);
    //
    //     printf("Longest consecutive sequence: %d\n", test0_result);
    //
    //     std::vector<int> test1{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    //     const int test1_result = Solution_LongestConsecutiveSequence().longestConsecutive(test1);
    //
    //     printf("Longest consecutive sequence: %d\n", test1_result);
    // }
    //
    // {
    //     std::vector<int> input0{3, 3};
    //     std::vector<int> test0 = Solution_TwoSum().twoSum(input0, 6);
    //     printf("Two Sum is: %d %d\n", test0.at(0), test0.at(1));
    // }
    //
    // {
    //     const auto res0 =
    //         Solution_LongestSubstringWithoutRepeating().lengthOfLongestSubstring("abcabcbb");
    //     printf("Longest substring without repeating is: %d\n", res0);
    //     const auto res1 =
    //         Solution_LongestSubstringWithoutRepeating().lengthOfLongestSubstring("bbbbbbb");
    //     printf("Longest substring without repeating is: %d\n", res1);
    //     const auto res2 =
    //         Solution_LongestSubstringWithoutRepeating().lengthOfLongestSubstring("pwwkew");
    //     printf("Longest substring without repeating is: %d\n", res2);
    //     const auto res3 =
    //     Solution_LongestSubstringWithoutRepeating().lengthOfLongestSubstring("c");
    //     printf("Longest substring without repeating is: %d\n", res3);
    //     {
    //         const auto res =
    //             Solution_LongestSubstringWithoutRepeating().lengthOfLongestSubstring("abba");
    //         printf("Longest substring without repeating is: %d\n", res);
    //     }
    // }

    return 0;
}