#include <iostream>
using namespace std;

template < typename DataType >
struct Node
{
	DataType info;
	Node< DataType>* next;
};

// 搜索反馈信息包 
template < typename DataType >	
struct SearchInfo
{
	Node< DataType >* searched;
	bool found;
};
	
template < typename DataType >
class NodeList
{
private:
	Node< DataType >* start;  // 有指针成员，析构函数等就是必要的了
			
public:
	NodeList( DataType item )
	{
		start = new Node< DataType >;
		start->info = item;
		start->next = 0;
	}
	
	// 在链表表头插入一个节点
	Node< DataType >* insertItem( DataType item )
	{
		Node< DataType >* newNode = new Node< DataType >;
		newNode->info = item;
		newNode->next = start;
		start = newNode;	
	}
		
	SearchInfo< DataType > searchItem( DataType target )
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
	
	void printList(  )
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
	
};

int main( )
{
	NodeList< int > start( 1 );
	start.printList( );
	
	start.insertItem( 3 );
	start.printList( );
	
	start.insertItem( 2 );
	start.printList( );
	
	SearchInfo< int > searchInfo = start.searchItem( 1 );
	if ( searchInfo.found )
	{
		cout << "Found: " << searchInfo.searched->info << " at address: " << searchInfo.searched << endl << endl;
	}
	else
	{
		cout << "Not found." << endl << endl;
	}
	
	searchInfo = start.searchItem( 2 );
	if ( searchInfo.found )
	{
		cout << "Found: " << searchInfo.searched->info << " at address: " << searchInfo.searched << endl << endl;
	}
	else
	{
		cout << "Not found." << endl << endl;
	}
	
}
