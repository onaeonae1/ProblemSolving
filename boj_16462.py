import sys
import decimal

context = decimal.getcontext()
context.rounding = decimal.ROUND_HALF_UP

N = int(input())

temp_list = []
temp_sum = 0
for i in range(N):
    m = input()
    m = m.replace("6", "9")
    m = m.replace("0", "9")
    m = int(m)
    m = 100 if m >= 100 else m
    temp_sum += m

res = temp_sum / N
res = round(decimal.Decimal(res), 0)
print(res)
