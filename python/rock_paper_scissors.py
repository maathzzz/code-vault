import random 

def play():
    user = input("What's your choice? 'r' for rock, 'p' for paper, 's' for scissors\n")
    computer =  random.choice(['r', 'p', 's'])

    if user == computer:
        return print('It was a tie!')
    
    if who_win(user, computer):
        return print('You Won! :)')
    return print('You Lost! :(')

def who_win(player, opponent):
    if (player == 'r' and opponent == 's') or (player == 's' and opponent == 'p') or (player == 'p' and opponent == 'r'):
        return True

play() 