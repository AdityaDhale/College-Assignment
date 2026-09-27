# Assignment 2: Cricket, Badminton and Football

# Input students
cricket = input("Enter names of students playing cricket: ").split()
badminton = input("Enter names of students playing badminton: ").split()
football = input("Enter names of students playing football: ").split()

# 1. Students who play both cricket and badminton
print("\n1. Students who play both cricket and badminton:")

for student in cricket:
    if student in badminton:
        print(student)

# 2. Students who play either cricket or badminton but not both
print("\n2. Students who play either cricket or badminton but not both:")

for student in cricket:
    if student not in badminton:
        print(student)

for student in badminton:
    if student not in cricket:
        print(student)

# 3. Number of students who play neither cricket nor badminton
print("\n3. Number of students who play neither cricket nor badminton:")

count = 0

for student in football:
    if student not in cricket and student not in badminton:
        count = count + 1

print(count)

# 4. Number of students who play cricket and football but not badminton
print("\n4. Number of students who play cricket and football but not badminton:")

count = 0

for student in cricket:
    if student in football and student not in badminton:
        count = count + 1

print(count)