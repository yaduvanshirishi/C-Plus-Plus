#include<iostream>
#define N 20
using namespace std;
int main(){
  int primes[N],primeIndex,p,isPrime;
  primes[0]=2;
  primes[1]=3;
  primeIndex=2;
  for(p=5;p<=N;p=p+2){
    //Remove even numbers
    isPrime=1;
    for(int i=1;i<primeIndex;i++){
      if(p % primes[i]==0)
        isPrime=0;
        //break;
      }
      if(isPrime==1){
        primes[primeIndex]=p;
        ++primeIndex;
      }
  }
  for(int i=0;i<primeIndex;i++){
      cout<<primes[i]<<endl;
  }
  return 0;
}
