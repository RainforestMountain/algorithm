import pickle

with open('b.txt', 'w') as file:
    file.write("Student Number, Name, Python Program, Data Structure\n")
    file.write("1001, Alice, 85, 78\n")
    file.write("1002, Bob, 90, 92\n")

with open('b.txt', 'r') as file:
    next(file)  # Skip the header row
    total_python_score = 0
    total_ds_score = 0
    num_students = 0
    for line in file:
        student_info = line.strip().split(',')
        python_score = int(student_info[2])
        ds_score = int(student_info[3])
        total_python_score += python_score
        total_ds_score += ds_score
        num_students += 1

    average_python_score = total_python_score / num_students
    average_ds_score = total_ds_score / num_students

data = {
    'average_python_score': average_python_score,
    'average_ds_score': average_ds_score
}

with open('average_scores.pkl', 'wb') as file:
    pickle.dump(data, file)

print("Average Python Program score:", average_python_score)
print("Average Data Structure score:", average_ds_score)
