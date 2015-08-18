// Stack.h - an array based implementation of a stack

#ifndef STACK_H
#define STACK_H
// Refer to
// 'https://github.com/highlightz/Adjustable-Array/blob/master/AdjustableArray.h'
#include "AdjustableArray.h"

template < class DataType >
class Stack
{
public:
  Stack( );
  void push( DataType elementToPush );
  bool pop( DataType& poppedElement );
  bool peek( DataType& topElement );
  bool isEmpty( ) const;
  void makeEmpty( );
private:
  int top;
  AdjustableArray< DataType > elements;
};

template < class DataType >
Stack< DataType >::Stack( )
: top( -1 ), elements( 2 )
{
}

template < class DataType >
void Stack< DataType >::push( DataType elementToPush )
{
  if ( ++top == elements.length( ) )
    elements.changeSize( elements.length( ) << 1 );  // Equals to elements.length( ) * 2
  elements[top] = elementToPush;
}

// Removes an element from the top of the stack and returns it in poppedElement;
// Returns false if called on an empty stack; otherwise, returns true.
template < class DataType >
bool Stack< DataType >::pop( DataType& poppedElement )
{
  if ( pop == -1 )
    return false;
    
  poppedElement = elements[pop];
  top--;
  
  int trysize = elements.length( );
  
  while ( ( ( top + 1 ) <= ( trysize >> 2 ) ) && ( trysize > 2 ) )
    trysize >>= 1;
    
  if ( trysize < elements.length( ) )
    try
    {
      elements.changeSize( trysize );
    }
    catch( ... )
    {
    }
    
  return true;
}

template < class DataType >
bool Stack< DataType >::peek( DataType& topElement )
{
  if ( top == -1 )
    return false;
  topElement = elements[top];
  return true;
}

template < class DataType >
bool Stack< DataType >::isEmpty( ) const
{
  return top == -1;
}

template < class DataType >
void Stack< DataType >::makeEmpty( )
{
  top = -1;
  try
  {
    elements.changeSize( 2 );
  }
  catch ( ... )
  {
  }
}
#endif
