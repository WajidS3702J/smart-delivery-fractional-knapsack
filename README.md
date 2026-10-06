# smart-delivery-fractional-knapsack
Menu-driven C program that solves the Fractional Knapsack problem using the Greedy method to maximize the value of packages loaded in a delivery vehicle.
Smart Delivery Planning – Fractional Knapsack
PBLE project for Analysis of Algorithms (S.E. Semester III, Computer Engineering, VIT Mumbai).

Each package has a value and a weight, and a delivery vehicle has a fixed capacity. Packages can be split, so the program ranks them by value/weight ratio and loads the highest-ratio ones first, taking a fraction of the last package if it doesn't fit completely. This gives the maximum possible value.

Algorithm: Greedy (Fractional Knapsack)
Language: C
Time complexity: O(n²) with Bubble Sort (O(n log n) possible with qsort or Merge Sort)
Space complexity: O(n)
