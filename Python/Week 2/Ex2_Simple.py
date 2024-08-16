import random
# get user to choose between option 1 and 2 to choose program.
# use of exception should user enter an invalid input, req user to re-enter selection
gamechoice = int(0)
while gamechoice <= 0 or gamechoice >= 3:
    try:
        gamechoice = int(input(
            "please enter a NUMBER 1 or 2 for the following selection:\n1. Number guessing game\n2. Calculate sum\n"))
    except ValueError:
        print("Please enter a valid value")

if gamechoice == 1:                   # Program 1 is the number guessing game
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
            print("Congratulations, you guessed it!")
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

else:                               # selection 2 is the sum calculation
    print("This program will calculate the sum of 5 consecutive integers.")
    # generate a random number beeween 55 and 66 67 not included
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
        print("Correct")
    else:
        print("Wrong, The result is {}".format(sum))
print("End of program")             # end of prog
