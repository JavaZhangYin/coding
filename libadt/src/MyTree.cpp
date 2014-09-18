#include <string>
#include <stdlib.h>
#include <stdexcept>

using namespace std;

#include "MyMacro.hpp"
#include "MyArray.hpp"
#include "MyLink.hpp"
#include "MyObject.hpp"
#include "MyContainer.hpp"
#include "MyQueue.hpp"
#include "MyStack.hpp"
#include "MyTree.hpp"

using namespace ADT;
///////////////////////////////////////////////////////////////////
unsigned int Tree::GetCount() const
{
  unsigned int nRet = 0;
  Iterator& iter = NewIterator();
  while(!iter.IsDone())
    {
      nRet++;
      ++iter;
    }
  return nRet;
}
void Tree::DepthFirstTraversal(PrePostVisitor& visitor) const
{
  if(visitor.IsDone())
    return;
  if(!IsEmpty())
    {
      visitor.PreVisit(GetKey());
      for(unsigned int i = 0; i < GetDegree(); i++)
	GetSubTree(i).DepthFirstTraversal(visitor);
      visitor.PostVisit(GetKey());
    }
}

void Tree::Accept(Visitor& visitor) const
{
  PreOrder v(visitor);
  DepthFirstTraversal(v);
}

Iterator& Tree::NewIterator() const
{
  return *new Iter(*this);
}

void Tree::BreadthFirstTraversal(Visitor& visitor) const
{
  QueueAsLinkedList& queue = *new QueueAsLinkedList();
  queue.RescindOwnership();

  if(!IsEmpty())
    queue.EnQueue(const_cast<Tree&>(*this));
  while(!queue.IsEmpty() && !visitor.IsDone())
    {
      Tree const& head = 
	dynamic_cast<Tree const&>(queue.DeQueue());

      visitor.Visit(head.GetKey());
      for(unsigned int i = 0; i < head.GetDegree(); i++)
	{
	  Tree& child = head.GetSubTree(i);
	  if(!child.IsEmpty())
	    queue.EnQueue(child);
	}
    }

  delete &queue;
}
int Tree::GetHeight() const
{
  int iRet = 0;

  if(IsLeaf())
    return 0;

  for(unsigned int i = 0; i < GetDegree(); i++)
    {
      Tree& tree = GetSubTree(i);
      if(!tree.IsEmpty())
	{
	  if(!tree.IsLeaf()) //!= NullObject::GetInstance())
	    {
	      int iTemp = tree.GetHeight();
	      iRet = iRet >= iTemp ? iRet : iTemp;
	    }
	}
    }
  iRet++;
  return iRet;
}
//////////////////////////////////////////////////////////////////
Tree::Iter::Iter(Tree const& _tree) :
  tree(_tree),
  stack(*new StackAsLinkedList())
{
  stack.RescindOwnership();
  Reset();
}

Tree::Iter::~Iter()
{
  delete &stack;
}

void Tree::Iter::Reset()
{
  stack.Purge();
  if(!tree.IsEmpty())
    stack.Push(const_cast<Tree&>(tree));
}

bool Tree::Iter::IsDone() const
{
  return stack.IsEmpty();
}

Object& Tree::Iter::operator *() const
{
  if(!stack.IsEmpty())
    {
      Tree const& top = 
	dynamic_cast<Tree const&> (stack.Top());
      return top.GetKey();
    }
  else
    return NullObject::GetInstance();
}

