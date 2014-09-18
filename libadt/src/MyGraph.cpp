#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdarg>
using namespace std;

#include "common.h"
#include "debug.h"
#include "log.h"

#include "MyMacro.hpp"
#include "MyArray.hpp"
#include "MyLink.hpp"
#include "MyObject.hpp"
#include "MyContainer.hpp"
#include "MyAssociation.hpp"
#include "MyStack.hpp"
#include "MyQueue.hpp"
#include "MyTree.hpp"
#include "MyHeap.hpp"
#include "MyGraph.hpp"

using namespace ADT;
////////////////////////////////////////////////////////////
Vertex::Vertex(Vertex::Number n) : number(n) {}

Vertex::operator Number() const { return number; }

int Vertex::CompareTo(Object const& object) const
{
  Vertex const& vertex = dynamic_cast<Vertex const&> (object);
  return ::Compare(number, vertex.number);
}
HashValue Vertex::Hash() const
{
  return ::Hash(number);
}
void Vertex::Put(ostream& s) const
{
  s << "Vertex{" << number << "}";
}
////////////////////////////////////////////////////////////
Edge::Edge(Vertex& _v0, Vertex& _v1) :
  v0(_v0),
  v1(_v1)
{}

Vertex& Edge::V0() const
{
  return v0;
}

Vertex& Edge::V1() const
{
  return v1;
}
Vertex& Edge::Mate(Vertex const& vx) const
{
  if(v0 == vx)
    return v1;
  else if(v1 == vx)
    return v0;
  else
    throw std::invalid_argument("invalid argument!");
}

int Edge::CompareTo(Object const& object) const
{
  Edge const& edge = 
    dynamic_cast<Edge const&> (object);
  int i = ::Compare(v0, edge.V0());
  if( i == 0)
    {
      i = ::Compare(v1, edge.V1());
    }
  return i;
}

HashValue Edge::Hash() const
{
  char sz[64];
  sprintf(sz, "%d%d", (Vertex::Number)v0, (Vertex::Number)v1);
  return ::Hash(std::string(sz));
}

void Edge::Put(ostream& s) const
{
  s << "Edge{" << v0 << ", " << v1<< "}";
}

///////////////////////////////////////////////////////
CountingVisitor::CountingVisitor() : 
  nCount(0)
{}

void CountingVisitor::Visit(Object&)
{
  nCount++;
}

unsigned int CountingVisitor::GetCount() const
{
  return nCount;
}
///////////////////////////////////////////////////////

Graph::Graph()
{}

unsigned int Graph::GetNumberOfEdges() const
{
  return nNumberOfEdges;
}

unsigned int Graph::GetNumberOfVertices() const
{
  return nNumberOfVertices;
}

int Graph::CompareTo(Object const& object) const
{
  return 0;
}

Vertex& Graph::operator [](Vertex::Number n) const
{
  return SelectVertex(n);
}

bool Graph::IsConnected() const
{
  CountingVisitor visitor;
  PreOrder order(visitor);
  DepthFirstTraversal(order, SelectVertex(0));
  return visitor.GetCount() == nNumberOfVertices;
}

bool Graph::IsCyclic() const
{
  return false;
}

void Graph::DepthFirstTraversal(PrePostVisitor& visitor, 
				Vertex const& start) const
{
  Array<bool> visited(nNumberOfVertices);
  for(Vertex::Number v = 0; v < nNumberOfVertices; v++)
    visited[v] = false;
  DepthFirstTraversal(visitor, const_cast<Vertex&>(start), visited);
}

void Graph::DepthFirstTraversal(PrePostVisitor& visitor, 
				Vertex& vertex, 
				Array<bool>& visited) const
{
  if(visitor.IsDone())
    return;
  visitor.PreVisit(vertex);
  visited[vertex] = true;
  Iterator& p = EmanatingEdges(vertex);
  while(!p.IsDone())
    {
      Edge& edge = dynamic_cast<Edge&>(*p);
      Vertex& to = edge.Mate(vertex);
      if(!visited[to])
	DepthFirstTraversal(visitor, to, visited);
      ++p;
    }
  delete &p;
  visitor.PostVisit(vertex);
}

