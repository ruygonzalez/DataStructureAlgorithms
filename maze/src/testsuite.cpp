/**
 * @file testsuite.cpp
 * @author Ellen Price <<eprice@caltech.edu>>
 * @version 1.0
 * @date 2014-2015
 * @copyright see License section
 *
 * @brief Performs tests of the CoordinateQueue and CoordinateStack classes.
 *
 * @section License
 * Copyright (c) 2014-2015 California Institute of Technology.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the  nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the California Institute of Technology.
 *
 */

#include <cstdio>
#include "CoordinateStack.hpp"
#include "CoordinateQueue.hpp"
#include <iostream>
using namespace std;

int main()
{
    Coordinate c;
    Coordinate d;
    Coordinate temp;
    CoordinateQueue *queue = new CoordinateQueue();
    CoordinateStack *stack = new CoordinateStack();
    c.x = 5; 
    c.y = 7;
    d.x = 12;
    d.y = 6;
    stack->push(c);
    temp = stack->peek();
    cout << "Pushed coordinate (5,7)" << endl;
    cout << "Pushed value: " << temp.x << " " << temp.y << endl;
    stack->push(d);
    temp = stack->peek();
    cout << "Pushed coordinate (12,6)" << endl;
    cout << "Pushed value: " << temp.x << " " << temp.y << endl;
    temp = stack->pop();
    cout << "Popped coordinate (12,6)" << endl;
    cout << "Popped value: " << temp.x << " " << temp.y << endl;
    temp = stack->pop();
    cout << "Popped coordinate (5,7)" << endl;
    cout << "Popped value: " << temp.x << " " << temp.y << endl;
    cout << "Attempting to pop empty stack " << endl;
    temp = stack->pop();

    queue->enqueue(c);
    temp = queue->peek();
    cout << "Enqueued coordinate (5,7)" << endl;
    cout << "Enqueued value: " << temp.x << " " << temp.y << endl;
    queue->enqueue(d);
    temp = queue->peek();
    cout << "Enqueued coordinate (12,6)" << endl;
    cout << "Value in front should still be (5,7) : " << temp.x << " " << temp.y << endl;
    temp = queue->dequeue();
    cout << "Dequeued coordinate (5,7)" << endl;
    cout << "Dequeued value: " << temp.x << " " << temp.y << endl;
    temp = queue->dequeue();
    cout << "Dequeued coordinate (12,6)" << endl;
    cout << "Dequeue value: " << temp.x << " " << temp.y << endl;
    cout << "Attempting to dequeue empty queue " << endl;
    temp = queue->dequeue();
    
    delete queue;
    delete stack;

    return 0;
}
