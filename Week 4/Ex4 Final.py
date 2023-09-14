import random
# dictionary of existing users
userDict = {
    'Test': 'Test12345',
    'Jack': 'Test12345',
    'Tom': 'Password1',
}


def getuserchoice():
    choice = 0
    while choice <= 0 or choice >= 5:
        try:
            choice = int(input(
                "Please select one of the following options:\n1. User registration\n2. User Login\n3. Play the game as a guest\n"))
        except ValueError:
            print("Please enter a valid value")
    return choice


def UserReg(Name, Password):
    # At this pt, username and password are both valid
    # add username and password to dictionary
    userDict[Name] = Password
    # prompt start game
    print("New User registered. You can start the game.")


# To get username
def NewUsername():
    check = False
    while check != True:
        # get UserInput
        Username = input("User registration:\nInput your user name:")
        # calls Function usernameChecker, and shares userInput variables "Username" and GLOBAL variable "userDict"
        # if function returns 0 (username is free)
        if usernameChecker(Username, userDict) == 0:
            break
        # else if function returns 1 (username is taken)
        else:
            print("The user exists. Please choose another user name.")
    return Username


# function to check if username is in existing users
# return 1 if username is taken
# retuen 0 if username is free
def usernameChecker(Username, userList):
    if Username in list(userList):
        return 1
    else:
        return 0


def NewPassword():
    # To get password
    check = False
    while check != True:
        # req UserInput
        Password = input(
            "Input your password:\n1.the password has at least one upper case letter\n2.the password has at least one lower case letter\n3.the password has at least one digit\n")
        # Calls Function passwordchecker, and shares UserInput Variable "Password"
        # if funct returns 0 (password meets requirements)
        if passwordchecker(Password) == 0:
            print("Your password is strong enough. User registered.")
            return Password
        else:
            print("Your password is weak. Please enter a new password")


# function to check if password meets req
# ask for the User's Input to be shared through variable "Password"
# returns 1 if password does not meet requirement
# returns 0 if password meets requirements
def passwordchecker(Password):
    # set variables to false/0
    special = upper = lower = digit = int(0)
    length = int(len(Password))
    if length <= 7:
        return 1
    # this is prob how u will do it in C language
    for i in range(0, length):
        if Password[i].isupper() == 1:
            upper = 1
        if Password[i].islower() == 1:
            lower = 1
        if Password[i].isdigit() == 1:
            digit = 1
        # if all condt are met, return 0
        if upper*lower*digit == 1:
            return 0
    return 1


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


def Quizzes():
    print("Dear Guest, you have to pass one quiz to play the game.")
    gamechoice = getGamechoice()
    if gamechoice == 1:                   # Program 1 is the number guessing game
        guessingGame()
    else:                               # selection 2 is the sum calculation
        calcGame()


# get user to choose between option 1 and 2 to choose program.
# use of exception should user enter an invalid input, req user to re-enter selection
def getGamechoice():
    gamechoice = int(0)
    while gamechoice <= 0 or gamechoice >= 3:
        try:
            gamechoice = int(input(
                "please enter a NUMBER 1 or 2 for the following selection:\n1. Number guessing game\n2. Calculate sum\n"))
        except ValueError:
            print("Please enter a valid value")
    return gamechoice


def guessingGame():
    print("\nWelcome to the number guessing game!\nYou have 3 tries to guess a number between 1 and 9\nThe system will tell you if your guess is too high or low")
    # generate a number between 1 and 9 10 not included
    n = random.randrange(1, 10, 1)
    tries = int(1)                    # set intial tries number 1
    # allow 3 tries in program
    while tries <= 3:
        # get user input
        guess = int(0)               # set guess back to 0
        while guess <= 0 or guess >= 10:
            try:
                guess = int(
                    input("Please enter guess number {}\n".format(tries)))
            except ValueError:
                print("Invalid input", end=", ")
                tries += 1
                if tries == 4:
                    break

        if guess == n:            # end if user guesses number
            print(
                "Congratulations. You guessed it by {} trials!\n\nCongratulations. You can start the game.".format(tries))
            break
        elif guess > n:               # tell user if guess is too high or low
            print("Your guess was too high", end=", ")
            tries += 1
        elif guess == 0:
            print
        else:
            print("Your guess was too low", end=", ")
            tries += 1
    if tries == 4:                    # tell user the number if failed to guess number
        print("you did not guess the number.\nThe number was {}\nThanks for playing!".format(n))


def calcGame():
    print("This program will calculate the sum of 5 consecutive integers.")
    # generate a random number beeween 55 and 66, 67 not included
    number = random.randrange(55, 67, 1)
    sum = int(0)                      # intialize sum to integer
    for n in range(0, 5, 1):          # add the consecutive number and print result
        sum += int(number+n)
    guess = int(0)
    while (True):
        try:
            print("Please calculate the sum of 5 integers start from {}".format(number))
            guess = int(input())
            break
        except ValueError:
            print("Invalid input, please enter a number")
    if guess == sum:
        print("Congratulations. You can start the game.")
    else:
        print("Wrong, The result is {}".format(sum))


def main():
    while True:
        choice = getuserchoice()
        if choice == 1:
            # so this calles the 2 other functions, if u move to the UserReg function on top, it saves it as name and password respectively
            # therefore:
            #  Name = NewUsername()
            #  Password = NewPassword()
            UserReg(NewUsername(), NewPassword())
        elif choice == 2:
            UserLogin()
        elif choice == 3:
            Quizzes()
        else:
            return 0


main()
