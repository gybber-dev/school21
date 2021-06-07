def run_once(f):
    def wrapper(*args, **kwargs):
        if not wrapper.has_run:
            wrapper.has_run = True
            return f(*args, **kwargs)
    wrapper.has_run = False
    return wrapper

def my_function(foo, bar):
    return foo+bar

action = run_once(my_function)
print(action(1, 2))
print(action(1, 2))
