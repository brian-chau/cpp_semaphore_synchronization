# vscpp_semaphores

I followed [this website's example](https://www.modernescpp.com/index.php/semaphores-in-c-20) and tweaked it slightly to handle something similar to [this Leetcode question](https://leetcode.com/problems/print-in-order/discuss/461686/c-semaphore).

The idea is to use C++20's semaphore library to synchronize the function calls.

When I remove the acquire/release calls, the executable seems to pick its own order -- after 100 runs, I somewhat noticed a pattern that 1 and 2 would switch back and forth in the first and second positions, while 2 and 3 would switch back and forth between the second and third positions.

Keeping the acquire/release calls in made the executable keep the order of 1 -> 2 -> 3 throughout all 100 runs.
