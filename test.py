import process
import time

data='abdqwbeujqehujqkahwsdjkwqgherjqwabndjkgqukwjehnkqwbadxukjqwghjkkbjdklbqwuikbjklhgeujkdqwbnadsxjkbquwkgedujkqwbsdjkxhqwuikhbedjkgbqwujkasgxjkqwbeukdsgq'

iter = 100000

ptr = process.setup(1234)

start_time = time.time()

for i in range(0, iter):
    process.set(ptr, data)
    value = process.get(ptr)

print(time.time() - start_time)

process.clean(1234, ptr)

