//
//  main.cpp
//  ParentingPartneringReturns
//
//  Created by Alexis Quinto on 5/3/20.
//  Copyright © 2020 Alexis Quinto. All rights reserved.
//

#include <vector>
#include <utility>
#include <algorithm>
#include <string>

void test() {
    int N;
    scanf("%d", &N);
    
    std::vector<std::pair<std::pair<int, int>, int>> scheds;
    for (int i = 0; i < N; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        scheds.emplace_back(std::make_pair(l, r), i);
    }
    
    std::sort(scheds.begin(), scheds.end());
    std::string answer(N, '?');
    int A = 0, B = 0;
    for (auto pp : scheds) {
        int low = pp.first.first;
        int high = pp.first.second;
        int id = pp.second;
        if (A <= low) {
            A = high;
            answer[id] = 'C';
        } else if (B <= low) {
            B = high;
            answer[id] = 'J';
        } else {
            answer = "IMPOSSIBLE";
            break;
        }
    }
    
    printf("%s\n", answer.c_str());
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
