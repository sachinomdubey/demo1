#include <iostream>

using namespace std;
template<class T>
class Array {
private:
    T *A;
    int size;
    int length;
public:
    Array()
    {
        size = 10;
        A = new T[10];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        A = new T[size];
        length = 0;
    }
    ~Array()
    {
        delete []A;
    }
    void Display();
    void Insert(int index, T x);
    T Delete(int index);
};

template<class T>
void Array<T>::Display()
{
    for (int i=0; i<length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

template<class T>
void Array<T>::Insert(int index,T x)
{
    if (index>=0 && index<=length)
    {
        for(int i=length;i>=index;i--)
        {
            A[i]=A[i-1];
        }
        A[index]=x;
        length++;
    }
}
template<class T>
T Array<T>::Delete(int index)
{
    if (index>=0 && index<=length)
    {
        T x = A[index];
        for (int i=index; i<length-1; i++)
        {
            A[i]=A[i+1];
        }
        length--;
        return x;
    }
}

int main()
{
    Array<char> arr(10);
    arr.Insert(0,'a');
    arr.Insert(1,'c');
    arr.Insert(2,'d');
    arr.Display();
    cout << arr.Delete(0) << endl;
    arr.Display();
    return 0;
}
