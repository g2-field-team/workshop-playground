import sys
import time
import random
import zmq

def main():

    ctx = zmq.Context()

    pub = ctx.socket(zmq.PUB)
    pub.bind('tcp://127.0.0.1:7653')

    while True:
        
        pub.send('timeStamp:' + str(int(time.time())))
        pub.send('rand_int:' + random.int(0, 100))
        pub.send('rand_flat:' + random.random())
        time.sleep(2)

if __name__ == __main__:
    sys.exit(main())
