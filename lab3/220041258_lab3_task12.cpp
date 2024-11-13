#include <iostream>
#include <vector>
#include <queue>


using namespace std;




int main()
{

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int temp, Cost=0;


    while(cin>> temp &&  temp != -1)
    {
        minHeap.push(temp);
    }

    while(minHeap.size()> 1)
    {
        int temp1 = minHeap.top();
        minHeap.pop();
        int temp2 =minHeap.top();
        minHeap.pop();
        Cost += (temp1 + temp2) ;
        minHeap.push(temp1 + temp2);

    }

    cout<< Cost<< endl;



    return 0;
}
