n = int(input())
curr_time = 0
travel = 0
cost = [0] + list(map(int, input().split()))
time = list(map(int, input().split()))
best_wait = [0] * n
best_wait[1] = cost[1]
for i in range(2, n):
    best_wait[i] = min(best_wait[i - 1], cost[i])
for i in range(1, n):
    curr_time += 1
    travel += cost[i]
    if curr_time < time[i]:
        wait_interval = time[i] - curr_time
        if wait_interval % 2 != 0:
            wait_interval += 1
        curr_time += wait_interval
        travel += wait_interval * best_wait[i]
print(travel)
