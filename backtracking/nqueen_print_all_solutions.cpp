/**
 * @brief [Eight Queens](https://en.wikipedia.org/wiki/Eight_queens_puzzle) puzzle, printing all solutions
 */
#include <array>     /// for std::array
#include <iostream>  /// for IO operations

namespace backtracking { namespace n_queens_all_solutions {
  /**
   * @brief Utility function to print matrix
   * @tparam n number of matrix size
   * @param board matrix where numbers are saved
   */
  template <size_t n>
  void PrintSol(const std::array<std::array<int, n>, n>& board) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << board[i][j] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  /**
   * @brief Check if a queen can be placed on the matrix
   * @tparam n number of matrix size
   * @param board matrix where numbers are saved
   * @param row current index in rows
   * @param col current index in columns
   * @returns `true` if queen can be placed on matrix
   * @returns `false` if queen can't be placed on matrix
   */
  template <size_t n>
  bool CanIMove(const std::array<std::array<int, n>, n>& board, int row, int col) {
    /// check in the row
    for (int i = 0; i < col; i++) {
      if (board[row][i] == 1) {
        return false;
      }
    }
    /// check the first diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 1) {
        return false;
      }
    }
    /// check the second diagonal
    for (int i = row, j = col; i <= n - 1 && j >= 0; i++, j--) {
      if (board[i][j] == 1) {
        return false;
      }
    }
    return true;
  }

  /**
     * @brief Main function to solve the N Queens problem
     * @tparam n number of matrix size
     * @param board matrix where numbers are saved
     * @param col current index in columns
     */
  template <size_t n>
  void NQueenSol(std::array<std::array<int, n>, n> board, int col) {
    if (col >= n) {
      PrintSol(board);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (CanIMove(board, i, col)) {
        board[i][col] = 1;
        NQueenSol(board, col + 1);
        board[i][col] = 0;
      }
    }
  }
}}  // namespace backtracking::n_queens_all_solutions

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
const int n = 4;
std::array<std::array<int, n>, n> board{0};

backtracking::n_queens_all_solutions::NQueenSol(board, 0);
}
