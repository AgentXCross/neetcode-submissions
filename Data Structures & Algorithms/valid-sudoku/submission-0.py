class Solution:
    def is_valid_row(self, row: List[str]) -> bool:
        seen = {}
        for char in row:
            if char == '.':
                continue
            if char in seen:
                return False
            else:
                seen[char] = 1
        return True

    def transpose_board(self, board: List[List[str]]) -> List[List[str]]:
        board_transpose = []
        for i in range(0, 9):
            new_row = []
            for row in board:
                new_row.append(row[i])
            board_transpose.append(new_row)
        return board_transpose

    def board_to_boxes(self, board: List[List[str]]) -> List[List[str]]:
        top_left = [(0, 0), (3, 0), (6, 0), (0, 3), (3, 3), (6, 3), (0, 6), (3, 6), (6, 6)]
        bottom_right = [(2, 2), (5, 2), (8, 2), (2, 5), (5, 5), (8, 5), (2, 8), (5, 8), (8, 8)]
        board_as_box = []
        for t_l, b_r in zip(top_left, bottom_right):
            box = []
            for i in range(t_l[0], b_r[0] + 1):
                for j in range(t_l[1], b_r[1] + 1):
                    box.append(board[i][j])
            board_as_box.append(box)
        return board_as_box

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for row in board:
            if not self.is_valid_row(row):
                return False
            
        board_transpose = self.transpose_board(board)
        for column in board_transpose:
            if not self.is_valid_row(column):
                return False
        
        # Check every box
        board_by_box = self.board_to_boxes(board)
        for box in board_by_box:
            if not self.is_valid_row(box):
                return False
        return True
