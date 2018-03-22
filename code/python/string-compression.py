# Date  : 3/22
# Time  : O(n)
# Space : O(1); technically O(lg(n)) in worst case

class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        if not chars:
            return 0
        
        def write_encoded(char, str_count):
            nonlocal i_write
            chars[i_write] = char
            i_write += 1
            if str_count == '1':
                return
            chars[i_write : i_write + len(str_count)] = str_count
            i_write += len(str_count)
        
        i_write, count = 0, 1
        for i_read in range(1, len(chars)):
            if chars[i_read - 1] == chars[i_read]:
                count += 1
            else:
                write_encoded(chars[i_read - 1], str(count))
                count = 1
        write_encoded(chars[-1], str(count))
        
        del chars[i_write:]
        return len(chars)
