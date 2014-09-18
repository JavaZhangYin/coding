#include <stdexcept>
#include <iostream>
#include <limits>

using namespace std;

#include "MyArray.hpp"
#include "MyLink.hpp"
#include "MyObject.hpp"
#include "MyContainer.hpp"
#include "MyQueue.hpp"
#include <stdexcept>
#include "MyAlgorithms.hpp"

using namespace ADT;

Solution& Solver::Solve(Solution const& initial) {
  bestSolution = 0;
  bestObjective = numeric_limits<int>::max();
  DoSolve(initial);
  
  if(bestSolution == 0)
    throw std::domain_error("no feasible solution found");
  return *bestSolution;
}

void Solver::UpdateBest(Solution const& solution) {
  if(solution.IsFeasible() && solution.Objective() < bestObjective)
    {
      delete bestSolution;
      bestSolution = &(solution.Clone());
      bestObjective = solution.Objective();
    }
}

void DepthFirstSolver::DoSolve(Solution const& solution) {
  if(solution.IsComplete())
    UpdateBest(solution);
  else
    {
      Iterator& i = solution.Successors();
      while(!i.IsDone())
	{
	  Solution& successor = dynamic_cast<Solution&>(*i);
	  DoSolve(successor);
	  delete &successor;
	  ++i;
	}
      delete &i;
    }
}

void BreadthFirstSolver::DoSolve(Solution const& initial) {
  Queue& queue = *new QueueAsLinkedList();
  queue.EnQueue(initial.Clone());
  while(!queue.IsEmpty())
    {
      Solution& solution = dynamic_cast<Solution&>(queue.DeQueue());
      if(solution.IsComplete())
	UpdateBest(solution);
      else
	{
	  Iterator& i = solution.Successors();
	  while(!i.IsDone())
	    {
	      Solution& succ = dynamic_cast<Solution&>(*i);
	      queue.EnQueue(succ);
	      ++i;
	      
	    }
	  delete &i;
	  
	}
      delete &solution;
    }
  delete &queue;
  
}

void DepthFirstBranchAndBoundSolver::DoSolve(Solution const& solution){
  if(solution.IsComplete())
    UpdateBest(solution);
  else
    {
      Iterator& i = solution.Successors();
      while(!i.IsDone())
	{
	  Solution& successor = dynamic_cast<Solution&>(*i);
	  if(successor.IsFeasible() && successor.Bound() < bestObjective)
	    DoSolve(successor);
	  delete &successor;
	  ++i;
	}
      delete &i;
    }
}

