import math
def sort_list(list1, list2): 
  
    zipped_pairs = zip(list2, list1) 
  
    z = [x for _, x in sorted(zipped_pairs)] 
      
    return z

curSum=0
i=0
j=0
t1=[0]
y1=[0]
s,x,n=map(int,input().split())

for i in range(0,n):
    
    t,y=list(map(int,input().split()))   
    t1.append(t)
    y1.append(y)

y1 = sort_list(y1,t1)
t1 = sorted(t1)

daysRequired = 0
curSum = 0

for i in range(1,len(t1)):

    if curSum >=s:
        break


    prevWindow = t1[i] - t1[i-1] -1
    if curSum + prevWindow*x <= s:
        curSum += prevWindow*x
        daysRequired += prevWindow

        if curSum == s:
            break
        else:
            curSum += y1[i]
            daysRequired +=1
            
    else:
        adjustedWindow = math.ceil((s - curSum)/x)
        daysRequired += adjustedWindow
        curSum += adjustedWindow*x
        break

if curSum < s:
    adjustedWindow = math.ceil((s - curSum)/x)
    daysRequired += adjustedWindow
    curSum += adjustedWindow*x

print(daysRequired)