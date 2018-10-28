#!/usr/bin/env python
# -*- coding: utf-8 -*-
class Task:
    def rotate(self,matrix):
	#********* Begin *********#
        mat_size = len(matrix)
        for row in range(mat_size // 2):
            for col in range(mat_size):
                matrix[row][col], matrix[mat_size-1-row][col] =\
                matrix[mat_size-1-row][col], matrix[row][col]
	    for row in range(mat_size):
            for col in range(row, mat_size):
                matrix[row][col], matrix[col][row] = matrix[col][row], matrix[row][col]
	#********* End *********#
