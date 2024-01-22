import random
jackpot = random.randint(1, 10)
hit =False
for i in range(1, 6):
    guess = int ( input('Enter your guess: ') )
    if guess > jackpot:
        print('Your guess is too high!')
    elif guess < jackpot:
        print('Your guess is too low!')
    else: # hit it!
        hit = True
        break
if hit == False:
    print("You lose. The jackpot is", jackpot)
else:
    print('You hit the JACKPOT!') 
