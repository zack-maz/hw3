#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  PComparator c_;
  unsigned int m_;
  std::vector<T> data; //store data as vector
  void trickleUp(unsigned int idx, const PComparator &c);
  void trickleDown(unsigned int idx, const PComparator &c);



};








// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(unsigned int idx, const PComparator &c)
{
  if (idx == 0) return; //if at root, stop trickling up

  int parentIdx = (idx-1)/m_; //find index of parent
  if (c(data[idx], data[parentIdx])) //compare
  {
    std::swap(data[idx], data[parentIdx]); //comparator passes, swap
    trickleUp(parentIdx, c); //recurse at swapped node
  }
}


  

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(unsigned int idx, const PComparator& c)
{
  unsigned int swap = m_*idx+1; //get index of first child
  if (swap >= data.size()) return; //if child doesnt exist, end recursion

  for (unsigned int i = 2; i <= m_; i++) //loop through children and compare the min/max
  {
    unsigned int currChildIdx = m_*idx+i;
    if (currChildIdx > data.size()-1) break; //if parent doesnt have all children, end loop
    if (c(data[currChildIdx], data[swap])) { swap = currChildIdx; } //get index of min/max
  }

  if (c(data[swap], data[idx]))
  {
    std::swap(data[idx], data[swap]);
    trickleDown(swap, c); //recurse at swapped node
  }

}










template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) //: m_(m), c_(c) 
{
  m_ = m;
  c_ = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {}



template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data.push_back(item); //add item at end
  trickleUp(data.size()-1, c_); //recurse it up to right spot
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty.");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty.");

  }
  else if (data.size() == 1) 
  {
    data.pop_back(); //just remove only value if only root
  }
  else
  {
    data[0] = data.back(); //replace first value with last
    data.pop_back(); //remove last value so no duplicate
    trickleDown(0, c_); //recurse down to right spot
  }

}




template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const { return data.empty(); }

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const { return data.size(); }




#endif

