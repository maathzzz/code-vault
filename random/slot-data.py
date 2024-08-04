import random
from collections import Counter

def spin():
    grid = [[random.choices(symbols, probabilities)[0] for _ in range(3)] for _ in range(3)]
    return grid

def calculate_payment(grid, bet_per_line):
    lines = [
        [grid[0][0], grid[0][1], grid[0][2]],  # Horizontal 1
        [grid[1][0], grid[1][1], grid[1][2]],  # Horizontal 2
        [grid[2][0], grid[2][1], grid[2][2]],  # Horizontal 3
        [grid[0][0], grid[1][1], grid[2][2]],  # Diagonal 1
        [grid[0][2], grid[1][1], grid[2][0]]   # Diagonal 2
    ]
    
    total_payment = 0
    for line in lines:
        if line[0] == line[1] == line[2]:
            symbol = line[0]
            total_payment += bet_per_line * multipliers[symbol]
    
    return total_payment

# Dados iniciais
symbols = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
probabilities = [40.22, 24.15, 15.09, 12.08, 4.83, 2.42, 1.21]
multipliers = {'A': 3, 'B': 5, 'C': 8, 'D': 10, 'E': 25, 'F': 50, 'G': 100}

# Parâmetros de teste
total_bet = 5
bet_per_line = total_bet / 5

# Estatísticas
total_spins = 1000
wins = 0
total_won = 0
symbol_count = Counter()

for _ in range(total_spins):
    grid = spin()
    payment = calculate_payment(grid, bet_per_line)
    
    # Atualizar contagem de símbolos
    for row in grid:
        symbol_count.update(row)
    
    if payment > 0:
        wins += 1
        total_won += payment

# Resultados
print(f"Total de rodadas: {total_spins}")
print(f"Total de vitórias: {wins}")
print(f"Total ganho: ${total_won}")
print(f"Total apostado: ${total_bet * total_spins}")
print(f"Frequência dos símbolos:")
for symbol, count in symbol_count.items():
    print(f"  {symbol}: {count}")
