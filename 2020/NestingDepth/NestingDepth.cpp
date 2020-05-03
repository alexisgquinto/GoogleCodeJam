//
//  NestingDepth.cpp
//  Google Code Jam
//
//  Created by Alexis Quinto on 5/3/20.
//  Copyright © 2020 Alexis Quinto. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>

void test() {
    char str[105];
    scanf("%s", str);
    
    int n = std::strlen(str);
    int depth = 0;
    for (int i = 0; i < n; ++i) {
        int digit = str[i] - '0';
        
        for (int i = 0; i < std::max(0, digit - depth); ++i) {
            printf("(");
        }
        for (int i = 0; i < std::max(0, depth - digit); ++i) {
            printf(")");
        }
        printf("%d", digit);
        depth = digit;
    }
    for (int i = 0; i < depth; ++i) {
        printf(")");
    }
    
    printf("\n");
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
