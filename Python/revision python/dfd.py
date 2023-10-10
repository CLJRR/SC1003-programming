userDict = {
    'Test': 'Test12345',
    'Jack': 'Test12345',
    'Tom': 'Password1',
}
# test = 1
# print(userDict.items())
# print(userDict.keys())
# print(userDict.values())


def pfunct(param):
    param.append(4)
    return param


arg = [1, 2, 3]
newlist = pfunct(arg)
print(newlist, arg)

myVar = 127


def myFun():
    global myVar
    myVar += 1


myFun()
print(myVar)
