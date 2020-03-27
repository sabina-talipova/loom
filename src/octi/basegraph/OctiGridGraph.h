// Copyright 2017, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Authors: Patrick Brosi <brosi@informatik.uni-freiburg.de>

#ifndef OCTI_BASEGRAPH_OCTIGRIDGRAPH_H_
#define OCTI_BASEGRAPH_OCTIGRIDGRAPH_H_

#include "octi/basegraph/GridGraph.h"

namespace octi {
namespace basegraph {

class OctiGridGraph : public GridGraph {
 public:
  using GridGraph::getNeighbor;
  OctiGridGraph(const util::geo::DBox& bbox, double cellSize, double spacer,
                const Penalties& pens)
      : GridGraph(bbox, cellSize, spacer, pens) {}

  virtual void unSettleEdg(GridNode* a, GridNode* b);
  virtual void settleEdg(GridNode* a, GridNode* b, CombEdge* e);
  virtual CrossEdgPairs getCrossEdgPairs() const;
  virtual GridEdge* getNEdg(const GridNode* a, const GridNode* b) const;
  virtual size_t getNumNeighbors() const;

 protected:
  virtual void writeInitialCosts();
  virtual GridNode* writeNd(size_t x, size_t y);
  virtual GridNode* getNeighbor(size_t cx, size_t cy, size_t i) const;
  virtual GridNode* getNode(size_t x, size_t y) const;
};
}  // namespace basegraph
}  // namespace octi

#endif  // OCTI_BASEGRAPH_OCTIGRIDGRAPH_H_