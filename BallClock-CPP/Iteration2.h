//
//  Simple.h
//  BallClock-CPP
//
//  Created by Christopher Evans on 9/1/15.
//  Copyright (c) 2015 Morphosis Games. All rights reserved.
//

#ifndef __BallClock_CPP__Simple__
#define __BallClock_CPP__Simple__

#include <stdio.h>
#include <Deque>
#include <vector>

class I2Track;

typedef std::vector<I2Track> I2Ramp;
typedef std::deque<int> I2Queue;


class I2Track {
    
    int* track;
    int currentIndex;
    int maxSize;

public:
    I2Track(int size);
    I2Track(const I2Track& copy);
    ~I2Track();
    bool addBall(int ball, I2Queue &queue);
};

class I2Clock {
    int ballCount;
    I2Queue queue;
    I2Ramp tracks;

    void tick();
    
public:
    I2Clock(const int ballCount);
    
    int cycle();
};

#endif /* defined(__BallClock_CPP__Simple__) */
