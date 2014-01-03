#!/usr/bin/env python

# http://www.pythonforbeginners.com/systems-programming/how-to-use-the-pexpect-module-in-python/
# http://pexpect.readthedocs.org/en/latest/
import pexpect
import sys

child = pexpect.spawn('./ex19')
child.logfile = sys.stdout

child.expect('You enter the The great Hall.')
child.sendline('l')
child.expect('NORTH')
child.sendline('n')
child.expect('The throne room\.')
child.sendline('l')
child.expect('WEST')
child.sendline('e')
child.expect('Kitchen, you have the knife now\.')
child.sendline('w')
child.expect('The throne room\.')
child.sendline('w')
child.expect('The arena, with the minotaur\.')
child.sendline('a')
child.expect('You attack The evil minotaur!')
