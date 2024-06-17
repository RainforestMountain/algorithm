from test2 import Student


class GraduateStudent(Student):
    def __init__(self, name, student_id, age, mentor):
        super().__init__(name, student_id, age)
        # test2.Student.__init__(self, name, student_id, age)
        self.mentor = mentor

    def get_mentor(self):
        return self.mentor


g1 = GraduateStudent("lisi", 1234, 20, "jack")
print(g1.get_mentor())
