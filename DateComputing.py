#!/usr/bin/env python
# -*- coding: utf-8 -*-
class Task:
    days = {1: 31, 2: 28, 3: 31, 4: 30, \
            5: 31, 6: 30, 7: 31, 8: 31, \
            9: 30, 10: 31, 11: 30, 12: 31}
    def getDate(self,releaseDate,day):
	#********* Begin *********#
        ty = y = int(releaseDate[0:4])
        tm = int(releaseDate[5:7])
        td = int(releaseDate[8:10])

        if m <= 2:
            start = y
        else:
            start = y + 1

        ty = start
        while day - 365 - self.leapOffset(ty) >= 0:
            day -= 365 + self.leapOffset(ty)
            ty += 1
            
        self.days[2] += self.leapOffset(ty)
        while day - self.days[tm] >= 0:
            day -= self.days[tm]
            ty += tm // 12
            tm = (tm % 12) + 1

        if td + day > self.days[tm]:
        	tm += 1
        	td = td + day - self.days[tm-1]
		else:
            td = td + day
            
        if start == y + 1:
            ty -= 1
        ty = str(ty)
        tm = str(tm) if tm >= 10 else '0'+str(tm)
        td = str(td) if td >= 10 else '0'+str(td)
        return ty+'-'+tm+'-'+td
	#********* End *********#
    def leapOffset(self,year):
        if year % 4 == 0 and year % 100 != 0:
            return 1
        if year % 400 == 0:
            return 1
        return 0
