// 例1：函数指针的数组
double sum( double, double );  // Function prototype
double product( double, double );
double difference( double, double );
double (* pfun[3] )( double, double ) = { sum, product, difference };  // Array of function pointers

// 使用该指针数组的第二个元素调用product( )函数
pfun[1]( 2.5, 3.5 );
