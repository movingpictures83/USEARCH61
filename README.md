# USEARCH61
# Language: C++
# Input: TXT
# Output: DIR
# Tested with: PluMA 1.0, GCC 4.8.4
# Dependencies: USEARCH 6.1

PluMA plugin that removes chimeras with USEARCH (Edgar et al, 2010)

The plugin takes as input a TXT file of keyword-value pairs

fastafile: input FASTA
database: Database for queries
wordlength: number of bases per word

Denoised sequences will be sent to the user-specified output directory
