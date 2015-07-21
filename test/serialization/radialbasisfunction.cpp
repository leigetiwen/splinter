/*
 * This file is part of the SPLINTER library.
 * Copyright (C) 2012 Bjarne Grimstad (bjarne.grimstad@gmail.com).
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <Catch.h>
#include <datatable.h>
#include <radialbasisfunction.h>
#include "testingutilities.h"

using namespace SPLINTER;


TEST_CASE("RadialBasisFunction can be saved and loaded", "[serialization][rbf][radialbasisfunction]")
{
    unsigned int dim = 2;
    auto func = getTestFunction(dim, 1);
    // Don't sample too fine, this test isn't supposed to test the speed
    auto points = linspace(dim, std::pow(300, 1.0/dim));
    DataTable table = sample(func, points);

    const char *fileName = "test.rbf";

    SECTION("Gaussian") {
        RadialBasisFunction rbf(table, RadialBasisFunctionType::GAUSSIAN);

        rbf.save(fileName);
        RadialBasisFunction loadedRBF(fileName);

        REQUIRE(rbf == loadedRBF);
    }

    SECTION("Inverse multiquadric") {
        RadialBasisFunction rbf(table, RadialBasisFunctionType::INVERSE_MULTIQUADRIC);

        rbf.save(fileName);
        RadialBasisFunction loadedRBF(fileName);

        REQUIRE(rbf == loadedRBF);
    }

    SECTION("Inverse quadric") {
        RadialBasisFunction rbf(table, RadialBasisFunctionType::INVERSE_QUADRIC);

        rbf.save(fileName);
        RadialBasisFunction loadedRBF(fileName);

        REQUIRE(rbf == loadedRBF);
    }

    SECTION("Multiquadric") {
        RadialBasisFunction rbf(table, RadialBasisFunctionType::MULTIQUADRIC);

        rbf.save(fileName);
        RadialBasisFunction loadedRBF(fileName);

        REQUIRE(rbf == loadedRBF);
    }

    SECTION("Thin plate spline") {
        RadialBasisFunction rbf(table, RadialBasisFunctionType::THIN_PLATE_SPLINE);

        rbf.save(fileName);
        RadialBasisFunction loadedRBF(fileName);

        REQUIRE(rbf == loadedRBF);
    }

    remove(fileName);
}
