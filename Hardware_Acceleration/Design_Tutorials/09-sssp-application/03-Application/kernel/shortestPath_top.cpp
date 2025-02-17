/*
Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
SPDX-License-Identifier: X11
*/

#include "shortestPath_top.hpp"

#ifndef __SYNTHESIS__
#include <iostream>
#endif

extern "C" void shortestPath_top(ap_uint<32>* config,
                                 ap_uint<512>* offset,
                                 ap_uint<512>* column,
                                 ap_uint<512>* weight,

                                 ap_uint<512>* ddrQue512,
                                 ap_uint<32>* ddrQue,

                                 ap_uint<512>* result512,
                                 ap_uint<32>* result,
                                 ap_uint<512>* pred512,
                                 ap_uint<32>* pred,
                                 ap_uint<8>* info) {
// clang-format off
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 1 num_read_outstanding = \
    32 max_write_burst_length = 2 max_read_burst_length = 8 bundle = gmem0 port = config
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 1 num_read_outstanding = \
    32 max_write_burst_length = 2 max_read_burst_length = 8 bundle = gmem0 port = offset
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 1 num_read_outstanding = \
    32 max_write_burst_length = 2 max_read_burst_length = 32 bundle = gmem1 port = column
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 1 num_read_outstanding = \
    32 max_write_burst_length = 2 max_read_burst_length = 32 bundle = gmem2 port = weight
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 32 num_read_outstanding = \
    1 max_write_burst_length = 2 max_read_burst_length = 2 bundle = gmem3 port = ddrQue
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 32 num_read_outstanding = \
    1 max_write_burst_length = 2 max_read_burst_length = 2 bundle = gmem3 port = ddrQue512
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 32 num_read_outstanding = \
    32 max_write_burst_length = 64 max_read_burst_length = 2 bundle = gmem4 port = result512
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 32 num_read_outstanding = \
    32 max_write_burst_length = 64 max_read_burst_length = 2 bundle = gmem4 port = info
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 32 num_read_outstanding = \
    32 max_write_burst_length = 64 max_read_burst_length = 2 bundle = gmem4 port = result
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 32 num_read_outstanding = \
    1 max_write_burst_length = 64 max_read_burst_length = 2 bundle = gmem5 port = pred512
#pragma HLS INTERFACE m_axi offset = slave latency = 32 num_write_outstanding = 32 num_read_outstanding = \
    1 max_write_burst_length = 64 max_read_burst_length = 2 bundle = gmem5 port = pred

// clang-format on

#ifndef __SYNTHESIS__
    std::cout << "kernel call success" << std::endl;
#endif
    xf::graph::singleSourceShortestPath<32, MAXOUTDEGREE>(config, offset, column, weight, ddrQue512, ddrQue, result512,
                                                          result, pred512, pred, info);
#ifndef __SYNTHESIS__
    std::cout << "kernel call finish" << std::endl;
#endif
}
