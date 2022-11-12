#ifndef FDE20_BONUSPROJECT_3_KNN_HPP
#define FDE20_BONUSPROJECT_3_KNN_HPP
#include <array>
#include "Matrix.hpp"
#include <queue>
#include <limits>


//---------------------------------------------------------------------------
/// Find the top k neighbors for the node start. The directed graph is stored in
/// matrix m and you can use getNeighbors(node) to get all neighbors of a node.
/// A more detailed description is provided in Matrix.hpp.
/// The function should return the k nearest neighbors in sorted order as vector
/// of Matrix::Entry, where Entry->column is the neighbor node and Entry->weight
/// is the cost to reach the node from the start node.
std::vector<Matrix::Entry> getKNN(const Matrix &m, unsigned start, unsigned k) {

  using Entry = Matrix::Entry;
  std::vector<Entry> result;
  result.reserve(k);

  // ToDo implement your solution here
    unsigned int V=m.getRowCount();
    std::priority_queue<Entry,std::vector<Entry>,std::greater<Entry>> pq;
    //std::priority_queue<Entry,std::vector<Entry>,std::greater<Entry>> pq2;
    std::vector<double> dist(V,INF);
    pq.push(Entry(start, 0));
    dist[start]=0;

    while(!pq.empty()){
        int u=pq.top().column;

        if(u!=start&&result.size()<k){
            result.insert(result.end(),pq.top());
            //pq2.push(pq.top())
        }

        pq.pop();
        // std::cout<<"current u: "<<u<<std::endl;
        for(auto &x:m.getNeighbors(u)){
            int v=x.column;
            double_t weight=x.weight;
            //std::cout<<"node connect to:"<<v<<"with edge:"<<weight<<std::endl;
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                //std::cout<<"dist of :"<<v<<" is "<<dist[v]<<std::endl;
                pq.push(Entry(v, dist[v]));
            }

        }

    }


    return result;
}

//---------------------------------------------------------------------------

#endif // FDE20_BONUSPROJECT_3_KNN_HPP
