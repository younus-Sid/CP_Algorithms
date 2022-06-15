# What is Dynamic Programming
Dynamic programming is a technique that breaks the problems into sub-problems, and saves the result for future purposes so that we do not need to compute the result again.
The subproblems are optimized to optimize the overall solution is known as optimal substructure property.
The main use of dynamic programming is to solve optimization problems. Here, optimization problems mean that when we are trying to find out the minimum or the maximum solution of a problem.
The dynamic programming guarantees to find the optimal solution of a problem if the solution exists.

Dynamic programming approach is similar to divide and conquer in breaking down the problem into smaller and yet smaller possible sub-problems.
But unlike, divide and conquer, these sub-problems are not solved independently.
Rather, results of these smaller sub-problems are remembered and used for similar or overlapping sub-problems.

Dynamic programming is used where we have problems, which can be divided into similar sub-problems, so that their results can be re-used.
Mostly, these algorithms are used for optimization. Before solving the in-hand sub-problem, dynamic algorithm will try to examine the results of the previously solved sub-problems.
The solutions of sub-problems are combined in order to achieve the best solution.

So we can say that −
The problem should be able to be divided into smaller overlapping sub-problem.
An optimum solution can be achieved by using an optimum solution of smaller sub-problems.
Dynamic algorithms use Memoization.

The following vedio tutorial by CS Dojo will help you understand the concept more easily.\
Link: https://youtu.be/vYquumk4nWw

# Comparison with other algorithms
In contrast to greedy algorithms, where local optimization is addressed, dynamic algorithms are motivated for an overall optimization of the problem.

In contrast to divide and conquer algorithms, where solutions are combined to achieve an overall solution, dynamic algorithms use the output of a smaller sub-problem and then try to optimize a bigger sub-problem.
Dynamic algorithms use Memoization to remember the output of already solved sub-problems.

# Examples
The following computer problems can be solved using dynamic programming approach −
<ul>
  <li>Fibonacci number series</li>
  <li>Knapsack problem</li>
  <li>Tower of Hanoi</li>
  <li>All pair shortest path by Floyd-Warshall</li>
  <li>Shortest path by Dijkstra</li>
  <li>Project scheduling</li>
</ul>