void Tree::Iter::operator ++()
{
  if(!stack.IsEmpty())
    {
      Tree const& top = 
	dynamic_cast<Tree const&> (stack.Pop());
      for(int i = top.GetDegree() - 1; i >= 0; i--)
	{
	  Tree& subTree = top.GetSubTree(i);
	  if(!subTree.IsEmpty())
	    stack.Push(subTree);
	}
    }
}
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
GeneralTree::GeneralTree(Object& _key) : 
  pObjKey(&_key),
  nDegree(0),
  list()
{}
GeneralTree::~GeneralTree()
{
  Purge();
}
void GeneralTree::Purge()
{
  DListElement<GeneralTree*> const* ptr;
  if(IsOwner())
    delete pObjKey;
  for(ptr = list.GetHeadNode(); ptr != 0; ptr = ptr->GetNextNodeRight())
    delete ptr->GetData();
}
Object& GeneralTree::GetKey() const
{
  return *pObjKey;
}
GeneralTree& GeneralTree::GetSubTree(unsigned int i) const
{
  if(i > nDegree)
    throw std::out_of_range("invalid subtree index");
  unsigned int j = 0;
  DListElement<GeneralTree*> const* ptr = list.GetHeadNode();

  for(; j < i && ptr != 0; j++)
    ptr = ptr->GetNextNodeRight();
  if(ptr == 0)
    throw std::logic_error("should never happen");
  return *ptr->GetData();
}
void GeneralTree::AttachSubTree(GeneralTree& t)
{
  list.Append(&t);
  nDegree++;
}
GeneralTree& GeneralTree::DetachSubTree(GeneralTree& t)
{
  list.Extract(&t);
  nDegree--;
  return t;
}
unsigned int GeneralTree::GetDegree() const
{
  unsigned int nRet = 0;
  DListElement<GeneralTree*> const* ptr = 
    list.GetHeadNode();
  if(ptr == 0)
    return 0;
  for(; ptr != 0; ptr = ptr->GetNextNodeRight())
    nRet++;
  return nRet;
}
bool GeneralTree::IsLeaf() const
{
  return list.GetHeadNode() == 0;
}
bool GeneralTree::IsEmpty() const
{
  return (pObjKey == 0);// false == (pObjKey == 0 && IsLeaf()) it's right?;
}
int GeneralTree::CompareTo(Object const& object) const
{
  GeneralTree const& tree =
    dynamic_cast<GeneralTree const&> (object);
  return ::Compare(GetHeight(), tree.GetHeight());
}
/////////////////////////////////////////////////////////////////////////////
NaryTree::NaryTree(unsigned int _nDegree) :
  pObjKey(0),
  nDegree(_nDegree),
  arraySubTree(0)
{}
/////////////////////////////////////////////////////////////////////////////
NaryTree::NaryTree(unsigned int _nDegree, Object& _objKey) :
  pObjKey(&_objKey),
  nDegree(_nDegree),
  arraySubTree(_nDegree)
{
  for(unsigned int i = 0; i < nDegree; i++)
    arraySubTree[i] = new NaryTree(nDegree);
}
/////////////////////////////////////////////////////////////////////////////
NaryTree::~NaryTree()
{
  Purge();
}
/////////////////////////////////////////////////////////////////////////////
int NaryTree::CompareTo(Object const& object) const
{
  NaryTree const& tree =
    dynamic_cast<NaryTree const&> (object);
  return ::Compare(GetHeight(), tree.GetHeight());
}
/////////////////////////////////////////////////////////////////////////////
unsigned int NaryTree::GetDegree() const
{
  return nDegree;
}
/////////////////////////////////////////////////////////////////////////////
void NaryTree::Purge()
{
  if(!IsEmpty())
    {
      if(IsOwner())
	delete pObjKey;
      for(unsigned int i = 0; i < nDegree;  i++)

	{
	  if(arraySubTree[i] == 0)
	    throw std::logic_error("should never happen");
	  delete arraySubTree[i];
	}
      arraySubTree.SetLength(0); //it is right? difficult to determine
    }
}
/////////////////////////////////////////////////////////////////////////////
bool NaryTree::IsEmpty() const
{
  return pObjKey == 0;
}
/////////////////////////////////////////////////////////////////////////////
bool NaryTree::IsLeaf() const
{
  if(IsEmpty()) //It's right?
    throw std::domain_error("invalid operation");
  for(unsigned int i = 0; i < nDegree; i++)
    {
      if(GetSubTree(i).IsEmpty())
	continue;
      else
	return false;
    }
  return true;
}
/////////////////////////////////////////////////////////////////////////////
Object& NaryTree::GetKey() const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  return *pObjKey;
}
/////////////////////////////////////////////////////////////////////////////
void NaryTree::AttachKey(Object& object)
{
  if(!IsEmpty())
    throw std::domain_error("invalid operation");
  pObjKey = &object;
  arraySubTree.SetLength(nDegree);
  for(unsigned int i = 0; i < nDegree; i++)
    arraySubTree[i] = new NaryTree(nDegree);
}
/////////////////////////////////////////////////////////////////////////////
Object& NaryTree::DetachKey()
{
  if(!IsLeaf())
    throw std::domain_error("invalid operation");
  Object& result = *pObjKey;
  pObjKey = 0;
  for(unsigned int i = 0; i < nDegree; i++)
    delete arraySubTree[i];
  arraySubTree.SetLength(0);
  return result;
}
/////////////////////////////////////////////////////////////////////////////
NaryTree& NaryTree::GetSubTree(unsigned int i) const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  return *arraySubTree[i];
}
/////////////////////////////////////////////////////////////////////////////
void NaryTree::AttachSubTree(unsigned int i, NaryTree& t)
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  if(!arraySubTree[i]->IsEmpty())
    throw std::domain_error("non-empty subtree present");
  delete arraySubTree[i];
  arraySubTree[i] = &t;
}
/////////////////////////////////////////////////////////////////////////////
NaryTree& NaryTree::DetachSubTree(unsigned int i)
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  NaryTree& result = *arraySubTree[i];
  arraySubTree[i] = new NaryTree(nDegree);
  return result;
}
/////////////////////////////////////////////////////////////////////////////
BinaryTree::BinaryTree() :
  pObjKey(0),
  pBinaryTreeLeft(0),
  pBinaryTreeRight(0)
{}
/////////////////////////////////////////////////////////////////////////////
BinaryTree::BinaryTree(Object& objKey) :
  pObjKey(&objKey),
  pBinaryTreeLeft(new BinaryTree()),
  pBinaryTreeRight(new BinaryTree())
{}
/////////////////////////////////////////////////////////////////////////////
void BinaryTree::Purge()
{
  if(!IsEmpty())
    {
      if(IsOwner())
	{
	  delete pObjKey;
	}
      delete pBinaryTreeLeft;
      delete pBinaryTreeRight;
      pObjKey = 0;
      pBinaryTreeLeft = 0;
      pBinaryTreeRight = 0;
    }
}
/////////////////////////////////////////////////////////////////////////////
BinaryTree::~BinaryTree()
{
  Purge();
}
/////////////////////////////////////////////////////////////////////////////
void BinaryTree::DepthFirstTraversal(PrePostVisitor& visitor) const
{
  if(visitor.IsDone())
    return;
  if(!IsEmpty())
    {
      visitor.PreVisit(*pObjKey);
      pBinaryTreeLeft->DepthFirstTraversal(visitor);
      visitor.Visit(*pObjKey);
      pBinaryTreeRight->DepthFirstTraversal(visitor);
      visitor.PostVisit(*pObjKey);
    }
}
/////////////////////////////////////////////////////////////////////////////
int BinaryTree::CompareTo(Object const& object) const
{
  BinaryTree const& arg = dynamic_cast<BinaryTree const&> (object);
  if(IsEmpty())
    return arg.IsEmpty() ? 0 : -1;
  else if(arg.IsEmpty())
    return 1;
  else
    {
      int result = this->GetKey().Compare(arg.GetKey());
      if(result == 0)
	result = GetLeft().CompareTo(arg.GetLeft());
      if(result == 0)
	result = GetRight().CompareTo(arg.GetRight());
      return result;
    }
}
/////////////////////////////////////////////////////////////////////////////
void BinaryTree::AttachKey(Object& object)
{
  if(!IsEmpty())
    throw std::domain_error("invalid operation");
  pObjKey = &object;
  pBinaryTreeLeft =new BinaryTree();
  pBinaryTreeRight = new BinaryTree();
}
/////////////////////////////////////////////////////////////////////////////
Object& BinaryTree::DetachKey()
{
  if(!IsLeaf())
    throw std::domain_error("invalid operation");
  Object& result = *pObjKey;
  pObjKey = 0;
  delete pBinaryTreeLeft;
  delete pBinaryTreeRight;
  pBinaryTreeLeft = 0;
  pBinaryTreeRight = 0;
  return result;
}
/////////////////////////////////////////////////////////////////////////////
void BinaryTree::AttachLeft(BinaryTree& t)
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  if(!pBinaryTreeLeft->IsEmpty())
    throw std::domain_error("non-empty subtree present");
  delete pBinaryTreeLeft;
  pBinaryTreeLeft = &t;
}
/////////////////////////////////////////////////////////////////////////////
void BinaryTree::AttachRight(BinaryTree& t)
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  if(!pBinaryTreeRight->IsEmpty())
    throw std::domain_error("non-empty subtree present");
  delete pBinaryTreeRight;
  pBinaryTreeRight = &t;
}
/////////////////////////////////////////////////////////////////////////////
BinaryTree& BinaryTree::DetachLeft()
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  BinaryTree& result = *pBinaryTreeLeft;
  pBinaryTreeLeft = new BinaryTree();
  return result;
}		
/////////////////////////////////////////////////////////////////////////////
BinaryTree& BinaryTree::DetachRight()
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  BinaryTree& result = *pBinaryTreeRight;
  pBinaryTreeRight = new BinaryTree();
  return result;
}
/////////////////////////////////////////////////////////////////////////////
Object& BinaryTree::GetKey() const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  return *pObjKey;
}
/////////////////////////////////////////////////////////////////////////////
bool BinaryTree::IsEmpty() const
{
  return pObjKey == 0;
}	
/////////////////////////////////////////////////////////////////////////////
bool BinaryTree::IsLeaf() const
{
  if(IsEmpty()) //It's right?
    throw std::domain_error("invalid operation");
  return (GetLeft().IsEmpty() && GetRight().IsEmpty());
}
/////////////////////////////////////////////////////////////////////////////
Tree& BinaryTree::GetSubTree(unsigned int i) const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  switch(i)
    {
    case 0:
      return *pBinaryTreeLeft;
      break;
    case 1:
      return *pBinaryTreeRight;
      break;
    default:
      throw std::out_of_range("invalid subtree index");
    }
}
/////////////////////////////////////////////////////////////////////////////
BinaryTree& BinaryTree::GetLeft() const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  return *pBinaryTreeLeft;
}
/////////////////////////////////////////////////////////////////////////////
BinaryTree& BinaryTree::GetRight() const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  return *pBinaryTreeRight;
}
/////////////////////////////////////////////////////////////////////////////
unsigned int BinaryTree::GetDegree() const
{
  return 2U;
}
/////////////////////////////////////////////////////////////////////////////
BST& BST::GetLeft() const
{
  return dynamic_cast<BST&> (BinaryTree::GetLeft());
}
/////////////////////////////////////////////////////////////////////////////
BST& BST::GetRight() const
{
  return dynamic_cast<BST&> (BinaryTree::GetRight());
}
/////////////////////////////////////////////////////////////////////////////
Object& BST::Find(Object const& object) const
{
  if(IsEmpty())
    return NullObject::GetInstance();
  int const diff = object.Compare(*pObjKey);
  if(diff == 0)
    return *pObjKey;
  else if(diff < 0)
    return GetLeft().Find(object);
  else
    return GetRight().Find(object);
}
/////////////////////////////////////////////////////////////////////////////
Object& BST::FindMin() const
{
  if(IsEmpty())
    return NullObject::GetInstance();
  else if(GetLeft().IsEmpty())
    return *pObjKey;
  else
    return GetLeft().FindMin();
}
/////////////////////////////////////////////////////////////////////////////
Object& BST::FindMax() const
{
  if(IsEmpty())
    return NullObject::GetInstance();
  else if(GetRight().IsEmpty())
    return *pObjKey;
  else
    return GetRight().FindMax();
}
/////////////////////////////////////////////////////////////////////////////
void BST::Insert(Object& object)
{
  if(IsEmpty())
    AttachKey(object);
  else
    {
      int const diff = object.Compare(*pObjKey);
      if(diff == 0)
	throw std::invalid_argument("duplicate key");
      if(diff < 0)
	GetLeft().Insert(object);
      else
	GetRight().Insert(object);
    }
  Balance();
}
/////////////////////////////////////////////////////////////////////////////
void BST::AttachKey(Object& object)
{
  if(!IsEmpty())
    throw std::domain_error("invalid operation");
  pObjKey = &object;
  pBinaryTreeLeft = new BST();
  pBinaryTreeRight = new BST();
}
/////////////////////////////////////////////////////////////////////////////
void BST::Balance()
{}
/////////////////////////////////////////////////////////////////////////////
void BST::WithDraw(Object& object)
{
  if(IsEmpty())
    throw std::invalid_argument("object not find");
  int const diff = object.Compare(*pObjKey);
  if(diff == 0)
    {
      if(!GetLeft().IsEmpty())
	{
	  Object& max = GetLeft().FindMax();
	  pObjKey = &max;
	  GetLeft().WithDraw(max);
	}
      else if(!GetRight().IsEmpty())
	{
	  Object& min = GetRight().FindMin();
	  pObjKey = &min;
	  GetRight().WithDraw(min);
	}
      else
	DetachKey();	 
    }
  else if(diff < 0)
    GetLeft().WithDraw(object);
  else
    GetRight().WithDraw(object);
  Balance();
}
/////////////////////////////////////////////////////////////////////////////
Object& BST::DetachKey()
{
  if(!IsLeaf())
    throw std::domain_error("invalid operation");
  Object& result = *pObjKey;
  delete pBinaryTreeLeft;
  delete pBinaryTreeRight;
  pObjKey = 0;
  pBinaryTreeLeft = 0;
  pBinaryTreeRight = 0;
  return result;
}
/////////////////////////////////////////////////////////////////////////////
bool BST::IsMember(Object const& object) const
{
  return Find(object) != NullObject::GetInstance();
}
/////////////////////////////////////////////////////////////////////////////
AVLTree::AVLTree() : 
  BST(), 
  iHeight(-1)
{}
/////////////////////////////////////////////////////////////////////////////
int AVLTree::GetHeight() const
{
  return iHeight;
}
/////////////////////////////////////////////////////////////////////////////
void AVLTree::AdjustHeight()
{
  if(IsEmpty())
    iHeight = -1;
  else
    iHeight = Max(pBinaryTreeLeft->GetHeight(), pBinaryTreeRight->GetHeight()) + 1;
}
/////////////////////////////////////////////////////////////////////////////
int AVLTree::BalanceFactor() const
{
  if(IsEmpty())
    return 0;
  else
    return pBinaryTreeLeft->GetHeight() - pBinaryTreeRight->GetHeight();
}
/////////////////////////////////////////////////////////////////////////////
void AVLTree::LLRotation()
{
  if(IsEmpty())
    throw std::domain_error("invalid rotation");
  BinaryTree* const tmp = pBinaryTreeRight;
  pBinaryTreeRight = pBinaryTreeLeft;
  pBinaryTreeLeft = GetRight().pBinaryTreeLeft;
  GetRight().pBinaryTreeLeft = GetRight().pBinaryTreeRight;
  GetRight().pBinaryTreeRight = tmp;

  Object* const pTmpObj = pObjKey;
  pObjKey = GetRight().pObjKey;
  GetRight().pObjKey = pTmpObj;

  GetRight().AdjustHeight();
  AdjustHeight();
}
/////////////////////////////////////////////////////////////////////////////
void AVLTree::LRRotation()
{
  if(IsEmpty())
    throw std::domain_error("invalid rotation");
  GetLeft().RRRotation();
  LLRotation();
}
/////////////////////////////////////////////////////////////////////////////
void AVLTree::RRRotation()
{
  if(IsEmpty())
    throw std::domain_error("invalid rotation");
  BinaryTree* const tmp = pBinaryTreeLeft;
  pBinaryTreeLeft = pBinaryTreeRight;
  pBinaryTreeRight = GetLeft().pBinaryTreeRight;
  GetLeft().pBinaryTreeRight = GetLeft().pBinaryTreeLeft;
  GetLeft().pBinaryTreeLeft  = tmp;

  Object* const pTmpObj = pObjKey;
  pObjKey = GetLeft().pObjKey;
  GetLeft().pObjKey = pTmpObj;

  GetLeft().AdjustHeight();
  AdjustHeight();
}
/////////////////////////////////////////////////////////////////////////////
void AVLTree::RLRotation()
{
  if(IsEmpty())
    throw std::domain_error("invalid rotation");
  GetRight().LLRotation();
  RRRotation();
}
/////////////////////////////////////////////////////////////////////////////
void AVLTree::AttachKey(Object& object)
{
  if(!IsEmpty())
    throw std::domain_error("invalid operation");
  pObjKey = &object;
  pBinaryTreeLeft = new AVLTree();
  pBinaryTreeRight = new AVLTree();
  iHeight = 0;
}
/////////////////////////////////////////////////////////////////////////////
Object& AVLTree::DetachKey()
{
  iHeight = -1;
  return BST::DetachKey();
}
/////////////////////////////////////////////////////////////////////////////
void AVLTree::Balance()
{
  AdjustHeight();
  if(abs(BalanceFactor()) > 1)
    {
      if(BalanceFactor() > 0)
	{
	  if(GetLeft().BalanceFactor() > 0)
	    LLRotation();
	  else
	    LRRotation();
	}
      else
	{
	  if(GetRight().BalanceFactor() < 0)
	    RRRotation();
	  else
	    RLRotation();
	}
    }
}
/////////////////////////////////////////////////////////////////////////////
AVLTree& AVLTree::GetLeft() const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  return dynamic_cast<AVLTree&> (*pBinaryTreeLeft);
}
/////////////////////////////////////////////////////////////////////////////
AVLTree& AVLTree::GetRight() const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  return dynamic_cast<AVLTree&> (*pBinaryTreeRight);
}
/////////////////////////////////////////////////////////////////////////////
MWayTree::MWayTree(unsigned int m) :
  nWay(m),
  nNumberOfKeys(0),
  arrayKey(m - 1, 1),
  arraySubTree(m)
{}
/////////////////////////////////////////////////////////////////////////////
MWayTree::~MWayTree()
{
  Purge();
}
/////////////////////////////////////////////////////////////////////////////
Object& MWayTree::GetKey(unsigned int i) const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  return *arrayKey[i];
}
/////////////////////////////////////////////////////////////////////////////
Tree& MWayTree::GetSubTree(unsigned int i) const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  return *arraySubTree[i];
}
/////////////////////////////////////////////////////////////////////////////
void MWayTree::DepthFirstTraversal(PrePostVisitor& visitor) const
{
  //DebugPrintf(("nNumberOfKeys = %d", nNumberOfKeys));
  if(!IsEmpty())
    {
      for(int i = 0; i <= (int)nNumberOfKeys + 1; i++)
	{
	  //DebugPrintf(("nNumberOfKeys = %d", nNumberOfKeys));
	  if(i >= 2)
	    visitor.PostVisit(*arrayKey[i - 1]);
	  if(i >= 1 && i <= (int)nNumberOfKeys)
	    visitor.Visit(*arrayKey[i]);
	  if(i <= int(nNumberOfKeys - 1))
	    visitor.PreVisit(*arrayKey[i + 1]);
	  if(i <= (int)nNumberOfKeys)
	    arraySubTree[i]->DepthFirstTraversal(visitor);
	}
    }
}
void MWayTree::BreadthFirstTraversal(Visitor& visitor) const
{
  QueueAsLinkedList queueList;
  queueList.RescindOwnership();
  if(!IsEmpty())
    {
      queueList.EnQueue(const_cast<MWayTree&>(*this));
      while(!queueList.IsEmpty())
	{
	  MWayTree const& tree = dynamic_cast<MWayTree const&> (queueList.DeQueue());		 
	  for(unsigned int i = 1; i <= tree.nNumberOfKeys; i++)			 
	    visitor.Visit(tree.GetKey(i));
	  for(unsigned int i = 0; i <= tree.nNumberOfKeys; i++)
	    if(!tree.GetSubTree(i).IsEmpty())
	      queueList.EnQueue(tree.GetSubTree(i));
	}
    }
}
/////////////////////////////////////////////////////////////////////////////
unsigned int MWayTree::FindIndex(Object const& object) const
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  if(object < *arrayKey[1])
    return 0;
  unsigned int nLeft = 1U;
  unsigned int nRight = nNumberOfKeys;
  while(nLeft < nRight)
    {
      //int const iMiddle = (nLeft + nRight +1) / 2;
      unsigned int nMiddle = (nLeft + nRight + 1) / 2;
      if(object >= *arrayKey[nMiddle])
	nLeft = nMiddle;
      else
	nRight = nMiddle - 1U;
    }
  return nLeft;
}
/////////////////////////////////////////////////////////////////////////////
Object& MWayTree::Find(Object const& object) const
{
  if(IsEmpty())
    return NullObject::GetInstance();
  unsigned int const nIndex = FindIndex(object);
  if(nIndex != 0 && object == *arrayKey[nIndex])
    return *arrayKey[nIndex];
  else
    return arraySubTree[nIndex]->Find(object);
}
/////////////////////////////////////////////////////////////////////////////
void MWayTree::Insert(Object& object)
{
  if(IsEmpty())
    {
      arraySubTree[0] = new MWayTree(nWay);
      arrayKey[1] = &object;
      arraySubTree[1] = new MWayTree(nWay);
      nNumberOfKeys = 1U;
    }
  else
    {
      unsigned int const nIndex = FindIndex(object);

      if(nIndex != 0 && object == *arrayKey[nIndex])
	throw std::invalid_argument("duplicate key");

      if(nNumberOfKeys < nWay - 1U)
	{
	  for(unsigned int i = nNumberOfKeys; i > nIndex; i--)
	    {
	      arrayKey[i + 1U] = arrayKey[i];
	      arraySubTree[i + 1U] = arraySubTree[i];
	    }
	  arrayKey[nIndex + 1U] = &object;
	  arraySubTree[nIndex + 1U] = new MWayTree(nWay);
	  nNumberOfKeys++;
	}
      else
	arraySubTree[nIndex]->Insert(object);
    }
}
/////////////////////////////////////////////////////////////////////////////
void MWayTree::WithDraw(Object& object)
{
  if(IsEmpty())
    throw std::invalid_argument("object not found");
  unsigned int const nIndex = FindIndex(object);
  if(nIndex != 0 && object == *arrayKey[nIndex])
    {
      if(!arraySubTree[nIndex - 1U]->IsEmpty())
	{
	  Object& objMax = arraySubTree[nIndex - 1U]->FindMax();
	  arrayKey[nIndex] = &objMax;
	  arraySubTree[nIndex - 1U]->WithDraw(objMax);
	}
      else if(!arraySubTree[nIndex]->IsEmpty())
	{
	  Object& objMin = arraySubTree[nIndex]->FindMin();
	  arrayKey[nIndex] = &objMin;
	  arraySubTree[nIndex]->WithDraw(objMin);
	}
      else
	{
	  nNumberOfKeys--;
	  delete arraySubTree[nIndex];
	  for(unsigned int i = nIndex; i <= nNumberOfKeys; i++)
	    {
	      arrayKey[i] = arrayKey[i + 1];
	      arraySubTree[i] = arraySubTree[i + 1];
	    }
	  if(nNumberOfKeys == 0)
	    delete arraySubTree[0];
	}
    }
  else
    arraySubTree[nIndex]->WithDraw(object);
}
/////////////////////////////////////////////////////////////////////////////
bool MWayTree::IsMember(Object const& object) const
{
  return Find(object) != NullObject::GetInstance();
}
/////////////////////////////////////////////////////////////////////////////
int MWayTree::CompareTo(Object const& object) const
{
  MWayTree const& tree =
    dynamic_cast<MWayTree const&> (object);
  return ::Compare(GetHeight(), tree.GetHeight());
}
/////////////////////////////////////////////////////////////////////////////
bool MWayTree::IsEmpty() const
{
  return nNumberOfKeys == 0;
}
/////////////////////////////////////////////////////////////////////////////
Object& MWayTree::GetKey() const
{
  throw std::invalid_argument("invalid argument");
  return NullObject::GetInstance();
}
/////////////////////////////////////////////////////////////////////////////
Object& MWayTree::FindMin() const
{
  if(IsEmpty())
    return NullObject::GetInstance();
  else if(GetSubTree(0).IsEmpty())
    return GetKey(1);
  else
    return (dynamic_cast<MWayTree&> (GetSubTree(0))).FindMin();
}
/////////////////////////////////////////////////////////////////////////////
Object& MWayTree::FindMax() const
{
  if(IsEmpty())
    return NullObject::GetInstance();
  else if(GetSubTree(nNumberOfKeys).IsEmpty())
    return GetKey(nNumberOfKeys);
  else
    return (dynamic_cast<MWayTree&> (GetSubTree(nNumberOfKeys))).FindMax();
}
/////////////////////////////////////////////////////////////////////////////
unsigned int MWayTree::GetDegree() const
{
  return nWay;
}
/////////////////////////////////////////////////////////////////////////////
bool MWayTree::IsLeaf() const
{
  if(IsEmpty()) //It's right?
    throw std::domain_error("invalid operation");
  for(unsigned int i = 0; i <= nNumberOfKeys; i++)
    {
      if(GetSubTree(i).IsEmpty())
	continue;
      else
	return false;
    }
  return true;
}
/////////////////////////////////////////////////////////////////////////////
void MWayTree::Purge()
{
  if(!IsEmpty())
    {
      unsigned int i = 0;
      if(IsOwner())
	{
	  for(i = 1; i <= nNumberOfKeys; i++)
	    {
	      if(arrayKey[i] == 0)
		throw std::logic_error("should never happen");
	      delete arrayKey[i];
	    }
	}
      for( i = 0; i <= nNumberOfKeys;  i++)
	{
	  if(arraySubTree[i] == 0)
	    throw std::logic_error("should never happen");
	  delete arraySubTree[i];
	}
      arraySubTree.SetLength(0); //it is right? difficult to determine
    }
}
Iterator& MWayTree::NewIterator() const
{
  return *new Iter(*this);
}
/////////////////////////////////////////////////////////////////////////////
MWayTree::Iter::Iter(MWayTree const& _tree) :
  tree(_tree),
  stack(*new StackAsLinkedList()),
  queue(*new QueueAsLinkedList())
{
  stack.RescindOwnership();
  queue.RescindOwnership();
  Reset();
}
MWayTree::Iter::~Iter()
{
  delete &stack;
  delete &queue;
}
//	virtual function of Iterator	
void MWayTree::Iter::Reset()
{
  stack.Purge();
  queue.Purge();

  if(!tree.IsEmpty())
    {
      int i = 0;
      for(i = 1; i <= (int)tree.nNumberOfKeys; i++)
	queue.EnQueue(tree.GetKey(i));
      for(i = tree.nNumberOfKeys; i >= 0; i--)
	{			
	  MWayTree& subTree = dynamic_cast<MWayTree&>(tree.GetSubTree(i));			
	  if(!subTree.IsEmpty())
	    stack.Push(subTree);
	}

      //stack.Push(const_cast<MWayTree&>(tree));
    }
}
bool MWayTree::Iter::IsDone() const
{
  return queue.IsEmpty() && stack.IsEmpty();
}
Object& MWayTree::Iter::operator *() const
{
  if(!queue.IsEmpty())
    {
      return queue.GetHead();
    }
  else
    return NullObject::GetInstance();
}
void MWayTree::Iter::operator ++()
{
  int i = 0;
  if(!queue.IsEmpty())
    queue.DeQueue();

  if(!stack.IsEmpty() && queue.IsEmpty())
    {
      MWayTree const& top = 
	dynamic_cast<MWayTree const&> (stack.Pop());

      for(i = 1; i <= (int)top.nNumberOfKeys; i++)
	{
	  queue.EnQueue(top.GetKey(i));
	}
      for(i = (int)top.nNumberOfKeys; i >= 0; i--)
	{
	  MWayTree& subTree = dynamic_cast<MWayTree&>(top.GetSubTree(i));
	  if(!subTree.IsEmpty())
	    stack.Push(subTree);
	}
    }
}
/////////////////////////////////////////////////////////////////////////////
void BTree::Insert(Object& object)
{
  //	DebugPrintf(("this->nWay: %d", nWay));
  if(IsEmpty())
    {
      if(pBTreeParent == 0)
	{
	  AttachSubTree(0, *new BTree(nWay, *this));
	  AttachKey(1, object);
	  AttachSubTree(1, *new BTree(nWay, *this));
	  nNumberOfKeys = 1;
	}
      else
	pBTreeParent->InsertPair(object, *new BTree(nWay, *pBTreeParent));
    }
  else
    {
      unsigned int const nIndex = FindIndex(object);
      if(nIndex != 0 && object == *arrayKey[nIndex])
	throw std::invalid_argument("duplicate key");
      arraySubTree[nIndex]->Insert(object);
    }
}
/////////////////////////////////////////////////////////////////////////////
void BTree::InsertPair(Object& object, BTree& child)
{
  //	DebugPrintf(("object = %d", int(dynamic_cast<Int&>(object))));
  unsigned int const nIndex = FindIndex(object);
  //	DebugPrintf(("nIndex = %d", nIndex));
  BTree& extraTree = InsertSubTree(nIndex + 1, child);
  Object& extraKey = InsertKey(nIndex + 1, object);
  //	DebugPrintf(("extraKey = %d", int(dynamic_cast<Int&>(extraKey))));

  if(++nNumberOfKeys == nWay)
    {
      if(pBTreeParent == 0)
	{
	  BTree& left = *new BTree(nWay, *this);
	  BTree& right = *new BTree(nWay, *this);
	  left.AttachLeftHalfOf(*this);
	  right.AttachRightHalfOf(*this, extraKey, extraTree);
	  AttachSubTree(0, left);
	  AttachKey(1, *arrayKey[(nWay + 1) / 2]);
	  //		DebugPrintf(("*arrayKey[%d] = %d", (nWay + 1) / 2, int(dynamic_cast<Int&>(*arrayKey[(nWay + 1) / 2]))));
	  AttachSubTree(1, right);
	  nNumberOfKeys = 1;
	}
      else
	{
	  nNumberOfKeys = (nWay + 1) / 2 - 1;
	  BTree& right = * new BTree(nWay, *pBTreeParent);
	  right.AttachRightHalfOf(*this, extraKey, extraTree);
	  pBTreeParent->InsertPair(*arrayKey[(nWay + 1) / 2], right);
	}
    }
}
/////////////////////////////////////////////////////////////////////////////
BTree::BTree(unsigned int nWay) : 
  MWayTree(nWay),
  pBTreeParent(0)
{}
/////////////////////////////////////////////////////////////////////////////
BTree::BTree(unsigned int nWay, BTree& btree) : 
  MWayTree(nWay),
  pBTreeParent(&btree)
{}
/////////////////////////////////////////////////////////////////////////////
void BTree::AttachKey(unsigned int nIndex, Object& object)
{
  arrayKey[nIndex] = &object;
}
/////////////////////////////////////////////////////////////////////////////
void BTree::AttachSubTree(unsigned int nIndex, MWayTree& btree)
{
  arraySubTree[nIndex] = &btree;
}
/////////////////////////////////////////////////////////////////////////////
Object& BTree::DeleteKey(unsigned int nIndex)
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  if(nIndex >= nWay)
    throw std::invalid_argument("invalid argument");
  Object& object = DetachKey(nIndex);
  for(unsigned int i = nIndex; i < nNumberOfKeys; i++)
    arrayKey[i] = arrayKey[i + 1];
  arrayKey[nNumberOfKeys] = 0;
  return object;
}
/////////////////////////////////////////////////////////////////////////////
Object& BTree::InsertKey(unsigned int nIndex, Object& object)
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");

  if(nIndex == nWay)
    return object;

  if(nNumberOfKeys < nWay - 1)
    {
      for(unsigned int i = nNumberOfKeys + 1; i > nIndex; i--)
	{
	  arrayKey[i] = arrayKey[i - 1];
	}
      arrayKey[nIndex] = &object;
      return *arrayKey[nNumberOfKeys + 1];
    }
  else
    {
      Object* pObj = arrayKey[nWay - 1];
      for(unsigned int i = nWay - 1; i > nIndex; i--)
	{
	  arrayKey[i] = arrayKey[i - 1];
	}
      arrayKey[nIndex] = &object;
      return *pObj;
    }	
}
/////////////////////////////////////////////////////////////////////////////
BTree& BTree::DeleteSubTree(unsigned int nIndex)
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  if(nIndex >= nWay)
    throw std::invalid_argument("invalid argument");
  BTree& btree = DetachSubTree(nIndex);
  for(unsigned int i = nIndex; i < nNumberOfKeys; i++)
    arraySubTree[i] = arraySubTree[i + 1];
  arraySubTree[nNumberOfKeys] = 0;
  return btree;
}
/////////////////////////////////////////////////////////////////////////////
BTree& BTree::InsertSubTree(unsigned int nIndex, BTree& btree)
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");

  if(nIndex == nWay)
    return btree;

  if(nNumberOfKeys < nWay - 1)
    {
      for(unsigned int i = nNumberOfKeys + 1; i > nIndex; i--)
	{
	  arraySubTree[i] = arraySubTree[i - 1];
	}
      arraySubTree[nIndex] = &btree;
      return dynamic_cast<BTree&>(*arraySubTree[nNumberOfKeys + 1]);
    }
  else
    {
      BTree* pTree = dynamic_cast<BTree*>(arraySubTree[nWay - 1]);
      for(unsigned int i = nWay - 1; i > nIndex; i--)
	{
	  arraySubTree[i] = arraySubTree[i - 1];
	}
      arraySubTree[nIndex] = &btree;
      return *pTree;
    }
}
/////////////////////////////////////////////////////////////////////////////
void BTree::AttachLeftHalfOf(BTree const& btree)
{
  if(!IsEmpty())
    throw std::domain_error("invalid operation");

  if(nWay > 2)
    {
      arraySubTree[0] = btree.arraySubTree[0];
      (dynamic_cast<BTree*>(arraySubTree[0]))->pBTreeParent = this;
    }
  for(unsigned int i = 1; i < (nWay + 1) / 2; i++)
    {
      arrayKey[i] = btree.arrayKey[i];
      //		DebugPrintf(("AttachLeftHalfOf::*arrayKey[%d] = %d", i, int(dynamic_cast<Int&>(*arrayKey[i]))));
      arraySubTree[i] = btree.arraySubTree[i];
      (dynamic_cast<BTree*>(arraySubTree[i]))->pBTreeParent = this;
    }
  nNumberOfKeys = (nWay + 1) / 2 - 1;
}
/////////////////////////////////////////////////////////////////////////////
void BTree::AttachRightHalfOf(BTree const& btree, Object& object, BTree& extraTree)
{
  if(!IsEmpty())
    throw std::domain_error("invalid operation");

  arraySubTree[0] = btree.arraySubTree[(nWay + 1) / 2];
  (dynamic_cast<BTree*>(arraySubTree[0]))->pBTreeParent = this;

  for(unsigned int i = (nWay + 1) / 2 + 1; i < nWay; i++)
    {
      arrayKey[i - (nWay + 1) / 2] = btree.arrayKey[i];
      //DebugPrintf(("AttachLeftHalfOf::*arrayKey[%d] = %d", i - (nWay + 1) / 2, int(dynamic_cast<Int&>(*arrayKey[i - (nWay + 1) / 2]))));
      arraySubTree[i - (nWay + 1) / 2] = btree.arraySubTree[i];
      (dynamic_cast<BTree*>(arraySubTree[i - (nWay + 1) / 2]))->pBTreeParent = this;
    }
  arrayKey[nWay / 2] = &object;
  arraySubTree[nWay / 2] = &extraTree;
  (dynamic_cast<BTree*>(arraySubTree[nWay / 2]))->pBTreeParent = this;
  nNumberOfKeys = nWay / 2;
}
/////////////////////////////////////////////////////////////////////////////
void BTree::WithDraw(Object& object)
{	 
  if(IsEmpty())
    throw std::invalid_argument("object not find");

  unsigned int nIndex = FindIndex(object);

  if(nIndex != 0 && object == *arrayKey[nIndex])
    {
      if(!arraySubTree[nIndex - 1]->IsEmpty())
	{
	  Object& max = arraySubTree[nIndex - 1]->FindMax();
	  arrayKey[nIndex] = &max;
	  arraySubTree[nIndex - 1]->WithDraw(max);
	  Balance(nIndex);
	}
      else if(!arraySubTree[nIndex]->IsEmpty())
	{
	  Object& min = arraySubTree[nIndex]->FindMin();
	  arrayKey[nIndex] = &min;
	  arraySubTree[nIndex]->WithDraw(min);
	  Balance(nIndex);
	}
      else
	{
	  DeleteKey(nIndex);
	  DeleteSubTree(nIndex);

	  if(nNumberOfKeys == 1)
	    DetachSubTree(nIndex - 1);

	  nNumberOfKeys--;
	  //DebugPrintf(("nNumberOfKeys = %d", nNumberOfKeys));
	}			
    }
  else
    {
      arraySubTree[nIndex]->WithDraw(object);
      Balance(nIndex);
    }	
}
/////////////////////////////////////////////////////////////////////////////
Object& BTree::DetachKey(unsigned int nIndex)
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  Object& object = *arrayKey[nIndex];
  arrayKey[nIndex] = 0;
  return object;
}
/////////////////////////////////////////////////////////////////////////////
BTree& BTree::DetachSubTree(unsigned int nIndex)
{
  if(IsEmpty())
    throw std::domain_error("invalid operation");
  BTree& btree = dynamic_cast<BTree&>(*arraySubTree[nIndex]);
  arraySubTree[nIndex] = 0;
  return btree;
}
/////////////////////////////////////////////////////////////////////////////
void BTree::Balance(unsigned int nIndex)
{
  if(nIndex > nNumberOfKeys)
    throw std::invalid_argument("invalid argument");

  int left = 0;
  int right = 0;
  if(nIndex > 0)
    {
      left = (int)dynamic_cast<BTree*>(arraySubTree[nIndex - 1])->nNumberOfKeys;
      right = (int)dynamic_cast<BTree*>(arraySubTree[nIndex])->nNumberOfKeys;
    }
  else
    {
      left = (int)dynamic_cast<BTree*>(arraySubTree[nIndex])->nNumberOfKeys;
      right = (int)dynamic_cast<BTree*>(arraySubTree[nIndex + 1])->nNumberOfKeys;
    }
	
  if((left - right >= 2) && (right == (nWay + 1) / 2 - 2))
    {
      LLRotation(nIndex);
    }
  else if((right - left >= 2) && (left == (nWay + 1) / 2 - 2))
    {
      RRRotation(nIndex);
    }
  else if((abs(left - right) == 1) && (left + right <= nWay - 2))
    {
      Coalition(nIndex);
    }
}
/////////////////////////////////////////////////////////////////////////////
void BTree::LLRotation(unsigned int nIndex)
{
  BTree& leftTree = dynamic_cast<BTree&>(*arraySubTree[nIndex - 1]);
  BTree& rightTree = dynamic_cast<BTree&>(*arraySubTree[nIndex]);

  unsigned int left = leftTree.nNumberOfKeys;
  unsigned int right = rightTree.nNumberOfKeys;


  for(int i = (int)right; i > 0; i--)
    {
      rightTree.arraySubTree[i + 1] = rightTree.arraySubTree[i];
      rightTree.arrayKey[i + 1] = rightTree.arrayKey[i];
    }

  rightTree.arraySubTree[1] = rightTree.arraySubTree[0];
  if(rightTree.arraySubTree[1] == 0)
    rightTree.arraySubTree[1] = new BTree(nWay, rightTree);
  rightTree.arrayKey[1] = arrayKey[nIndex];
  rightTree.arraySubTree[0] = leftTree.arraySubTree[left];
  (dynamic_cast<BTree*>(rightTree.arraySubTree[0]))->pBTreeParent = &rightTree;

  rightTree.nNumberOfKeys++;

  arrayKey[nIndex] = leftTree.arrayKey[left];

  leftTree.arraySubTree[left] = 0; 
  leftTree.arrayKey[left] = 0;

  leftTree.nNumberOfKeys--;
}
/////////////////////////////////////////////////////////////////////////////
void BTree::RRRotation(unsigned int nIndex)
{
  BTree& leftTree = dynamic_cast<BTree&>(*arraySubTree[nIndex - 1]);
  BTree& rightTree = dynamic_cast<BTree&>(*arraySubTree[nIndex]);

  unsigned int left = leftTree.nNumberOfKeys;
  unsigned int right = rightTree.nNumberOfKeys;

  if(left == 0)
    leftTree.arraySubTree[0] = new BTree(nWay, leftTree);
  leftTree.arrayKey[left + 1] = arrayKey[nIndex];
  leftTree.arraySubTree[left + 1] = rightTree.arraySubTree[0];
  (dynamic_cast<BTree*>(leftTree.arraySubTree[left + 1]))->pBTreeParent = &leftTree;

  leftTree.nNumberOfKeys++;

  rightTree.arraySubTree[0] = rightTree.arraySubTree[1];
  for(unsigned int i = 1; i < right; i++)
    {
      rightTree.arrayKey[i] = rightTree.arrayKey[i + 1];
      rightTree.arraySubTree[i] = rightTree.arraySubTree[i + 1];
    }
  rightTree.arrayKey[right] = 0;
  rightTree.arraySubTree[right] = 0;

  rightTree.nNumberOfKeys--;
}
/////////////////////////////////////////////////////////////////////////////
void BTree::Coalition(unsigned int nIndex)
{
  BTree& leftTree = dynamic_cast<BTree&>(*arraySubTree[nIndex - 1]);
  BTree& rightTree = dynamic_cast<BTree&>(*arraySubTree[nIndex]);

  unsigned int left = leftTree.nNumberOfKeys;
  unsigned int right = rightTree.nNumberOfKeys;

  if(left == 0)
    leftTree.arraySubTree[0] = new BTree(nWay, leftTree);
  leftTree.arrayKey[left + 1] = arrayKey[nIndex];
  leftTree.arraySubTree[left + 1] = rightTree.arraySubTree[0];
  (dynamic_cast<BTree*>(leftTree.arraySubTree[left + 1]))->pBTreeParent = &leftTree;
  rightTree.arraySubTree[0] = new BTree(nWay, rightTree);
  for(unsigned int i = 1; i <= right; i++)
    {
      leftTree.arrayKey[left + 1 + i] = rightTree.arrayKey[i];
      leftTree.arraySubTree[left + 1 + i] = rightTree.arraySubTree[i];
      (dynamic_cast<BTree*>(leftTree.arraySubTree[left + 1 + i]))->pBTreeParent = &leftTree;
      rightTree.arraySubTree[i] = new BTree(nWay, rightTree);
    }
  leftTree.nNumberOfKeys = left + 1 + right;

  rightTree.RescindOwnership();
  delete &rightTree;

  for(unsigned int i = nIndex; i < nNumberOfKeys; i++)
    {
      arrayKey[i] = arrayKey[i + 1];
      arraySubTree[i] = arraySubTree[i + 1];
    }
  arrayKey[nNumberOfKeys] = 0;
  arraySubTree[nNumberOfKeys] = 0;

  nNumberOfKeys--;
}
/////////////////////////////////////////////////////////////////////////////
BinomialTree::BinomialTree(Object& object):GeneralTree(object)
{}
///////////////////////////////////////////////////////////////////
void BinomialTree::Add(BinomialTree& tree)
{
  if(nDegree != tree.nDegree)
    throw std::invalid_argument("incompatible degrees");
  if(*pObjKey > *tree.pObjKey)
    SwapContents(tree);
  AttachSubTree(tree);
}
///////////////////////////////////////////////////////////////////
void BinomialTree::SwapContents(BinomialTree& tree)
{
  Swap((void*&)pObjKey, (void*&)tree.pObjKey);
  DLinkedList<GeneralTree*> listTemp = list;
  list = tree.list;
  tree.list = listTemp;
}
///////////////////////////////////////////////////////////////////
BinomialTree& BinomialTree::GetSubTree(unsigned int n) const
{
  return dynamic_cast<BinomialTree&>(GeneralTree::GetSubTree(n));
}
///////////////////////////////////////////////////////////////////
