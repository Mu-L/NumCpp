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

#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a new array with the specified shape. If new shape
    /// is larger than old shape then array will be padded with zeros.
    /// If new shape is smaller than the old shape then the data will
    /// be discarded.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.resize.html
    ///
    /// @param inArray
    /// @param inNumRows
    /// @param inNumCols
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& resizeSlow(NdArray<dtype>& inArray, uint32 inNumRows, uint32 inNumCols)
    {
        inArray.resizeSlow(inNumRows, inNumCols);
        return inArray;
    }

    //============================================================================
    // Method Description:
    /// Return a new array with the specified shape. If new shape
    /// is larger than old shape then array will be padded with zeros.
    /// If new shape is smaller than the old shape then the data will
    /// be discarded.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.resize.html
    ///
    /// @param inArray
    /// @param inNewShape
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& resizeSlow(NdArray<dtype>& inArray, const Shape& inNewShape)
    {
        inArray.resizeSlow(inNewShape);
        return inArray;
    }
} // namespace nc
