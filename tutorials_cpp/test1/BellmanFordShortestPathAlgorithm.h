/*
    Author      :       Sreejith Sreekantan
    Description :       BellmanFordShortestPathAlgorithm
*/

#ifndef __BELLMANFORDSHORTESTPATHALGORITHM_H__
#define __BELLMANFORDSHORTESTPATHALGORITHM_H__

#include <vector>
#include <memory>
#include <limits>
#include "EdgeWeightedDigraph.h"

namespace graph
{

class BellmanFordShortestPathAlgorithm
{
public:
    BellmanFordShortestPathAlgorithm(std::shared_ptr<EdgeWeightedDigraph> edgeWeightedDigraphPtr, int src);
    double weight(int x);
    const std::vector<double> &weight();
    int parent(int x);
    const std::vector<int> parent();
private:
    std::shared_ptr<EdgeWeightedDigraph> edgeWeightedDigraphPtr_;
    int src_;
    int v_;
    std::vector<int> parent_;
    std::vector<double> weight_;
    double weight(int from, int to);
    void relax(int x);
};
BellmanFordShortestPathAlgorithm::BellmanFordShortestPathAlgorithm(std::shared_ptr<EdgeWeightedDigraph> edgeWeightedDigraphPtr, int src):
edgeWeightedDigraphPtr_(edgeWeightedDigraphPtr), src_(src), v_(edgeWeightedDigraphPtr_->V()), parent_(v_, -1), weight_(v_, std::numeric_limits<double>::max())
{
	weight_[src_] = 0;
	for (int i = 0; i < v_; ++i)
	{
		for (int j = 0; j < v_; ++j)
		{
			relax(j);
		}
	}
}
double BellmanFordShortestPathAlgorithm::weight(int x)
{
	return weight_[x];
}
const std::vector<double> &BellmanFordShortestPathAlgorithm::weight()
{
	return weight_;
}
int BellmanFordShortestPathAlgorithm::parent(int x)
{
	return parent_[x];
}
const std::vector<int> BellmanFordShortestPathAlgorithm::parent()
{
	return parent_;
}
double BellmanFordShortestPathAlgorithm::weight(int from, int to)
{
	for (std::shared_ptr<const Edge> edgePtr : edgeWeightedDigraphPtr_->edgesOf(from))
	{
		if (edgePtr->from()==from && edgePtr->to()==to)
		{
			return edgePtr->weight();
		}
	}
	return std::numeric_limits<double>::max();
}

void BellmanFordShortestPathAlgorithm::relax(int x)
{
	for (std::shared_ptr<const Edge> edgePtr : edgeWeightedDigraphPtr_->edgesOf(x))
	{
		int to = edgePtr->to();
		if (weight_[to] > weight_[x] + weight(x, to))
		{
			weight_[to] = weight_[x] + weight(x, to);
			parent_[to] = x;
		}
	}
}	

} // namespace graph

#endif // __BELLMANFORDSHORTESTPATHALGORITHM_H__