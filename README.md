# cap_pythonscript
Simple example to run python script with capabilities i.e. ambient capability.  

# Reference
http://man7.org/linux/man-pages/man7/capabilities.7.html

# Ambient Capability
       Ambient (since Linux 4.3)
              This is a set of capabilities that are preserved across an
              execve(2) of a program that is not privileged.  The ambient
              capability set obeys the invariant that no capability can ever
              be ambient if it is not both permitted and inheritable.

              The ambient capability set can be directly modified using
              prctl(2).  Ambient capabilities are automatically lowered if
              either of the corresponding permitted or inheritable
              capabilities is lowered.

              Executing a program that changes UID or GID due to the set-
              user-ID or set-group-ID bits or executing a program that has
              any file capabilities set will clear the ambient set.  Ambient
              capabilities are added to the permitted set and assigned to
              the effective set when execve(2) is called.  If ambient
              capabilities cause a process's permitted and effective
              capabilities to increase during an execve(2), this does not
              trigger the secure-execution mode described in ld.so(8).
              
# Building
> make
The make will build required binaries and places it in directory build/


# Running
Refer build/readme for more details

# What the sample code illustrates?
* Use of ambient capability 
* Semi-privileged environment with bash as example
* Running python script using ambient binary

Note: For more details refer file **readme** 
