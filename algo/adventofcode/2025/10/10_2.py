from itertools import combinations
from scipy.optimize import linprog

ans = 0
for _, *buttons, jolts in map(str.split, open('input.txt')):
    buttons = [eval(b[:-1]+',)') for b in buttons]
    jolts = eval(jolts[1:-1])
    costs = [1 for b in buttons]
    eqs = [[i in b for b in buttons] for i in range(len(jolts))]
    ans += linprog(costs, A_eq=eqs, b_eq=jolts, integrality=1).fun

print(ans)