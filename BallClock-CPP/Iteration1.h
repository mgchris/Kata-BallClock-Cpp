//
//  Iteration1.h
//  BallClock-CPP
//
//  Created by Christopher Evans on 9/4/15.
//  Copyright (c) 2015 Morphosis Games. All rights reserved.
//

#ifndef __BallClock_CPP__Iteration1__
#define __BallClock_CPP__Iteration1__

#include <stdio.h>

#include <Vector>
#include <List>


class I1Track;

typedef std::vector<I1Track> I1Ramp;
typedef std::list<int> I1Queue;


class I1Track {
    
    I1Queue track;
    int currentIndex;
    int maxSize;
    
public:
    I1Track(int size);
    bool addBall(int ball, I1Queue &queue);
};

class I1Clock {
    int ballCount;
    I1Queue queue;
    I1Ramp tracks;
    
    void tick();
    
public:
    I1Clock(const int ballCount);
    
    int cycle();
};


#endif /* defined(__BallClock_CPP__Iteration1__) */
