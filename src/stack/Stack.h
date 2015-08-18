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
