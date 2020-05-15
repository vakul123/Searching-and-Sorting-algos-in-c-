#include <bits/stdc++.h>

using namespace std;

class Student{
public:
long double a[1000];
int n;
int num;
int loc;
int l;
int h;
int m;
int x;
    void getData();
    void InsertionSort();
    void pA();
    void BubbleSort();
    void SelectionSort();
    void QuickSort(int l,int h);
    void MergeSort(int l,int h);
    int partition(int l,int h);
    void Merge(int l,int m,int h);
    int LinearSearch();
    int Binary_Search(int l,int h);
    void Find();
    void HeapSort();
    void Heapify(int i);
    void buildHeap();
}s;

void Student::getData()
{

    cout<< "Enter the number of students in the class : ";
    cin>>n;
 cout<< "Enter the Student Marks : ";
    for(int i=0;i<s.n;i++)
        cin>>a[i];

}
void Student::Find()
{
    cout<<"Enter the element you want to search: ";
        cin>>s.x;
}

void Student::pA()
{
cout<<"Sorted Marks of the students are: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<endl;
}
void Student:: InsertionSort(){
   for(int i=1;i<n;i++)
  {
    int j=i-1;
    while(a[j+1]<a[j] && j>=0)
    {
       swap(a[j],a[j+1]);
       j--;

    }
  }
s.pA();

}
void Student::BubbleSort()
{
    for(int i=0;i<n;i++)
    for(int j=n-i-1;j>=0;j--)
    if(a[j]<a[j-1])
    swap(a[j],a[j-1]);

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<endl;
    cout<<" Bubble sort is done "<<endl<<endl<<endl;

}
void Student::SelectionSort()
{
    int m;
    int index;
    for(int i=0;i<n;i++)
    {
        m=a[i];
        index=i;
        for(int j=i;j<n;j++)
        {
          if(m>a[j])
          {
              m=a[j];
              index=j;
          }
        }
       swap(a[index],a[i]);
    }
   s.pA();

}
int Student::partition(int l,int h)
{
    int pivot=a[h];
    int i=l-1;

    for(int j=l;j<h;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);

        }
    }
    swap(a[i+1],a[h]);
    return i+1;
}
void Student::QuickSort(int l,int h)
{
    int pi;
    if(l<h)
    {
       pi=partition(l,h);
       QuickSort(l,pi-1);
       QuickSort(pi+1,h);

    }
}
void Student::Merge(int l,int m,int h)
{
    int i=0;
    int j=m+1;
    int k=0;
    int temp[h-l+1];

    while(i<=m && j<=h)
    {
        if(a[i]<a[j])
            temp[k++]=s.a[i++];
        else
            temp[k++]=s.a[j++];
    }
    while(i<=m)
        temp[k++]=s.a[i++];
    while(j<=h)
        temp[k++]=s.a[j++];

    for(int i=l;i<=h;i++)
        a[i]=temp[i-l];

}
void Student::MergeSort(int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=l+(h-l)/2;
        MergeSort(l,mid);
        MergeSort(mid+1,h);
        Merge(l,mid,h);
    }

}
int Student::LinearSearch()
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
            return i+1;
    }
    return 0;
}
int Student::Binary_Search(int l,int h)
{

   if(l<=h)
    {
         int mid=l+(h-l)/2;

        if(a[mid]==x)
            return mid;
        else if(a[mid]>x)
          return Binary_Search(l,mid-1);
        else
           return Binary_Search(mid+1,h);

    }
    return 0;
}
void Student::Heapify( int i)  {
      int l=2*i+1;
      int r=2*i+2;
      int ll=i;
      if(l<n && a[l]>a[i])
      ll=l;
      if(r<n && a[r]>a[ll])
      ll=r;
      if(ll!=i)
      {
          swap(a[i],a[ll]);
          Heapify(ll);
      }
}

// Rearranges input array so that it becomes a max heap
void Student::buildHeap()  {
   for(int i=n-1/2;i>=0;--i)
   Heapify(i);

}
void mainPage(){
cout<<endl<<"Select sorting algo you want to perform :-"<<endl;
    int xx;
       cout<<"1. Insertion Sort"<<endl<<"2. Bubble Sort"<<endl<<"3. Selection Sort"<<endl
       <<"4. Quick Sort"<<endl<<"5. Merge Sort"<<endl<<"6. Linear Search"<<endl<<"7. Binary Search"<<endl
       <<"8. Heap Sort"<<endl<<"0. Exit"<<endl;
       cout<< "Enter your choice: ";
       cin>>xx;
switch(xx){
    case 1:
        cout<<endl<<"Insertion Sort is done:"<<endl;
        s.InsertionSort();
        break;
    case 2:
        cout<<endl<<"Bubble Sort is done:"<<endl;
        s.BubbleSort();
        break;
   case 3:
       cout<<endl<<"Selection Sort is done:"<<endl;
        s.SelectionSort();
        break;
    case 4:
        cout<<endl<<"Quick Sort is done:"<<endl;
        s.QuickSort(0,s.n-1);
        s.pA();
        break;
    case 5:
        cout<<endl<<"Merge Sort is done:"<<endl;
        s.MergeSort(0,s.n-1);
        s.pA();
        break;
    case 6:
        s.Find();
        cout<<"Linear Search result:"<<endl;
        s.loc=s.LinearSearch();
        if(s.loc)
            cout<<s.num<<" is found at index "<<s.loc<<endl;
        else
            cout<<s.num<<" is not found in the array"<<endl;
        break;
    case 7:
        cout<<endl<<"Note: Please ensure that the array is already sorted !"<<endl;
         s.Find();
        cout<<"Binary Search result:"<<endl;
        s.loc=s.Binary_Search(0,s.n-1);
        if(s.loc)
            cout<<s.x<<" is found at index "<<s.loc<<endl;
        else
            cout<<s.x<<" is not found in the array"<<endl;
        break;
    case 8:
        cout<<endl<<"Heap Sort is done:"<<endl;
        s.InsertionSort();
        break;

    default:
    s.pA();
    break;

    }
}

int main()
{
    cout << "Welcome to Sorting and Searching Machine"<<endl;
s.getData();
mainPage();
    return 0;
}
