/// @file
/// @author David Pilger <dpilger26@gmail.com>
/// [GitHub Repository](https://github.com/dpilger26/NumCpp)
///
/// License
/// Copyright 2018-2025 David Pilger
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this
/// software and associated documentation files(the "Software"), to deal in the Software
/// without restriction, including without limitation the rights to use, copy, modify,
/// merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
/// permit persons to whom the Software is furnished to do so, subject to the following
/// conditions :
///
/// The above copyright notice and this permission notice shall be included in all copies
/// or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
/// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
/// PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
/// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
/// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
/// Description
/// Special Functions
///
#pragma once

#include <cmath>

#if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

#ifndef __cpp_lib_math_special_functions
#include "boost/math/special_functions/hermite.hpp"
#endif

namespace nc::polynomial
{
    //============================================================================
    // Method Description:
    /// Hermite Polynomial
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param n: the order of the hermite polynomial
    /// @param x: the input value
    /// @return double
    ///
    template<typename dtype>
    double hermite(uint32 n, dtype x)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

#ifdef __cpp_lib_math_special_functions
        return std::hermite(n, static_cast<double>(x));
#else
        return boost::math::hermite(n, static_cast<double>(x));
#endif
    }

    //============================================================================
    // Method Description:
    /// Hermite Polynomial.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param n: the order of the hermite polynomial
    /// @param inArrayX: the input value
    /// @return NdArray<double>
    ///
    template<typename dtype>
    NdArray<double> hermite(uint32 n, const NdArray<dtype>& inArrayX)
    {
        NdArray<double> returnArray(inArrayX.shape());

        const auto function = [n](dtype x) -> double { return hermite(n, x); };

        stl_algorithms::transform(inArrayX.cbegin(), inArrayX.cend(), returnArray.begin(), function);

        return returnArray;
    }
} // namespace nc::polynomial

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
