# dictionary of existing users
userDict = {
    'Test': 'Test12345',
    'Jack': 'Test12345',
    'Tom': 'Password1',
}


# function to check if username is in existing users
# return 1 if username is taken
# retuen 0 if username is free
def usernameChecker(Username, userList):
    if Username in list(userList):
        return 1
    else:
        return 0


# function to check if password meets req
# ask for the User's Input to be shared through variable "Password"
# returns 1 if password does not meet requirement
# returns 0 if password meets requirements
def passwordchecker(Password):
    # set variables to false/0
    upper = lower = digit = int(0)
    length = int(len(Password))
    if length <= 0:
        return 1
    # this is prob how u will do it in C language
    for i in range(0, length):
        if Password[i].isupper() == 1:
            upper = 1
        if Password[i].islower() == 1:
            lower = 1
        if Password[i].isdigit() == 1:
            digit = 1
        if upper*lower*digit == 1:
            return 0
    return 1


def main():
    check = False
    # To get username
    while check != True:
        # req UserInput
        Username = input("User registration:\nInput your user name:")
        # calls Function usernameChecker, and shares userInput variables "Username" and GLOBAL variable "userDict"
        # if function returns 0 (username is free)
        if usernameChecker(Username, userDict) == 0:
            break
        # else if function returns 1 (username is taken)
        else:
            print("The user exists. Please choose another user name.")

    # To get password
    while check != True:
        # req UserInput
        Password = input(
            "Input your password:\n1.the password has at least one upper case letter\n2.the password has at least one lower case letter\n3.the password has at least one digit\n")
        # Calls Function passwordchecker, and shares UserInput Variable "Password"
        # if funct returns 0 (password meets requirements)
        if passwordchecker(Password) == 0:
            print("Your password is strong enough. User registered.")
            break
        else:
            print("Your password is weak. Please enter a new password")
    # At this pt, username and password are both valid

    # add username and password to dictionary
    userDict[Username] = Password
    # print all existing users in dictionary
    print(userDict)


# this main() is to tell vscode / idle that this is the main program to run
main()