void Graph::BreadthFirstTraversal(Visitor& visitor, Vertex const& start) const
{
  Array<bool> enqueued(nNumberOfVertices);
  for(Vertex::Number v = 0; v < nNumberOfVertices; v++)
    enqueued[v] = false;
  Queue& queue = *new QueueAsLinkedList();
  queue.RescindOwnership();

  enqueued[start] = true;
  queue.EnQueue(const_cast<Vertex&>(start));
  while(!queue.IsEmpty() && !visitor.IsDone())
    {
      Vertex& vertex = dynamic_cast<Vertex&>(queue.DeQueue());
      visitor.Visit(vertex);
      Iterator& p = EmanatingEdges(vertex);
      while(!p.IsDone())
	{
	  Edge& edge = dynamic_cast<Edge&>(*p);
	  Vertex& to = edge.Mate(vertex);
	  if(!enqueued[to])
	    {
	      enqueued[to] = true;
	      queue.EnQueue(to);
	    }
	  ++p;
	}
      delete &p;
    }
  delete &queue;
}
/////////////////////////////////////////////////////////////////////
bool Digraph::IsConnected() const
{
  for(Vertex::Number v = 0; v < nNumberOfVertices; ++v)
    {
      CountingVisitor visitor;
      PreOrder order(visitor);
      DepthFirstTraversal(order, SelectVertex(v));
      if(visitor.GetCount() != nNumberOfVertices)
	return false;
    }
  return true;
}

bool Digraph::IsCyclic() const
{
  CountingVisitor visitor;
  TopologicalOrderTraversal(visitor);
  return visitor.GetCount() != nNumberOfVertices;
}

void Digraph::TopologicalOrderTraversal(Visitor& visitor) const
{
  Array<unsigned int>inDegree(nNumberOfVertices);
  for(Vertex::Number v = 0; v < nNumberOfVertices; v++)
    inDegree[v] = 0;
  Iterator& p = Edges();
  while(!p.IsDone())
    {
      Edge& edge = dynamic_cast<Edge&>(*p);
      ++inDegree[edge.V1()];
      ++p;
    }
  delete &p;

  Queue& queue = *new QueueAsLinkedList;
  queue.RescindOwnership();

  for(Vertex::Number v = 0; v < nNumberOfVertices; ++v)
    if(inDegree[v] == 0)
      queue.EnQueue(SelectVertex(v));

  while(!queue.IsEmpty() && !visitor.IsDone())
    {
      Vertex& vertex = dynamic_cast<Vertex&>(queue.DeQueue());
      visitor.Visit(vertex);
      Iterator& q = EmanatingEdges(vertex);
      while(!q.IsDone())
	{
	  Edge& edge = dynamic_cast<Edge&>(*q);
	  Vertex& to = edge.V1();
	  if(--inDegree[to] == 0)
	    queue.EnQueue(to);
	  ++q;
	}
      delete &q;
    }
  delete &queue;
}
/////////////////////////////////////////////////////////////////////
WeightedVertex::WeightedVertex(Vertex::Number n, Object& object) :
  Vertex(n),
  pWeight(&object)
{}

Object& WeightedVertex::GetWeight() const
{
  return *pWeight;
}
/////////////////////////////////////////////////////////////////////
WeightedEdge::WeightedEdge(Vertex& v0, Vertex& v1, Object& object) :
  Edge(v0, v1),
  pWeight(&object)
{}

Object& WeightedEdge::GetWeight() const
{
  return *pWeight;
}
/////////////////////////////////////////////////////////////////////
GraphAsMatrix::GraphAsMatrix(unsigned int n) :
  vertices(n),
  adjacencyMatrix(n, n),
  Graph()
{
  for(unsigned int i = 0; i < n; ++i)
    {
      vertices[i] = 0;
    }
  for(unsigned int i = 0; i < n; ++i)
    for(unsigned int j = 0; j < n; j++)
      {
	adjacencyMatrix[i][j] = 0;
      }
}

GraphAsMatrix::~GraphAsMatrix()
{
  Purge();
}

