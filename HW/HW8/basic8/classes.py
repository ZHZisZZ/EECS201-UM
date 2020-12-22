class Student:
    def __init__(self, name, grade):
        self.name = name
        self.grade = grade
    
    def passing(self):
        return True if self.grade >= 70 else False 

    def __str__(self):
        return "{} - {}".format(self.name, self.grade)

