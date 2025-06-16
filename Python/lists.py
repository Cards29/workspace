friends = ["Rafat", 5, 3.14159, "Rahinur"]
print(friends)
print(*friends)
print(friends[0])
print(friends[1])
print(friends[2])
print(friends[0::])
print(*friends[0::])

print(friends[-1])
print(friends[-2])
print(friends[-3])
print(friends[::-1])
print(*friends[::-1])

print(friends[1:])
print(friends[1:1])
print(friends[1:3]) # prints from index 1 to index 3 (excluding index 3)

friends[1] = "Jhingalala 10"
print(*friends)