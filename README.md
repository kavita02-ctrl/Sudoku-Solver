# Sudoku is a 9x9 grid divided into 3x3 subgrids, where some cells are pre-filled with numbers (1-9).
  Each row must contain all numbers from 1 to 9 without repetition.
  Each column must contain all numbers from 1 to 9 without repetition.
  Each of the nine 3x3 subgrids must also contain all numbers from 1 to 9 without repetition.
  The goal is to fill the empty cells (represented by 0) in the grid such that all the above rules are satisfied.


# Algorithm Used
 # Backtracking
    A recursive algorithm that tries to build a solution incrementally. If it encounters a situation where no valid move can be made, it backtracks by undoing the last move and trying a different option.