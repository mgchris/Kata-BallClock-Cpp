//
//  Simple.cpp
//  BallClock-CPP
//
//  Created by Christopher Evans on 9/1/15.
//  Copyright (c) 2015 Morphosis Games. All rights reserved.
//

#include "Iteration2.h"


#pragma mark - Track
I2Track::I2Track(int size) {
    track = new int[size];
    currentIndex = 0;
    maxSize = size;
}

I2Track::I2Track(const I2Track& copy) {
    maxSize = copy.maxSize;
    track = new int[maxSize];
    currentIndex = 0;
}

I2Track::~I2Track() {
    if (track != NULL) {
        delete track;
    }
}

bool I2Track::addBall(int ball, I2Queue &queue) {
    auto added = false;

    
    if (currentIndex < maxSize) {
        track[currentIndex] = ball;
        ++currentIndex;
        added = true;
    } else {
        for (int i = maxSize - 1; i >= 0; --i) {
            queue.push_back(track[i]);
            //track[i] = -1;
        }
        currentIndex = 0;
    }

    return added;
}

#pragma mark - Clock
I2Clock::I2Clock(const int ballCount) {
    this->ballCount = ballCount;
    
    queue = I2Queue();
    
    tracks.push_back(I2Track(4));
    tracks.push_back(I2Track(11));
    tracks.push_back(I2Track(11));
    
    
    for (int idx = 0; idx < ballCount; ++idx) {
        queue.push_back(idx);
    }
}

void I2Clock::tick() {
    
    auto ball = queue.front();
    auto added = false;
    
    for(auto &ramp : tracks) {
        if(ramp.addBall(ball, queue) ) {
            added = true;
            break;
        }
    }
    
    if (added == false) {
        queue.push_back(ball);
    }
    
    queue.pop_front();
    
}

int I2Clock::cycle() {
    auto totalTicks = 0;
    while (true) {
        ++totalTicks;
        
        tick();
        
        if(queue.size() == ballCount && queue.front() == 0) {
            
            auto idx = 0;
            auto match = true;
            for (auto it = queue.begin(); it != queue.end(); ++it) {
                if(idx != *it) {
                    match = false;
                    break;
                }
                ++idx;
            }
            
            if (match) {
                break;
            }
        }
    }
   
    return totalTicks / 24 / 60;  // Interesting: If I just return the ticks it is slower then if I change it to days
}





