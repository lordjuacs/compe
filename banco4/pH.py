import heapq

customer_dict = {}
money_ordered = []
cash = 0

n, t = map(int, input().split())
people = {}
for customer in range(n):
    money, time = map(int, input().split())
    if time not in people:
        people[time] = []
    people[time].append(money)

for time in range(t - 1, -1, -1):
    if time in people:
        for money in people[time]:
            heapq.heappush(money_ordered, -money)
        cash += heapq.heappop(money_ordered)

print(cash * -1)
