template < class DataType >
void Stack< DataType >::push( DataType elementToPush )
{
  if ( ++top == elements.length( ) )
    elements.changeSize( elements.length( ) << 1 );
  elements[top] = elementToPush;
}
