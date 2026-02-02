'''
2 ways
1. decorator
2. metaclass
'''

#either __call__ method is overrided or __new__ method is overrided

#metaclass
class SingletonMeta(type):
    _instance = None

    def __call__(cls, *args, **kwargs):
        print("class", cls)
        if cls._instance is None:
            cls._instance = super().__call__(*args, **kwargs)

        return cls._instance


#class
class SingletonClass(metaclass = SingletonMeta):

    def __init__(self) -> None:
        pass

single_instance1 = SingletonClass()
single_instance2 = SingletonClass()
print(single_instance1 is single_instance2)



