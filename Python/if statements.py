isHungry = True
fridgeHasFood = False

if isHungry:
    print("Gotta eat breakfast, les see what the fridge has")
    if fridgeHasFood:
        print("yes, les cook some real good breakfast")
    else:
        print("tch, les go to the store")
else:
    print("Nah Imma skip breakfast")

print("")
print("")
print("")

cheap = True
goodQuality = False

if cheap and goodQuality: # for || , use 'or'
    print("I'm buying this")
elif cheap and not goodQuality:
    print("I think I'll have to go with it")
elif not cheap and goodQuality:
    print("Why is it so expensive???")
else:
    print("This is trash")

print("")
print("")
print("")

