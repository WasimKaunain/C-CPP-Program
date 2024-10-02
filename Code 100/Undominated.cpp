def round_robin_schedule(n):
    # Base case: If there are 2 teams, the schedule is trivial
    if n == 2:
        return [[(1, 2)]]
    
    # Recursive case: Divide the teams into two halves
    half = n // 2
    left_schedule = round_robin_schedule(half)  # Schedule for teams 1 to half
    right_schedule = round_robin_schedule(half)  # Schedule for teams half+1 to n
    
    # Create a schedule of size n-1 days
    schedule = []
    
    # Schedule matches within groups (copying from the recursive results)
    for i in range(half - 1):
        schedule.append(left_schedule[i] + right_schedule[i])
    
    # Schedule matches between teams in left group and right group
    for day in range(half):
        cross_group_matches = []
        for i in range(half):
            cross_group_matches.append((i+1, i+half+1))  # (team from left group, team from right group)
        schedule.append(cross_group_matches)
    
    return schedule

# Example usage:
n = 4
schedule = round_robin_schedule(n)
for day, matches in enumerate(schedule, start=1):
    print(f"Day {day}: {matches}")