/**
 * @file BreadthFirstSolver.cpp
 * @author Ellen Price <<eprice@caltech.edu>>
 * @version 2.0
 * @date 2014-2015
 * @copyright see License section
 *
 * @brief Functions for maze solver that implements breadth-first search.
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

#include "BreadthFirstSolver.hpp"

/**
 * @brief Initializes the solver.
 *
 * @param[in] app Pointer to the main MazeSolverApp class.
 */
BreadthFirstSolver::BreadthFirstSolver(class MazeSolverApp *app)
{
    queue = new CoordinateQueue(app);
    init();
}

/**
 * @brief Initializes the solver (student-implemented).
 */
void BreadthFirstSolver::init()
{
    for(int i = 0; i < WIDTH; i++)
        for(int j = 0; j < HEIGHT; j++){
            visited[i][j].visited = false;
	        Coordinate c = Coordinate();
	        visited[i][j].from = c;
	}
    high = Coordinate();
}

/**
 * @brief Deinitializes the solver.
 */
BreadthFirstSolver::~BreadthFirstSolver()
{
    delete queue;
    deinit();
}

/**
 * @brief Deinitializes the solver (student-implemented).
 */
void BreadthFirstSolver::deinit()
{
    // no new structures creates other than the queue deleted above
}

/**
 * @brief Solve the maze given by `maze`.
 *
 * @param[in] maze MazeGrid object that stores the maze to be
 * solved.
 */
void BreadthFirstSolver::solve(MazeGrid *maze)
{
    Coordinate h = Coordinate();
    h.x = MAZE_START_X;
    h.y = MAZE_START_Y;
    high = h;
    queue->enqueue(h);
    Coordinate c;
    visited[MAZE_START_X][MAZE_START_Y].visited = true;
    while(!queue->is_empty()){
        if((queue->peek()).x == MAZE_END_X && (queue->peek()).y == MAZE_END_Y){
            break;
        }
        c = queue->dequeue();
        high = c;
        Coordinate temp = Coordinate();
        temp.x = c.x;
        temp.y = c.y;
        int res = maze->get_possible_moves(c.x, c.y);
		if (res & E) {
		/* We can move east from (1, 2) to (2, 2). */
			temp.x += 1;
			if(!(visited[temp.x][temp.y].visited)){
				queue->enqueue(temp);
                visited[temp.x][temp.y].visited = true;
                visited[temp.x][temp.y].from = c;
			}
		}
    	temp.x = c.x;
    	temp.y = c.y;
		if (res & S) {
		/* We can move south from (1, 2) to (1, 3). */
			temp.y += 1;
 			if(!(visited[temp.x][temp.y].visited)){
		    	queue->enqueue(temp);
                visited[temp.x][temp.y].visited = true;
                visited[temp.x][temp.y].from = c;
			}
		}
		temp.x = c.x;
    	temp.y = c.y;
		if (res & N) {
		/* We can move north from (1, 2) to (1, 1). */
			temp.y -= 1;
			if(!(visited[temp.x][temp.y].visited)){
		    	queue->enqueue(temp);
                visited[temp.x][temp.y].visited = true;
                visited[temp.x][temp.y].from = c;
			}
		}
        temp.x = c.x;
        temp.y = c.y;
		if (res & W) {
		/* We can move west from (1, 2) to (0, 2). */
			temp.x -= 1;
			if(!(visited[temp.x][temp.y].visited)){
       			queue->enqueue(temp);
                visited[temp.x][temp.y].visited = true;
                visited[temp.x][temp.y].from = c;
			}
		}
    }    
    c = queue->dequeue(); 
    high = c;
    visited[c.x][c.y].visited = true;

    /*
     *
     * You are provided a member variable `visited` that stores
     * (bool, Coordinate) pairs describing whether a square has already
     * been checked and the square immediately preceding it in the path.
     * You are responsible for maintaining this array, filling it with
     * useful information, and using it in a consistent way. */
}

/**
 * @brief Retrieves the current path through the maze.
 *
 * @return Vector storing the current path through the maze.
 */
vector<Coordinate> BreadthFirstSolver::get_path()
{
    vector<Coordinate> list;
    Coordinate current = high;
    list.push_back(current);
    while(current.x != MAZE_START_X || current.y != MAZE_START_Y){
        current = visited[current.x][current.y].from;
        list.push_back(current);
    }
    return list;
}

