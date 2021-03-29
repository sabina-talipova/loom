// Copyright 2016, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Authors: Patrick Brosi <brosi@informatik.uni-freiburg.de>

#ifndef OCTI_CONFIG_OCTICONFIG_H_
#define OCTI_CONFIG_OCTICONFIG_H_

#include <string>
#include "octi/basegraph/GridGraph.h"
#include "octi/basegraph/BaseGraph.h"
#include "util/geo/Geo.h"

namespace octi {
namespace config {

struct Config {
  std::string gridSize;
  double borderRad;

  std::string printMode;
  std::string optMode;
  std::string ilpPath;
  bool fromDot;
  bool deg2Heur;
  bool restrLocSearch;
  double enfGeoPen;
  bool ilpNoSolve;
  int ilpTimeLimit;
  std::string ilpSolver;
  std::string ilpCacheDir;

  double maxGrDist;

  size_t abortAfter;

  size_t hananIters;
  bool writeStats;

  std::string obstaclePath;
  std::vector<util::geo::DPolygon> obstacles;

  octi::basegraph::BaseGraphType baseGraphType;

  octi::basegraph::Penalties pens;
};

}  // namespace config
}  // namespace octi

#endif  // OCTI_CONFIG_OCTICONFIG_H_
