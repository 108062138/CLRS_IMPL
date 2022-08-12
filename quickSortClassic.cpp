#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class quickSortClassic{
private:
    /* data */
    vector<int> A;
    int randLimit;
    int offset;
public:
    int sz;
    int RAND(int min,int max){
        int range = max - min + 1;
        int num = rand() % range + min;
        return num;
    }
    int RANDPARTITION(int p,int r){
        int someWhere = RAND(p,r);
        swap(A[someWhere],A[r]);
        int x = A[r];//the pivot
        int i = p-1;
        for(int j = p;j<=r-1;j++){
            if(A[j]<=x){
                i++;
                swap(A[i],A[j]);
            }
        }
        swap(A[i+1],A[r]);

        return i+1;
    }
    int PARTITION(int p,int r){
        int x = A[r];//the pivot
        int i = p-1;
        for(int j = p;j<=r-1;j++){
            if(A[j]<=x){
                i++;
                swap(A[i],A[j]);
            }
        }
        swap(A[i+1],A[r]);

        return i+1;
    }
    void QSORT(/*param A is omited in the class*/int p, int r){
        if(p<r){
            int q = PARTITION(p,r);
            QSORT(p,q-1);
            QSORT(q+1,r);
        }
    }
    bool cmp(){
        vector<int> cpA = A;
        sort(cpA.begin(),cpA.end());
        for(int i=0;i<A.size();i++)
            if(cpA[i]!=A[i]) return false;
        return true;
    }
    void display(){
        for(auto x:A)cout<<x<<" ";
        cout << endl;
    }
    quickSortClassic(int n){
        randLimit = n*n+1;
        offset = 7;
        for(int i=0;i<n*offset;i++)
            A.push_back(rand()%randLimit);
        sz = A.size();
    }
    ~quickSortClassic(){
        A.clear();
    }
};

int main(){
    int n;
    cin >> n;
    quickSortClassic QSC(n);
    QSC.display();
    QSC.QSORT(0,QSC.sz-1);
    QSC.display();
    if(QSC.cmp()) cout << "ok" <<endl;
    else cout<< "fail..." <<endl;
}