rafat = "Rafat"
def f1() :
    global rafat 
    rafat = "RAFAT"
    if len(rafat) == 6 :
        return False
print(rafat)
num = f1()
print(rafat, num)
