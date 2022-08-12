#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<array>
using namespace std;

class heapSort
{
private:
    /* data */
    vector<int> myA;
    int head;
    int offset;
    int heapSize;
public:
    int LEFT(int i){return 2*i;}
    int RIGHT(int i){return 2*i+1;}
    int PARENT(int i){return i/2;}
    void heapIncreaseKey(int i,int key){
        if(key<myA[i]) return;
        myA[i] = key;
        while (i>1 &&myA[PARENT(i)]<myA[i]){
            swap(myA[i],myA[PARENT(i)]);
            i = PARENT(i);
        }
    }
    int heapExtractMax(){
        int res = myA[1];
        myA[1] = myA[heapSize];
        heapSize--;
        maxHeapify(/*myA*/1);
        return res;
    }
    int heapMaximum(){
        if(heapSize==0)return -1;
        else return myA[1];//heap starts from 1 to ease the coding process
    }
    void maxHeapify(/*vector<int>&vec,*/int i){
        int left = LEFT(i);
        int right = RIGHT(i);
        int largest;
        if(left<=heapSize && myA[left]>myA[i])
            largest = left;
        else largest = i;
        if(right<=heapSize&& myA[right]>myA[largest])
            largest = right;
        
        if(largest!=i){
            swap(myA[i],myA[largest]);
            maxHeapify(/*myA*/largest);
        }
    }
    void buildMaxHeap(vector<int> &A){
        myA.clear();
        myA.push_back(head);
        for(auto x:A)myA.push_back(x);
        heapSize = A.size();
        for(int i=heapSize/2;i>=1;i--)
            maxHeapify(i);
    }
    bool cmp(vector<int>& targetVec){
        sort(targetVec.begin(),targetVec.end(),greater<int>());
        for(int i=0;i<targetVec.size();i++)
            if(targetVec[i]!=heapExtractMax())
                return false;

        return true;
    }
    heapSort(int n):head(777),offset(777){
        vector<int> A;
        for(int i=0;i<n*n+offset;i++)
            A.push_back(rand()%offset);
        buildMaxHeap(A);
        if(cmp(A)) cout<<"save heap"<<endl;
        else cout<<"fuck up"<<endl;
    }
    ~heapSort(){
        myA.clear();
        heapSize = 0;
    };
};

int main(){
    int n;
    cin >> n;
    heapSort  HSC(n);
    vector<int> tmp(1111,0);
    for(auto& x:tmp)
        x = rand()%1024;
    HSC.buildMaxHeap(tmp);
    if(HSC.cmp(tmp))cout<<"save heap"<<endl;
    else cout<<"fuck up"<<endl;
}