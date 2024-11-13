#include <iostream>

using namespace std;
#define ppi pair<int,char>

struct item {
    int value;
    int priority;
};

item pr[100];

int size = -1;
int peek()
{
    int highestPriority = INT_MIN;
    int ind = -1;
    for (int i = 0; i <= size; i++) {
        if (highestPriority == pr[i].priority && ind > -1&& pr[ind].value < pr[i].value) {
            highestPriority = pr[i].priority;
            ind = i;
        }
        else if (highestPriority < pr[i].priority) {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}
void enqueue(int value, int priority)
{
    size++;
    pr[size].value = value;
    pr[size].priority = priority;
}
void dequeue()
{
    int ind = peek();
    for (int i = ind; i < size; i++) {
        pr[i] = pr[i + 1];
    }
    size--;
}
#include <bits/stdc++.h>
//CUSTOM COMPARATOR for Heap
class Compare{
public:
//Override
bool operator()(pair<int,char>below, pair<int,char> above){
	if(below.first == above.first){
	//freq same
	return below.second > above.second; //lexicographically smaller is TOP
	}
	return below.first <= above.first; //less freq at TOP
}
};

string frequencySort(string s) {

unordered_map<char,int> mpp;
priority_queue<ppi,vector<ppi>,Compare> minH; // freq , character

for(char ch : s){
	mpp[ch]++;
}

for(auto m : mpp){
	minH.push({m.second, m.first}); // as freq is 1st , char is 2nd
}

string ans="";


while(minH.size()>0){

	int freq = minH.top().first;
	char ch = minH.top().second;
	for(int i=0; i<freq; i++){
	ans+=ch; // append as many times of freq
	}
	minH.pop(); //Heapify happens
}

return ans;

}
int main()
{
	char str[100];
	cin.get(str,100);

	cout<<frequencySort(str)<<"\n";

	return 0;
}

/*
1. Take the the frequency of each character into a map.

2 .Take a MIN Heap, store in FREQUENCY, CHAR

3. After all insertions, Topmost element is the less frequent character

4. We keep a CUSTOM COMPARATOR for LESS FREQ, WHEN SAME FREQ � Ascending Order Characters.

5. Then Pop one by one and append in ANS String for FREQ no. of times.
*/

