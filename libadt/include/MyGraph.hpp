#ifndef MY_GRAPH
#define MY_GRAPH
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <limits>

namespace ADT
{
  /**
   *\brief define of class Vertex
   */
  class Vertex : public Object
  {
  public:
    typedef unsigned int Number;///<for label a vertex
  protected:
    Number number;
  public:
    Vertex(Number);
    virtual operator Number() const;
    //virtual functions of Object
  protected:
    int CompareTo(Object const&) const;
  public:
    HashValue Hash() const;
    void Put(ostream&) const;
  };
  
  class Edge : public Object
  {
  protected:
    Vertex& v0;
    Vertex& v1;
  public:
    Edge(Vertex&, Vertex&);
    virtual Vertex& V0() const;
    virtual Vertex& V1() const;
    virtual Vertex& Mate(Vertex const&) const;
    //virtual functions of Object
  protected:
    int CompareTo(Object const&) const;
  public:
    HashValue Hash() const;
    void Put(ostream&) const;
  };

  class Graph : public Container
  {
  protected:
  typedef LinkedList<Edge*> EdgeList;
  
  protected:
    unsigned int nNumberOfVertices;
    unsigned int nNumberOfEdges;

    void DepthFirstTraversal(PrePostVisitor&, Vertex&, Array<bool>&) const;
  public:
    Graph();
    virtual unsigned int GetNumberOfEdges() const;
    virtual unsigned int GetNumberOfVertices() const;
    virtual void AddVertex(Vertex&) = 0;
    virtual Vertex& SelectVertex(Vertex::Number) const = 0;
    virtual Vertex& operator [](Vertex::Number) const;
    virtual void AddEdge(Edge&) = 0;
    virtual Edge& SelectEdge(Vertex::Number, Vertex::Number) const = 0;
    virtual bool IsEdge(Vertex::Number, Vertex::Number) const = 0;
    virtual bool IsConnected() const;
    virtual bool IsCyclic() const;

    virtual Iterator& Vertices() const = 0;
    virtual Iterator& Edges() const = 0;
    virtual Iterator& IncidentEdges(Vertex const&) const = 0;
    virtual Iterator& EmanatingEdges(Vertex const&) const = 0;

    virtual void DepthFirstTraversal(PrePostVisitor&, Vertex const&) const;
    virtual void BreadthFirstTraversal(Visitor&, Vertex const&) const;

    //virtual functions of Container
    //void Purge();
    //void Accept(Visitor&) const;
    //virtual functions of Object
    int CompareTo(Object const&) const;
  };

  class Digraph : public virtual Graph
  {
  public:
    virtual bool IsConnected() const;
    virtual bool IsCyclic() const;
    virtual void TopologicalOrderTraversal(Visitor&) const;
  };

  class GraphAsMatrix : public virtual Graph
  {
  protected:
    Array<Vertex*> vertices;
    Array2D<Edge*> adjacencyMatrix;
  public:
    GraphAsMatrix(unsigned int);
    ~GraphAsMatrix();
    //virtual functions of Graph
    void AddVertex(Vertex&);
    Vertex& SelectVertex(Vertex::Number) const;
    void AddEdge(Edge&);
    Edge& SelectEdge(Vertex::Number, Vertex::Number) const;
    bool IsEdge(Vertex::Number, Vertex::Number) const;
    Iterator& Vertices() const;
    Iterator& Edges() const;
    Iterator& IncidentEdges(Vertex const&) const;
    Iterator& EmanatingEdges(Vertex const&) const;
    //virtual functions of Container
    void Purge();
    void Accept(Visitor&) const;
    //virtual functions of Object
    //int CompareTo(Object const&) const;
  private:
    //顶点遍历器
    class VerticesIter : public Iterator
    {
    private:
      Array<Vertex*> const& vertices;
      unsigned int index;
      unsigned int length;
    public:
      VerticesIter(GraphAsMatrix const&);
      ~VerticesIter();
      //	virtual function of Iterator	
      void Reset();
      bool IsDone() const;
      Object& operator *() const;
      void operator ++();
    };
    //从顶点p出发的边遍历器
    class IncidentEdgesIter : public Iterator
    {
    private:
      Array2D<Edge*> const& edges;
      Vertex const& vertex;
      unsigned int v0;
      unsigned int index;
      unsigned int length;
    public:
      IncidentEdgesIter(GraphAsMatrix const&, Vertex const&);
      ~IncidentEdgesIter();
      //	virtual function of Iterator	
      void Reset();
      bool IsDone() const;
      Object& operator *() const;
      void operator ++();
    };
    //到顶点p的边遍历器
    class EmanatingEdgesIter : public Iterator
    {
    private:
      Array2D<Edge*> const& edges;
      Vertex const& vertex;
      unsigned int v1;
      unsigned int index;
      unsigned int length;
    public:
      EmanatingEdgesIter(GraphAsMatrix const&, Vertex const&);
      ~EmanatingEdgesIter();
      //	virtual function of Iterator	
      void Reset();
      bool IsDone() const;
      Object& operator *() const;
      void operator ++();
    };
    //所有边遍历器
    class EdgesIter : public Iterator
    {
    private:
      Array2D<Edge*> const& edges;
      unsigned int row, column;
      unsigned int length;
    public:
      EdgesIter(GraphAsMatrix const&);
      ~EdgesIter();
      //	virtual function of Iterator	
      void Reset();
      bool IsDone() const;
      Object& operator *() const;
      void operator ++();
    };
  };

