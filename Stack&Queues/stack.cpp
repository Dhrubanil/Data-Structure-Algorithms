#include<bits/stdc++.h>
using namespace std;
template <typename T>

class stackUsingArray{
    private:
        T *data;
        int size;
        int nextIndex;
    public:
        stackUsingArray(){
            size=1;
            nextIndex=0;
            data=new T[size];
        }
        int Size(){
            return this->nextIndex;
        }
        void push(T element){
            if(nextIndex==this->size){
                T* newData=new T(this->size*2);
                for(int i=0;i<this->nextIndex;i++){
                    newData[i]=this->data[i];
                }
                delete []data;
                this->data=newData;
            }
            this->data[this->nextIndex]=element;
            this->nextIndex++;
        }
        T pop(){
            if(nextIndex==0){
                cout<<"no data for pop"<<endl;
                return 0;
            }else{
                nextIndex--;
                return data[nextIndex];
            }
        }
        T top(){
                cout<<"stack is empty"<<nextIndex<<data[nextIndex-1]<<endl;
            if(nextIndex==0){
                return 0;
            }else{
                return data[nextIndex-1];
            }
        }
};

int main(){
    stackUsingArray <int>s;
    s.push(4);
    s.push(6);
    s.push(8);
    cout<<s.pop()<<endl;
    cout<<s.Size()<<endl;
    cout<<s.top()<<endl;
}