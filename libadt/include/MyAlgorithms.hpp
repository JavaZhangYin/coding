#ifndef MY_ALGORITHMS
#define MY_ALGORITHMS

/**
 *@file MyAlgorithms.hpp head file of algorithms
 *@author leizhou(13howk@sina.com)
 */

namespace ADT
{
  /**
   *@brief define of class Solution 
   */
  class Solution : public Object
    {
    public:
      /**
       *@brief test the solution is feasible
       *@param void
       *@return return true if feasible else false
       */
      virtual bool IsFeasible() const = 0;//如果解实例是给定问题的一个可行解, 则这个函数返回真
      /**
       *@brief test the solution is complete
       *@param void
       *@return return true if conplete else false
       */
      virtual bool IsComplete() const = 0;//如果解实例是给定问题的一个完全解, 则这个函数返回真
      /**
       *@brief retrun the value by the objective function in the solution
       *@param void
       *@return the value of int
       */
      virtual int Objective() const = 0;//这个函数返回目标函数对给定解实例的求值
      /**
       *@brief get the sub bound for the solution
       *@param void
       *@return bound value of int
       */
      virtual int Bound() const = 0;//这个函数为给定的解实例及从他导出的所有解返回一个关于目标函数的下届值(如果存在的话)
      /**
       *@brief clone the solution
       *@param void
       *@return solution reference of the clone's 
       */
      virtual Solution& Clone() const = 0;//这个函数用于复制给定的解实例
      /**
       *@brief get the iterator for the success solutions
       *@param void
       *@return iterator refernece of new(need delete self)
       */
      virtual Iterator& Successors() const = 0;
    };

  /**
   *@brief define of class Solver 
   */
  class Solver
    {
    protected:
      Solution* bestSolution; ///< pointer of best solution
      int bestObjective; ///< value by the objective function for best solution
      /**
       *@brief update the best solution
       *@param solution that update the best solution by that
       *@return void
       */
      void UpdateBest(Solution const&);
      /**
       *@brief solve the problem, abstract fuction, need realize by the subclass
       *@param solution for the problem
       *@return void
       */
      virtual void DoSolve(Solution const&) = 0;
    public:
      /**
       *@brief interface for solve the problem
       *@param solution for the problem
       *@return void
       */
      virtual Solution& Solve(Solution const&); 
    };
  /**
   *@brief define of class depth first Solver 
   */
  class DepthFirstSolver : public Solver
    {
      /**
       *@brief solve the problem
       *@param solution for the problem
       *@return void
       */
      void DoSolve(Solution const&);
    };

  /**
   *@brief define of class breadth first Solver 
   */
  class BreadthFirstSolver : public Solver
    {
      /**
       *@brief solve the problem
       *@param solution for the problem
       *@return void
       */
      void DoSolve(Solution const&);
    };

  /**
   *@brief define of class depth first branch and bound Solver
   */
  class DepthFirstBranchAndBoundSolver : public Solver
    {
      /**
       *@brief solve the problem
       *@param solution for the problem
       *@return void
       */
      void DoSolve(Solution const&);
    };
};

#endif//My_ALGORITHMS
