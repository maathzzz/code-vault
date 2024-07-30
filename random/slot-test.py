import random

def spin():
    grid = [[random.choices(symbols, probabilities)[0] for _ in range(3)] for _ in range(3)]
    return grid

# Grid:
# ['#', '#', '#']
# ['#', '#', '#']
# ['#', '#', '#']

# Função para calcular o pagamento
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

# Teste
total_bet = 5
bet_per_line = total_bet / 5
grid = spin()
payment = calculate_payment(grid, bet_per_line)

print("Grid:")
for row in grid:
    print(row)
print(f"Total Payment: ${payment}")
