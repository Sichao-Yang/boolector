#!/bin/bash

# Default values
ROOT=/home/sichaoy/GNN_DPV/yosys/boolector
BTORMC=${ROOT}/build/bin/btormc
EXTRACT=${ROOT}/examples/btormc/btor_dumper/extractbtor.py
OUT=data_out
INFILE=design_btor_single.btor

# Parse command line arguments
while getopts "b:o:i:" opt; do
    case $opt in
        b) BTORMC="$OPTARG" ;;
        o) OUT="$OPTARG" ;;
        i) INFILE="$OPTARG" ;;
        \?) echo "Invalid option -$OPTARG" >&2
            exit 1 ;;
    esac
done

# Create output directory
mkdir -p ${OUT}
rm -rf ${OUT}/*

# Run the loop
for i in {0..3}
do
    $BTORMC -npp -rw $i -d -v ${INFILE} > ${OUT}/out_rw${i}.log
    python $EXTRACT ${OUT}/out_rw${i}.log > ${OUT}/out_rw${i}.btor
done