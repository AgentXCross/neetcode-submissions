from collections import Counter, defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_map = defaultdict(list)
        for str in strs:
            key = tuple(sorted(Counter(str)))
            anagram_map[key].append(str)
        return anagram_map.values()