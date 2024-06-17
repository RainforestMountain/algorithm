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

    @classmethod
    def get_class_average_age(cls, students):
        try:
            listA = list(students)
            all_age = 0
            for student in listA:
                all_age += student.age

            return all_age / len(listA)
        except Exception as e:
            print(e)
            return -1

    def is_adult(self):
        if self.age >= 18:
            print("yes")
        else:
            print("no")


listA = [Student("lisi", 1234, 20), Student("zhangsan", 1235, 23),
         Student("wangwu", 1236, 17)]
print(Student.get_class_average_age(listA))

for student in listA:
    student.is_adult()
