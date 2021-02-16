def meet(x1, x2, v1, v2):  
    if (x1 < x2 and v1 <= v2): 
        return False 
    if (x1 > x2 and v1 >= v2): 
        return False  
    
    if (x1 < x2): 
        x1 = x2
        x2 = x1
        v1 = v2
        v2 = v1
    while (x1 >= x2):    
        if (x1 == x2):  
            return True 
        
        x1 = x1 + v1   
        x2 = x2 + v2  
        
    return False  
   
x1 = 6
v1 = 6 
x2 = 4 
v2 = 8 
if (meet(x1, x2,v1, v2)): 
    print("Yes") 
else: 
    print("No") 
