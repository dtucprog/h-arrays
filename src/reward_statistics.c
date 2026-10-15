#include <stddef.h>
#include <stdio.h>
constexpr int PLAYER_COUNT = 20, INTERVAL_COUNT = 10, REWARD_BASE = 10,
              REWARD_PER_HOUR = 1;
// Intervals
// 10-19
// 20-29
// ...
// 90-99
// >= 100
int main() {
  // Assume that we have received the following values:
  int played_hours[PLAYER_COUNT] = {10,     22, 12 * 7, 5 * 7, 1,     0,  0,
                                    16 * 7, 98, 32,     45,    50,    30, 50,
                                    34,     86, 7 * 7,  3 * 7, 9 * 7, 2};
  puts("Played hours: ");
  for (size_t i = 0; i < PLAYER_COUNT; ++i)
    printf("%d, ", played_hours[i]);
  puts("\n");

  // YOUR CODE HERE
  puts("Reward point statistics:");
  for (size_t i = 0; i < INTERVAL_COUNT - 1; ++i)
    printf("[%2zu - %2zu]: %d\n", (i + 1) * 10, (i + 1) * 10 + 9,
           reward_slots[i]);
  // Last slot
  printf("[ >= 100]: %d\n", reward_slots[INTERVAL_COUNT - 1]);
}