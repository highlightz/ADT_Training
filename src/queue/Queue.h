// Queue.h -- class template implemented with linked list.

#ifndef QUEUE_H
#define QUEUE_H

template < class DataType >
struct Node
{
  DataType info;
  Node< DataType >* next;
};

template < class DataType >
class Queue
{
public:
  Queue( );
  Queue( const Queue< DataType >& qpqueue );
  ~Queue( );
  Queue< DataType >& operator =( const Queue< DataType >& rqueue );
  void enqueue( const DataType& element );
  
  // Dequeues element and returns it in deqElem
  // returns false if called on an empty queue; otherwise returns true
  bool dequeue( DataType& deqElem );
  
  // Returns element at the front of the queue into frontElem without removing it.
  // Returns false if called on an empty queue; otherwise returns true.
  bool peek( DataType& frontElem );
  bool isEmpty( ) const;  // Returns true if the queue is empty; otherwise returns false
  void makeEmpty( );
private:
  Node< DataType >* front;
  Node< DataType >* back;
  Node< DataType > header;
  inline void deepCopy( const Queue< DataType >& original );
};

// Implementation of class template Queue
template < class DataType >
Queue< DataType >::Queue( )
{
  front = back = &header;
}

template < class DataType >
Queue< DataType >::Queue( const Queue< DataType >& apqueue )
{
  deepCopy( apqueue );
}

template < class DataType >
Queue< DataType >::~Queue( )
{
  makeEmpty( );
}

template < class DataType >
Queue< DataType >& Queue< DataType >::operator =( const Queue< DataType >& rqueue )
{
  if ( this == &rqueue )
    return *this;
    
  makeEmpty( );
  deepCopy( rqueue );
  return *this;
}

template < class DataType >
void Queue< DataType >::enqueue( const DataType& element )
{
  Node< DataType >* ptr = new Node< DataType >;
  ptr->info = element;
  back->next = ptr;
  back = ptr;
}

template < class DataType >
bool Queue< DataType >::dequeue( DataType& deqElem )
{
  if ( front == back )
    return false;
 
  Node< DataType >* ptr = front->next; 
  deqElem = ptr->info;
  front->next = ptr->next;
  if ( back == ptr )
    back = front;
    
  delete ptr;
  
  return true;
}

#endif
