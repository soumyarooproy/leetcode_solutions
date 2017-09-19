### Longest Continuous Increasing Subsequence (#674)
### Second Minimum Node In a Binary Tree (#671)
### Trim a Binary Search Tree (#669)
### Non-decreasing Array (#665)
### Image Smoother (#661)
* Brute force - Use a `k`-by-`k` (`k = 3`) window
* Sliiding window - complicated
### Judge Route Circle (#657)
### Two Sum IV - Input is a BST (#653)
### Set Mismatch (#645)
### Maximum Average Subarray I (#643)
### Average of Levels in Binary Tree (#637)
### Sum of Square Numbers (#633)
### Maximum Product of Three Numbers (#628)
### Maximum Distance in Arrays (#624)
### Merge Two Binary Trees (#617)
### Construct String from Binary Tree (#606)
### Can Place Flowers (#605)
### Design Compressed String Iterator (#604)
### Minimum Index Sum of Two Lists (#599)
### Range Addition II (#598)
### Longest Harmonious Subsequence (#594)
### Shortest Unsorted Continuous Subarray (#581)
### Distribute Candies (#575)
### Subtree of Another Tree (#572)
### Reshape the Matrix (#566)
### Binary Tree Tilt (#563)
### Array Partition I (#561)
### Reverse Words in a String III (#557)
### Student Attendance Record I (#551)
### Diameter of Binary Tree (#543)
### Reverse String II (#541)
### Convert BST to Greater Tree (#538)
### K-diff Pairs in an Array (#532)
### Minimum Absolute Difference in BST (#530)
### Longest Uncommon Subsequence I (#521)
### Detect Capital (#520)
### Perfect Number (#507)
### Relative Ranks (#506)
### Base 7 (#504)
### Find Mode in Binary Search Tree (#501)
### Keyboard Row (#500)
### Next Greater Element I (#496)
### Construct the Rectangle (#492)
### Max Consecutive Ones (#485)
### Largest Palindrome Product (#479)
### Number Complement (#476)
### Heaters (#475)
### Island Perimeter (#463)
### Hamming Distance (#461)
### Repeated Substring Pattern (#459)
### Poor Pigs (#458)
### Assign Cookies (#455)
### Minimum Moves to Equal Array Elements (#453)
### Find All Numbers Disappeared in an Array (#448)
### Number of Boomerangs (#447)
### Arranging Coins (#441)
### Find All Anagrams in a String (#438)
### Path Sum III (#437)
### Number of Segments in a String (#434)
### Valid Word Square (#422)
### Add Strings (#415)
### Third Maximum Number (#414)
### Fizz Buzz (#412)
### Longest Palindrome (#409)
### Valid Word Abbreviation (#408)
### Convert a Number to Hexadecimal (#405)
### Sum of Left Leaves (#404)
### Binary Watch (#401)
### Nth Digit (#400)
### Find the Difference (#389)
### First Unique Character in a String (#387)
### Ransom Note (#383)
### Guess Number Higher or Lower (#374)
### Sum of Two Integers (#371)
### Valid Perfect Square (#367)
### Logger Rate Limiter (#359)
### Intersection of Two Arrays II (#350)
### Intersection of Two Arrays (#349)
### Moving Average from Data Stream (#346)
### Reverse Vowels of a String (#345)
### Reverse String (#344)
### Power of Four (#342)
### Nested List Weight Sum (#339)
### Power of Three (#326)
### Range Sum Query - Immutable (#303)
### Flip Game (#293)
### Nim Game (#292)
### Word Pattern (#290)
### Move Zeroes (#283)
### First Bad Version (#278)
### Paint Fence (#276)
### Closest Binary Search Tree Value (#270)
### Missing Number (#268)
### Palindrome Permutation (#266)
### Ugly Number (#263)
### Add Digits (#258)
### Binary Tree Paths (#257)
### Paint House (#256)
### Meeting Rooms (#252)
### Strobogrammatic Number (#246)
### Shortest Word Distance (#243)
### Valid Anagram (#242)
### Delete Node in a Linked List (#237)
### Lowest Common Ancestor of a Binary Search Tree (#235)
### Palindrome Linked List (#234)
### Implement Queue using Stacks (#232)
### Power of Two (#231)
### Invert Binary Tree (#226)
### Implement Stack using Queues (#225)
### Contains Duplicate II (#219)
### Contains Duplicate (#217)
### Reverse Linked List (#206)
### Isomorphic Strings (#205)
### Count Primes (#204)
### Remove Linked List Elements (#203)
### Happy Number (#202)
### House Robber (#198)
### Number of 1 Bits (#191)
### Reverse Bits (#190)
### Rotate Array (#189)
* Simple approach - reverse the entire array and then reverse the two ranges - `[0, k)` and `[k, n)` separately
* Other approaches - EPI's approach and `std::rotate()` approach
### Factorial Trailing Zeroes (#172)
* Zeroes are contributed only by 10's, whose prime factors are `2` and `5`
* In the first `n` numbers, `2` is contributed by `2, 4, 6, 8, ...` while `5` is contributed by `5, 10, 15, 20, ...`
* It suffices to count the number of `5`'s because there will be at least as many `2`'s available to pair with the `5`'s
   * Remember to account for the fact that `25 = 5 * 5`, `625 = 5 * 25`, etc.
