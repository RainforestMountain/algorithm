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

    def introduce(self):
        print("name = {0},student_id =  {1}, age = {2}".format(self.name, self.student_id, self.age))


if __name__ == "__main__":
    s1 = Student("lisi", 1234, 20)
    s1.introduce()
