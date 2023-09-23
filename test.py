def myFun(x):
    Y = x[:]
    Y.append(4)
    return Y


mylist = ["a", "b", "c"]
newlist = myFun(mylist)

print(newlist)
print(mylist)
