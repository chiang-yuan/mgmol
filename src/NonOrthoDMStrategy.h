// Copyright (c) 2017, Lawrence Livermore National Security, LLC and
// UT-Battelle, LLC.
// Produced at the Lawrence Livermore National Laboratory and the Oak Ridge
// National Laboratory.
// LLNL-CODE-743438
// All rights reserved.
// This file is part of MGmol. For details, see https://github.com/llnl/mgmol.
// Please also read this link https://github.com/llnl/mgmol/LICENSE

#ifndef MGMOL_NONORTHODMSTRATEGY_H
#define MGMOL_NONORTHODMSTRATEGY_H

#include "DMStrategy.h"
#include "ProjectedMatricesInterface.h"

template <class OrbitalsType>
class NonOrthoDMStrategy : public DMStrategy<OrbitalsType>
{
private:
    ProjectedMatricesInterface* proj_matrices_;
    const double mix_;

public:
    NonOrthoDMStrategy(
        ProjectedMatricesInterface* proj_matrices, const double mix);

    void initialize(OrbitalsType& orbitals) override;
    int update(OrbitalsType& orbitals) override;

    bool needH() const override { return true; }

    void stripDM() override;

    void dressDM() override;

    void reset() override { proj_matrices_->resetDM(); }
};

#endif
