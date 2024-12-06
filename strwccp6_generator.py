import random

def generate_test_data(num_tasks, max_deadline):
    print(num_tasks)
    for _ in range(num_tasks):
        t = random.randint(1, 1440)
        d = random.randint(1, max_deadline)
        print(t, d)

if __name__ == "__main__":
    num_tasks = 100000
    max_deadline = 100000
    generate_test_data(num_tasks, max_deadline)

