class Solution:
    def encode(self, strs: List[str]) -> str:
        return_str = ""
        for s in strs:
            return_str += f"{len(s)}#"
            return_str += s
        return return_str
    def decode(self, s: str) -> List[str]:
        return_strs = []
        read_idx = 0
        s_len = len(s)
        while read_idx < s_len:
            # Find the number
            cur_strlen = ""
            cur_str = ""
            while s[read_idx] != '#':
                cur_strlen += s[read_idx]
                read_idx += 1
            cur_strlen = int(cur_strlen)
            read_idx += 1
            # Word starts here
            for i in range(cur_strlen):
                cur_str += s[read_idx]
                read_idx += 1
            return_strs.append(cur_str)
        return return_strs