void GraphAsMatrix::Purge()
{
  if(IsOwner())
    {
      int index, row, column;
      int length;
      Vertex *vertex;
      Edge *edge;
      
      length = vertices.GetLength();

      for(index = 0; index< length; ++index)
	{
	  if(vertices[index])
	    delete vertices[index];
	  vertices[index] = 0;
	}
      for(row = 0; row < length; ++row)
	for(column = 0; column < row + 1; ++column)
	  if(adjacencyMatrix[row][column])
	    {
	      delete adjacencyMatrix[row][column];
	      adjacencyMatrix[row][column] = 0;
	    }
    }
}

void GraphAsMatrix::AddVertex(Vertex& vertex)
{
  DEBUG1("vertex = %d", Vertex::Number(vertex));
  DEBUG2("vertices[%d] = %d", Vertex::Number(vertex), vertices[Vertex::Number(vertex)]);
  Vertex* &p = vertices[Vertex::Number(vertex)];

  if(p != 0)
    throw std::invalid_argument("invalid argument");

  p = &vertex;
  ++nNumberOfVertices;
}

Vertex& GraphAsMatrix::SelectVertex(Vertex::Number n) const
{
  Vertex*& p = const_cast<Vertex*&>(vertices[n]);
  if(p == 0)
    throw std::invalid_argument("invalid argument");
  return *p;
}

void GraphAsMatrix::AddEdge(Edge& edge)
{
  Vertex& v0 = edge.V0();
  Vertex& v1 = edge.V1();
  
  Edge*& p0 = adjacencyMatrix[v0][v1];
  Edge*& p1 = adjacencyMatrix[v1][v0];
  
  if(p0 != 0 || p1 != 0)
    throw std::invalid_argument("invalid argument");
  
  p0 = &edge;
  p1 = &edge;

  ++nNumberOfEdges;
}

Edge& GraphAsMatrix::SelectEdge(Vertex::Number n0, Vertex::Number n1) const
{
  Edge *p0 = const_cast<Array2D<Edge*>&>(adjacencyMatrix)[n0][n1];
  if(p0) 
    return *p0;

  Edge *p1 = const_cast<Array2D<Edge*>&>(adjacencyMatrix)[n1][n0];
  if(p1) 
    return *p1;

  throw std::invalid_argument("invalid argument");
}

bool GraphAsMatrix::IsEdge(Vertex::Number n0, Vertex::Number n1) const
{
  Edge *p0 = const_cast<Array2D<Edge*>&>(adjacencyMatrix)[n0][n1];
  if(p0) return true;
  Edge *p1 = const_cast<Array2D<Edge*>&>(adjacencyMatrix)[n1][n0];
  if(p1) return true;

  return false;
}

void GraphAsMatrix::Accept(Visitor&) const
{}

Iterator& GraphAsMatrix::Vertices() const
{
  return *new VerticesIter(*this);
}

Iterator& GraphAsMatrix::Edges() const
{
  return *new EdgesIter(*this);
}

Iterator& GraphAsMatrix::IncidentEdges(Vertex const& vertex) const
{
  return *new IncidentEdgesIter(*this, vertex);
}

Iterator& GraphAsMatrix::EmanatingEdges(Vertex const& vertex) const
{
  return *new EmanatingEdgesIter(*this, vertex);
}
/////////////////////////////////////////////////////////////////////
GraphAsMatrix::VerticesIter::VerticesIter(GraphAsMatrix const& graph) :
  vertices(graph.vertices)
{
  Reset();
}

GraphAsMatrix::VerticesIter::~VerticesIter()
{
}

void GraphAsMatrix::VerticesIter::Reset()
{
  length = vertices.GetLength();
  for(index = 0; index < length && vertices[index] == NULL; ++index)
    {
    }
}

bool GraphAsMatrix::VerticesIter::IsDone() const
{
  return index == length;
}

Object& GraphAsMatrix::VerticesIter::operator *() const
{
  Vertex *p = vertices[index];
  if(p == NULL)
    throw std::logic_error("invalid operation");
  
  return *p;
}

void GraphAsMatrix::VerticesIter::operator ++()
{
  ++index;
  while(index < length)
    {
      if(vertices[index] != NULL)
	break;
      ++index;
    }
}

