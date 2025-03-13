#include "dp_solvers.h"
#include <iostream>
#include <vector>
#include <graphics.h>

using namespace std;

// ✅ CLI Menu
void displayMenu() {
    cout << "\n===== Dynamic Programming Solver =====\n";
    cout << "1. Solve Knapsack (Memoization)\n";
    cout << "2. Solve LCS (Longest Common Subsequence)\n";
    cout << "3. Solve Coin Change (Tabulation)\n";
    cout << "4. Exit\n";
}

void knapsackSolver() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> wt(n), val(n);

    cout << "Enter weights of items: ";
    for (int &w : wt) cin >> w;

    cout << "Enter values of items: ";
    for (int &v : val) cin >> v;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int maxValue = knapsackMemoization(W, wt, val, n);
    cout << "Maximum Value in Knapsack: " << maxValue << "\n";
}

void guiDisplay() {
    initwindow(800, 600, "DP Solver GUI");

    setcolor(WHITE);
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(250, 100, "Dynamic Programming Solver");

    settextstyle(8, HORIZ_DIR, 2);
    outtextxy(200, 200, "1. Knapsack Problem");
    outtextxy(200, 250, "2. LCS Problem");
    outtextxy(200, 300, "3. Coin Change Problem");

    while (!kbhit()) delay(100);

    closegraph();
}

void runCLI() {
    while (true) {
        displayMenu();
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) knapsackSolver();
        else if (choice == 2) {
            string X, Y;
            cout << "Enter first string: ";
            cin >> X;
            cout << "Enter second string: ";
            cin >> Y;
            cout << "LCS Length: " << lcs(X, Y, X.length(), Y.length()) << "\n";
        }
        else if (choice == 3) {
            int n, amount;
            cout << "Enter number of coins: ";
            cin >> n;
            vector<int> coins(n);
            cout << "Enter coin values: ";
            for (int &c : coins) cin >> c;
            cout << "Ways to make change: " << coinChangeWays(coins, amount) << "\n";
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
    }
}
