//
//  Vestigium.cpp
//  Google Code Jam
//
//  Created by Alexis Quinto on 5/3/20.
//  Copyright © 2020 Alexis Quinto. All rights reserved.
//

#include <stdio.h>
#include <set>
#include <vector>

int grid[1005][1005];

void test() {
    int N;
    scanf("%d", &N);
    std::vector<std::set<int>> rows(N+1), cols(N+1);
    long long trace = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &grid[i][j]);
            rows[i].insert(grid[i][j]);
            cols[j].insert(grid[i][j]);
            if (i == j) trace += grid[i][j];
        }
    }
    
    int badRows = 0, badCols = 0;
    for (int i = 0; i < N; ++i) {
        if (rows[i].size() != N) badRows++;
        if (cols[i].size() != N) badCols++;
    }
    
    printf("%lld %d %d\n", trace, badRows, badCols);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int tc = 1; tc <= T; ++tc) {
        printf("Case #%d: ", tc);
        test();
    }
    return 0;
}
