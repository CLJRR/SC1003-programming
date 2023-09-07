import random

def guess_check():
    guess = input("Enter an integer from 1 to 9: ")
    while guess.isdigit() == False:
        guess = input("Wrong input format. Please try again.")
    guess = int(guess)
    if guess < 1 or guess > 9:
        print("Guess out of range. Please try again.")
        guess_check()
    return guess

def sum_check():
    guess = input("Please enter your answer: ")
    while guess.isdigit() == False:
        print("Wrong input format. Please try again.")
    guess = int(guess)
    return guess
              
    
def guessing():
    n = random.randint(1, 9)
    guess = guess_check()
    trials = 1
    while trials < 3:
        print
        if guess < n:
            print ("guess is low")
            guess = guess_check()
            trials += 1
        elif guess > n:
            print ("guess is high")
            guess = guess_check()
            trials += 1
        elif guess == n:
            break
        print
    if guess == n:
        print("You guessed it by {} trials!".format(str(trials)))
    if trials == 3 and guess != n:
        print("Sorry, you exceeded the trial limit. Failed.")

def sum_game():
    n = random.randint(55,66)
    total = 0
    for i in range(n,n+5):
        total += i
    print("Please calculate the sum of 5 integers that start from {}".format(str(n)))
    guess = sum_check()
    if guess != total:
        print("Sorry, wrong answer. Failed.")
    else:
        print("Answer is correct. Well done.")

def menu_check():
    done = False
    while not done:
        menu_option = input()
        if len(menu_option) == 0:
            continue
        elif menu_option.isdigit():
            if 1 <= int(menu_option) <= 2:
                done = True
            else:
                print("Please select a valid option.")
    return int(menu_option)
        
    
def menu():
    done = False
    while not done:
        print('''Please select one of the following quizzes:
                    1.Number guessing
                    2.Calculate sum''')
        option = menu_check()
        done = True
    if option == 1:
        guessing()
    elif option == 2:
        sum_game()
menu()




        
