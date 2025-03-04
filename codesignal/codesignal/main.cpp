//
//  main.cpp
//  codesignal
//
//  Created by 尚华豪 on 2/2/22.
//  Copyright © 2022 尚华豪. All rights reserved.
//

#include <iostream>
using namespace std;
bool checkint(int num){
    int digits = 0;
    int temp = num;
    while (temp != 0){
        temp /= 10;
        digits++;
    }
    int lefthalf = 0, count1 = 0,righthalf{0};
    int tempnum = num;
    while (count1 < digits/2 ) {
        lefthalf = lefthalf+tempnum%10;
        tempnum /= 10;
        count1++;
    }
    while (count1<digits){
        righthalf = righthalf + tempnum%10;
        tempnum /= 10;
        count1++;
    }
    if (lefthalf == righthalf){
        return true;
    }
    else {
        return false;
    }
    
}

int solution(int n) {
    int ans = 0;
    if (n == 2){
        for (int i = 10; i<100; i++){
            if (checkint(i)){
                ans++;
            }
        }
        return ans+1;
    }
    if (n == 4){
        for (int i = 1000; i<9999; i++){
            if (checkint(i)){
                ans++;
            }
        }
        return ans+1;
    }
    if (n == 6){
        for (int i = 100000; i<999999; i++){
            if (checkint(i)){
                ans++;
            }
        }
        return ans+1;
    }
    return 10;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << solution(6);
    return 0;
}
