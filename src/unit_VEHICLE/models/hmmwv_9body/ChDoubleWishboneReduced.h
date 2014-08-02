// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All right reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Radu Serban
// =============================================================================
//
// Base class for a double-A arm suspension modeled with distance constraints.
// The suspension subsystem is modeled with respect to a right-handed frame,
// with X pointing towards the rear, Y to the right, and Z up.
// By default, a right suspension is constructed.  This can be mirrored to
// obtain a left suspension.
//
// =============================================================================

#ifndef CH_DOUBLEWISHBONEREDUCED_H
#define CH_DOUBLEWISHBONEREDUCED_H


#include <string>

#include "core/ChShared.h"
#include "core/ChVector.h"
#include "physics/ChSystem.h"


namespace chrono {


class ChDoubleWishboneReduced : public ChShared
{
public:
  ChDoubleWishboneReduced(const std::string& name);
  virtual ~ChDoubleWishboneReduced() {};

  void Initialize(ChSharedBodyPtr   chassis,
                  const ChVector<>& location,
                  bool              left = false);

  virtual double getSpindleMass() const = 0;
  virtual double getUprightMass() const = 0;

  virtual const ChVector<>& getSpindleInertia() const = 0;
  virtual const ChVector<>& getUprightInertia() const = 0;

  virtual double getSpringCoefficient() const = 0;
  virtual double getDampingCoefficient() const = 0;
  virtual double getSpringRestLength() const = 0;

protected:
  enum PointId {
    SPINDLE,    // spindle location
    UPRIGHT,    // upright location
    UCA_F,      // upper control arm, chassis front
    UCA_B,      // upper control arm, chassis back
    UCA_U,      // upper control arm, upright
    LCA_F,      // lower control arm, chassis front
    LCA_B,      // lower control arm, chassis back
    LCA_U,      // lower control arm, upright
    SHOCK_C,    // shock, chassis
    SHOCK_U,    // shock, upright
    TIEROD_C,   // tierod, chassis
    TIEROD_U,   // tierod, upright
    NUM_POINTS
  };

  virtual const ChVector<> getLocation(PointId which) = 0;

  virtual void OnInitializeSpindle() {}
  virtual void OnInitializeUpright() {}

  std::string       m_name;

  ChVector<>        m_points[NUM_POINTS];

  ChSharedBodyPtr   m_spindle;
  ChSharedBodyPtr   m_upright;

  ChSharedPtr<ChLinkLockRevolute>   m_revolute;
  ChSharedPtr<ChLinkDistance>       m_distUCA_F;
  ChSharedPtr<ChLinkDistance>       m_distUCA_B;
  ChSharedPtr<ChLinkDistance>       m_distLCA_F;
  ChSharedPtr<ChLinkDistance>       m_distLCA_B;
  ChSharedPtr<ChLinkDistance>       m_distTierod;

  ChSharedPtr<ChLinkSpring>         m_shock;

  static const double in2m;

private:

};


} // end namespace chrono


#endif
