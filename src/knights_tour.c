// Solves the Knight's tour problem

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

constexpr int SIZE = 8; // Board size
typedef int Board[SIZE][SIZE];

/* Knight move offsets.

The moves that a knight can make relative to the current position.
For example:
x += MOVES_X[0]; y += MOVES_Y[0]
corresponds to one of the eight moves that a knight can make, where `x` and
`y` represent the current position.
*/
constexpr size_t MOVE_COUNT = 8; // Number of moves that a knight can make.
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};
enum {
  NO_MOVE = MOVE_COUNT
}; // Identifier that reflects that none of the moves is possible. Used in
   // `move_*` functions.
typedef enum { GREEDY, WITH_ACCESSIBILITY_METRIC } Strategy;

// Prints the contents of the board.
void print_board(Board board) {
  // YOUR CODE HERE
}

/* Returns whether a move is possible from a position (x, y).

move_id: One of the 8 moves that the knight wants to make.
visits: A two-dimensional array that represents the squares. If a value is
positive, then the corresponding square was visited before. Returns true if the
move is possible.
*/
bool move_is_possible(size_t move_id, size_t x, size_t y, Board visited) {
  // YOUR CODE HERE
}

/* Calculates accessibility for each square based on the already visited
squares.

Accessibility describes for each square, how many other squares this square
is reachable from. For example a corner square is only reachable from two
other squares.

accessibility: Zero-initialized board, that is filled with
accessibility values.
visited: Describes for each square, whether it is visited or
not. If non-zero, then visited. For generating the general accessibility
table, `visited = {}`.
*/
void calculate_accessibility(Board accessibility, Board visited) {
  // YOUR CODE HERE
}

// Returns the move_id of the first possible move from (x, y) or NO_MOVE if
// none exists.
size_t move_greedy(size_t x, size_t y, Board visited) {
  // YOUR CODE HERE
}

// Returns the move_id of the least accessible move from (x, y) or NO_MOVE if
// none exists.
size_t move_with_accessibility_metric(size_t x, size_t y, Board visited) {
  // YOUR CODE HERE
}

// Returns the move selected by the given strategy on a given board.
size_t move(size_t x, size_t y, Board visited, Strategy strategy) {
  switch (strategy) {
  case GREEDY:
    return move_greedy(x, y, visited);
  case WITH_ACCESSIBILITY_METRIC:
    return move_with_accessibility_metric(x, y, visited);
  }
}

/* Attempts a tour by picking the first accessible square beginning at (x, y),
returns number of visited squares.

An array is created for the attempt.
print_result: If true, then the board is printed at the end of the tour.
*/
int tour(size_t x, size_t y, Strategy strategy, bool print_result) {
  Board visited = {};
  int visits = 1; // Total number of visited squares
  visited[y][x] = visits;

  // YOUR CODE HERE
  return visits;
}

/* Attempts tours beginning from each square on the board and
annotates the number of visited squares, e.g.,:

15  8 15 15
10  6  4 15
 8 10 14 14
14 14 14 11

15 in the left top corner means that the tour from the square (0, 0) could visit
15 squares and not more.
*/
void tour_from_each_square(Board tour_lengths, Strategy strategy) {
  for (size_t y = 0; y < SIZE; ++y)
    for (size_t x = 0; x < SIZE; ++x)
      tour_lengths[y][x] = tour(x, y, strategy, false);
}

int main() {
  Board visits_greedy = {};
  tour_from_each_square(visits_greedy, GREEDY);
  puts("Visited squares starting from each square");
  puts("Greedy:");
  print_board(visits_greedy);
  puts("");

  puts("Example tour with greedy strategy:");
  tour(0, 1, GREEDY, true);
  puts("");

  puts("Accessibility table:");
  Board accessibility = {};
  calculate_accessibility(accessibility, (Board){});
  print_board(accessibility);
  puts("");

  Board visits_accessibility = {};
  tour_from_each_square(visits_accessibility, WITH_ACCESSIBILITY_METRIC);
  puts("Visited squares starting from each square");
  puts("With accessibility metric:");
  print_board(visits_accessibility);
  puts("");

  puts("Example tour with accessibility metric:");
  tour(0, 1, WITH_ACCESSIBILITY_METRIC, true);
  puts("");
}