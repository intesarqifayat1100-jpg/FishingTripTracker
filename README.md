# Fishing Trip Tracker

A C++ console application that simulates a fishing trip log using parallel arrays (`species` and `weights`) to track fish spotted in the lake and fish caught.

## How It Works
- Supports up to **10** logged fish (`MAXFISH = 10`) in the current lake log.
- Displays the current fish log at the start of each turn and offers three actions:
  1. **Display fish log:** Prints all logged fish species and their weights (`1` decimal place), or `No fish logged` if empty.
  2. **Add a fish seen:** Prompts for a species name, generates a random weight between `0.5` and `25.0` lbs, and appends it to the arrays.
  3. **Catch a fish:** Searches for a matching species, adds its weight to `totalWeightCaught`, removes that entry by shifting subsequent elements left, and decrements `fishCount`.
- Prompts `Continue? (y/n):` after each action and prints the **Final Fish Log** and **Total Weight of Fish Kept** upon exiting.

## Compiling & Running
Compile with `g++` (C++17) and run from the terminal:

```bash
g++ -std=c++17 -Wall -Wextra fishing_tracker.cpp -o fishing_tracker
./fishing_tracker
