// Queue.h -- class template implemented with linked list.

template < class DataType >
struct Node
{
  DataType info;
  Node< DataType >* next;
};