/////////////////////////////////////////////////////////////////////
GraphAsMatrix::EdgesIter::EdgesIter(GraphAsMatrix const& graph) :
  edges(graph.adjacencyMatrix)
{
  Reset();
}

GraphAsMatrix::EdgesIter::~EdgesIter()
{
}

void GraphAsMatrix::EdgesIter::Reset()
{
  length = edges.GetNumberOfRows();
  row = 0;
  column = 0;

  bool stop = false;

  while(row < length)
    {
      while(column < row + 1)
	{
	  if((const_cast< Array2D<Edge*>& >(edges))[row][column] != NULL)
	    {
	      stop = true;
	      break;
	    }
	  ++column;
	}
      
      
      if(stop) break;
      
      column = 0;
      ++row;
    }
}

bool GraphAsMatrix::EdgesIter::IsDone() const
{
  return row == length;
}

Object& GraphAsMatrix::EdgesIter::operator *() const
{
  Edge *p = (const_cast< Array2D<Edge*>& >(edges))[row][column];
  if(p == NULL)
    throw std::logic_error("invalid operation");
  
  return *p;
}

void GraphAsMatrix::EdgesIter::operator ++()
{
  bool stop = false;
  
  ++column;

  while(row < length)
    {
      while(column < row + 1)
	{
	  if((const_cast< Array2D<Edge*>& >(edges))[row][column] != NULL)
	    {
	      stop = true;
	      break;
	    }
	  ++column;
	}
      
      
      if(stop) break;
      
      column = 0;
      ++row;
    }
}

/////////////////////////////////////////////////////////////////////
GraphAsMatrix::IncidentEdgesIter::
IncidentEdgesIter(GraphAsMatrix const& graph, Vertex const& _vertex) :
  edges(graph.adjacencyMatrix),
  vertex(_vertex)
{
  Reset();
}

GraphAsMatrix::IncidentEdgesIter::~IncidentEdgesIter()
{}

void GraphAsMatrix::IncidentEdgesIter::Reset()
{
  length = edges.GetNumberOfColumns();
  v0 = Vertex::Number(vertex);
  index = 0;
}

bool GraphAsMatrix::IncidentEdgesIter::IsDone() const
{
  return index == length;
}

Object& GraphAsMatrix::IncidentEdgesIter::operator *() const
{
  Edge *p = (const_cast< Array2D<Edge*>& >(edges))[v0][index];
  if(p == NULL)
    throw std::logic_error("invalid operation");
  
  return *p;
}

void GraphAsMatrix::IncidentEdgesIter::operator ++()
{
  ++index;
  while(index < length)
    {
      if((const_cast< Array2D<Edge*>& >(edges))[v0][index] != NULL)
	{
	  break;
	}
      ++index;
    }
}

/////////////////////////////////////////////////////////////////////
GraphAsMatrix::EmanatingEdgesIter::
EmanatingEdgesIter(GraphAsMatrix const& graph, Vertex const& _vertex) :
  edges(graph.adjacencyMatrix),
  vertex(_vertex)
{
  Reset();
}

GraphAsMatrix::EmanatingEdgesIter::~EmanatingEdgesIter()
{}

void GraphAsMatrix::EmanatingEdgesIter::Reset()
{
  length = edges.GetNumberOfRows();
  v1 = Vertex::Number(vertex);
  index = 0;
}

bool GraphAsMatrix::EmanatingEdgesIter::IsDone() const
{
  return index == length;
}

Object& GraphAsMatrix::EmanatingEdgesIter::operator *() const
{
  Edge *p = (const_cast< Array2D<Edge*>& >(edges))[index][v1];
  if(p == NULL)
    throw std::logic_error("invalid operation");
  
  return *p;
}

