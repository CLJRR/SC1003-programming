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
    special = upper = lower = digit = int(0)
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
        # all special character converted to decimals based on ASCII table are
        # 33–47 / 58–64 / 91–96 / 123–126
        # ord converts the character to decimal based on ASCII table
        # e.g. A=65, B=66,...
        # J UST GOOGLE ASCII TABLE
        # therefore if CHAR is >=33 and <=47, it is a special char
        if (ord(Password[i]) >= 33 and ord(Password[i]) <= 47) or (ord(Password[i]) >= 58 and ord(Password[i]) <= 64) or (ord(Password[i]) >= 91 and ord(Password[i]) <= 96) or (ord(Password[i]) >= 123 and ord(Password[i]) <= 126):
            special = 1
        # if all condt are met, return 0
        if special*upper*lower*digit == 1:
            return 0
    return 1


def UserReg():
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


def UserLogin():
    Username = input("Input your user name:")
    # calls Function usernameChecker, and shares userInput variables "Username" and GLOBAL variable "userDict"
    # if Function returns 0 (username is not in directory)
    if usernameChecker(Username, userDict) == 0:
        print("User Does not exist")
        # return 0 can be used as "break"
        return 0
    check = False
    while check != True:
        password = input("Input password:")
        if password != userDict[Username]:
            print("Wrong password, input again")
        else:
            print("Welcome back, {}, You can start the game.".format(Username))
            return 0


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


# this main() is to tell vscode / idle that this is the main program to run
main()
