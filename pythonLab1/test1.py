class Student:
    def __init__(self, name, student_id, age):
        self.name = name
        self.student_id = student_id
        self.age = age

    def getName(self):
        return self.name

    def getStudent_id(self):
        return self.student_id

    def getAge(self):
        return self.age


s1 = Student("lisi", 1234, 20)
print(f"name = {s1.getName()}, student_id = {s1.getStudent_id()}, age = {s1.getAge()}")
