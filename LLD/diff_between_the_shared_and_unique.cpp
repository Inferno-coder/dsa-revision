#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
        void drive(){
            cout<<"driving car"<<endl;
        }
};

class Engine{
    public:
    int power=100;
    void start(){
        cout<<"car starts "<<power<<endl;
    }
};

int main(){
  unique_ptr<Engine>e1=make_unique<Engine>();
  unique_ptr<Engine>e2=move(e1);
  e2->start();
  shared_ptr<Engine>e3=make_shared<Engine>();
  shared_ptr<Engine>e4=e3;
  e3->start();
  e4->start();
 return 0;
} 
