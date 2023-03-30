n, m = map(int, input().split())

result = 0

for i in range(n):
    cards = list(map(int, input().split()))
    tmp=min(cards)

    result=max(tmp,result)
    
print(result)