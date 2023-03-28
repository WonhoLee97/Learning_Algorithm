N, M, K = map(int, input().split())

data = list(map(int, input().split()))

data.sort()

result = 0
while True:
    first = data[N-1]
    second = data[N-2]
    
    for i in range(K): #K번 까지는 제일 큰 수 더함
        if M==0:
            break
        result += first
        M-=1
        
    if M==0: #K번 이후
        break
    result += second
    M-=1

print(result)
            

