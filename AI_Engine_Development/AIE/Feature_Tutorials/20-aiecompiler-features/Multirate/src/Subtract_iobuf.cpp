// Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
// SPDX-License-Identifier: MIT

#include "kernels.h"

void Subtract_iobuf(adf::input_buffer<int32, adf::extents<adf::inherited_extent>> &__restrict in1, adf::input_buffer<int32, adf::extents<adf::inherited_extent>> &__restrict in2, adf::output_buffer<int32, adf::extents<adf::inherited_extent>> &__restrict out)
{
    int32 i;
    int32 FrameLengthOut = out.size();

    auto pi1 = aie::begin_vector<VECTOR_LENGTH>(in1);
    auto pi2 = aie::begin_vector<VECTOR_LENGTH>(in2);
    auto po1 = aie::begin_vector<VECTOR_LENGTH>(out);

    for (i = 0; i < FrameLengthOut/VECTOR_LENGTH ; i++)
	chess_prepare_for_pipelining
    {
        *po1++ = *pi1++ - *pi2++;
    }

}