void GraphAsMatrix::EmanatingEdgesIter::operator ++()
{
  ++index;
  while(index < length)
    {
      if((const_cast< Array2D<Edge*>& >(edges))[index][v1] != NULL)
	{
	  break;
	}
      ++index;
    }
}
//GraphAsLists
//DGraphAsMatrix
//DGraphAsLists
/////////////////////////////////////////////////////////////////////
DigraphAsMatrix::DigraphAsMatrix(unsigned int n) :
  GraphAsMatrix(n)
{}
/////////////////////////////////////////////////////////////////////
DigraphAsMatrix::~DigraphAsMatrix()
{
  Purge();
}
/////////////////////////////////////////////////////////////////////
void DigraphAsMatrix::AddEdge(Edge& edge)
{
  Vertex& v0 = edge.V0();
  Vertex& v1 = edge.V1();
  
  Edge*& p0 = adjacencyMatrix[v0][v1];
    
  if(p0 != 0)
    throw std::invalid_argument("invalid argument");
  
  p0 = &edge;

  ++nNumberOfEdges;
}
/////////////////////////////////////////////////////////////////////
Edge& DigraphAsMatrix::SelectEdge(Vertex::Number n0, Vertex::Number n1) const
{
  Edge *p0 = const_cast<Array2D<Edge*>&>(adjacencyMatrix)[n0][n1];
  if(p0) 
    return *p0;

  throw std::invalid_argument("invalid argument");
}
/////////////////////////////////////////////////////////////////////
bool DigraphAsMatrix::IsEdge(Vertex::Number n0, Vertex::Number n1) const
{
  Edge *p0 = const_cast<Array2D<Edge*>&>(adjacencyMatrix)[n0][n1];
  if(p0) return true;

  return false;
}

/////////////////////////////////////////////////////////////////////
Iterator& DigraphAsMatrix::Edges() const
{
  return *new DigraphAsMatrix::EdgesIter(*this);
}
/////////////////////////////////////////////////////////////////////
DigraphAsMatrix::EdgesIter::EdgesIter(DigraphAsMatrix const& graph) :
  edges(graph.adjacencyMatrix)
{
  Reset();
}

DigraphAsMatrix::EdgesIter::~EdgesIter()
{
}

void DigraphAsMatrix::EdgesIter::Reset()
{
  length = edges.GetNumberOfRows();
  row = 0;
  column = 0;

  bool stop = false;

  while(row < length)
    {
      while(column < length)
	{
	  if((const_cast< Array2D<Edge*>& >(edges))[row][column] != NULL)
	    {
	      stop = true;
	      break;
	    }
	  ++column;
	}
      
      
      if(stop) break;
      
      column = 0;
      ++row;
    }
}

bool DigraphAsMatrix::EdgesIter::IsDone() const
{
  return row == length;
}

Object& DigraphAsMatrix::EdgesIter::operator *() const
{
  Edge *p = (const_cast< Array2D<Edge*>& >(edges))[row][column];
  if(p == NULL)
    throw std::logic_error("invalid operation");
  
  return *p;
}

void DigraphAsMatrix::EdgesIter::operator ++()
{
  bool stop = false;
  
  ++column;

  while(row < length)
    {
      while(column < length)
	{
	  if((const_cast< Array2D<Edge*>& >(edges))[row][column] != NULL)
	    {
	      stop = true;
	      break;
	    }
	  ++column;
	}
      
      
      if(stop) break;
      
      column = 0;
      ++row;
    }
}

/////////////////////////////////////////////////////////////////////
GraphAsLists::GraphAsLists(unsigned int n) :
  vertices(n),
  adjacencyLists(n),
  Graph()
{}

GraphAsLists::~GraphAsLists()
{
  Purge();
}

void GraphAsLists::Purge()
{
  if(IsOwner())
    {
      int index, length;
      length = vertices.GetLength();

      Vertex *vertex;
     
      index = 0;

      Array2D<bool> redord(length, length);

      while(index < length)
	{
	  if(vertices[index])
	    delete vertices[index];

	  LinkedList<Edge*>& edgelist = adjacencyLists[index];
	  for(ListElement<Edge*> const *current = edgelist.GetHeadNode();
	      current != NULL; 
	      current = current->GetNextNode())
	    {
	      Edge *edge = current->GetData();
	      if(edge != NULL)
		delete edge;
	    }
	  ++index;
	}  
    }
}

void GraphAsLists::AddVertex(Vertex& vertex)
{
  Vertex*& p = vertices[Vertex::Number(vertex)];

  if(p != NULL)
    throw std::invalid_argument("invalid argument");

  p = &vertex;
  ++nNumberOfVertices;
}

