#!/usr/bin/env python
# -*- coding: utf-8 -*-
class Task:
    def getNum(self,n):
		#********* Begin *********#
		return bin(n).count('1')
		#********* End *********#
