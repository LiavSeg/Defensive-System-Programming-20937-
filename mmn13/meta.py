import importlib.util
import inspect
import types
import builtins

def find_first_class(module):
    for name in dir(module):
        attribute = getattr(module,name)
        if inspect.isclass(attribute):
            return attribute
    return None

def func_wrap(func, code_to_add,cls):
    def ret(*args):
        try:
            compile(code_to_add,'<string>','exec')
        except Exception as e:
            print('Could not compile this given code')
            exit(1)
        print(f'>>> This is an added code for {func.__name__} function of {cls} class: ',end= ">>> " )
        exec(code_to_add)
        return func(*args)
    return ret

def modify_funcs(moded_class,code_to_add):
    for name in dir(moded_class):
        attribute = getattr(moded_class,name)
        if inspect.isfunction(attribute):
            cls = func_wrap(attribute,code_to_add,moded_class.__name__)
            setattr(moded_class,name,cls)

def main():
    file_name = input("Please enter a file name: ") #File's name obtained by user's input
    spec = importlib.util.find_spec(file_name)
    if not spec:
        print(f'Could not locate file named {file_name}')
        exit(1)
    else:
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)

    code_to_add = input("Please enter a line of code: ")
    moded_class = find_first_class(module)
    if not moded_class:
        print(f"Could not locate any classes in {file_name} module")
        exit(1)
    modify_funcs(moded_class, code_to_add)

    if hasattr(module, 'main'):
        module.main()
    else:
        print('Could not locate main function')

if __name__=='__main__':
    main()