Vertex& GraphAsLists::SelectVertex(Vertex::Number n) const
{
  Vertex* p = const_cast<Vertex*>(vertices[n]);
  if(p == 0)
    throw std::invalid_argument("invalid argument");
  return *p;
}

void GraphAsLists::AddEdge(Edge& edge)
{
  Vertex& v0 = edge.V0();
  Vertex& v1 = edge.V1();
  
  LinkedList<Edge*>& p0 = adjacencyLists[v0];
  LinkedList<Edge*>& p1 = adjacencyLists[v1];

  ListElement<Edge*> const *item;

  for(item = p0.GetHeadNode(); 
      item != NULL; 
      item = item->GetNextNode())
    {
      if(item->GetData() == &edge)
	throw std::invalid_argument("invalid argument");;
    }

  for(item = p1.GetHeadNode(); 
      item != NULL; 
      item = item->GetNextNode())
    {
      if(item->GetData() == &edge)
	throw std::invalid_argument("invalid argument");;
    }

  p0.Append(&edge);
  p1.Append(&edge);

  ++nNumberOfEdges;
}

Edge& GraphAsLists::SelectEdge(Vertex::Number n0, Vertex::Number n1) const
{
  LinkedList<Edge*> const& p0 = adjacencyLists[n0];

  for(ListElement<Edge*> const *item = p0.GetHeadNode(); 
      item != NULL; 
      item = item->GetNextNode())
    {
      Edge *edge = item->GetData();
      
      if(Vertex::Number(edge->V1()) == n1)
	return *edge;
    }
  
  LinkedList<Edge*> const& p1 = adjacencyLists[n0];

  for(ListElement<Edge*> const *item = p1.GetHeadNode(); 
      item != NULL; 
      item = item->GetNextNode())
    {
      Edge *edge = item->GetData();
      
      if(Vertex::Number(edge->V1()) == n1)
	return *edge;
    }

  throw std::invalid_argument("invalid argument");
}

bool GraphAsLists::IsEdge(Vertex::Number n0, Vertex::Number n1) const
{
  LinkedList<Edge*> const& p0 = adjacencyLists[n0];

  for(ListElement<Edge*> const *item = p0.GetHeadNode(); item != NULL; item = item->GetNextNode())
    {
      Edge *edge = item->GetData();
      
      if(Vertex::Number(edge->V1()) == n1)
	return true;
    }

  LinkedList<Edge*> const& p1 = adjacencyLists[n0];

  for(ListElement<Edge*> const *item = p1.GetHeadNode(); item != NULL; item = item->GetNextNode())
    {
      Edge *edge = item->GetData();
      
      if(Vertex::Number(edge->V1()) == n1)
	return true;
    }
  
  return false;
}

Iterator& GraphAsLists::Edges() const
{
  return *new EdgesIter(adjacencyLists);
}

Iterator& GraphAsLists::Vertices() const
{
  return *new VerticesIter(vertices);
}

Iterator& GraphAsLists::IncidentEdges(Vertex const& vertex) const
{
  return *new IncidentEdgesIter(adjacencyLists, vertex);
}

Iterator& GraphAsLists::EmanatingEdges(Vertex const& vertex) const
{
  return *new EmanatingEdgesIter(adjacencyLists, vertex);
}

void GraphAsLists::Accept(Visitor&) const
{}
/////////////////////////////////////////////////////////////////////
GraphAsLists::VerticesIter::VerticesIter(Array<Vertex*> const& _vertices) :
  vertices(_vertices)
{
  Reset();
}

GraphAsLists::VerticesIter::~VerticesIter()
{
}

void GraphAsLists::VerticesIter::Reset()
{
  length = vertices.GetLength();
  for(index = 0; 
      index < length && vertices[index] == NULL; 
      ++index)
    {
    }
}

bool GraphAsLists::VerticesIter::IsDone() const
{
  return index == length;
}

Object& GraphAsLists::VerticesIter::operator *() const
{
  Vertex *vertex = vertices[index];
  if(vertex == NULL)
    throw std::logic_error("invalid operation");
  
  return *vertex;
}

