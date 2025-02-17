#
# Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
# SPDX-License-Identifier: MIT
#
# Author: Mark Rollins

DO_COSIM        := true
ECHO            := @echo

PLATFORM_USE    := xilinx_vck190_base_202320_1
XPFM            := ${PLATFORM_REPO_PATHS}/${PLATFORM_USE}/${PLATFORM_USE}.xpfm

KERNEL          := pfa1008_permute_o_wrapper
KERNEL_SRC      := pfa1008_permute_o.cpp
XO              := ${KERNEL}.xo
HLS_FREQ        := 312500000

.PHONY: clean all help

help::
	$(ECHO) "Makefile Usage:"
	$(ECHO) "  make all"
	$(ECHO) "      Command to generate the kernel used in this design"
	$(ECHO) ""
	$(ECHO) "  make clean"
	$(ECHO) "      Command to remove all the generated files."

all: ${XO}

${XO}: ${KERNEL_SRC} ${XPFM}
ifeq (${DO_COSIM},true)
	v++ --compile --debug --save-temps \
		--platform ${XPFM} \
		--hls.clock ${HLS_FREQ}:${KERNEL} \
		--hls.pre_tcl run_presyn.tcl \
		--hls.post_tcl run_postsyn.tcl \
		--kernel   ${KERNEL} \
		--output   ${XO} \
		${KERNEL_SRC}
	@cat _x/${KERNEL}/${KERNEL}/${KERNEL}/solution/impl/report/verilog/${KERNEL}_export.rpt
else
	v++ --compile --debug --save-temps \
		--platform ${XPFM} \
		--hls.clock ${HLS_FREQ}:${KERNEL} \
		--hls.pre_tcl run_presyn.tcl \
		--kernel   ${KERNEL} \
		--output   ${XO} \
		${KERNEL_SRC}
endif

clean:
	rm -f $(XO)* *.log
	rm -rf .Xil _x/ .crashReporter*
