import sys
import time
import random
import zmq
import struct

def main():

    ctx = zmq.Context()

    pub = ctx.socket(zmq.PUB)
    pub.bind('tcp://127.0.0.1:7653')
    run_num = 1
    evt_num = 1

    while True:
        
        x = int(time.time())
        pub.send('timeStamp:' + struct.pack('III', run_num, evt_num, x))

        x = random.randint(0, 100)
        pub.send('rand_flat:' + struct.pack('III', run_num, evt_num, x))

        x = int(random.gauss(50, 15))
        pub.send('rand_gaus:' + struct.pack('IId', run_num, evt_num, x))

        evt_num += 1
        time.sleep(2)

if __name__ == '__main__':
    sys.exit(main())
