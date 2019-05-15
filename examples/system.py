#################################################################
# this is an example on how to kill a process automatically
# after reading its pid file
#################################################################

import os
import syslog


pidfilename = "/var/run/login_bar.pid"


def check_pid(pid):
    syslog.syslog('checking for pid: ' + str(pid))
    """ Check For the existence of a unix pid. """
    try:
        os.kill(pid, 0)
    except OSError:
        return False
    else:
        return True


with open(pidfilename) as f:
    content = f.readlines()
    # read first line
    pid = int(content[0])
    if check_pid(pid):
        try:
            os.kill(pid, 9)
            os.remove(pidfilename)
        finally:
            print ("done")




