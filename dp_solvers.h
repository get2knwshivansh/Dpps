#ifndef DP_SOLVERS_H
#define DP_SOLVERS_H

#include <vector>
#include <string>

int knapsackMemoization(int W, std::vector<int>& wt, std::vector<int>& val, int n);
int lcs(std::string X, std::string Y, int m, int n);
int coinChangeWays(std::vector<int>& coins, int amount);

#endif
