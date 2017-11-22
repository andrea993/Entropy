# Entropy
File stats utility

## Overview
This tool anlyze binary file to find:
- Mean
- Variance
- Standard deviation
- Shannon entropy
- Gaussianity (from 0 to 100%)
- Uniformity (from 0 to 100%)

The purpose of the tool is to discover if a file is randomic, compressed, compressibile and to estimate the amount of included information.

This tool can be usefull in reverse engineering, data analysis and information theory.

## How to read output?
Entropy says how many bit/sample can be use at least to describe the file, so if it's near 8bit/sample the file is not compressibile and can be a randomic noise or a compressed file.

Gaussianity and Uniform estimate how much the data follow these distributions, in a compressed file it's probable that Uniformity is near 100%. In a gaussian randomic file Gaussianity will be about 100%


## Install
make

sudo make install

## Usage
entropy [filename]

