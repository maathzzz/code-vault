import random

def guess(x):
    random_number = random.randint(1, x)
    guess = 0

    while guess != random_number:
        guess = int(input(f'Guess a number between 1 and {x}: '))

        if guess < random_number:
            print('Number guessed is lower than the secret number')
        elif guess > random_number:
            print('Number guessed is bigger than the secret number')
    print(f"Congrats. You have have guessed the secret number: {random_number}")


def computer_guess(x):
    low = 1
    high = x
    feedback = ''

    while feedback != 'c':
        if low != high:
            guess = random.randint(low, high)
        else:
            guess = low # could also be high b/c low = high
        feedback = input(f"Is {guess} to high (H), too low (L), or correct (C)?").lower()
        if feedback == 'h':
            high = guess - 1
        elif feedback == 'l':
            low = guess + 1
    print(f'Congrats, the computer guessed the correct number, which is {guess}')

# guess(10)
computer_guess(392)