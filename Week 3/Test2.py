

usernames = {
    0: "Test",
    1: "Jack",
    2: "Tom",
}
passwords = {
    0: 'Test12345',
    1: 'Test12345',
    2: 'Password1',
}
check = False
userCheck = False
# while check != True:
#     Username = "Tom"
#     for i in range(0, 3, 1):
#         if Username is usernames[i]:
#             userCheck = True
#         print()
#         print(Username, usernames[i], userCheck)
#     break

while check != True:
    Username = input("User registration:\nInput your user name:")
    # Username = "Tom"
    for i in range(0, 3, 1):
        if Username is usernames[i]:
            userCheck = True
        print()
        print(Username, usernames[i], userCheck)
    break
