from collections import Counter
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_map = {}
        for str in strs:
            if Counter(str) not in anagram_map.keys():
                anagram_map[Counter(str)] = []
                anagram_map[Counter(str)].append(str)
            else:
                anagram_map[Counter(str)].append(str)
        return anagram_map.values()