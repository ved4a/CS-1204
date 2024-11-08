// Redoing the following problem from midterm (which I bombed...)

// A set of n candidates are interested in enrolling in the school boxing team. The coach asks
// all candidates to line up in random order. In the initial round of screening the coach wants
// a tall candidate to spar with multiple short candidates, and thus uses a simple algorithm. They 
// pair each candidate with the immediately next taller candidate on the right in the line.
// For instance, if the array represents the heights of 4 students in feet (in the order in which
// they stand in the line), the returned sparring pairs are (5.5, 6.2), (5.4,6.2), (6.2, NULL), and (5.8,NULL).
// Note that 6.2 and 5.8 candidates have no taller candidate on the right. Provide a pseudocode to
// implement the algorithm to return all sparring pairs and comment on its worst case time complexity.

#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    float data;
    Node *next;
} *Head = NULL;