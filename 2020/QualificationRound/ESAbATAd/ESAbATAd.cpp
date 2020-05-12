//
//  main.cpp
//  ESAbATAd
//
//  Created by Alexis Quinto on 5/7/20.
//  Copyright © 2020 Alexis Quinto. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <algorithm>
#include <string>
#include <vector>

int B;

int query(int i) {
    std::cout << i << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void test() {
    int L = 1;
    int R = B;
    std::vector<int> answer(B + 1);
    
    for (int p = 1; true; p+=2) {
        if (p % 10 == 1 && p != 1) {
            int same = -1;
            int diff = -1;
            for (int i = 1; i < L; ++i) {
                if (answer[i] == answer[B + 1 - i]) {
                    same = i;
                } else {
                    diff = i;
                }
            }
            
            if (same == -1) {
                int k = query(1);
                if (k != answer[1]) {
                    for (int i = 1; i <= L; ++i) {
                        answer[i] ^= 1;
                    }
                    
                    for (int i = R; i <= B; ++i) {
                        answer[i] ^= 1;
                    }
                }
                query(1);
            } else {
                int k = query(same);
                if (k != answer[same]) {
                    for (int i = 1; i <= L; ++i) {
                        answer[i] ^= 1;
                    }
                    for (int i = R; i <= B; ++i) {
                        answer[i] ^= 1;
                    }
                }
                
                if (diff == -1) {
                    query(same);
                } else {
                    if (query(diff) != answer[diff]) {
                        std::reverse(answer.begin() + 1, answer.end());
                    }
                }
            }
            
            p += 2;
        }
        
        answer[L] = query(L);
        answer[R] = query(R);
        L++;
        R--;
        
        if (L > R) {
            for (int i = 1; i <= B; ++i) {
                std::cout << answer[i];
            }
            std::cout << std::endl;
            std::string res;
            std::cin >> res;
            assert(res == "Y");
            return;
        }
    }
}

int main(int argc, const char * argv[]) {
    int T;
    scanf("%d%d", &T, &B);
    
    for (int tc = 1; tc <= T; ++tc) {
        test();
    }
    
    return 0;
}
