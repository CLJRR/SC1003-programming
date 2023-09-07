
userList = {
    'Test': 'Test12345',
    'Jack': 'Test12345',
    'Tom': 'Password1',
}
check = False
while check != True:
    Username = str(input("User registration:\nInput your user name:"))
    # Username = "Tom"
    if Username in list(userList):
        print("The user exists. Please choose another user name.")
    else:
        break
