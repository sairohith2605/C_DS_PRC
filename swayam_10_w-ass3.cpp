#include<iostream>
#include<cstdlib>
using namespace std;

struct eArray
{
public:
  int *arr;
  int capacity;
public:
    eArray ()
  {
    arr = NULL;
    capacity = 0;
  }				// construct an array with 0 elements
  int &operator[] (int i)
  {
    return arr[i];
  }
  // return a reference to the ith element of the array
  void push_back (int v)
  {
    int *temp = new int[capacity + 1];
    capacity++;
    int i;
    for (i = 0; i < capacity - 1; i++)
      {
	temp[i] = arr[i];
      }
    temp[i] = v;
    delete[]arr;
    arr = new int[capacity];
    for (i = 0; i < capacity; i++)
      {
	arr[i] = temp[i];
      }
    delete[]temp;
  }
  // Append v to the current array
  // Use a simple implementation: allocate a new array to
  // accommodate the extra element v.  Then copy the current
  // array into it.  Copy v, and delete the current array.
  int size () const
  {
    return capacity;
  }
  // return the current size of the array
  // "const" says this function will not change the receiver
  eArray (const eArray & rhs)
  {
    delete[]arr;
    arr = new int[rhs.size ()];
    int i;
    for (i = 0; i < rhs.size (); i++)
      {
	arr[i] = rhs.arr[i];
      }
    capacity = rhs.size ();

  }
  // copy constructor
  ~eArray ()
  {
    delete arr;
  }
  // destructor
  eArray & operator= (const eArray & rhs)
  {
    if (this == &rhs)
      return *this;
    delete arr;
    arr = new int[rhs.size ()];
    int i;
    for (i = 0; i < rhs.size (); i++)
      {
	arr[i] = rhs.arr[i];
      }
    capacity = rhs.size ();
    return *this;
  }
  // assignment operator
};

void
f (eArray A)
{
  A[5] = 5000;
}				// changes only local copy

void
g (eArray & A)
{
  A[6] = 6000;
}				// changes original

int
main ()
{
  eArray A, B;
  for (int i = 0; i < 10; i++)
    {
      int v;
      cin >> v;
      A.push_back (v);
    }
  f (A);
  g (A);
  B = A;
  B[8] = 800;
  A[8] = 8000;
  for (int i = 0; i < B.size (); i++)
    cout << B[i] << ' ';
  cout << endl;
}

