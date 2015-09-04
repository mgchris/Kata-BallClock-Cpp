//
//  Iteration1.cpp
//  BallClock-CPP
//
//  Created by Christopher Evans on 9/4/15.
//  Copyright (c) 2015 Morphosis Games. All rights reserved.
//

#include "Iteration1.h"

#pragma mark - Track

I1Track::I1Track(int size) {
    track = I1Queue();
    maxSize = size;
}


bool I1Track::addBall(int ball, I1Queue &queue) {
    auto added = false;

    if (track.size() < maxSize) {
        track.push_back(ball);
        added = true;
    } else {
        track.reverse();
        for (auto it = track.begin(); it != track.end(); ++it) {
            queue.push_back(*it);
        }
        track.clear();
    }
    
    return added;
}

#pragma mark - Clock
I1Clock::I1Clock(const int ballCount) {
    this->ballCount = ballCount;
    
    queue = I1Queue();
    
    tracks.push_back(I1Track(4));
    tracks.push_back(I1Track(11));
    tracks.push_back(I1Track(11));
    
    
    for (int idx = 0; idx < ballCount; idx++) {
        queue.push_back(idx);
    }
}

void I1Clock::tick() {
    
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

int I1Clock::cycle() {
    auto totalTicks = 0;
    auto queueCopy(queue);
    
    while (true) {
        totalTicks++;
        
        tick();
        
        if (queueCopy == queue) {
            break;
        }
    }
    
    return totalTicks / 24 / 60;
}