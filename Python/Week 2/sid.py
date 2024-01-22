def main():
    import random
    jackpot = random.randint(1, 10)
    for i in range(1, 6):
        guess = int ( input('Enter your guess: ') )
    if guess > jackpot:
        print('Your guess is too high!')
    elif guess < jackpot:
        print('Your guess is too low!')
    else: # hit it!
        print('You hit the JACKPOT!') 
        print('%d',jackpot) 
        return 0
    print("You lose. The jackpot is", jackpot)
    return 1
main()