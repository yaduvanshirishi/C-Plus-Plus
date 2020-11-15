#include <iostream>
#include <queue>
using namespace std;
 
template <typename T> 
void showPQ(priority_queue<T,vector<T>, greater<T>> pq)
{
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<"\n";
}
 
int main() {
 
	//For Integer heap just change char to int in priority queue definition
	//and change data char to int, same for float
	priority_queue<char, vector<char>, greater<char>> pq;
	int n; cin>>n;
	while(n--)
	{
		char data; cin>>data;
		pq.push(data);
	}
	showPQ(pq);
	return 0;
}

