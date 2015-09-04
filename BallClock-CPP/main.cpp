//
//  main.cpp
//  BallClock-CPP
//
//  Created by Christopher Evans on 9/1/15.
//  Copyright (c) 2015 Morphosis Games. All rights reserved.
//

#include <iostream>
#include "Iteration1.h"
#include "Iteration2.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    auto startTime = std::chrono::high_resolution_clock::now();
    
    for (int idx = 27; idx <= 127; ++idx) {
        //auto clock = I1Clock(idx);
        auto clock = I2Clock(idx);
        auto startCycle = std::chrono::high_resolution_clock::now();
        auto days = clock.cycle();
        auto endCycle = std::chrono::high_resolution_clock::now();
        auto msCycle = std::chrono::duration_cast<std::chrono::milliseconds>(endCycle - startCycle).count();
        
        std::cout << idx << " balls cycle after " << days << " days. Time:" << msCycle << "\n";
    }
    
    auto endTime = std::chrono::high_resolution_clock::now();
    
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(endTime - startTime).count();

    std::cout << "Time:" << " In Minutes: " << minutes << " In Seconds: " << seconds << " In Milliseconds: " << milliseconds << "\n";
    
    return 0;
}
