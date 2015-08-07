// LinkedList.h - class for a linked list as a data structure

template < class DataType >
struct Node 
{
	DataType info;
	Node< DataType >* next;
};

// LinkedList maintain a current position in list after each function call.
// If an object of a struct is used for DataType, the == operator must be overloaded for it;
// the left and right operands are both DataType objects, the == comparison is used for finding elements,
// usually by key value.
// For find, retrieve and remove functions, if you are using an object as an element, 
// a typical use would be to set the key of the desired object to find or remove, 
// then pass the object into the function.

// The constructor, copy constructor, overloaded assignment operator, and insert function
// can throw an exception if out of heap memory.

template < class DataType >
class LinkedList
{
public:
	LinkedList( );
	LinkedList( const LinkedList< DataType >& aplist );
	~LinkedList( );
	LinkedList< DataType >& operator =( const LinkedList< DataType >& rlist );


};