void GraphAsLists::VerticesIter::operator ++()
{
  ++index;
  while(index < length)
    {
      if(vertices[index] != NULL)
	break;
      ++index;
    }
}
/////////////////////////////////////////////////////////////////////
GraphAsLists::EdgesIter::EdgesIter(Array<EdgeList> const& _edges) :
  edges(_edges),
  record(_edges.GetLength(), _edges.GetLength())
{
  Reset();
}

GraphAsLists::EdgesIter::~EdgesIter()
{
}

void GraphAsLists::EdgesIter::Reset()
{
  length = edges.GetLength();
  current = NULL;

  for(unsigned int i = 0; i < length; i++)
    for(unsigned int j = 0; j < length; i++)
      record[i][j] = false;

  for(index = 0; index < length; ++index)
    {
      LinkedList<Edge*> &edgelist = const_cast<LinkedList<Edge*>&> (edges[index]);
      current = edgelist.GetHeadNode();
      if(current != NULL)
	break;
    }

  if(current != NULL)
    {
      Edge *edge = current->GetData();
      Vertex& v0 = edge->V0();
      Vertex& v1 = edge->V1();

      record[v0][v1] = true;
      record[v1][v0] = true;
    }
}

bool GraphAsLists::EdgesIter::IsDone() const
{
  return current == NULL;
}

Object& GraphAsLists::EdgesIter::operator *() const
{
  Edge *edge = current->GetData();
  if(edge == NULL)
    throw std::logic_error("invalid operation");
  
  return *edge;
}

void GraphAsLists::EdgesIter::operator ++()
{
  current = current->GetNextNode();
  
  if(current == NULL)
    {
      while (++index < length)
	{
	  LinkedList<Edge*> &edgelist = const_cast<LinkedList<Edge*>&> (edges[index]);
	  current = edgelist.GetHeadNode();
	  if(current != NULL)
	    {
	      Edge *edge = current->GetData();
	      Vertex& v0 = edge->V0();
	      Vertex& v1 = edge->V1();
	      if(record[v0][v1] == false && record[v1][v0] == false)
		{
		  record[v0][v1] == true;
		  record[v1][v0] == true;
		  break;
		}	      
	    }
	}
    }
}
/////////////////////////////////////////////////////////////////////
GraphAsLists::IncidentEdgesIter::
IncidentEdgesIter(Array<EdgeList> const &_edges, Vertex const& _vertex) :
  edges(_edges),
  vertex(_vertex)
{
  Reset();
}

GraphAsLists::IncidentEdgesIter::~IncidentEdgesIter()
{}

void GraphAsLists::IncidentEdgesIter::Reset()
{
  LinkedList<Edge*> &edge = const_cast<LinkedList<Edge*>&>(edges[vertex]);
  current = edge.GetHeadNode();
}

bool GraphAsLists::IncidentEdgesIter::IsDone() const
{
  return current == NULL;
}

Object& GraphAsLists::IncidentEdgesIter::operator *() const
{
  Edge *edge = current->GetData();
  if(edge == NULL)
    throw std::logic_error("invalid operation");
  return *edge;
}

void GraphAsLists::IncidentEdgesIter::operator ++()
{
  current = current->GetNextNode();
}

/////////////////////////////////////////////////////////////////////
GraphAsLists::EmanatingEdgesIter::
EmanatingEdgesIter(Array<EdgeList> const &_edges, Vertex const& _vertex) :
  edges(_edges),
  vertex(_vertex)
{
  Reset();
}

GraphAsLists::EmanatingEdgesIter::~EmanatingEdgesIter()
{}

void GraphAsLists::EmanatingEdgesIter::Reset()
{
  LinkedList<Edge*> &edge = const_cast<LinkedList<Edge*>&>(edges[vertex]);
  current = edge.GetHeadNode();
}

bool GraphAsLists::EmanatingEdgesIter::IsDone() const
{
  return current == NULL;
}

Object& GraphAsLists::EmanatingEdgesIter::operator *() const
{
  Edge *edge = current->GetData();
  if(edge == NULL)
    throw std::logic_error("invalid operation");
  return *edge;
}

