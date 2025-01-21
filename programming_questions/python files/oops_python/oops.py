class Person:

    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def get_name(self):
        return self.name
    
    def get_age(self):
        return self.age
    
    def set_name(self, name):
        self.name = name

    def set_age(self, age):
        self.age = age
    
    def __priv(self):
        return "private_string"
    
    def get_priv(self):
        s = self.__priv()
        return s
    
    

class Employee(Person):

    def __init__(self, team, id, project, name, age):

        super().__init__(name, age)
        self.team  = team
        self.id = id
        self.project = project
    
    def get_id(self):
        return self.id
    
    def set_id(self, id):
        self.id = id
    
    def get_age(self):
        return "12"

class Matrix:

    def __init__(self, row, col):
        arr = [0] * row




if __name__ == '__main__':
    person = Person("keshav","2")
    print("person age: ",person.get_age())
    print("private method val: ",person.get_priv())
    emp = Employee("jarvis","1","MRE","keshav","48")
    print("Accessing the base call method using child obj: get_name ",emp.get_name(), emp.get_age())