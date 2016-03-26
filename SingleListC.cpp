#include <iostream>
#include <string>
using namespace std;

template < typename DataType >
struct Node
{
	DataType info;
	Node< DataType>* next;
};

template < typename DataType >
void printList( Node< DataType >* start )
{
	Node< DataType >* ptr = start;
	if ( 0 == ptr )
	{
		cout << "Empty list." << endl;
	}
	
	while ( ptr != 0 )
	{
		cout << ptr->info << " at address: " << ptr << endl;
		ptr = ptr->next;
	}	
	cout << endl;
}

// 搜索一个必然存在的值
/*
// TOTEST:
Node< int >* existed = searchExistingItem<int>( start, atoi( argv[1] ) );
cout << "Found: " << existed->info << " at address: " << existed << endl << endl;
*/
template < typename DataType >
Node< DataType >* searchExistingItem( Node< DataType >* start, DataType target )
{
	Node< DataType >* ptr = start;
	while ( ptr->info != target )
	{
		ptr = ptr->next;	
	}
	
	return ptr;  // TOASK: is this operation safe?
}

// 搜索一个可能不存在的值
// 搜索结果信息包 
template < typename DataType >
struct SearchInfo
{
	Node< DataType >* searched;
	bool found;
};

template < typename DataType >
SearchInfo< DataType> searchItem( Node< DataType >* start, DataType target )
{
	Node< DataType >* ptr = start;
	bool found = false;
	
	while ( ptr != 0 && !found )
	{
		if ( ptr->info == target )
		{
			found = true;
		}
		
		if ( !found )
		{
			ptr = ptr->next;
		}
	}	
	
	SearchInfo< DataType > info;
	info.found = found;
	info.searched = ptr;
	
	return info;
}
	
// 在链表表头插入一个节点
template < typename DataType >
Node< DataType >* insertItem( Node< DataType >* start, DataType item )
{
	Node< DataType >* newNode = new Node< DataType >;
	newNode->info = item;
	newNode->next = start;
	start = newNode;
	
	return start;
}
	
int main( int argc, char** argv )
{
	// 初始化链表 
	Node< int >* start = new Node< int >;
	start->info = 1;  // contents: [1|\]
	
	start->next = new Node< int >;
	start->next->info = 3;
	start->next->next = 0;  // contents: [1|->&3 3|\]
	
	cout << "Initialized list:"<< endl;
	printList<int>( start );

	// 搜索一个可能不存在的值
	SearchInfo< int > info = searchItem< int >( start, atoi( argv[1] ) );	
	if ( info.found )
	{
		cout << "Found: " << info.searched->info << " at address: " << info.searched << endl << endl;
	} 
	else
	{
		cout << "Not found." << endl << endl;
	}
	
	// 在链表表头插入一个节点
	Node< int >* newStart = insertItem( start, 8 );
	cout << "After inserting before head:"<< endl;
	printList<int>( newStart );
	
	return 0;
}