### Excel Sheet Column Number (#171)
### Two Sum III - Data structure design (#170)
### Majority Element (#169)
### Excel Sheet Column Title (#168)
### Two Sum II - Input array is sorted (#167)
* Use two indices - one that starts at the leftmost index and moves rightwards and the other that starts are the rightmost index and moves leftwards
* if `val[leftindex] + val[rightindex] == target`, return `True`
   * Otherwise, if `val[leftindex] + val[rightindex] > target`, increment `leftindex`
   * Otherwise, decrement `rightindex`
### Intersection of Two Linked Lists (#160)
### Read N Characters Given Read4 (#157)
* If the stream has at least `N` characters, use `Read4()` `floor(N/4)` times to read all characters except the final `1-3` characters
   * For the last `1-3` characters, read `4` characters but serve back exactly as many characters as needed
* Otherwise, return as many characters as there are in the stream
### Min Stack (#155)
* Use a tuple of `(key, min_key)` to store in the stack, i.e., propagate the `min_key` up the stack
### Linked List Cycle (#141)
* Use fast and slow pointers
### Single Number (#136)
### Valid Palindrome (#125)
### Best Time to Buy and Sell Stock II (#122)
### Best Time to Buy and Sell Stock (#121)
### Pascal's Triangle II (#119)
### Pascal's Triangle (#118)
### Path Sum (#112)
### Minimum Depth of Binary Tree (#111)
### Balanced Binary Tree (#110)
### Convert Sorted Array to Binary Search Tree (#108)
### Binary Tree Level Order Traversal II (#107)
### Maximum Depth of Binary Tree (#104)
### Symmetric Tree (#101)
### Same Tree (#100)
### Merge Sorted Array (#88)
* Since this needs to be done in place, start writing in the final array from the back
* Use two **_read_** indices to keep a track of the **_next largest_** key in each of the two sorted arrays
* Use a **_write_** index to track the position the **_next larger_** key in the final array
### Remove Duplicates from Sorted List (#83)
### Climbing Stairs (#70)
### Sqrt(x) (#69)
* Use binary search with initial bounds as `1` and `n`
### Add Binary (#67)
### Plus One (#66)
### Length of Last Word (#58)
### Maximum Subarray (#53)
### Count and Say (#38)
### Search Insert Position (#35)
### Implement strStr() (#28)
### Remove Element (#27)
### Remove Duplicates from Sorted Array (#26)
### Merge Two Sorted Lists (#21)

### Valid Parentheses (#20)
### Longest Common Prefix (#14)
### Roman to Integer (#13)
### Palindrome Number (#9)
### Reverse Integer (#7)
### Two Sum (#1)