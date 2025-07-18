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
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <complex>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/NdArray/NdArrayBroadcast.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Element-wise maximum of array elements.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.maximum.html
    ///
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> maximum(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        const auto comparitor = [](const dtype& lhs, const dtype& rhs) noexcept -> bool { return lhs < rhs; };
        return broadcast::broadcaster<dtype>(inArray1,
                                             inArray2,
                                             [&comparitor](const dtype& value1, const dtype& value2)
                                             { return std::max(value1, value2, comparitor); });
    }

    //============================================================================
    // Method Description:
    /// Element-wise maximum of array elements.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.maximum.html
    ///
    ///
    /// @param inArray
    /// @param inScalar
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> maximum(const NdArray<dtype>& inArray, const dtype& inScalar)
    {
        const NdArray<dtype> inArray2 = { inScalar };
        return maximum(inArray, inArray2);
    }

    //============================================================================
    // Method Description:
    /// Element-wise maximum of array elements.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.maximum.html
    ///
    ///
    /// @param inScalar
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> maximum(const dtype& inScalar, const NdArray<dtype>& inArray)
    {
        return maximum(inArray, inScalar);
    }
} // namespace nc
