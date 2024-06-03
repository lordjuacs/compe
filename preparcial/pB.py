LEFT = 0
RIGHT = 1
INF = 10**9


def check(k, r, direction, gallery, dp):
    if k == 0:
        return 0
    if r < 0:
        return INF
    if dp[k][r][direction] is not None:
        return dp[k][r][direction]

    room = gallery[r][direction]
    dp[k][r][direction] = min(
        check(k - 1, r - 1, direction, gallery, dp) + room, solve(k, r - 1, gallery, dp)
    )
    return dp[k][r][direction]


def solve(k, r, gallery, dp):
    if k == 0:
        return 0
    if r < 0:
        return INF
    if dp[k][r][LEFT] is None or dp[k][r][RIGHT] is None:
        dp[k][r][LEFT] = check(k, r, LEFT, gallery, dp)
        dp[k][r][RIGHT] = check(k, r, RIGHT, gallery, dp)
    return min(dp[k][r][LEFT], dp[k][r][RIGHT])


while True:
    n, k = map(int, input().split())
    if n == 0 and k == 0:
        break

    gallery = []
    sum_rooms = 0
    for _ in range(n):
        left, right = map(int, input().split())
        gallery.append([left, right])
        sum_rooms += left + right

    dp = [[[None] * 2 for _ in range(n)] for _ in range(k + 1)]
    result = solve(k, n - 1, gallery, dp)
    print(sum_rooms - result)
