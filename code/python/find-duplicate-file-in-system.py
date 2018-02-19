# 02/19/2018
#  Time : O(n*s), s = avg. file content size (assuming s >> filename size)
# Space : O(n*s)

class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        
        # For each dir entry, return a list of absolute filename -> content tuples
        def get_files_and_contents(dir_info):
            import re, os.path
            tokens = dir_info.split()
            result = []
            pattern = re.compile(r'(?P<name>.*)\((?P<content>.*)\)')
            for entry in tokens[1:]:
                match = pattern.match(entry)
                result.append((os.path.join(tokens[0], match.group('name')), match.group('content')))
            return result
        
        # Iterate over all the (absolute) filename -> content tuples and create entries
        # in a map content -> list of filenames with this content; use a hash map to
        # obtain O(1) lookup time
        import collections
        grouped = collections.defaultdict(list)
        for dir_info in paths:
            for filename, contents in get_files_and_contents(dir_info):
                grouped[contents].append(filename)
        return [group for group in grouped.values() if len(group) > 1]
