current = input().split(":")
explosion = input().split(":")
current = [int(i) for i in current]
explosion = [int(i) for i in explosion]
if current == explosion:
    print("24:00:00")
else:
    if current[2] > explosion[2]:
        explosion[2] += 60
        explosion[1] -= 1
    second = explosion[2] - current[2]
    if current[1] > explosion[1]:
        explosion[1] += 60
        explosion[0] -= 1
    minute = explosion[1] - current[1]
    if current[0] > explosion[0]:
        explosion[0] += 24
    hour = explosion[0] - current[0]
    if hour < 10:
        hour = "0" + str(hour)
    if minute < 10:
        minute = "0" + str(minute)
    if second < 10:
        second = "0" + str(second)
    print(str(hour) + ":" + str(minute) + ":" + str(second))
