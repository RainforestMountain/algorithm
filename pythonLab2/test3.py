import struct
import pickle

with open('E:\\python_code\\program_code\\pythonLab2\\b.bat', 'wb') as file:
    table_head = struct.pack("20s20sii", b'Student Number', b'Name', 0, 0)  # Assuming fixed size for student number and name
    student1 = struct.pack("20s20sii", b'1001', b'Alice', 85, 78)
    student2 = struct.pack("20s20sii", b'1002', b'Bob', 90, 92)
    file.write(table_head)
    file.write(student1)
    file.write(student2)

with open('b.bat', 'rb') as file:
    table_head_size = struct.calcsize("20s20sii")
    total_python_score = 0
    total_ds_score = 0
    num_students = 0

    while True:
        data = file.read(table_head_size)
        if not data:
            break
        student_info = struct.unpack("20s20sii", data)
        total_python_score += student_info[2]
        total_ds_score += student_info[3]
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
