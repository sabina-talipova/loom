// Copyright 2016, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Authors: Patrick Brosi <brosi@informatik.uni-freiburg.de>

#ifndef SHARED_OPTIM_ILPSOLVPROV_H_
#define SHARED_OPTIM_ILPSOLVPROV_H_

#include "shared/optim/GLPKSolver.h"
#include "shared/optim/COINSolver.h"
#include "shared/optim/GurobiSolver.h"
#include "shared/optim/ILPSolver.h"

namespace shared {
namespace optim {

inline ILPSolver* getSolver(const std::string& wish,
                            shared::optim::DirType dir) {
  ILPSolver* lp = 0;

  // first try to consider wish

#ifdef GUROBI_FOUND
  if (wish == "gurobi") lp = new shared::optim::GurobiSolver(dir);
#endif

#if COIN_FOUND
  if (wish == "coin") lp = new shared::optim::COINSolver(dir);
#endif

#if GLPK_FOUND
  if (wish == "glpk") lp = new shared::optim::GLPKSolver(dir);
#endif

  // fallbacks

#ifdef GUROBI_FOUND
  if (!lp) lp = new shared::optim::GurobiSolver(dir);
#endif

#ifdef COIN_FOUND
  if (!lp) lp = new shared::optim::COINSolver(dir);
#endif

#if GLPK_FOUND
  if (!lp) lp = new shared::optim::GLPKSolver(dir);
#endif

  return lp;
}

}  // namespace optim
}  // namespace shared

#endif
