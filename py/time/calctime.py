#!/usr/bin/python3


from datetime import timedelta as dt

def str2dt(st):
    (hr,mn) = st.split(':')
    return dt(hours=int(hr),minutes=int(mn))

def time_init(tt):#tin='8:45',tout='17:30'
    (tin,tout) = tt
    timeofcount = dict()
    timeofcount['t_in'] = tin
    timeofcount['t_out'] = tout
    timeofcount['worktime'] = str2dt(tout) - str2dt(tin)
    return timeofcount

## here read and pars time-file
#import xml fd = open('table2.xml','r') for s in fd: print(s)

##fill local structures with data from the file
data = (('9:15','18:20')
        ,('10:55','21:00')
        ,('9:20','18:15')
        ,('10:30','20:55')
        ,('9:15','19:05')
        #,('9:15's,'19:20') ,('9:15','19:20')
        )

#fun = lambda x_list: dt()

daysofweek = ('monday','tuesday','wednsday','thursday','friday','saterday','sunday')


week = {k:time_init(tio) for k,tio in zip(daysofweek,data)}

for kv in week.items():
    print(kv[0],kv[1]['t_in'],kv[1]['t_out'],kv[1]['worktime'],sep=' \t')



