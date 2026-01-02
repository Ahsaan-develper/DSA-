#include <iostream>
#include<list>
using namespace std ;
class Graph {
    private:
        list<int> *l ;
        int V ;
    public:
        Graph(int V){
            this->V = V;
            l= new list<int> [V];
        }
        void addEdge (int u ,int v ){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        void Print (){
            for (int i=0 ;i<V ;i++){
                cout <<i<<" :";
                for (int neighbor : l[i]){
                    cout <<neighbor<<" ";
                }
                cout <<endl;
            }
        }
};
int main(){
    Graph g(10);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2 );
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(4,6);
    g.addEdge(6,7);
    g.addEdge(4,8);
    g.addEdge(8,9);
 
    g.Print();
    return 0;
}