void GraphAsLists::EmanatingEdgesIter::operator ++()
{
  current = current->GetNextNode();
}

/////////////////////////////////////////////////////////////////////

DigraphAsLists::DigraphAsLists(unsigned int n) :
  emanatingLists(n),
  GraphAsLists(n)
{}

DigraphAsLists::~DigraphAsLists()
{
  Purge();
}

void DigraphAsLists::AddEdge(Edge& edge)
{
  Vertex& v0 = edge.V0();
  Vertex& v1 = edge.V1();
  
  LinkedList<Edge*>& p0 = adjacencyLists[v0];
  LinkedList<Edge*>& p1 = emanatingLists[v0];

  ListElement<Edge*> const *item;

  for(item = p0.GetHeadNode(); 
      item != NULL; 
      item = item->GetNextNode())
    {
      if(item->GetData() == &edge)
	throw std::invalid_argument("invalid argument");;
    }

  for(item = p1.GetHeadNode(); 
      item != NULL; 
      item = item->GetNextNode())
    {
      if(item->GetData() == &edge)
	throw std::invalid_argument("invalid argument");;
    }

  p0.Append(&edge);
  p1.Append(&edge);

  ++nNumberOfEdges;
}

Edge& DigraphAsLists::SelectEdge(Vertex::Number n0, Vertex::Number n1) const
{
  LinkedList<Edge*> const& p0 = adjacencyLists[n0];

  for(ListElement<Edge*> const*item = p0.GetHeadNode(); 
      item != NULL; 
      item = item->GetNextNode())
    {
      Edge *edge = item->GetData();
      
      if(Vertex::Number(edge->V1()) == n1)
	return *edge;
    }
  
  throw std::invalid_argument("invalid argument");
}

bool DigraphAsLists::IsEdge(Vertex::Number n0, Vertex::Number n1) const
{
  LinkedList<Edge*> const& p0 = adjacencyLists[n0];

  for(ListElement<Edge*> const*item = p0.GetHeadNode(); 
      item != NULL; 
      item = item->GetNextNode())
    {
      Edge *edge = item->GetData();
      
      if(Vertex::Number(edge->V1()) == n1)
	return true;
    }

  return false;
}

Iterator& DigraphAsLists::EmanatingEdges(Vertex const& vertex) const
{
  return *new EmanatingEdgesIter(emanatingLists, vertex);
}
////////////////////////////////////////////////////////////////

Digraph& DijkstrasAlgorithm(Digraph const& g, Vertex const& s)
{
  unsigned int const n = g.GetNumberOfVertices();
  Array<TableEntry> table(n);
  PriorityQueue& queue = *new BinaryHeapAsArray(g.GetNumberOfEdges());
  table[s].distance = 0;
  queue.EnQueue(*new Assoc(0, const_cast<Vertex&>(s)));
  while(!queue.IsEmpty())
    {
      Assoc& assoc = dynamic_cast<Assoc&>(queue.DeQueueMin());
      Vertex& v0 = dynamic_cast<Vertex&>(assoc.GetValue());
      if(!table[v0].known)
	{
	  table[v0].known = true;
	  Iterator& p = g.EmanatingEdges(v0);
	  while(!p.IsDone())
	    {
	      WeightedEdge& edge = dynamic_cast<WeightedEdge&>(*p);
	      Vertex& v1 = edge.V1();
	      Int& weight = dynamic_cast<Int&>(edge.GetWeight());
	      int const d = table[v0].distance + weight;
	      if(table[v1].distance > d)
		{
		  table[v1].distance = d;
		  table[v1].predecessor = v0;
		  queue.EnQueue(*new Assoc(d, v1));
		}
	      ++p;
	    }
	  delete &p;
	}
      delete &assoc;
    }
  delete &queue;

  Digraph& result = *new DigraphAsLists(n);
  
  for(Vertex::Number v = 0; v < n; ++v)
    result.AddVertex(*new WeightedVertex(v, *new Int(table[v].distance)));
  
  for(Vertex::Number v = 0; v < n; ++v)
    if(v != s)
      result.AddEdge(*new Edge(result[v], result[table[v].predecessor]));
  
  return result;
}
