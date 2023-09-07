
def usernameChecker(Username, userList):
    if Username in list(userList):
        return 0
    else:
        return 1


def passwordchecker(Password):
    upper = lower = digit = int(0)
    password = Password
    length = int(len(password))
    if length == 0:
        return 0
    for i in range(0, length):
        if password[i].isupper() == 1:
            upper = 1
        if password[i].islower() == 1:
            lower = 1
        if password[i].isdigit() == 1:
            digit = 1
        if upper*lower*digit == 1:
            return 1


def UserReg():
    userDict = {
        'Test': 'Test12345',
        'Jack': 'Test12345',
        'Tom': 'Password1',
    }
    check = False
    while check != True:
        Username = input("User registration:\nInput your user name:")
        if usernameChecker(Username, userDict) == 1:
            print("user exists")
        else:
            print("enter password")

    while check != True:
        Password = input(
            "Input your password:\n1.the password has at least one upper case letter\n2.the password has at least one lower case letter\n3.the password has at least one digit\n")
        if passwordchecker(Password) == 1:
            print("Your password is strong enough. User registered.")
            break
        else:
            print("Your password is weak. Please enter a new password")
    userDict[Username] = Password
    print(userDict)


def UserLogin():
    userDict = {
        'Test': 'Test12345',
        'Jack': 'Test12345',
        'Tom': 'Password1',
    }
    Username = input("Input your user name:")
    if usernameChecker(Username, userDict) == 1:
        print("User Does not exist")
        return 0
    print("check")


def main():
    choice = 0
    while choice <= 0 or choice >= 3:
        try:
            choice = int(input(
                "Please select one of the following options:\n1. User registration\n2. User Login\n"))
        except ValueError:
            print("Please enter a valid value")

    if choice == 1:
        UserReg()
    else:
        UserLogin()


main()