  class GraphAsLists : public virtual Graph
  {
    //typedef LinkedList<Edge*> EdgeList;
  protected:
    Array<Vertex*> vertices;
    Array<EdgeList> adjacencyLists;
  public:
    GraphAsLists(unsigned int);
    ~GraphAsLists();
    //virtual functions of Graph
    void AddVertex(Vertex&);
    Vertex& SelectVertex(Vertex::Number) const;
    void AddEdge(Edge&);
    Edge& SelectEdge(Vertex::Number, Vertex::Number) const;
    bool IsEdge(Vertex::Number, Vertex::Number) const;
    Iterator& Vertices() const;
    Iterator& Edges() const;
    Iterator& IncidentEdges(Vertex const&) const;
    Iterator& EmanatingEdges(Vertex const&) const;
    //virtual functions of Container
    void Purge();
    void Accept(Visitor&) const;
    //virtual functions of Object
    //int CompareTo(Object const&) const;
  protected:
    //顶点遍历器
    class VerticesIter : public Iterator
    {
    private:
      Array<Vertex*> const& vertices;
      unsigned int index;
      unsigned int length;
    public:
      VerticesIter(Array<Vertex*> const&);
      ~VerticesIter();
      //	virtual function of Iterator	
      void Reset();
      bool IsDone() const;
      Object& operator *() const;
      void operator ++();
    };
    //从顶点p出发的边遍历器
    class IncidentEdgesIter : public Iterator
    {
    private:
      Array<EdgeList> const& edges;
      Vertex const& vertex;
      ListElement<Edge*> const *current;
    public:
      IncidentEdgesIter(Array<EdgeList> const&, Vertex const&);
      ~IncidentEdgesIter();
      //	virtual function of Iterator	
      void Reset();
      bool IsDone() const;
      Object& operator *() const;
      void operator ++();
    };
    //到顶点p的边遍历器
    class EmanatingEdgesIter : public Iterator
    {
    private:
      Array<EdgeList> const& edges;
      Vertex const& vertex;
      ListElement<Edge*> const *current;
    public:
      EmanatingEdgesIter(Array<EdgeList> const&, Vertex const&);
      ~EmanatingEdgesIter();
      //	virtual function of Iterator	
      void Reset();
      bool IsDone() const;
      Object& operator *() const;
      void operator ++();
    };
    //所有边遍历器
    class EdgesIter : public Iterator
    {
    private:
      Array<EdgeList> const& edges;
      unsigned int length;
      unsigned int index;
      ListElement<Edge*> const *current;
      Array2D<bool> record;
    public:
      EdgesIter(Array<EdgeList> const&);
      ~EdgesIter();
      //	virtual function of Iterator	
      void Reset();
      bool IsDone() const;
      Object& operator *() const;
      void operator ++();
    };
  };

  class WeightedVertex : public Vertex /* 带权顶点 */
  {
  private:
    Object* pWeight;
  public:
    WeightedVertex(Vertex::Number, Object&);
    virtual Object& GetWeight() const;
  };

  class WeightedEdge : public Edge /* 带权边 */
  {
  private:
    Object* pWeight;
  public:
    WeightedEdge(Vertex&, Vertex&, Object&);
    virtual Object& GetWeight() const;
  };

  class DigraphAsMatrix : public Digraph, public GraphAsMatrix
  {
  public:
    DigraphAsMatrix(unsigned int);
    ~DigraphAsMatrix();
    void AddEdge(Edge&);
    Edge& SelectEdge(Vertex::Number, Vertex::Number) const;
    bool IsEdge(Vertex::Number, Vertex::Number) const;
    Iterator& Edges() const;

  private:
    class EdgesIter : public Iterator
    {
    private:
      Array2D<Edge*> const& edges;
      unsigned int row, column;
      unsigned int length;
    public:
      EdgesIter(DigraphAsMatrix const&);
      ~EdgesIter();
      //	virtual function of Iterator	
      void Reset();
      bool IsDone() const;
      Object& operator *() const;
      void operator ++();
    };
  };

 class DigraphAsLists : public Digraph, public GraphAsLists
  {
  protected:
    Array<EdgeList> emanatingLists;
  public:
    DigraphAsLists(unsigned int);
    ~DigraphAsLists();
    void AddEdge(Edge&);
    Edge& SelectEdge(Vertex::Number, Vertex::Number) const;
    bool IsEdge(Vertex::Number, Vertex::Number) const;
    //Iterator& Edges() const;
    Iterator& EmanatingEdges(Vertex const&) const;
  };
  ////////////////////////////////////////////////////////

  class CountingVisitor : public Visitor
  {
  private:
    unsigned int nCount;
  
  public:
    CountingVisitor();
    void Visit(Object&);
    unsigned int GetCount() const;
  };

  ////////////////////////////////////////////////////////
  class TableEntry
  {
  public:
    bool known;
    int distance;
    Vertex::Number predecessor;
    TableEntry() : known(false), distance(numeric_limits<int>::max()){}
  };
  class Assoc : public Association
  {
    Int priority;
  public:
    Assoc(int p, Object& object) :
      Association(priority, object), priority(p)
    {
      RescindOwnership();
    }
  };

  extern Digraph& DijkstrasAlgorithm(Digraph const& g, Vertex const& s);
}
#endif //MY_GRAPH
