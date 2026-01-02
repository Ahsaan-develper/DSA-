#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std ;
class Graph{
    private:
        int V ;
        list<int> *l ;
    public:
        Graph(int V){
          
            this->V = V;
            l = new list<int> [V];
        }
        void addEdeg (int u , int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void print (){
            if (l->size() == 0){
                cout <<"The graph is empty "<<endl;
                return;
            }
            for (int i=0 ; i<V ; i++){
                cout <<i<<" :";
                for ( int neighbor: l[i]){
                    cout<<neighbor<<" ";
            }
            cout <<endl;
            }
        }

        void BFS (){
            queue<int> q;
            vector<bool> visit(V , false);
            q.push(0);
            visit[0] =true;
            while (q.size() > 0)
            {
                int u = q.front();
                q.pop();
                cout << u<<" ";
                for ( int v : l[u]){
                    if (!visit[v]){
                        visit[v] = true;
                        q.push(v);
                    }
                }
            }
            
        }
};
int main(){
    Graph g (5);
    g.addEdeg(0,1);
    g.addEdeg(1,2);
    g.addEdeg(1,3);
    g.addEdeg(2,4);
    // g.print();
    g.BFS();
    return 0;
}