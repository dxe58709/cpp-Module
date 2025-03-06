#include "iter.hpp"
/
int main(void)
{
	int intArr[] = {1, 2, 3, 4, 5};
	std::size_t len = sizeof(intArr) / sizeof(intArr[0]);
	iter(intArr, len, printT<int>);
	std::cout << "\n";

	const int intArr2[] = {10, 25, 30};
	len = sizeof(intArr2) / sizeof(intArr2[0]);
	iter(intArr2, len, printT<const int>);
	std::cout << "\n";

	int *nullArr = NULL;
	iter(nullArr, 5, printT<int>);
	iter(intArr, 5, (void (*)(int))NULL);

	const char *charArr[] = {"John", "Ken", "Alice"}; 
	len = sizeof(charArr) / sizeof(charArr[0]);
	iter(charArr, len, printT<const char*>);
	std::cout << "\n";
	
	void *pointerArr[] = {(void*)1, (void*)2, (void*)3};
	iter(pointerArr, sizeof(pointerArr) / sizeof(pointerArr[0]), printT<void*>);
	std::cout << "\n";	
	return 0;
}

/*test
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
*/